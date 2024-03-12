#ifndef _BOMBE_H
#define _BOMBE_H

class Bombe {
    private:
        int x;
        int y;
        int range;
        int timer;
    
    public:
        Bombe() : x(0), y(0), range(1), timer(3) {};
        Bombe(int xpos, int ypos, int flamerange);

        int getPosX();
        int getPosY();
        int getRange();
        
        /**
         * @brief Avance d'une unité de temps, jusqu'à l'explosion.
        */
        void avancerTemps();
        bool estExplosee();
};

#endif