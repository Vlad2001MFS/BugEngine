#include "BgRenderDevice.h"
#include "../Math/BgMath.h"
#include <cstring>
#include <algorithm>

BgRenderDevice::BgRenderDevice(const BgWindow * window) : mWindow(window) {
    BG_ASSERT(window);
    mSurfaceColor = window->GetSurface();
    mSize = window->GetSize();
    mSurfaceColorPitch = sizeof(BgUint32)*mSize.x;

    mClearColorLine = new BgUint32[mSize.x];
    memset(mClearColorLine, 0, mSurfaceColorPitch);
    mTempLine = new BgUint32[mSize.x];
    memset(mTempLine, 0, mSurfaceColorPitch);

    float step = BG_MATH_PI / mUnitArc.GetSize();
    BgUint32 i = 0;
    for (float a = -BG_MATH_PI / 2.0f; a < BG_MATH_PI / 2.0f; a += step) {
        mUnitArc[i].x = cosf(a);
        mUnitArc[i].y = sinf(a);
        i++;
    }
}

BgRenderDevice::~BgRenderDevice() {
    BG_DELETE_ARRAY(mTempLine);
    BG_DELETE_ARRAY(mClearColorLine);
}

void BgRenderDevice::ClearColor(BgUint8 r, BgUint8 g, BgUint8 b, BgUint8 a) {
    BgUint32 color = BG_MAP_RGBA(r, g, b, a);
    if (mClearColorLine[0] != color) {
        for (int x = 0; x < mSize.x; x++) {
            mClearColorLine[x] = color;
        }
    }
    for (int y = 0; y < mSize.y; y++) {
        memcpy(&mSurfaceColor[y*mSize.x], mClearColorLine, mSurfaceColorPitch);
    }
}

void BgRenderDevice::DrawPoint(BgUint32 color, const BgVector2 & pos) {
    mSetPixel(color, (int)pos.x, (int)pos.y);
}

void BgRenderDevice::DrawLine(BgUint32 color, const BgVector2 & start, const BgVector2 & end) {
    int x0 = (int)start.x, y0 = (int)start.y;
    int x1 = (int)end.x, y1 = (int)end.y;
    if (x0 == x1) {
        int dirY = BgMath::Clamp(y1 - y0, -1, 1);
        for (int y = y0; y != y1; y += dirY) {
            mSetPixel(color, x0, y);
        }
    }
    else {
        if (x1 - x0 < y1 - y0) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        int dirX = BgMath::Clamp(x1 - x0, -1, 1);
        for (int x = x0; x != x1; x += dirX) {
            int y = ((y1 - y0)*(x - x0))/(x1 - x0) + y0;
            mSetPixel(color, x, y);
        }
    }
}

void BgRenderDevice::DrawTriangle(BgUint32 color, const BgVector2 * verts) {
    BG_ASSERT(verts);
    DrawLine(color, verts[0], verts[1]);
    DrawLine(color, verts[1], verts[2]);
    DrawLine(color, verts[2], verts[0]);
}

void BgRenderDevice::DrawRect(BgUint32 color, const BgVector2 & pos, const BgVector2 & size) {
    BgIntVector2 min = pos;
    BgIntVector2 max = pos + size;
    if (min.x >= 0 && min.y >= 0 && max.x < mSize.x && max.y < mSize.y) {
        mSetPixelLine(color, min.x, min.y, (int)size.x);
        mSetPixelLine(color, min.x, max.y, (int)size.x);
        for (int y = min.y; y < max.y; y++) {
            mSetPixel(color, min.x, y);
            mSetPixel(color, max.x, y);
        }
    }
}

void BgRenderDevice::DrawCircle(BgUint32 color, const BgVector2 & pos, float radius) {
    for (BgUint32 i = 0; i < mUnitArc.GetSize(); i++) {
        float c = mUnitArc[i].x*radius;
        float s = mUnitArc[i].y*radius;
        BgUint32 x0 = (BgUint32)(pos.x - c);
        BgUint32 x1 = (BgUint32)(pos.x + c);
        BgUint32 y = (BgUint32)(pos.y + s);
        mSetPixel(color, x0, y);
        mSetPixel(color, x1, y);
    }
}

