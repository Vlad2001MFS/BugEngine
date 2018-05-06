#ifndef BG_VECTOR_H
#define BG_VECTOR_H

#include "BgCommon.h"
#include "../Math/BgMath.h"
#include <cstring>

template<typename T>
class BgVector {
public:
    BgVector() : mData(nullptr), mSize(0), mCapacity(0) { }
    ~BgVector() {
        BG_DELETE_ARRAY(mData);
    }

    const T &operator[](const BgSize idx) const {
        BG_ASSERT(idx < mSize);
        return mData[idx];
    }

    T &operator[](const BgSize idx) {
        BG_ASSERT(idx < mSize);
        return mData[idx];
    }

    void Append(const T &value) {
        if ((mSize + 1) > mCapacity) {
            Reserve(static_cast<BgSize>((mCapacity + 1)*BG_MATH_SQRT2));
        }
        mData[mSize] = value;
        mSize++;
    }

    void Reserve(BgSize capacity) {
        if (capacity > mCapacity) {
            T *data = new T[capacity];
            if (mData) {
                memcpy(data, mData, sizeof(T)*mSize);
                BG_DELETE_ARRAY(mData);
            }
            mData = data;
            mCapacity = capacity;
        }
    }

    BgSize GetSize() const {
        return mSize;
    }

    BgSize GetCapacity() const {
        return mCapacity;
    }

private:
    T *mData;
    BgSize mSize, mCapacity;
};

#endif