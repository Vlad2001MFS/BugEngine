#include <cstdio>
#include "Core/BgCommon.h"
#include "Core/BgString.h"

int main(int argc, char **argv) {
    BgString str = "Hello!";
    printf("STR: %s | LEN: %d\n", str.GetData(), str.GetLength());

    system("pause");
    return 0;
}