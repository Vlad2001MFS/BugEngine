#ifndef BG_EVENT_H
#define BG_EVENT_H

#include "../Core/BgCommon.h"

enum class BgEventType {
    Close,
    Resize,
    LostFocus,
    GetFocus,
    KeyDown,
    KeyUp,
    MouseWheel,
    MouseButtonDown,
    MouseButtonUp,
    MouseMove
};

enum class BgMouseButton {
    Left,
    Right,
    Middle,
    X1,
    X2
};

enum class BgKeyCode {
    Unknown,
    A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
    Return, Escape, BackSpace, Tab, Space,
    F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
    Pause, Insert, Home, PageUp, PageDown, Delete, End, Left, Right, Up, Down,
    Numpad0, Numpad1, Numpad2, Numpad3, Numpad4, Numpad5, Numpad6, Numpad7, Numpad8, Numpad9,
    LControl, RControl, LShift, RShift, LAlt, RAlt, LSystem, RSystem
};

struct BgEvent {
    BgEventType type;
    union {
        struct {
            BgUint32 width;
            BgUint32 height;
        } resize;
        struct {
            BgKeyCode code;
            bool alt;
            bool control;
            bool shift;
            bool system;
        } key;
        struct {
            int direction;
            int x;
            int y;
            bool control;
            bool leftButton;
            bool middleButton;
            bool rightButton;
            bool shift;
            bool xButton1;
            bool xButton2;
        } mouseWheel;
        struct {
            BgMouseButton btn;
            BgUint32 x;
            BgUint32 y;
        } mouseButton;
        struct {
            BgUint32 x;
            BgUint32 y;
            int deltaX, deltaY;
        } mouseMove;
    };
};

#endif