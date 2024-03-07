#ifndef _EXPLOSION_H
#define _EXPLOSION_H

class Explosion {
    private:
        int x;
        int y;
        int timer;

    public:
        Explosion() : x(0), y(0), timer(3) {};
        Explosion(int xpos, int ypos);

        int getPosX();
        int getPosY();

        void avancerTemps();
        bool estActif();
};

#endif