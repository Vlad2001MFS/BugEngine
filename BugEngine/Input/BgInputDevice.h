#ifndef BG_INPUTDEVICE_H
#define BG_INPUTDEVICE_H

#include "../Core/BgVector.h"
#include "../Window/BgWindow.h"

typedef void(*BgKeyboardCallback)(const BgKeyboardEvent&);
typedef void(*BgMouseWheelCallback)(const BgMouseWheelEvent&);
typedef void(*BgMouseButtonCallback)(const BgMouseButtonEvent&);
typedef void(*BgMouseMoveCallback)(const BgMouseMoveEvent&);

class BgInputDevice {
public:
    BgInputDevice(const BgWindow *window);
    ~BgInputDevice();

    void ProcessEvent(const BgEvent &e);
    void AddCallback(BgKeyboardCallback callback);
    void AddCallback(BgMouseWheelCallback callback);
    void AddCallback(BgMouseButtonCallback callback);
    void AddCallback(BgMouseMoveCallback callback);

    void SetMousePosition(const BgIntVector2 &pos);
    void SetMouseVisible(bool visible);

    BgIntVector2 GetMousePosition() const;
    bool IsMouseVisible() const;
    bool IsKeyDown(BgKeyCode key) const;
    bool IsMouseButtonDown(BgMouseButton btn) const;

private:
    const BgWindow *mWindow;
    BgVector<BgKeyboardCallback> mKeyboardCallbacks;
    BgVector<BgMouseWheelCallback> mMouseWheelCallbacks;
    BgVector<BgMouseButtonCallback> mMouseButtonCallbacks;
    BgVector<BgMouseMoveCallback> mMouseMoveCallbacks;
};

#endif