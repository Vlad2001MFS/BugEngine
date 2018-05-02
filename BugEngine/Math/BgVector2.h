#ifndef BG_VECTOR2_H
#define BG_VECTOR2_H

#include "../Core/BgCommon.h"

struct BgVector2 {
    BgVector2();
    BgVector2(float x, float y);

    float operator[](BgUint32 idx) const;
    float &operator[](BgUint32 idx);
    BgVector2 operator-() const;
    friend BgVector2 operator+(const BgVector2 &lhs,  const BgVector2 &rhs);
    friend BgVector2 operator-(const BgVector2 &lhs, const BgVector2 &rhs);
    friend BgVector2 operator*(const BgVector2 &lhs, int rhs);
    friend BgVector2 operator*(const BgVector2 &lhs, float rhs);
    friend BgVector2 operator/(const BgVector2 &lhs, int rhs);
    friend BgVector2 operator/(const BgVector2 &lhs, float rhs);
    friend BgVector2 operator+=(BgVector2 &lhs, const BgVector2 &rhs);
    friend BgVector2 operator-=(BgVector2 &lhs, const BgVector2 &rhs);
    friend BgVector2 operator*=(BgVector2 &lhs, float rhs);
    friend BgVector2 operator/=(BgVector2 &lhs, float rhs);

    float x, y;
};

#endif