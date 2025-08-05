#include <SDL.h>
#include "ui/controls.h"
#include "core/player.h"

int SDL_main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) return 1;

    SDL_Window* window = SDL_CreateWindow("Video Player", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) return 1;

    Player player;
    if (!player.open(argc > 1 ? argv[1] : "sample.mp4")) return 1;

    Controls controls(&player);
    bool running = true;
    while (running) {
        controls.handleInput(); // Process events
        if (!player.isPlaying()) running = false; // Use method instead of direct access
        SDL_Delay(16); // Approx 60 FPS
    }

    player.cleanup();
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}