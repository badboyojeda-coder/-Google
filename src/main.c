
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include <psp2/display.h>
#include <vita2d.h>
#include <stdio.h>

int main(void) {
    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);

    vita2d_init();
    vita2d_set_clear_color(RGBA8(15, 25, 55, 255));

    while (1) {
        SceCtrlData pad;
        sceCtrlPeekBufferPositive(0, &pad, 1);

        vita2d_start_drawing();
        vita2d_clear_screen();

        vita2d_end_drawing();
        vita2d_swap_buffers();

        if (pad.buttons & SCE_CTRL_START) {
            break;
        }
    }

    vita2d_fini();
    sceKernelExitProcess(0);
    return 0;
}
