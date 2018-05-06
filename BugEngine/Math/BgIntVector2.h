#ifndef BG_INTVECTOR2_H
#define BG_INTVECTOR2_H

#include "../Core/BgCommon.h"
#include "BgVector2.h"

struct BgIntVector2 {
    BgIntVector2();
    BgIntVector2(BgInt32 x, BgInt32 y);
    BgIntVector2(const BgVector2 &v);

    BgIntVector2 &operator=(const BgVector2 &rhs);
    BgInt32 operator[](BgSize idx) const;
    BgInt32 &operator[](BgSize idx);
    BgIntVector2 operator-() const;
    friend BgIntVector2 operator+(const BgIntVector2 &lhs,  const BgIntVector2 &rhs);
    friend BgIntVector2 operator-(const BgIntVector2 &lhs, const BgIntVector2 &rhs);
    friend BgIntVector2 operator*(const BgIntVector2 &lhs, BgInt32 rhs);
    friend BgIntVector2 operator/(const BgIntVector2 &lhs, BgInt32 rhs);
    friend BgIntVector2 operator+=(BgIntVector2 &lhs, const BgIntVector2 &rhs);
    friend BgIntVector2 operator-=(BgIntVector2 &lhs, const BgIntVector2 &rhs);
    friend BgIntVector2 operator*=(BgIntVector2 &lhs, BgInt32 rhs);
    friend BgIntVector2 operator/=(BgIntVector2 &lhs, BgInt32 rhs);

    BgInt32 x, y;
};

#endif