#include <grrlib.h>
#include <wiiuse/wpad.h>
#include "assets/roboto_ttf.h"

const char* scanServerIp() {
    return "192.1.0.10";
}

int main() {
    GRRLIB_Init();
    WPAD_Init();

    u32 slackPurple = RGBA(74, 21, 75, 255);

    GRRLIB_ttfFont *myFont = GRRLIB_LoadTTF(roboto_ttf, roboto_ttf_len);

    while (true) {
        WPAD_ScanPads();
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break;

        GRRLIB_FillScreen(slackPurple);

        GRRLIB_PrintfTTF(20, 20, myFont, "Slack", 16, 0xFFFFFFFF);

        GRRLIB_Render();
    }

    GRRLIB_FreeTTF(myFont);
    GRRLIB_Exit();

    return 0;
}
