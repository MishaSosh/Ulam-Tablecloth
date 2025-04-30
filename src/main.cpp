#include <SDL2/SDL.h>
#include "graphic/structs.h"
#include "graphic/init.h"
#include "graphic/cleaner.h"
#include "graphic/draw.h"
#include "graphic/input.h"

App app;

int main(int argc, char **argv) {
    memset(&app, 0, sizeof(App));

    SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, "1");

    initSDL();

    atexit(cleanup);

    prepareScene();
    drawing();
    

    while (1) {
        doInput();
        SDL_Delay(16);
    }
}