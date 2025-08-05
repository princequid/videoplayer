#include "renderer.h"
#include <SDL.h>

Renderer::Renderer() : renderer(nullptr), texture(nullptr) {}

Renderer::~Renderer() { cleanup(); }

bool Renderer::initialize(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) return false;
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STREAMING, 1920, 1080); // Example resolution
    if (!texture) {
        SDL_DestroyRenderer(renderer);
        return false;
    }
    return true;
}

void Renderer::renderFrame(const uint8_t* data, int linesize, int width, int height) {
    SDL_UpdateTexture(texture, nullptr, data, linesize);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void Renderer::cleanup() {
    if (texture) SDL_DestroyTexture(texture);
    if (renderer) SDL_DestroyRenderer(renderer);
}

SDL_Renderer* Renderer::getRenderer() const { return renderer; }