#pragma once

const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;


class FrameRate
{
public:
    void start();
    void delay();

private:
    unsigned _frameStart = 0;
    int _frameTime = 0;
};
