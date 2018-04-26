#include "BgWindow.h"
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

BgKeyCode GetKeyCodeFromSDLScanCode(const BgInt16 key) {
    switch (key) {
        case SDL_SCANCODE_A:
            return BgKeyCode::A;
            break;
        case SDL_SCANCODE_B:
            return BgKeyCode::B;
            break;
        case SDL_SCANCODE_C:
            return BgKeyCode::C;
            break;
        case SDL_SCANCODE_D:
            return BgKeyCode::D;
            break;
        case SDL_SCANCODE_E:
            return BgKeyCode::E;
            break;
        case SDL_SCANCODE_F:
            return BgKeyCode::F;
            break;
        case SDL_SCANCODE_G:
            return BgKeyCode::G;
            break;
        case SDL_SCANCODE_H:
            return BgKeyCode::H;
            break;
        case SDL_SCANCODE_I:
            return BgKeyCode::I;
            break;
        case SDL_SCANCODE_J:
            return BgKeyCode::J;
            break;
        case SDL_SCANCODE_K:
            return BgKeyCode::K;
            break;
        case SDL_SCANCODE_L:
            return BgKeyCode::L;
            break;
        case SDL_SCANCODE_M:
            return BgKeyCode::M;
            break;
        case SDL_SCANCODE_N:
            return BgKeyCode::N;
            break;
        case SDL_SCANCODE_O:
            return BgKeyCode::O;
            break;
        case SDL_SCANCODE_P:
            return BgKeyCode::P;
            break;
        case SDL_SCANCODE_Q:
            return BgKeyCode::Q;
            break;
        case SDL_SCANCODE_R:
            return BgKeyCode::R;
            break;
        case SDL_SCANCODE_S:
            return BgKeyCode::S;
            break;
        case SDL_SCANCODE_T:
            return BgKeyCode::T;
            break;
        case SDL_SCANCODE_U:
            return BgKeyCode::U;
            break;
        case SDL_SCANCODE_V:
            return BgKeyCode::V;
            break;
        case SDL_SCANCODE_W:
            return BgKeyCode::W;
            break;
        case SDL_SCANCODE_X:
            return BgKeyCode::X;
            break;
        case SDL_SCANCODE_Y:
            return BgKeyCode::Y;
            break;
        case SDL_SCANCODE_Z:
            return BgKeyCode::Z;
            break;
        case SDL_SCANCODE_0:
            return BgKeyCode::Num0;
            break;
        case SDL_SCANCODE_1:
            return BgKeyCode::Num1;
            break;
        case SDL_SCANCODE_2:
            return BgKeyCode::Num2;
            break;
        case SDL_SCANCODE_3:
            return BgKeyCode::Num3;
            break;
        case SDL_SCANCODE_4:
            return BgKeyCode::Num4;
            break;
        case SDL_SCANCODE_5:
            return BgKeyCode::Num5;
            break;
        case SDL_SCANCODE_6:
            return BgKeyCode::Num6;
            break;
        case SDL_SCANCODE_7:
            return BgKeyCode::Num7;
            break;
        case SDL_SCANCODE_8:
            return BgKeyCode::Num8;
            break;
        case SDL_SCANCODE_9:
            return BgKeyCode::Num9;
            break;
        case SDL_SCANCODE_RETURN:
            return BgKeyCode::Return;
            break;
        case SDL_SCANCODE_ESCAPE:
            return BgKeyCode::Escape;
            break;
        case SDL_SCANCODE_BACKSPACE:
            return BgKeyCode::BackSpace;
            break;
        case SDL_SCANCODE_TAB:
            return BgKeyCode::Tab;
            break;
        case SDL_SCANCODE_SPACE:
            return BgKeyCode::Space;
            break;
        case SDL_SCANCODE_F1:
            return BgKeyCode::F1;
            break;
        case SDL_SCANCODE_F2:
            return BgKeyCode::F2;
            break;
        case SDL_SCANCODE_F3:
            return BgKeyCode::F3;
            break;
        case SDL_SCANCODE_F4:
            return BgKeyCode::F4;
            break;
        case SDL_SCANCODE_F5:
            return BgKeyCode::F5;
            break;
        case SDL_SCANCODE_F6:
            return BgKeyCode::F6;
            break;
        case SDL_SCANCODE_F7:
            return BgKeyCode::F7;
            break;
        case SDL_SCANCODE_F8:
            return BgKeyCode::F8;
            break;
        case SDL_SCANCODE_F9:
            return BgKeyCode::F9;
            break;
        case SDL_SCANCODE_F10:
            return BgKeyCode::F10;
            break;
        case SDL_SCANCODE_F11:
            return BgKeyCode::F11;
            break;
        case SDL_SCANCODE_F12:
            return BgKeyCode::F12;
            break;
        case SDL_SCANCODE_PAUSE:
            return BgKeyCode::Pause;
            break;
        case SDL_SCANCODE_INSERT:
            return BgKeyCode::Insert;
            break;
        case SDL_SCANCODE_HOME:
            return BgKeyCode::Home;
            break;
        case SDL_SCANCODE_PAGEUP:
            return BgKeyCode::PageUp;
            break;
        case SDL_SCANCODE_PAGEDOWN:
            return BgKeyCode::PageDown;
            break;
        case SDL_SCANCODE_DELETE:
            return BgKeyCode::Delete;
            break;
        case SDL_SCANCODE_END:
            return BgKeyCode::End;
            break;
        case SDL_SCANCODE_LEFT:
            return BgKeyCode::Left;
            break;
        case SDL_SCANCODE_RIGHT:
            return BgKeyCode::Right;
            break;
        case SDL_SCANCODE_UP:
            return BgKeyCode::Up;
            break;
        case SDL_SCANCODE_DOWN:
            return BgKeyCode::Down;
            break;
        case SDL_SCANCODE_KP_0:
            return BgKeyCode::Numpad0;
            break;
        case SDL_SCANCODE_KP_1:
            return BgKeyCode::Numpad1;
            break;
        case SDL_SCANCODE_KP_2:
            return BgKeyCode::Numpad2;
            break;
        case SDL_SCANCODE_KP_3:
            return BgKeyCode::Numpad3;
            break;
        case SDL_SCANCODE_KP_4:
            return BgKeyCode::Numpad4;
            break;
        case SDL_SCANCODE_KP_5:
            return BgKeyCode::Numpad5;
            break;
        case SDL_SCANCODE_KP_6:
            return BgKeyCode::Numpad6;
            break;
        case SDL_SCANCODE_KP_7:
            return BgKeyCode::Numpad7;
            break;
        case SDL_SCANCODE_KP_8:
            return BgKeyCode::Numpad8;
            break;
        case SDL_SCANCODE_KP_9:
            return BgKeyCode::Numpad9;
            break;
        case SDL_SCANCODE_LCTRL:
            return BgKeyCode::LControl;
            break;
        case SDL_SCANCODE_LSHIFT:
            return BgKeyCode::LShift;
            break;
        case SDL_SCANCODE_LALT:
            return BgKeyCode::LAlt;
            break;
        case SDL_SCANCODE_LGUI:
            return BgKeyCode::LSystem;
            break;
        case SDL_SCANCODE_RCTRL:
            return BgKeyCode::RControl;
            break;
        case SDL_SCANCODE_RSHIFT:
            return BgKeyCode::RShift;
            break;
        case SDL_SCANCODE_RALT:
            return BgKeyCode::RAlt;
            break;
        case SDL_SCANCODE_RGUI:
            return BgKeyCode::RSystem;
            break;
        default:
            return BgKeyCode::Unknown;
            break;
    }
}

