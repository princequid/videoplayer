#ifndef AUDIO_OUTPUT_H
#define AUDIO_OUTPUT_H

#include <cstdint>

class AudioOutput {
public:
    AudioOutput();
    ~AudioOutput();

    bool initialize(int sampleRate, int channels);
    void playAudio(const uint8_t* data, int len);
    void cleanup();

    void setVolume(float volume);     // ✅ New method
    float getVolume() const;          // ✅ Optional getter

private:
    unsigned int deviceId;
    float currentVolume = 1.0f;       // ✅ Volume scale: 0.0 (mute) to 1.0 (max)
};

#endif
