#include <SDL2/SDL.h>
#include "graphic/input.h"

void doInput() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
            default:
                break;
        }
    }
}