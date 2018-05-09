#ifndef BG_RENDERDEVICE_H
#define BG_RENDERDEVICE_H

#include "../Core/BgArray.h"
#include "../Math/BgIntVector2.h"
#include "../Window/BgWindow.h"
#include "BgTexture.h"

class BgRenderDevice {
public:
    BgRenderDevice(const BgWindow *window);
    ~BgRenderDevice();

    void Clear(BgUint8 r, BgUint8 g, BgUint8 b, BgUint8 a);
    void DrawPoint(BgUint32 color, const BgIntVector2 &pos);
    void DrawLine(BgUint32 color, const BgIntVector2 &start, const BgIntVector2 &end);
    void DrawTriangle(BgUint32 color, const BgIntVector2 &v0, const BgIntVector2 &v1, const BgIntVector2 &v2);
    void DrawRect(BgUint32 color, const BgIntVector2 &pos, const BgIntVector2 &size);
    void DrawCircle(BgUint32 color, const BgIntVector2 &pos, BgUint32 radius);
    void DrawFilledTriangle(BgUint32 color, const BgIntVector2 &v0, const BgIntVector2 &v1, const BgIntVector2 &v2);
    void DrawFilledRect(BgUint32 color, const BgIntVector2 &pos, const BgIntVector2 &size);
    void DrawFilledCircle(BgUint32 color, const BgIntVector2 &pos, BgUint32 radius);
    void DrawTexturedTriangle(const BgTexture *texture, const BgIntVector2 &v0, const BgIntVector2 &v1, const BgIntVector2 &v2);
    void DrawTexturedRect(const BgTexture *texture, const BgIntVector2 &pos, const BgIntVector2 &size);
    void DrawTexturedCircle(const BgTexture *texture, const BgIntVector2 &pos, BgUint32 radius);

private:
    const BgWindow *mWindow;
    BgUint32 *mSurfaceColor;
    BgIntVector2 mSize;
    BgUint32 mSurfaceColorPitch;

    BgUint32 *mClearColorLine, *mTempLine;
};

#endif