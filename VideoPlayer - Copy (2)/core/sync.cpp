#include "sync.h"
#include <SDL.h>

Sync::Sync() : frameRate(0.0), lastVideoPts(0.0) {}

void Sync::initialize(double frameRate) {
    this->frameRate = frameRate;
}

void Sync::waitForVideoFrame(double pts) {
    double frameTime = 1.0 / frameRate;
    double delay = (pts - lastVideoPts) * 1000.0;
    if (delay > 0) SDL_Delay(static_cast<Uint32>(delay));
    lastVideoPts = pts;
}

void Sync::waitForAudioFrame(double pts) {
    // Placeholder: Audio sync logic
}