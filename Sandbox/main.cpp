#include <cstdio>
#include "BugEngine.h"

int main(int argc, char **argv) {
    BgWindow *window = new BgWindow("BgSandbox", BgIntVector2(640, 480), false);
    BgInputDevice *inputDevice = new BgInputDevice(window);

    bool isExit = false;
    while (!isExit) {
        BgEvent e;
        while (window->ProcessEvent(e)) {
            inputDevice->ProcessEvent(e);
            if (e.type == BgEventType::Close || (e.type == BgEventType::Key && e.key.code == BgKeyCode::Escape)) {
                isExit = true;
            }
        }
    }
    BG_DELETE(inputDevice);
    BG_DELETE(window);
    return 0;
}