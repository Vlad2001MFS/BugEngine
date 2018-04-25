#ifndef BG_STRING_H
#define BG_STRING_H

#include "BgCommon.h"

class BgString {
public:
    BgString();
    BgString(const char *str);
    ~BgString();

    const char *GetData() const;
    char *GetData();
    const BgUint32 GetLength() const;

private:
    char *mData;
};

#endif