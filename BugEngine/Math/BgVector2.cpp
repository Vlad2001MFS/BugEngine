#include "BgVector2.h"

BgVector2::BgVector2() 
    : x(0), y(0) {}

BgVector2::BgVector2(float x, float y) 
    : x(x), y(y) { }

float BgVector2::operator[](BgUint32 idx) const {
    BG_ASSERT(idx < 2);
    return (&this->x)[idx];
}

float & BgVector2::operator[](BgUint32 idx) {
    BG_ASSERT(idx < 2);
    return (&this->x)[idx];
}

BgVector2 BgVector2::operator-() const {
    return BgVector2(-this->x, -this->y);
}

BgVector2 operator+(const BgVector2 & lhs, const BgVector2 & rhs) {
    return BgVector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

BgVector2 operator-(const BgVector2 & lhs, const BgVector2 & rhs) {
    return BgVector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

BgVector2 operator*(const BgVector2 & lhs, int rhs) {
    return BgVector2(lhs.x*rhs, lhs.y*rhs);
}

BgVector2 operator*(const BgVector2 & lhs, float rhs) {
    return BgVector2(lhs.x*rhs, lhs.y*rhs);
}

BgVector2 operator/(const BgVector2 & lhs, int rhs) {
    BG_ASSERT(rhs);
    return BgVector2(lhs.x / rhs, lhs.y / rhs);
}

BgVector2 operator/(const BgVector2 & lhs, float rhs) {
    BG_ASSERT(rhs);
    return BgVector2(lhs.x / rhs, lhs.y / rhs);
}

BgVector2 operator+=(BgVector2 & lhs, const BgVector2 & rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

BgVector2 operator-=(BgVector2 & lhs, const BgVector2 & rhs) {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

BgVector2 operator*=(BgVector2 & lhs, float rhs) {
    lhs.x *= rhs;
    lhs.y *= rhs;
    return lhs;
}

BgVector2 operator/=(BgVector2 & lhs, float rhs) {
    BG_ASSERT(rhs);
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}
