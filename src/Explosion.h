#ifndef _EXPLOSION_H
#define _EXPLOSION_H

class Explosion {
    private:
        int x;
        int y;
        int timer;

    public:
        Explosion() : timer(3) {};
        void avancerTemps();
        bool estActif();
};

#endif