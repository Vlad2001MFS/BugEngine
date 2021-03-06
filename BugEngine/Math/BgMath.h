﻿#ifndef BG_MATH_H
#define BG_MATH_H

#include "../Core/BgCommon.h"
#include <math.h>

constexpr float BG_MATH_E           = 2.71828182845904523536f;   // e
constexpr float BG_MATH_LOG2E       = 1.44269504088896340736f;   // log2(e)
constexpr float BG_MATH_LOG10E      = 0.434294481903251827651f;  // log10(e)
constexpr float BG_MATH_LN2         = 0.693147180559945309417f;  // ln(2)
constexpr float BG_MATH_LN10        = 2.30258509299404568402f;   // ln(10)
constexpr float BG_MATH_PI          = 3.14159265358979323846f;   // pi
constexpr float BG_MATH_PI_2        = 1.57079632679489661923f;   // pi/2
constexpr float BG_MATH_PI_4        = 0.785398163397448309616f;  // pi/4
constexpr float BG_MATH_1_PI        = 0.318309886183790671538f;  // 1/pi
constexpr float BG_MATH_2_PI        = 0.636619772367581343076f;  // 2/pi
constexpr float BG_MATH_2_SQRTPI    = 1.12837916709551257390f;   // 2/sqrt(pi)
constexpr float BG_MATH_SQRT2       = 1.41421356237309504880f;   // sqrt(2)
constexpr float BG_MATH_SQRT1_2     = 0.707106781186547524401f;  // 1/sqrt(2)

class BgMath {
    BG_STATIC_CLASS(BgMath)

public:
    template<typename T> BG_FORCEINLINE static T Min(T a, T b) {
        return a < b ? a : b;
    }

    template<typename T> BG_FORCEINLINE static T Max(T a, T b) {
        return a > b ? a : b;
    }

    template<typename T> BG_FORCEINLINE static T Clamp(T value, T min, T max) {
        return Min(Max(min, value), max);
    }

    template<typename T> BG_FORCEINLINE static T Abs(T value) {
        return value < 0 ? -value : value;
    }

    template<typename T> BG_FORCEINLINE static T Lerp(T v0, T v1, T t) {
        return v0*(1 - t) + v1*t;
    }

    template<typename T> BG_FORCEINLINE static T Sq(T value) {
        return value*value;
    }

    template<typename T> BG_FORCEINLINE static float ToRadians(T degrees) {
        static constexpr float a = 1 / 180*BG_MATH_PI;
        return degrees*a;
    }

    template<typename T> BG_FORCEINLINE static T ToDegrees(T radians) {
        static constexpr float a = 180 / BG_MATH_PI;
        return radians*a;
    }

    BG_FORCEINLINE static float Sin(float radians) {
        return sinf(radians);
    }

    BG_FORCEINLINE static float Cos(float radians) {
        return cosf(radians);
    }

    BG_FORCEINLINE static float Floor(float value) {
        return floorf(value);
    }

    BG_FORCEINLINE static float Ceil(float value) {
        return ceilf(value);
    }

    BG_FORCEINLINE static float Round(float value) {
        return roundf(value);
    }

    BG_FORCEINLINE static float Sqrt(float value) {
        return sqrtf(value);
    }
};

#endif