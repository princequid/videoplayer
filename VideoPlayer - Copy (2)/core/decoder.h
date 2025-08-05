#ifndef DECODER_H
#define DECODER_H

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/imgutils.h>
#include <libavutil/samplefmt.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h> // For swrCtx
}
#include <SDL.h>
#include <string>

class Decoder {
public:
    Decoder();
    ~Decoder(); // Added destructor
    bool open(const std::string& filePath);
    bool decodeVideoFrame(uint8_t* data[4], int linesize[4], int* width, int* height);
    bool decodeAudioFrame(uint8_t* data, int* len);
    void cleanup();
    void seek(double seconds); // Added
    void stop(); // Added
    int getWidth() const; // Added
    int getHeight() const; // Added
    int getSampleRate() const; // Added
    int getChannels() const; // Added
    double getFrameRate() const; // Added

private:
    AVFormatContext* formatCtx;
    AVCodecContext* videoCodecCtx;
    AVCodecContext* audioCodecCtx;
    int videoStreamIndex;
    int audioStreamIndex;
    AVFrame* frame;
    AVPacket* packet;
    SwsContext* swsCtx;
    SwrContext* swrCtx; // Added for audio resampling
};

#endif