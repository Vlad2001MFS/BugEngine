#include "BgCommon.h"
#include <cstdarg>
#include <cstdio>

BgException::BgException(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
    mMessage = new char[_vscprintf(fmt, args) + 1];
    vsprintf(mMessage, fmt, args);
    va_end(args);
}

BgException::~BgException() {
    BG_DELETE_ARRAY(mMessage);
}

const char * BgException::GetMessage() const {
    return mMessage;
}

void BgDebugLog(BgLogType type, const char * file, int line, const char * fmt, ...) {
    static FILE *logFile = nullptr;
    static const char logFilename[] = "BugEngine.log";
    static bool first = true;
    if (first) {
        first = false;
        logFile = fopen(logFilename, "w");
        atexit([]() { fclose(logFile); });
    }

    switch (type) {
        case BgLogType::Info:
            fprintf(logFile, "Type: Info\n");
            fprintf(stdout, "Type: Info\n");
            break;
        case BgLogType::Warn:
            fprintf(logFile, "Type: Warning\n");
            fprintf(stdout, "Type: Warning\n");
            break;
        case BgLogType::Error:
            fprintf(logFile, "Type: Error\n");
            fprintf(stdout, "Type: Error\n");
            break;
        case BgLogType::AssertionFailed:
            fprintf(logFile, "Type: Assertion failed\n");
            fprintf(stdout, "Type: Assertion failed\n");
            break;
    };
    fprintf(logFile, "File: %s\nLine: %d\n", file, line);
    fprintf(stdout, "File: %s\nLine: %d\n", file, line);
    va_list args;
    va_start(args, fmt);
    if (type == BgLogType::AssertionFailed) {
        fprintf(logFile, "Expression: %s\n\n", fmt);
        fprintf(stdout, "Expression: %s\n\n", fmt);
    }
    else {
        fprintf(logFile, "Desciption: ");
        vfprintf(logFile, fmt, args);
        fprintf(logFile, "\n\n");
        fprintf(stdout, "Desciption: ");
        vfprintf(stdout, fmt, args);
        fprintf(stdout, "\n\n");
    }
    va_end(args);
    fflush(logFile);
}
