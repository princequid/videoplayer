#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "decoder.h"
#include "renderer.h"
#include "audio_output.h"
#include "subtitle_manager.h"
#include "sync.h"

class Player {
public:
    Player();
    ~Player();

    bool open(const std::string& filePath);
    void play();
    void pause();
    void seek(double time);
    void setVolume(float volume);
    void cleanup();
    bool initialize(const std::string& filename);
    void start();
    void stop();

    bool isPlaying() const;  // Getter for playing status

private:
    Decoder decoder;
    Renderer renderer;
    AudioOutput audioOutput;
    SubtitleManager subtitleManager;
    Sync sync;

    bool playing;           // Renamed to avoid conflict
    double currentTime;
};

#endif
