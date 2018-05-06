#ifndef BG_COMMON_H
#define BG_COMMON_H

#include <cstdlib>

#ifdef _DEBUG
#   define BG_DEBUG
#else
#   define BG_RELEASE
#endif

#if defined(_WIN32) || defined(_WIN64)
#   define BG_WINDOWS
#endif

#define BG_INLINE inline
#define BG_FORCEINLINE __forceinline
#define BG_STATIC_CLASS(className) \
private: \
    className() = delete; \
    className(const className&) = delete; \
    className(const className&&) = delete; \
    ~className() = delete;
#define BG_DELETE(obj) { delete (obj); (obj) = nullptr; }
#define BG_DELETE_ARRAY(obj) { delete[] (obj); (obj) = nullptr; }

#define BG_LOG_INFO(fmt, ...) do { BgDebugLog(BgLogType::Info, __FILE__, __LINE__, fmt, __VA_ARGS__); } while(0)
#define BG_LOG_WARN(fmt, ...) do { BgDebugLog(BgLogType::Warn, __FILE__, __LINE__, fmt, __VA_ARGS__); } while(0)
#define BG_LOG_ERROR(fmt, ...) do { BgDebugLog(BgLogType::Error, __FILE__, __LINE__, fmt, __VA_ARGS__); throw; } while(0)
#define BG_ASSERT(expr) do { if (expr) { } else { BgDebugLog(BgLogType::AssertionFailed, __FILE__, __LINE__, #expr); throw; } } while(0)

#define BG_FLAG_EXIST(flags, flag) (((flags) & (flag)) == (flag))

#define BG_MAP_RGBA(r, g, b, a) (((b) << 0) | ((g) << 8) | ((r) << 16) | ((a) << 24))
#define BG_MAP_RGB(r, g, b) (((b) << 0) | ((g) << 8) | ((r) << 16) | (255 << 24))

typedef signed char        BgInt8;
typedef short              BgInt16;
typedef int                BgInt32;
typedef long long          BgInt64;
typedef unsigned char      BgUint8;
typedef unsigned short     BgUint16;
typedef unsigned int       BgUint32;
typedef unsigned long long BgUint64;
typedef BgUint64 BgSize;

enum class BgLogType {
    Info,
    Warn,
    Error,
    AssertionFailed
};

void BgDebugLog(BgLogType type, const char *file, BgInt32 line, const char *fmt, ...);

class BgTimer {
    BG_STATIC_CLASS(BgTimer)

public:
    static BgUint64 Start();
    static double GetMs(BgUint64 startTime);
    static double GetSec(BgUint64 startTime);
};


#endif