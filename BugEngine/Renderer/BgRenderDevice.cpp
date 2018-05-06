#include "BgRenderDevice.h"
#include "../Math/BgMath.h"
#include <cstring>
#include <algorithm>
#include <string>

#define _SET_PIXEL(mcolor, mx, my) do { \
    if (mx >= 0 && mx < mSize.x && my >= 0 && my < mSize.y) { \
        mSurfaceColor[my*mSize.x + mx] = mcolor; \
    } \
} while(false)

#define _SET_PIXEL_LINE(mcolor, mx, my, mcount) do { \
    if (my >= 0 && my < mSize.y && mx + mcount >= 0 && mx < mSize.x) { \
        BgUint32 len = mcount; \
        if (mx < 0) { \
            len = mx + mcount; \
        } \
        else if ((mx + mcount - 1) >= mSize.x) { \
            len = BgMath::Abs(mx - mSize.x); \
        } \
        if (mTempLine[0] != mcolor || mTempLine[len - 1] != mcolor) { \
            if (mcolor <= INT_MAX) { \
                memset(mTempLine, mcolor, mSize.x); \
            } \
            else { \
                for (BgUint32 i = 0; i < len; i++) { \
                    mTempLine[i] = mcolor; \
                } \
            } \
        } \
        memcpy(&mSurfaceColor[my*mSize.x + BgMath::Max(0, mx)], mTempLine, sizeof(BgUint32)*len); \
    } \
} while(false)

#define SET_PIXEL(mcolor, mx, my) _SET_PIXEL(static_cast<BgUint32>(mcolor), static_cast<int>(mx), static_cast<int>(my))
#define SET_PIXEL_LINE(mcolor, mx, my, mcount) _SET_PIXEL_LINE(static_cast<BgUint32>(mcolor), static_cast<BgInt32>(mx), static_cast<BgInt32>(my), static_cast<BgInt32>(mcount))

BgRenderDevice::BgRenderDevice(const BgWindow * window) : mWindow(window) {
    BG_ASSERT(window);
    mSurfaceColor = window->GetSurface();
    mSize = window->GetSize();
    mSurfaceColorPitch = sizeof(BgUint32)*mSize.x;

    mClearColorLine = new BgUint32[mSize.x];
    memset(mClearColorLine, 0, mSurfaceColorPitch);
    mTempLine = new BgUint32[mSize.x];
    memset(mTempLine, 0, mSurfaceColorPitch);
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

void BgRenderDevice::DrawPoint(BgUint32 color, const BgIntVector2 & pos) {
    SET_PIXEL(color, pos.x, pos.y);
}

void BgRenderDevice::DrawLine(BgUint32 color, const BgIntVector2 & start, const BgIntVector2 & end) {
    int x0 = start.x, y0 = start.y;
    int x1 = end.x, y1 = end.y;
    if (x0 == x1) {
        int dirY = BgMath::Clamp(y1 - y0, -1, 1);
        for (int y = y0; y != y1; y += dirY) {
            SET_PIXEL(color, x0, y);
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
            SET_PIXEL(color, x, y);
        }
    }
}

void BgRenderDevice::DrawTriangle(BgUint32 color, const BgIntVector2 & v0, const BgIntVector2 & v1, const BgIntVector2 & v2) {
    DrawLine(color, v0, v1);
    DrawLine(color, v1, v2);
    DrawLine(color, v2, v0);
}

void BgRenderDevice::DrawRect(BgUint32 color, const BgIntVector2 & pos, const BgIntVector2 & size) {
    BgIntVector2 min = pos;
    BgIntVector2 max = pos + size;
    if (min.x >= 0 && min.y >= 0 && max.x < mSize.x && max.y < mSize.y) {
        SET_PIXEL_LINE(color, min.x, min.y, size.x);
        SET_PIXEL_LINE(color, min.x, max.y, size.x);
        for (int y = min.y; y < max.y; y++) {
            SET_PIXEL(color, min.x, y);
            SET_PIXEL(color, max.x, y);
        }
    }
}

void BgRenderDevice::DrawCircle(BgUint32 color, const BgIntVector2 & pos, BgUint32 radius) {
    int rSq = BgMath::Sq(radius);
    for (BgUint32 xy = 0; xy < radius; xy++) {
        int nxy = static_cast<int>(BgMath::Round(BgMath::Sqrt(static_cast<float>(rSq - BgMath::Sq(xy)))));

        SET_PIXEL(color, pos.x + xy, pos.y + nxy); // I
        SET_PIXEL(color, pos.x + nxy, pos.y + xy); // I
        SET_PIXEL(color, pos.x - xy, pos.y + nxy); // II
        SET_PIXEL(color, pos.x - nxy, pos.y + xy); // II
        SET_PIXEL(color, pos.x - xy, pos.y - nxy); // III
        SET_PIXEL(color, pos.x - nxy, pos.y - xy); // III
        SET_PIXEL(color, pos.x + xy, pos.y - nxy); // IV
        SET_PIXEL(color, pos.x + nxy, pos.y - xy); // IV
    }
}

void BgRenderDevice::DrawFilledTriangle(BgUint32 color, const BgIntVector2 & v0, const BgIntVector2 & v1, const BgIntVector2 & v2) {
    BgIntVector2 sortedVerts[3] = { v0, v1, v2 };
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
        SET_PIXEL_LINE(color, x1, y, x2 - x1 + 1);
    }
}

