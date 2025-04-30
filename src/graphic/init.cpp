#include <iostream>

#include <SDL2/SDL.h>
#include "graphic/init.h"
#include "graphic/defs.h"
#include "graphic/structs.h"

void initSDL() {
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = SDL_WINDOW_SHOWN;

    if (SDL_Init(SDL_INIT_VIDEO < 0)) {
        std::cerr << "Couldn't initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    app.window = SDL_CreateWindow("Ulam tablecloth", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!app.window) {
        std::cerr << "Couldn't create window: " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if (!app.renderer) {
        std::cerr << "Couldn't create renderer: " << SDL_GetError() << std::endl;
        exit(1);
    }
}