#ifndef BG_TEXTURE_H
#define BG_TEXTURE_H

#include "../Core/BgCommon.h"
#include "../Core/BgString.h"
#include "../Math/BgIntVector2.h"

class BgTexture {
public:
    BgTexture(const BgString &filename);
    ~BgTexture();

    BgUint32 GetPixel(BgUint32 x, BgUint32 y) const;
    const BgUint32 *GetData() const;
    const BgIntVector2 &GetSize() const;

private:
    BgUint32 *mData;
    BgIntVector2 mSize;
};

#endif