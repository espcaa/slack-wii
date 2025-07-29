// main.c
#include <grrlib.h>
#include <wiiuse/wpad.h>

int main() {
    GRRLIB_Init();
    WPAD_Init();

    u32 slackPurple = RGBA(74, 21, 75, 255);

    while (1) {
        WPAD_ScanPads();
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break;

        GRRLIB_FillScreen(slackPurple);
        GRRLIB_Render();
    }

    GRRLIB_Exit();
    return 0;
}
