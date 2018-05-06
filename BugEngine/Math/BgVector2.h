#ifndef BG_VECTOR2_H
#define BG_VECTOR2_H

#include "../Core/BgCommon.h"

struct BgVector2 {
    BgVector2();
    BgVector2(float x, float y);

    float operator[](BgSize idx) const;
    float &operator[](BgSize idx);
    BgVector2 operator-() const;
    friend BgVector2 operator+(const BgVector2 &lhs,  const BgVector2 &rhs);
    friend BgVector2 operator-(const BgVector2 &lhs, const BgVector2 &rhs);
    friend BgVector2 operator*(const BgVector2 &lhs, BgInt32 rhs);
    friend BgVector2 operator*(const BgVector2 &lhs, float rhs);
    friend BgVector2 operator/(const BgVector2 &lhs, BgInt32 rhs);
    friend BgVector2 operator/(const BgVector2 &lhs, float rhs);
    friend BgVector2 operator+=(BgVector2 &lhs, const BgVector2 &rhs);
    friend BgVector2 operator-=(BgVector2 &lhs, const BgVector2 &rhs);
    friend BgVector2 operator*=(BgVector2 &lhs, float rhs);
    friend BgVector2 operator/=(BgVector2 &lhs, float rhs);

    float Length() const;
    float LengthSq() const;
    float Distance(const BgVector2 &target) const;
    float DistanceSq(const BgVector2 &target) const;

    float x, y;
};

#endif