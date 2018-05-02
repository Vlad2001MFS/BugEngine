#ifndef BG_ARRAY_H
#define BG_ARRAY_H

#include "BgCommon.h"
#include <initializer_list>

template<typename T, BgUint32 S>
class BgArray {
public:
    BgArray() { }
    BgArray(const std::initializer_list<T> &initList) {
        for (BgUint32 i = 0; i < mSize; i++) {
            mData[i] = initList[i];
        }
    }

    const T &operator[](BgUint32 idx) const {
        BG_ASSERT(idx < mSize);
        return mData[idx];
    }

    T &operator[](BgUint32 idx) {
        BG_ASSERT(idx < mSize);
        return mData[idx];
    }

    const T *GetData() const {
        return mData;
    }

    T *GetData() {
        return mData;
    }

    BgUint32 GetSize() const {
        return mSize;
    }

private:
    T mData[S];
    const BgUint32 mSize = S;
};

#endif