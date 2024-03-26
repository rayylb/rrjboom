#ifndef _TIMER_H
#define _TIMER_H
#include <SDL2/SDL.h>

class Timer {
    private:
        int debut_timer;
        int debut_pause;
        bool paused;
        bool started;
    
    public:
        Timer() : debut_timer(0), debut_pause(0), paused(false), started(false) {};
        void start();
        void stop();
        void pause();
        void unpause();
        int temps_timer();
        bool isStarted();
        bool isPaused();

};

#endif