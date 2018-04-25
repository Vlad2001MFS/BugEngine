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
#define BG_LOG_ERROR(fmt, ...) do { BgDebugLog(BgLogType::Error, __FILE__, __LINE__, fmt, __VA_ARGS__); abort(); } while(0)
#define BG_ASSERT(expr) do { if (expr) { } else { BgDebugLog(BgLogType::AssertionFailed, __FILE__, __LINE__, #expr); abort(); } } while(0)

typedef signed char        BgInt8;
typedef short              BgInt16;
typedef int                BgInt32;
typedef long long          BgInt64;
typedef unsigned char      BgUint8;
typedef unsigned short     BgUint16;
typedef unsigned int       BgUint32;
typedef unsigned long long BgUint64;

class BgException {
public:
    BgException(const char *fmt, ...);
    ~BgException();

    const char *GetMessage() const;

private:
    char *mMessage;
};

enum class BgLogType {
    Info,
    Warn,
    Error,
    AssertionFailed
};

void BgDebugLog(BgLogType type, const char *file, int line, const char *fmt, ...);

#endif