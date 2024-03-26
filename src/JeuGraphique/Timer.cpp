#include "Timer.h"
#include <iostream>

void Timer::start() {
    started = true;
    paused = false;
    debut_timer = SDL_GetTicks();
    debut_pause = 0;
}

void Timer::stop() {
    started = false;
    paused = false;
    debut_timer = 0;
    debut_pause = 0;
}

void Timer::pause() {
    if (started && !paused) {
        paused = true;
        debut_pause = SDL_GetTicks() - debut_timer;
    }
}

void Timer::unpause() {
    if (started && paused) {
        paused = false;
        debut_timer = SDL_GetTicks() - debut_pause;
        debut_pause = 0;
    }
}

int Timer::temps_timer() {
    if (started) {
        if (paused) {
            return debut_pause;
        } else {
            return SDL_GetTicks() - debut_timer;
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