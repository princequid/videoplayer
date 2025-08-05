#include "decoder.h"
#include <iostream>

Decoder::Decoder() : formatCtx(nullptr), videoCodecCtx(nullptr), audioCodecCtx(nullptr),
                     videoStreamIndex(-1), audioStreamIndex(-1), frame(nullptr), packet(nullptr),
                     swsCtx(nullptr), swrCtx(nullptr) {}

Decoder::~Decoder() { cleanup(); }

bool Decoder::open(const std::string& filePath) {
    if (avformat_open_input(&formatCtx, filePath.c_str(), nullptr, nullptr) != 0) return false;
    if (avformat_find_stream_info(formatCtx, nullptr) < 0) return false;
    // Find streams (simplified)
    return true;
}

bool Decoder::decodeVideoFrame(uint8_t* data[4], int linesize[4], int* width, int* height) {
    return false; // Placeholder
}

bool Decoder::decodeAudioFrame(uint8_t* data, int* len) {
    return false; // Placeholder
}

void Decoder::cleanup() {
    if (swrCtx) swr_free(&swrCtx);
    if (swsCtx) sws_freeContext(swsCtx);
    if (frame) av_frame_free(&frame);
    if (packet) av_packet_free(&packet);
    if (audioCodecCtx) avcodec_free_context(&audioCodecCtx);
    if (videoCodecCtx) avcodec_free_context(&videoCodecCtx);
    if (formatCtx) avformat_close_input(&formatCtx);
}

void Decoder::seek(double seconds) {
    // Implement seeking
}

void Decoder::stop() {
    // Implement stop
}

int Decoder::getWidth() const { return videoCodecCtx ? videoCodecCtx->width : 0; }
int Decoder::getHeight() const { return videoCodecCtx ? videoCodecCtx->height : 0; }
int Decoder::getSampleRate() const { return audioCodecCtx ? audioCodecCtx->sample_rate : 0; }
int Decoder::getChannels() const { return audioCodecCtx ? audioCodecCtx->ch_layout.nb_channels : 0; }
double Decoder::getFrameRate() const { return videoCodecCtx ? av_q2d(videoCodecCtx->framerate) : 0.0; }