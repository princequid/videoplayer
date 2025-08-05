#include "controls.h"
#include <SDL.h>

Controls::Controls(Player* p) : player(p) {}

void Controls::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) player->stop();
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_SPACE: player->play(); break;
                case SDLK_p: player->pause(); break;
                    // Add more controls as needed
            }
        }
    }
}