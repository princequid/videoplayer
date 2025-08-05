#ifndef SYNC_H
#define SYNC_H

class Sync {
public:
    Sync();
    void initialize(double frameRate);
    void waitForVideoFrame(double pts);
    void waitForAudioFrame(double pts);

private:
    double frameRate;
    double lastVideoPts;
};

#endif