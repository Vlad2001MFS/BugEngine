#include "BgTexture.h"
#include "../Math/BgMath.h"
#include <SDL2/SDL.h>

BgTexture::BgTexture(const BgString & filename) {
    SDL_Surface *surface = SDL_LoadBMP(filename.GetData());
    BG_ASSERT(surface);
    BG_ASSERT(surface->format->format == SDL_PIXELFORMAT_BGR24);
    mSize.x = surface->w;
    mSize.y = surface->h;
    mData = new BgUint32[mSize.x*mSize.y];
    typedef BgUint8 SRCColor[3];
    SRCColor *src = static_cast<SRCColor*>(surface->pixels);
    BgUint32 *dst = mData;
    for (int i = 0; i < mSize.x*mSize.y; i++) {
        dst[i] = BG_MAP_RGBA(src[i][2], src[i][1], src[i][0], 255);
    }
    SDL_FreeSurface(surface);
}

BgTexture::~BgTexture() {
    BG_DELETE_ARRAY(mData);
}

BgUint32 BgTexture::GetPixel(BgUint32 x, BgUint32 y) const {
    BG_ASSERT(x < static_cast<BgUint32>(mSize.x));
    BG_ASSERT(y < static_cast<BgUint32>(mSize.y));
    return mData[y*mSize.x + x];
}

const BgUint32 * BgTexture::GetData() const {
    return mData;
}

const BgIntVector2 & BgTexture::GetSize() const {
    return mSize;
}
