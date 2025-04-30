#include <SDL2/SDL.h>
#include "graphic/structs.h"
#include "graphic/cleaner.h"

void cleanup() {
    if (app.renderer != NULL) {
        SDL_DestroyRenderer(app.renderer);
        app.renderer = NULL;
    }

    if (app.window != NULL) {
        SDL_DestroyWindow(app.window);
        app.window = NULL;
    }

    SDL_Quit();
}