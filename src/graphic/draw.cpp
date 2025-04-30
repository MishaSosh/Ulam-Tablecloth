#include <SDL2/SDL.h>
#include <stdbool.h>
#include "graphic/structs.h"
#include "graphic/draw.h"
#include "math/prime_nums.h"
#include "graphic/defs.h"
#include "graphic/input.h"

void prepareScene() {
    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene() {
    SDL_RenderPresent(app.renderer);
}

void drawing() {
    SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

int x = centerX;
int y = centerY;

bool dir = true;
int sideLength = 1;
int num = 1;
int pointCount = 0;

Uint32 lastPresentTime = SDL_GetTicks();

while (num <= 1000000) {
    if (dir) {
        for (int i = 0; i <= sideLength; i++) {
            if (isPrime(num)) {
                SDL_RenderDrawPoint(app.renderer, x, y);
                pointCount++;
            }
            x++;
            num++;
        }
        for (int i = 0; i <= sideLength; i++) {
            if (isPrime(num)) {
                SDL_RenderDrawPoint(app.renderer, x, y);
                pointCount++;
            }
            y--;
            num++;
        }
        sideLength++;
        dir = false;
    } else {
        for (int i = 0; i <= sideLength; i++) {
            if (isPrime(num)) {
                SDL_RenderDrawPoint(app.renderer, x, y);
                pointCount++;
            }
            x--;
            num++;
        }
        for (int i = 0; i <= sideLength; i++) {
            if (isPrime(num)) {
                SDL_RenderDrawPoint(app.renderer, x, y);
                pointCount++;
            }
            y++;
            num++;
        }
        sideLength++;
        dir = true;
    }

    doInput();

    if (SDL_GetTicks() - lastPresentTime >= 16) {
        SDL_RenderPresent(app.renderer);
        lastPresentTime = SDL_GetTicks();
    }
}

SDL_RenderPresent(app.renderer);



}

