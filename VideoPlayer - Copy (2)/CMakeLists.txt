cmake_minimum_required(VERSION 3.10)
project(video_player LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set include directories for FFmpeg and SDL2
include_directories("C:/Users/princ/ffmpeg-release-full-shared/ffmpeg-7.1.1-full_build-shared/include" "C:/Users/princ/OneDrive/Desktop/sdl2/SDL2-2.30.8/include")

# Set link directories for FFmpeg and SDL2
link_directories("C:/Users/princ/ffmpeg-release-full-shared/ffmpeg-7.1.1-full_build-shared/lib" "C:/Users/princ/OneDrive/Desktop/sdl2/SDL2-2.30.8/lib/x64")

add_executable(video_player
        main.cpp
        core/player.cpp
        core/decoder.cpp
        core/renderer.cpp
        core/audio_output.cpp
        core/subtitle_manager.cpp
        core/sync.cpp
        ui/controls.cpp
        ui/gui.cpp
        utils/logger.cpp
        utils/config.cpp
        utils/timer.cpp
)

target_link_libraries(video_player
        SDL2main SDL2
        avformat avcodec avutil swscale swresample
)