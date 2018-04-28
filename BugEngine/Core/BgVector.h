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

    const T &operator[](const BgUint32 idx) const {
        BG_ASSERT(idx < mSize);
        return mData[idx];
    }

    T &operator[](const BgUint32 idx) {
        BG_ASSERT(idx < mSize);
        return mData[idx];
    }

    void Append(const T &value) {
        if ((mSize + 1) > mCapacity) {
            Reserve((mCapacity + 1)*BG_MATH_SQRT2);
        }
        mData[mSize] = value;
        mSize++;
    }

    void Reserve(BgUint32 capacity) {
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

    BgUint32 GetSize() const {
        return mSize;
    }

    BgUint32 GetCapacity() const {
        return mCapacity;
    }

private:
    T *mData;
    BgUint32 mSize, mCapacity;
};

#endif