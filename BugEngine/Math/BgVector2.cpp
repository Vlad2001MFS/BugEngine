#include "BgVector2.h"

BgVector2::BgVector2() 
    : x(0), y(0) {}

BgVector2::BgVector2(float x, float y) 
    : x(x), y(y) { }

float BgVector2::operator[](BgSize idx) const {
    BG_ASSERT(idx < 2);
    return (&this->x)[idx];
}

float & BgVector2::operator[](BgSize idx) {
    BG_ASSERT(idx < 2);
    return (&this->x)[idx];
}

BgVector2 BgVector2::operator-() const {
    return BgVector2(-this->x, -this->y);
}

float BgVector2::Length() const {
    return sqrtf(this->x*this->x + this->y*this->y);
}

float BgVector2::LengthSq() const {
    return this->x*this->x + this->y*this->y;
}

float BgVector2::Distance(const BgVector2 & target) const {
    return (target - (*this)).Length();
}

float BgVector2::DistanceSq(const BgVector2 & target) const {
    return (target - (*this)).LengthSq();
}

BgVector2 operator+(const BgVector2 & lhs, const BgVector2 & rhs) {
    return BgVector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

BgVector2 operator-(const BgVector2 & lhs, const BgVector2 & rhs) {
    return BgVector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

BgVector2 operator*(const BgVector2 & lhs, BgInt32 rhs) {
    return BgVector2(lhs.x*rhs, lhs.y*rhs);
}

BgVector2 operator*(const BgVector2 & lhs, float rhs) {
    return BgVector2(lhs.x*rhs, lhs.y*rhs);
}

BgVector2 operator/(const BgVector2 & lhs, BgInt32 rhs) {
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
