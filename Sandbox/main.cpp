#include <cstdio>
#include "BugEngine.h"

int main(int argc, char **argv) {
    BgString str = "Hello!";
    printf("STR: %s | LEN: %d\n", str.GetData(), str.GetLength());

    BgWindow *window = new BgWindow("BgSandbox", BgIntVector2(640, 480), false);

    bool isExit = false;
    while (!isExit) {
        BgEvent e;
        while (window->ProcessEvent(e)) {
            if (e.type == BgEventType::Close) {
                isExit = true;
            }
        }
    }
    BG_DELETE(window);
    return 0;
}