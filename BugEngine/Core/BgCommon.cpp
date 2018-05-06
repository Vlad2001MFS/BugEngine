#include "BgCommon.h"
#include <SDL2/SDL.h>
#include <cstdarg>
#include <cstdio>

void BgDebugLog(BgLogType type, const char * file, BgInt32 line, const char * fmt, ...) {
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

void InitTimer() {
    static bool first = true;
    if (first) {
        first = false;
        SDL_Init(SDL_INIT_TIMER);
    }
}

BgUint64 BgTimer::Start() {
    InitTimer();
    return SDL_GetPerformanceCounter();
}

double BgTimer::GetMs(BgUint64 startTime) {
    InitTimer();
    return static_cast<double>(SDL_GetPerformanceCounter() - startTime) / SDL_GetPerformanceFrequency() * 1000.0f;
}

double BgTimer::GetSec(BgUint64 startTime) {
    InitTimer();
    return static_cast<double>(SDL_GetPerformanceCounter() - startTime) / SDL_GetPerformanceFrequency();
}
