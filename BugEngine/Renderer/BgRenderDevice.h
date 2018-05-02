#ifndef BG_RENDERDEVICE_H
#define BG_RENDERDEVICE_H

#include "../Core/BgArray.h"
#include "../Math/BgVector2.h"
#include "../Window/BgWindow.h"
#include "BgTexture.h"

class BgRenderDevice {
public:
    BgRenderDevice(const BgWindow *window);
    ~BgRenderDevice();

    void ClearColor(BgUint8 r, BgUint8 g, BgUint8 b, BgUint8 a);
    void DrawPoint(BgUint32 color, const BgVector2 &pos);
    void DrawLine(BgUint32 color, const BgVector2 &start, const BgVector2 &end);
    void DrawTriangle(BgUint32 color, const BgVector2 *verts);
    void DrawRect(BgUint32 color, const BgVector2 &pos, const BgVector2 &size);
    void DrawCircle(BgUint32 color, const BgVector2 &pos, float radius);
    void DrawFilledTriangle(BgUint32 color, const BgVector2 *verts);
    void DrawFilledRect(BgUint32 color, const BgVector2 &pos, const BgVector2 &size);
    void DrawFilledCircle(BgUint32 color, const BgVector2 &pos, float radius);
    void DrawTexturedTriangle(const BgTexture *texture, const BgVector2 *verts);
    void DrawTexturedRect(const BgTexture *texture, const BgVector2 &pos, const BgVector2 &size);
    void DrawTexturedCircle(const BgTexture *texture, const BgVector2 &pos, float radius);

private:
    void mSetPixel(BgUint32 color, BgInt32 x, BgInt32 y);
    void mSetPixelLine(BgUint32 color, BgInt32 x, BgInt32 y, BgUint32 count);

    const BgWindow *mWindow;
    BgUint32 *mSurfaceColor;
    BgIntVector2 mSize;
    BgUint32 mSurfaceColorPitch;
    BgArray<BgVector2, 256> mUnitArc;

    BgUint32 *mClearColorLine, *mTempLine;
};

#endif