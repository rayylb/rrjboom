#include "Timer.h"
#include <iostream>

void Timer::start() {
    started = true;
    paused = false;
    debutTimer = SDL_GetTicks();
    debutPause = 0;
}

void Timer::stop() {
    started = false;
    paused = false;
    debutTimer = 0;
    debutPause = 0;
}

void Timer::pause() {
    if (started && !paused) {
        paused = true;
        debutPause = SDL_GetTicks() - debutTimer;
    }
}

void Timer::unpause() {
    if (started && paused) {
        paused = false;
        debutTimer = SDL_GetTicks() - debutPause;
        debutPause = 0;
    }
}

int Timer::tempsTimer() {
    if (started) {
        if (paused) {
            return debutPause;
        } else {
            return SDL_GetTicks() - debutTimer;
        }
    }
    return 0;
}

bool Timer::isStarted() {
    return started;
}

bool Timer::isPaused() {
    return paused;
}