#include "BgString.h"
#include <cstring>

BgString::BgString() : mData(new char[1]) {
    mData[0] = '\0';
}

BgString::BgString(const char * str) {
    BG_ASSERT(str);
    mData = new char[strlen(str) + 1];
    strcpy(mData, str);
}

BgString::~BgString() {
    BG_DELETE_ARRAY(mData);
}

const char * BgString::GetData() const {
    return mData;
}

char * BgString::GetData() {
    return mData;
}

const BgUint32 BgString::GetLength() const {
    return strlen(mData);
}