void BgRenderDevice::DrawFilledRect(BgUint32 color, const BgIntVector2 & pos, const BgIntVector2 & size) {
    for (int y = pos.y; y < pos.y + size.y; y++) {
        SET_PIXEL_LINE(color, pos.x, y, size.x);
    }
}

void BgRenderDevice::DrawFilledCircle(BgUint32 color, const BgIntVector2 & pos, BgUint32 radius) {
    int rSq = BgMath::Sq(radius);
    for (BgUint32 xy = 0; xy < radius; xy++) {
        int nxy = static_cast<int>(BgMath::Round(BgMath::Sqrt(static_cast<float>(rSq - BgMath::Sq(xy)))));
        SET_PIXEL_LINE(color, pos.x - nxy, pos.y - xy, nxy*2);
        SET_PIXEL_LINE(color, pos.x - nxy, pos.y + xy, nxy*2);
    }
}

void BgRenderDevice::DrawTexturedTriangle(const BgTexture * texture, const BgIntVector2 & v0, const BgIntVector2 & v1, const BgIntVector2 & v2) {
    BG_ASSERT(texture);
    BgIntVector2 sortedVerts[3] = { v0, v1, v2 };
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

    const BgUint32 *td = texture->GetData();
    const BgIntVector2 &ts = texture->GetSize();
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
                int tx = ts.x*u / (maxX - minX);
                int ty = ts.y*v / (sortedVerts[2].y - sortedVerts[0].y + 1);
                SET_PIXEL(td[(ty)*ts.x + (tx)], x, y);
            }
        }
    }
}

void BgRenderDevice::DrawTexturedRect(const BgTexture * texture, const BgIntVector2 & pos, const BgIntVector2 & size) {
    BG_ASSERT(texture);
    const BgIntVector2 min = pos;
    const BgIntVector2 max = pos + size;
    const BgUint32 *td = texture->GetData();
    const BgIntVector2 &ts = texture->GetSize();
    for (int y = min.y, v = 0; y < max.y; y++, v++) {
        for (int x = min.x, u = 0; x < max.x; x++, u++) {
            int tx = ts.x*u / size.x;
            int ty = ts.y*v / size.y;
            SET_PIXEL(td[(ty)*ts.x + (tx)], x, y);
        }
    }
}

void BgRenderDevice::DrawTexturedCircle(const BgTexture * texture, const BgIntVector2 & pos, BgUint32 radius) {
    BG_ASSERT(texture);
    int rSq = BgMath::Sq(radius);
    int r = radius;
    int d = radius*2;
    const BgUint32 *td = texture->GetData();
    const BgIntVector2 &ts = texture->GetSize();
    for (int xy = -r; xy < r; xy++) {
        int nxy = static_cast<int>(BgMath::Round(BgMath::Sqrt(static_cast<float>(rSq - BgMath::Sq(xy)))));
        for (int x = -nxy; x < nxy; x++) {
            int tx = ts.x*(x+nxy+(r-nxy)) / d;
            int ty = ts.y*(xy+r) / d;
            SET_PIXEL(td[(ty)*ts.x + (tx)], pos.x + x, pos.y + xy);
        }
    }
}