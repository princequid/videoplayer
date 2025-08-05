#include "audio_output.h"
#include <SDL.h>

AudioOutput::AudioOutput() : deviceId(0), currentVolume(1.0f) {}

AudioOutput::~AudioOutput() {
    cleanup();
}

bool AudioOutput::initialize(int sampleRate, int channels) {
    SDL_AudioSpec spec, obtained;
    spec.freq = sampleRate;
    spec.format = AUDIO_S16SYS;
    spec.channels = channels;
    spec.samples = 4096;
    spec.callback = nullptr;
    spec.userdata = nullptr;
    deviceId = SDL_OpenAudioDevice(nullptr, 0, &spec, &obtained, 0);
    return deviceId != 0;
}

void AudioOutput::playAudio(const uint8_t* data, int len) {
    // Volume scaling not applied yet — just queue raw data
    SDL_QueueAudio(deviceId, data, len);
}

void AudioOutput::setVolume(float volume) {
    if (volume < 0.0f) volume = 0.0f;
    if (volume > 1.0f) volume = 1.0f;
    currentVolume = volume;
    // NOTE: You would need to scale audio samples manually before queuing
}

float AudioOutput::getVolume() const {
    return currentVolume;
}

void AudioOutput::cleanup() {
    if (deviceId)
        SDL_CloseAudioDevice(deviceId);
}
