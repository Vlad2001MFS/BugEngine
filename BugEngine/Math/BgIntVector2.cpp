#include "BgIntVector2.h"

BgIntVector2::BgIntVector2() 
    : x(0), y(0) {}

BgIntVector2::BgIntVector2(BgInt32 x, BgInt32 y)
    : x(x), y(y) { }

BgIntVector2::BgIntVector2(const BgVector2 & v)
    : x(static_cast<BgInt32>(v.x)), y(static_cast<BgInt32>(v.y)) { }

BgIntVector2 & BgIntVector2::operator=(const BgVector2 & rhs) {
    this->x = static_cast<BgInt32>(rhs.x);
    this->y = static_cast<BgInt32>(rhs.y);
    return *this;
}

int BgIntVector2::operator[](BgSize idx) const {
    BG_ASSERT(idx < 2);
    return (&this->x)[idx];
}

int & BgIntVector2::operator[](BgSize idx) {
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

BgIntVector2 operator*(const BgIntVector2 & lhs, BgInt32 rhs) {
    return BgIntVector2(lhs.x*rhs, lhs.y*rhs);
}

BgIntVector2 operator/(const BgIntVector2 & lhs, BgInt32 rhs) {
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

BgIntVector2 operator*=(BgIntVector2 & lhs, BgInt32 rhs) {
    lhs.x *= rhs;
    lhs.y *= rhs;
    return lhs;
}

BgIntVector2 operator/=(BgIntVector2 & lhs, BgInt32 rhs) {
    BG_ASSERT(rhs);
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}
