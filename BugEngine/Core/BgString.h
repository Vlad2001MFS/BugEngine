#ifndef BG_STRING_H
#define BG_STRING_H

#include "BgCommon.h"

class BgString {
public:
    BgString();
    BgString(const char *str);
    BgString(BgSize size, char ch = '\0');
    BgString(const BgString &str);
    ~BgString();

    BgString &operator=(const BgString &rhs);

    const char *GetData() const;
    char *GetData();
    BgSize GetLength() const;
    BgSize GetCapacity() const;

    static BgString Format(const char *fmt, ...);

private:
    char *mData;
    BgSize mSize, mCapacity;
};

#endif