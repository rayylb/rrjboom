#ifndef _BOMBE_H
#define _BOMBE_H

class Bombe {
    private:
        int x;
        int y;
        int range;
        int timer;
    
    public:
        Bombe();
        Bombe(int xpos, int ypos, int flamerange);

        /**
         * @brief Avance d'une unité de temps, jusqu'à l'explosion.
        */
        void avancerTemps();

        bool estExplosee();
};

#endif