#ifndef BG_EVENT_H
#define BG_EVENT_H

#include "../Core/BgCommon.h"

enum class BgEventType {
    Close,
    Resize,
    LostFocus,
    GetFocus,
    Key,
    MouseWheel,
    MouseButton,
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

enum class BgKeyState {
    Pressed,
    Released
};

struct BgResizeEvent {
    BgUint32 width;
    BgUint32 height;
};
struct BgKeyboardEvent {
    BgKeyCode code;
    BgKeyState state;
    bool alt;
    bool control;
    bool shift;
    bool system;
};
struct BgMouseWheelEvent {
    BgInt32 direction;
    BgInt32 x;
    BgInt32 y;
    bool leftButton;
    bool middleButton;
    bool rightButton;
    bool xButton1;
    bool xButton2;
    bool control;
    bool shift;
};
struct BgMouseButtonEvent {
    BgMouseButton btn;
    BgKeyState state;
    BgUint32 x;
    BgUint32 y;
};
struct BgMouseMoveEvent {
    BgUint32 x;
    BgUint32 y;
    BgInt32 deltaX, deltaY;
};

struct BgEvent {
    BgEventType type;
    union {
        BgResizeEvent resize;
        BgKeyboardEvent key;
        BgMouseWheelEvent mouseWheel;
        BgMouseButtonEvent mouseButton;
        BgMouseMoveEvent mouseMove;
    };
};

#endif