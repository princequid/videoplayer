#include "timer.h"
#include <SDL.h>

Timer::Timer() {
    SDL_GetTicks();
}

double Timer::getElapsedTime() {
    return SDL_GetTicks() / 1000.0;
}