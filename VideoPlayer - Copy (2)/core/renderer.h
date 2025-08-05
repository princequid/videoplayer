#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>

class Renderer {
public:
    Renderer();
    ~Renderer(); // Added destructor
    bool initialize(SDL_Window* window);
    void renderFrame(const uint8_t* data, int linesize, int width, int height);
    void cleanup();
    SDL_Renderer* getRenderer() const; // Added method

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};

#endif