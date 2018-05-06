#ifndef BG_ARRAY_H
#define BG_ARRAY_H

#include "BgCommon.h"
#include <initializer_list>

template<typename T, BgSize S>
class BgArray {
public:
    BgArray() { }
    BgArray(const std::initializer_list<T> &initList) {
        for (BgSize i = 0; i < mSize; i++) {
            mData[i] = initList[i];
        }
    }

    const T &operator[](BgSize idx) const {
        BG_ASSERT(idx < mSize);
        return mData[idx];
    }

    T &operator[](BgSize idx) {
        BG_ASSERT(idx < mSize);
        return mData[idx];
    }

    const T *GetData() const {
        return mData;
    }

    T *GetData() {
        return mData;
    }

    BgSize GetSize() const {
        return mSize;
    }

private:
    T mData[S];
    const BgSize mSize = S;
};

#endif