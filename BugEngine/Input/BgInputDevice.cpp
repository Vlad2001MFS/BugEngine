#include "BgInputDevice.h"
#include <SDL2/SDL.h>

const int gKeyCodes[] =
{
    SDL_SCANCODE_UNKNOWN,

    SDL_SCANCODE_A, SDL_SCANCODE_B, SDL_SCANCODE_C, SDL_SCANCODE_D, SDL_SCANCODE_E,
    SDL_SCANCODE_F, SDL_SCANCODE_G, SDL_SCANCODE_H, SDL_SCANCODE_I, SDL_SCANCODE_J,
    SDL_SCANCODE_K, SDL_SCANCODE_L, SDL_SCANCODE_M, SDL_SCANCODE_N, SDL_SCANCODE_O,
    SDL_SCANCODE_P, SDL_SCANCODE_Q, SDL_SCANCODE_R, SDL_SCANCODE_S, SDL_SCANCODE_T,
    SDL_SCANCODE_U, SDL_SCANCODE_V, SDL_SCANCODE_W, SDL_SCANCODE_X, SDL_SCANCODE_Y,
    SDL_SCANCODE_Z,

    SDL_SCANCODE_0, SDL_SCANCODE_1, SDL_SCANCODE_2, SDL_SCANCODE_3, SDL_SCANCODE_4,
    SDL_SCANCODE_5, SDL_SCANCODE_6, SDL_SCANCODE_7, SDL_SCANCODE_8, SDL_SCANCODE_9,

    SDL_SCANCODE_RETURN, SDL_SCANCODE_ESCAPE, SDL_SCANCODE_BACKSPACE,
    SDL_SCANCODE_TAB, SDL_SCANCODE_SPACE,

    SDL_SCANCODE_F1, SDL_SCANCODE_F2, SDL_SCANCODE_F3, SDL_SCANCODE_F4, SDL_SCANCODE_F5,
    SDL_SCANCODE_F6, SDL_SCANCODE_F7, SDL_SCANCODE_F8, SDL_SCANCODE_F9, SDL_SCANCODE_F10,
    SDL_SCANCODE_F11, SDL_SCANCODE_F12,

    SDL_SCANCODE_PAUSE, SDL_SCANCODE_INSERT, SDL_SCANCODE_HOME, SDL_SCANCODE_PAGEUP, SDL_SCANCODE_PAGEDOWN,
    SDL_SCANCODE_DELETE, SDL_SCANCODE_END, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN,

    SDL_SCANCODE_KP_0, SDL_SCANCODE_KP_1, SDL_SCANCODE_KP_2, SDL_SCANCODE_KP_3, SDL_SCANCODE_KP_4,
    SDL_SCANCODE_KP_5, SDL_SCANCODE_KP_6, SDL_SCANCODE_KP_7, SDL_SCANCODE_KP_8, SDL_SCANCODE_KP_9,

    SDL_SCANCODE_LCTRL, SDL_SCANCODE_RCTRL, SDL_SCANCODE_LSHIFT, SDL_SCANCODE_RSHIFT,
    SDL_SCANCODE_LALT, SDL_SCANCODE_RALT, SDL_SCANCODE_LGUI, SDL_SCANCODE_RGUI,
};

const BgUint32 gMouseButtons[] = {
    SDL_BUTTON_LEFT,
    SDL_BUTTON_RIGHT,
    SDL_BUTTON_MIDDLE,
    SDL_BUTTON_X1,
    SDL_BUTTON_X2
};

BgInputDevice::BgInputDevice(const BgWindow * window) : mWindow(window) { 
    BG_ASSERT(window);
}

BgInputDevice::~BgInputDevice() { }

void BgInputDevice::ProcessEvent(const BgEvent & e) {
    switch (e.type) {
        case BgEventType::Key:
            for (BgSize i = 0; i < mKeyboardCallbacks.GetSize(); i++) {
                mKeyboardCallbacks[i](e.key);
            }
            break;
        case BgEventType::MouseWheel:
            for (BgSize i = 0; i < mMouseWheelCallbacks.GetSize(); i++) {
                mMouseWheelCallbacks[i](e.mouseWheel);
            }
            break;
        case BgEventType::MouseButton:
            for (BgSize i = 0; i < mMouseButtonCallbacks.GetSize(); i++) {
                mMouseButtonCallbacks[i](e.mouseButton);
            }
            break;
        case BgEventType::MouseMove:
            for (BgSize i = 0; i < mMouseMoveCallbacks.GetSize(); i++) {
                mMouseMoveCallbacks[i](e.mouseMove);
            }
            break;
    }
}

void BgInputDevice::AddCallback(BgKeyboardCallback callback) { 
    BG_ASSERT(callback);
    mKeyboardCallbacks.Append(callback);
}

void BgInputDevice::AddCallback(BgMouseWheelCallback callback) {
    BG_ASSERT(callback);
    mMouseWheelCallbacks.Append(callback);
}

void BgInputDevice::AddCallback(BgMouseButtonCallback callback) {
    BG_ASSERT(callback);
    mMouseButtonCallbacks.Append(callback);
}

void BgInputDevice::AddCallback(BgMouseMoveCallback callback) {
    BG_ASSERT(callback);
    mMouseMoveCallbacks.Append(callback);
}

void BgInputDevice::SetMousePosition(const BgIntVector2 & pos) { 
    SDL_WarpMouseInWindow((SDL_Window*)mWindow->GetHandle(), pos.x, pos.y);
}

void BgInputDevice::SetMouseVisible(bool visible) { 
    SDL_ShowCursor(visible); 
}

BgIntVector2 BgInputDevice::GetMousePosition() const {
    BgIntVector2 v;
    SDL_GetMouseState(&v.x, &v.y);
    return v;
}

bool BgInputDevice::IsMouseVisible() const {
    return SDL_ShowCursor(-1);
}

bool BgInputDevice::IsKeyDown(BgKeyCode key) const {
    return SDL_GetKeyboardState(nullptr)[gKeyCodes[(BgUint32)key]];
}

bool BgInputDevice::IsMouseButtonDown(BgMouseButton btn) const {
    return BG_FLAG_EXIST(SDL_GetMouseState(nullptr, nullptr), SDL_BUTTON(gMouseButtons[(BgUint32)btn]));
    //return (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(gMouseButtons[static_cast<BgUint32>(button)])) == SDL_BUTTON(gMouseButtons[static_cast<BgUint32>(button)]);
}