void BgRenderDevice::DrawFilledTriangle(BgUint32 color, const BgVector2 * verts) {
    BG_ASSERT(verts);
    BgIntVector2 sortedVerts[3] = { verts[0], verts[1], verts[2] };
    std::sort(sortedVerts, sortedVerts + 3, [](const BgIntVector2 &lhs, const BgIntVector2 &rhs) {
        return lhs.y < rhs.y;
    });
    int x1 = 0, x2 = 0, x3 = 0;
    if (sortedVerts[0].y == sortedVerts[2].y) { // отметаем частный случай, если высота = 0
        return;
    }

    int y2suby1 = sortedVerts[2].y - sortedVerts[1].y;
    if (sortedVerts[2].y == sortedVerts[1].y) {
        y2suby1 = 1;
    }
    int y1suby0 = sortedVerts[1].y - sortedVerts[0].y;
    if (sortedVerts[1].y == sortedVerts[0].y) {
        y1suby0 = 1;
    }

    for (int y = sortedVerts[0].y; y <= sortedVerts[2].y; y++) { // цикл отрисовки грани
                                                                 // получаем x-координату самой длинной стороны
        x1 = sortedVerts[0].x + (sortedVerts[2].x - sortedVerts[0].x) * (y - sortedVerts[0].y) / (sortedVerts[2].y - sortedVerts[0].y);
        if (y >= sortedVerts[1].y) { // выясняем, какую сторону проходит скан-линия и вычисляем ее x-координату
            x2 = sortedVerts[1].x + (sortedVerts[2].x - sortedVerts[1].x) * (y - sortedVerts[1].y) / y2suby1;
        }
        else {
            x2 = sortedVerts[0].x + (sortedVerts[1].x - sortedVerts[0].x) * (y - sortedVerts[0].y) / y1suby0;
        }
        if (x1 > x2) { // x1 - слева, x2 - cправа
            x3 = x1;
            x1 = x2;
            x2 = x3;
        }
        mSetPixelLine(color, x1, y, x2 - x1 + 1);
    }
}

void BgRenderDevice::DrawFilledRect(BgUint32 color, const BgVector2 & pos, const BgVector2 & size) {
    for (int y = pos.y; y < pos.y + size.y; y++) {
        mSetPixelLine(color, pos.x, y, size.x);
    }
}

void BgRenderDevice::DrawFilledCircle(BgUint32 color, const BgVector2 & pos, float radius) {
    for (BgUint32 i = 0; i < mUnitArc.GetSize(); i++) {
        float c = mUnitArc[i].x*radius, s = mUnitArc[i].y*radius;
        int x0 = (int)(pos.x - c);
        int x1 = (int)(pos.x + c);
        int y = (int)(pos.y + s);
        mSetPixelLine(color, x0, y, BgMath::Abs(x1 - x0));
    }
}

