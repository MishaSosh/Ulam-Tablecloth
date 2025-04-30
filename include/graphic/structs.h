#pragma once

#include <SDL2/SDL.h>

struct App {
    SDL_Renderer *renderer;
    SDL_Window *window;
};

extern App app;