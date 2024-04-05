#ifndef _TIMER_H
#define _TIMER_H
#include <SDL2/SDL.h>

/**
* @class Timer
* @brief Classe représentant un timer dans le jeu
* Elle contient deux entiers qui représentent le temps de début du timer et le temps de début de pause, 
* ainsi que deux booléens qui indiquent si le timer a commencé et s'il est en pause
*/

class Timer {
    private:
        int debutTimer; //Le temps de début du timer
        int debutPause; //Le temps de fin du timer
        bool paused; //Indique si le timer est en pause
        bool started; //Indique si le timer a commencé
    
    public:

        Timer() : debutTimer(0), debutPause(0), paused(false), started(false) {};

        /*
        * @brief Fonction qui démarre le timer
        */
        void start();

        /*
        * @brief Fonction qui arrête le timer, en le réinitialisant
        */
        void stop();

        /* 
        * @brief Fonction qui met en pause le timer
        */
        void pause();

        /*
        * @brief Fonction qui enlève la pause du timer
        */
        void unpause();

        /*
        * @brief Fonction qui retourne le temps écoulé depuis le début du timer
        * @return L'entier qui représente le temps écoulé depuis le début du timer
        */
        int tempsTimer();

        /*
        * @brief Fonction qui indique si le timer est démarré
        * @return Le booléen qui indique si le timer est démarré
        */
        bool isStarted();

        /*
        * @brief Fonction qui indique si le timer est en pause
        * @return Le booléen qui indique si le timer est en pause
        */
        bool isPaused();

};

#endif