void BgRenderDevice::DrawTexturedTriangle(const BgTexture * texture, const BgVector2 * verts) {
    BG_ASSERT(texture);
    BG_ASSERT(verts);
    BgIntVector2 sortedVerts[3] = { verts[0], verts[1], verts[2] };
    std::sort(sortedVerts, sortedVerts + 3, [](const BgIntVector2 &lhs, const BgIntVector2 &rhs) {
        return lhs.y < rhs.y;
    });
    int x1 = 0, x2 = 0, x3 = 0;
    if (sortedVerts[0].y == sortedVerts[2].y) { // отметаем частный случай, если высота = 0
        return;
    }

    int y2suby1 = sortedVerts[2].y - sortedVerts[1].y;
    if (sortedVerts[2].y == sortedVerts[1].y) {
        y2suby1 = 1;
    }
    int y1suby0 = sortedVerts[1].y - sortedVerts[0].y;
    if (sortedVerts[1].y == sortedVerts[0].y) {
        y1suby0 = 1;
    }

    int minX = sortedVerts[0].x, maxX = sortedVerts[0].x;
    if (sortedVerts[0].x < minX) {
        minX = sortedVerts[0].x;
    }
    else if (sortedVerts[0].x > maxX) {
        maxX = sortedVerts[0].x;
    }
    if (sortedVerts[1].x < minX) {
        minX = sortedVerts[1].x;
    }
    else if (sortedVerts[1].x > maxX) {
        maxX = sortedVerts[1].x;
    }
    if (sortedVerts[2].x < minX) {
        minX = sortedVerts[2].x;
    }
    else if (sortedVerts[2].x > maxX) {
        maxX = sortedVerts[2].x;
    }

    for (int y = sortedVerts[0].y, v = 0; y <= sortedVerts[2].y; y++, v++) { // цикл отрисовки грани
                                                                             // получаем x-координату самой длинной стороны
        x1 = sortedVerts[0].x + (sortedVerts[2].x - sortedVerts[0].x) * (y - sortedVerts[0].y) / (sortedVerts[2].y - sortedVerts[0].y);
        if (y >= sortedVerts[1].y) { // выясняем, какую сторону проходит скан-линия и вычисляем ее x-координату
            x2 = sortedVerts[1].x + (sortedVerts[2].x - sortedVerts[1].x) * (y - sortedVerts[1].y) / y2suby1;
        }
        else {
            x2 = sortedVerts[0].x + (sortedVerts[1].x - sortedVerts[0].x) * (y - sortedVerts[0].y) / y1suby0;
        }
        if (x1 > x2) { // x1 - слева, x2 - cправа
            x3 = x1;
            x1 = x2;
            x2 = x3;
        }
        for (int x = minX, u = 0; x < maxX; x++, u++) {
            if (x >= x1 && x <= x2) {
                int tx = texture->GetSize().x*u / (maxX - minX);
                int ty = texture->GetSize().y*v / (sortedVerts[2].y - sortedVerts[0].y + 1);
                mSetPixel(texture->GetPixel(tx, ty), x, y);
            }
        }
    }
}

void BgRenderDevice::DrawTexturedRect(const BgTexture * texture, const BgVector2 & pos, const BgVector2 & size) {
    BG_ASSERT(texture);
    const BgIntVector2 min = pos;
    const BgIntVector2 max = pos + size;
    int i1 = max.y*(mSize.x-1) + max.x, i = min.y*mSize.x + min.x;
    int x = 0, y = 0;
    while (i < i1) {
        mSetPixel(texture->GetPixel(texture->GetSize().x*x / size.x, texture->GetSize().y*y / size.y), x + min.x, y + min.y);
        i++;
        x++;
        if (x == size.x) {
            x = 0;
            y++;
            i += min.x + mSize.x - max.x;
        }
    }
}

void BgRenderDevice::DrawTexturedCircle(const BgTexture * texture, const BgVector2 & pos, float radius) {
    for (BgUint32 i = 0; i < mUnitArc.GetSize(); i++) {
        float c = mUnitArc[i].x*radius;
        float s = mUnitArc[i].y*radius;
        int x0 = (int)(pos.x - c);
        int x1 = (int)(pos.x + c);
        int y = (int)(pos.y + s);
        int v = (int)(s + radius);
        for (int x = pos.x - radius, u = 0; x < pos.x + radius; x++, u++) {
            if (x >= x0 && x <= x1) {
                mSetPixel(texture->GetPixel(texture->GetSize().x*u / (2*radius), texture->GetSize().y*v / (2*radius)), x, y);
            }
        }
    }
}

void BgRenderDevice::mSetPixel(BgUint32 color, BgInt32 x, BgInt32 y) {
    if (x >= 0 && x < mSize.x && y >= 0 && y < mSize.y) {
        mSurfaceColor[y*mSize.x + x] = color;
    }
}

void BgRenderDevice::mSetPixelLine(BgUint32 color, BgInt32 x, BgInt32 y, BgUint32 count) {
    if (x >= 0 && y >= 0 && (x + (BgInt32)count) < mSize.x) {
        if (mTempLine[0] != color) {
            for (BgUint32 x = 0; x < mSize.x; x++) {
                mTempLine[x] = color;
            }
        }
        memcpy(&mSurfaceColor[y*mSize.x + x], mTempLine, sizeof(BgUint32)*count);
    }
}
