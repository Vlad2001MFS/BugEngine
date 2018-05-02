#ifndef BG_INTVECTOR2_H
#define BG_INTVECTOR2_H

#include "../Core/BgCommon.h"
#include "BgVector2.h"

struct BgIntVector2 {
    BgIntVector2();
    BgIntVector2(int x, int y);
    BgIntVector2(const BgVector2 &v);

    BgIntVector2 &operator=(const BgVector2 &rhs);
    int operator[](BgUint32 idx) const;
    int &operator[](BgUint32 idx);
    BgIntVector2 operator-() const;
    friend BgIntVector2 operator+(const BgIntVector2 &lhs,  const BgIntVector2 &rhs);
    friend BgIntVector2 operator-(const BgIntVector2 &lhs, const BgIntVector2 &rhs);
    friend BgIntVector2 operator*(const BgIntVector2 &lhs, int rhs);
    friend BgIntVector2 operator/(const BgIntVector2 &lhs, int rhs);
    friend BgIntVector2 operator+=(BgIntVector2 &lhs, const BgIntVector2 &rhs);
    friend BgIntVector2 operator-=(BgIntVector2 &lhs, const BgIntVector2 &rhs);
    friend BgIntVector2 operator*=(BgIntVector2 &lhs, int rhs);
    friend BgIntVector2 operator/=(BgIntVector2 &lhs, int rhs);

    int x, y;
};

#endif