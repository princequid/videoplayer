#include "subtitle_manager.h"
#include <fstream>
#include <sstream>

SubtitleManager::SubtitleManager() {}

bool SubtitleManager::loadSubtitle(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) return false;

    std::string line;
    SubtitleEntry entry;
    while (std::getline(file, line)) {
        // Simplified SRT parsing (adjust based on actual format)
        if (line.find("-->") != std::string::npos) {
            std::stringstream ss(line);
            ss >> entry.startTime >> entry.endTime; // Placeholder parsing
        } else if (!line.empty()) {
            entry.text = line;
            subtitles.push_back(entry);
        }
    }
    file.close();
    return true;
}

void SubtitleManager::renderSubtitle(SDL_Renderer* renderer, double pts) {
    for (const auto& entry : subtitles) {
        if (pts >= entry.startTime && pts <= entry.endTime) {
            // Placeholder: Add SDL_ttf or custom rendering logic here
            // Example: SDL_Rect rect; SDL_RenderDrawRect(renderer, &rect);
        }
    }
}