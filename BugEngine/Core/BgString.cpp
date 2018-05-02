#include "BgString.h"
#include <cstring>
#include <cstdarg>
#include <cstdio>

BgString::BgString() : mData(new char[1]), mSize(0), mCapacity(0) {
    mData[0] = '\0';
}

BgString::BgString(const char * str) {
    BG_ASSERT(str);
    mSize = mCapacity = strlen(str);
    mData = new char[mCapacity + 1];
    memset(mData, 0, mCapacity + 1);
    strcpy(mData, str);
}

BgString::BgString(BgSize size, char ch) {
    mSize = mCapacity = size;
    mData = new char[mCapacity + 1];
    memset(mData, 0, mCapacity + 1);
}

BgString::BgString(const BgString & str) {
    mSize = mCapacity = str.GetLength();
    mData = new char[mCapacity + 1];
    memset(mData, 0, mCapacity + 1);
    strcpy(mData, str.GetData());
}

BgString::~BgString() {
    BG_DELETE_ARRAY(mData);
    mSize = mCapacity = 0;
}

BgString & BgString::operator=(const BgString & rhs) {
    BG_DELETE_ARRAY(mData);
    mSize = mCapacity = rhs.GetLength();
    mData = new char[mCapacity + 1];
    memset(mData, 0, mCapacity + 1);
    strcpy(mData, rhs.GetData());
    return *this;
}

const char * BgString::GetData() const {
    return mData;
}

char * BgString::GetData() {
    return mData;
}

BgSize BgString::GetLength() const {
    return mSize;
}

BgSize BgString::GetCapacity() const {
    return mCapacity;
}

BgString BgString::Format(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
    BgString str(_vscprintf(fmt, args));
    vsprintf(str.GetData(), fmt, args);
    va_end(args);
    return str;
}
