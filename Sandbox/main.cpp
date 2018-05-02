#include "BugEngine.h"
#include <cstdio>
#include <algorithm>

#define ENABLE_PROFILING 1
#define SIZE 11

int main(int argc, char **argv) {
    BgWindow *window = new BgWindow("BgSandbox", BgIntVector2(640, 480), false);
    BgInputDevice *inputDevice = new BgInputDevice(window);
    BgRenderDevice *renderDevice = new BgRenderDevice(window);
    BgTexture *texture = new BgTexture("../Data/image.bmp");

    const BgVector2 point1 = BgVector2(640, 480);
    const BgVector2 point2 = BgVector2(0, 0);
    const BgVector2 line1[2] = { BgVector2(640,   0), BgVector2(0, 480) };
    const BgVector2 line2[2] = { BgVector2(0,   0), BgVector2(640, 480) };
    const BgVector2 line3[2] = { BgVector2(0, 240), BgVector2(640, 240) };
    const BgVector2 line4[2] = { BgVector2(320,   0), BgVector2(320, 480) };
    const BgVector2 triangle1[3] = { BgVector2(0, 128), BgVector2(64, 0), BgVector2(128, 128) };
    const BgVector2 triangle2[3] = { BgVector2(160, 128), BgVector2(224, 0), BgVector2(288, 128) };
    const BgVector2 triangle3[3] = { BgVector2(320, 128), BgVector2(384, 0), BgVector2(448, 128) };
    const BgVector2 rect1[2] = { BgVector2(0, 160), BgVector2(128, 128) };
    const BgVector2 rect2[2] = { BgVector2(160, 160), BgVector2(128, 128) };
    const BgVector2 rect3[2] = { BgVector2(320, 160), BgVector2(128, 128) };
    const BgVector2 circle1 = BgVector2(64, 384); float circleRadius1 = 64;
    const BgVector2 circle2 = BgVector2(224, 384); float circleRadius2 = 64;
    const BgVector2 circle3 = BgVector2(384, 384); float circleRadius3 = 64;

#if ENABLE_PROFILING
    BgPair<double, BgString> vals[SIZE] = {
    BgPair<double, BgString>(0.0, "DrawPoint           "),
    BgPair<double, BgString>(0.0, "DrawLine            "),
    BgPair<double, BgString>(0.0, "DrawTriangle        "),
    BgPair<double, BgString>(0.0, "DrawFilledTriangle  "),
    BgPair<double, BgString>(0.0, "DrawTexturedTriangle"),
    BgPair<double, BgString>(0.0, "DrawRect            "),
    BgPair<double, BgString>(0.0, "DrawFilledRect      "),
    BgPair<double, BgString>(0.0, "DrawTexturedRect    "),
    BgPair<double, BgString>(0.0, "DrawCircle          "),
    BgPair<double, BgString>(0.0, "DrawFilledCircle    "),
    BgPair<double, BgString>(0.0, "DrawTexturedCircle  "),
    };

    FILE *f = fopen("profile.txt", "w");
    BgUint64 timer = 0;
    const int count = 1000;
    for (int i = 0; i < count; i++) {
        timer = BgTimer::Start();
        renderDevice->DrawPoint(BG_MAP_RGBA(255, 0, 0, 255), point1);
        vals[0].first += BgTimer::GetMs(timer);
        timer = BgTimer::Start();
        renderDevice->DrawLine(BG_MAP_RGBA(0, 255, 0, 255), line1[0], line1[1]);
        vals[1].first += BgTimer::GetMs(timer);
        timer = BgTimer::Start();
        renderDevice->DrawTriangle(BG_MAP_RGBA(255, 0, 0, 255), triangle1);
        vals[2].first += BgTimer::GetMs(timer);
        timer = BgTimer::Start();
        renderDevice->DrawFilledTriangle(BG_MAP_RGBA(255, 0, 0, 255), triangle2);
        vals[3].first += BgTimer::GetMs(timer);
        timer = BgTimer::Start();
        renderDevice->DrawTexturedTriangle(texture, triangle3);
        vals[4].first += BgTimer::GetMs(timer);
        timer = BgTimer::Start();
        renderDevice->DrawRect(BG_MAP_RGBA(255, 0, 0, 255), rect1[0], rect1[1]);
        vals[5].first += BgTimer::GetMs(timer);
        timer = BgTimer::Start();
        renderDevice->DrawFilledRect(BG_MAP_RGBA(255, 0, 0, 255), rect2[0], rect2[1]);
        vals[6].first += BgTimer::GetMs(timer);
        timer = BgTimer::Start();
        renderDevice->DrawTexturedRect(texture, rect3[0], rect3[1]);
        vals[7].first += BgTimer::GetMs(timer);
        timer = BgTimer::Start();
        renderDevice->DrawCircle(BG_MAP_RGBA(0, 0, 255, 255), circle1, circleRadius1);
        vals[8].first += BgTimer::GetMs(timer);
        timer = BgTimer::Start();
        renderDevice->DrawFilledCircle(BG_MAP_RGBA(0, 0, 255, 255), circle2, circleRadius2);
        vals[9].first += BgTimer::GetMs(timer);
        timer = BgTimer::Start();
        renderDevice->DrawTexturedCircle(texture, circle3, circleRadius3);
        vals[10].first += BgTimer::GetMs(timer);
    }
    std::sort(vals, vals + SIZE, [](const BgPair<double, BgString> &v1, const BgPair<double, BgString> &v2) {
        return v1.first > v2.first;
    });
    for (int i = 0; i < SIZE; i++) {
        double time = vals[i].first / count;
        const char *name = vals[i].second.GetData();
        fprintf(f, "%.2d. %s - %f\n", i + 1, name, time);
    }
    fclose(f);
#else
    BgUint64 fpsTimer = BgTimer::Start();
    BgUint32 fps = 0;
    bool isExit = false;
    while (!isExit) {
        BgEvent e;
        while (window->ProcessEvent(e)) {
            inputDevice->ProcessEvent(e);
            if (e.type == BgEventType::Close || (e.type == BgEventType::Key && e.key.code == BgKeyCode::Escape)) {
                isExit = true;
            }
        }

        renderDevice->ClearColor(127, 127, 127, 255);

        renderDevice->DrawPoint(BG_MAP_RGBA(255, 0, 0, 255), point1);
        renderDevice->DrawPoint(BG_MAP_RGBA(255, 0, 0, 255), point2);
        renderDevice->DrawLine(BG_MAP_RGBA(0, 255, 0, 255), line1[0], line1[1]);
        renderDevice->DrawLine(BG_MAP_RGBA(0, 255, 0, 255), line2[0], line2[1]);
        renderDevice->DrawLine(BG_MAP_RGBA(0, 255, 0, 255), line3[0], line3[1]);
        renderDevice->DrawLine(BG_MAP_RGBA(0, 255, 0, 255), line4[0], line4[1]);
        renderDevice->DrawTriangle(BG_MAP_RGBA(255, 0, 0, 255), triangle1);
        renderDevice->DrawFilledTriangle(BG_MAP_RGBA(255, 0, 0, 255), triangle2);
        renderDevice->DrawTexturedTriangle(texture, triangle3);
        renderDevice->DrawRect(BG_MAP_RGBA(255, 0, 0, 255), rect1[0], rect1[1]);
        renderDevice->DrawFilledRect(BG_MAP_RGBA(255, 0, 0, 255), rect2[0], rect2[1]);
        renderDevice->DrawTexturedRect(texture, rect3[0], rect3[1]);
        renderDevice->DrawCircle(BG_MAP_RGBA(0, 0, 255, 255), circle1, circleRadius1);
        renderDevice->DrawFilledCircle(BG_MAP_RGBA(0, 0, 255, 255), circle2, circleRadius2);
        renderDevice->DrawTexturedCircle(texture, circle3, circleRadius3);

        window->SwapBuffers();

        fps++;
        if (BgTimer::GetMs(fpsTimer) >= 1000) {
            window->SetTitle(BgString::Format("FPS: %d | FrameTime: %f", fps, 1000.0f / fps));
            fps = 0;
            fpsTimer = BgTimer::Start();
        }
    }
#endif
    BG_DELETE(texture);
    BG_DELETE(renderDevice);
    BG_DELETE(inputDevice);
    BG_DELETE(window);
    return 0;
}