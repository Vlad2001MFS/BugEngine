#ifndef BG_WINDOW_H
#define BG_WINDOW_H

#include "../Core/BgCommon.h"
#include "../Core/BgString.h"
#include "../Math/BgIntVector2.h"
#include "BgEvent.h"

class BgWindow {
public:
    BgWindow(const BgString &title, const BgIntVector2 &size, bool fullscreen);
    ~BgWindow();

    bool ProcessEvent(BgEvent &e);
    void SwapBuffers();
    BgIntVector2 GetPosition() const;
    BgIntVector2 GetSize() const;
    BgIntVector2 GetCenter() const;
    void *GetHandle() const;
    BgUint32 *GetSurface() const;

private:
    void *mWindow;
    BgUint32 *mSurface;
};

#endif