BgWindow::BgWindow(const BgString & title, const BgIntVector2 & size, bool fullscreen) {
    BG_ASSERT(SDL_Init(SDL_INIT_VIDEO) == 0);
    if (fullscreen) {
        mWindow = SDL_CreateWindow(title.GetData(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN);
    }
    else {
        mWindow = SDL_CreateWindow(title.GetData(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_SHOWN);
    }
    BG_ASSERT(mWindow);
    SDL_Surface *surface = SDL_GetWindowSurface((SDL_Window*)mWindow);
    BG_ASSERT(surface);
    mSurface = (BgUint32*)surface->pixels;
}

BgWindow::~BgWindow() {
    SDL_DestroyWindow((SDL_Window*)mWindow);
    SDL_Quit();
}

bool BgWindow::ProcessEvent(BgEvent & e) {
    SDL_Event sdlEvent;
    if (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT:
            {
                e.type = BgEventType::Close;
                break;
            }
            case SDL_WINDOWEVENT:
            {
                switch (sdlEvent.window.type) {
                    case SDL_WINDOWEVENT_RESIZED:
                    {
                        e.type = BgEventType::Resize;
                        e.resize.width = sdlEvent.window.data1;
                        e.resize.height = sdlEvent.window.data2;
                        break;
                    }
                    case SDL_WINDOWEVENT_FOCUS_LOST:
                    {
                        e.type = BgEventType::LostFocus;
                        break;
                    }
                    case SDL_WINDOWEVENT_FOCUS_GAINED:
                    {
                        e.type = BgEventType::GetFocus;
                        break;
                    }
                }
                break;
            }
            case SDL_KEYDOWN:
            {
                e.type = BgEventType::KeyDown;
                e.key.code = GetKeyCodeFromSDLScanCode(sdlEvent.key.keysym.scancode);
                e.key.alt = SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LALT] || SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RALT];
                e.key.control = SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LCTRL] || SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RCTRL];
                e.key.shift = SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LSHIFT] || SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RSHIFT];
                e.key.system = SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LGUI] || SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RGUI];
                break;
            }
            case SDL_KEYUP:
            {
                e.type = BgEventType::KeyUp;
                e.key.code = GetKeyCodeFromSDLScanCode(sdlEvent.key.keysym.scancode);
                e.key.alt = SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LALT] || SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RALT];
                e.key.control = SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LCTRL] || SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RCTRL];
                e.key.shift = SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LSHIFT] || SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RSHIFT];
                e.key.system = SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LGUI] || SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RGUI];
                break;
            }
            case SDL_MOUSEWHEEL:
            {
                e.type = BgEventType::MouseWheel;
                e.mouseWheel.direction = sdlEvent.wheel.direction;
                e.mouseWheel.x = sdlEvent.wheel.x;
                e.mouseWheel.y = sdlEvent.wheel.y;
                unsigned int mouseState = SDL_GetMouseState(nullptr, nullptr);
                e.mouseWheel.control = SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LCTRL] || SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RCTRL];
                e.mouseWheel.leftButton = (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) == SDL_BUTTON(SDL_BUTTON_LEFT);
                e.mouseWheel.middleButton = (mouseState & SDL_BUTTON(SDL_BUTTON_MIDDLE)) == SDL_BUTTON(SDL_BUTTON_MIDDLE);
                e.mouseWheel.rightButton = (mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT)) == SDL_BUTTON(SDL_BUTTON_RIGHT);
                e.mouseWheel.shift = SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LSHIFT] || SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RSHIFT];
                e.mouseWheel.xButton1 = (mouseState & SDL_BUTTON(SDL_BUTTON_X1)) == SDL_BUTTON(SDL_BUTTON_X1);
                e.mouseWheel.xButton2 = (mouseState & SDL_BUTTON(SDL_BUTTON_X2)) == SDL_BUTTON(SDL_BUTTON_X2);
                break;
            }
            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEBUTTONDOWN:
            {
                if (sdlEvent.type == SDL_MOUSEBUTTONDOWN) {
                    e.type = BgEventType::MouseButtonDown;
                }
                else if (sdlEvent.type == SDL_MOUSEBUTTONUP) {
                    e.type = BgEventType::MouseButtonUp;
                }
                switch (sdlEvent.button.button) {
                    case SDL_BUTTON_LEFT:
                    {
                        e.mouseButton.btn = BgMouseButton::Left;
                        break;
                    }
                    case SDL_BUTTON_MIDDLE:
                    {
                        e.mouseButton.btn = BgMouseButton::Middle;
                        break;
                    }
                    case SDL_BUTTON_RIGHT:
                    {
                        e.mouseButton.btn = BgMouseButton::Right;
                        break;
                    }
                    case SDL_BUTTON_X1:
                    {
                        e.mouseButton.btn = BgMouseButton::X1;
                        break;
                    }
                    case SDL_BUTTON_X2:
                    {
                        e.mouseButton.btn = BgMouseButton::X2;
                        break;
                    }
                }
                e.mouseButton.x = sdlEvent.button.x;
                e.mouseButton.y = sdlEvent.button.y;
                break;
            }
            case SDL_MOUSEMOTION:
            {
                static int lastX = 0, lastY = 0;
                static bool first = true;
                if (first) {
                    first = false;
                    lastX = sdlEvent.motion.x;
                    lastY = sdlEvent.motion.y;
                }
                e.type = BgEventType::MouseMove;
                e.mouseMove.x = sdlEvent.motion.x;
                e.mouseMove.y = sdlEvent.motion.y;
                e.mouseMove.deltaX = lastX - sdlEvent.motion.x;//sdlEvent.motion.xrel;
                e.mouseMove.deltaY = lastY - sdlEvent.motion.y;//sdlEvent.motion.yrel;
                lastX = sdlEvent.motion.x;
                lastY = sdlEvent.motion.y;
                break;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

void BgWindow::SwapBuffers() {
    SDL_UpdateWindowSurface((SDL_Window*)mWindow);
}

void BgWindow::SetMousePos(const BgIntVector2 & pos) {
    SDL_WarpMouseInWindow((SDL_Window*)mWindow, pos.x, pos.y);
}

void BgWindow::SetMouseVisible(bool visible) {
    SDL_ShowCursor(visible);
}

BgIntVector2 BgWindow::GetPosition() const {
    BgIntVector2 v;
    SDL_GetWindowPosition((SDL_Window*)mWindow, &v.x, &v.y);
    return v;
}

BgIntVector2 BgWindow::GetSize() const {
    BgIntVector2 v;
    SDL_GetWindowSize((SDL_Window*)mWindow, &v.x, &v.y);
    return v;
}

BgIntVector2 BgWindow::GetCenter() const {
    return GetSize() / 2;
}

bool BgWindow::IsMouseVisible() const {
    return SDL_ShowCursor(-1);
}

void * BgWindow::GetHandle() const {
    return mWindow;
}

BgUint32 * BgWindow::GetSurface() const {
    return mSurface;
}
