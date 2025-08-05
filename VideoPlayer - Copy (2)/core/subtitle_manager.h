#ifndef SUBTITLE_MANAGER_H
#define SUBTITLE_MANAGER_H

#include <SDL.h> // Changed from <SDL2/SDL.h>
#include <string>
#include <vector>

class SubtitleManager {
public:
    SubtitleManager();
    bool loadSubtitle(const std::string& filePath);
    void renderSubtitle(SDL_Renderer* renderer, double pts);

private:
    struct SubtitleEntry {
        double startTime;
        double endTime;
        std::string text;
    };
    std::vector<SubtitleEntry> subtitles;
};

#endif