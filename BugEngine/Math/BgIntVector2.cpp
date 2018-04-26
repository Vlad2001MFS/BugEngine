#include "BgIntVector2.h"

BgIntVector2::BgIntVector2() 
    : x(0), y(0) {}

BgIntVector2::BgIntVector2(int x, int y) 
    : x(x), y(y) { }

int BgIntVector2::operator[](BgUint32 idx) const {
    BG_ASSERT(idx < 2);
    return (&this->x)[idx];
}

int & BgIntVector2::operator[](BgUint32 idx) {
    BG_ASSERT(idx < 2);
    return (&this->x)[idx];
}

BgIntVector2 BgIntVector2::operator-() const {
    return BgIntVector2(-this->x, -this->y);
}

BgIntVector2 operator+(const BgIntVector2 & lhs, const BgIntVector2 & rhs) {
    return BgIntVector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

BgIntVector2 operator-(const BgIntVector2 & lhs, const BgIntVector2 & rhs) {
    return BgIntVector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

BgIntVector2 operator*(int lhs, const BgIntVector2 & rhs) {
    return BgIntVector2(lhs*rhs.x, lhs*rhs.y);
}

BgIntVector2 operator*(const BgIntVector2 & lhs, int rhs) {
    return BgIntVector2(lhs.x*rhs, lhs.y*rhs);
}

BgIntVector2 operator/(const BgIntVector2 & lhs, int rhs) {
    BG_ASSERT(rhs);
    return BgIntVector2(lhs.x / rhs, lhs.y / rhs);
}

BgIntVector2 operator+=(BgIntVector2 & lhs, const BgIntVector2 & rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

BgIntVector2 operator-=(BgIntVector2 & lhs, const BgIntVector2 & rhs) {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

BgIntVector2 operator*=(BgIntVector2 & lhs, int rhs) {
    lhs.x *= rhs;
    lhs.y *= rhs;
    return lhs;
}

BgIntVector2 operator/=(BgIntVector2 & lhs, int rhs) {
    BG_ASSERT(rhs);
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}
