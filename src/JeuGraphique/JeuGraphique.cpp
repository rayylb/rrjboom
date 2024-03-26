#include "JeuGraphique.h"
#include <iostream>

void JeuGraphique::jeuRectangle() {
    affichage.initFenetre(800, 600);
    SDL_Event event;
    bool running = true;
    int recX = 100;
    int recY = 100;
    int movX = 0;
    int movY = 0;
    while(running) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT : running = false; break;
                case SDL_KEYDOWN :
                    switch (event.key.keysym.sym) {
                        case SDLK_UP : movY = -1; break;
                        case SDLK_DOWN : movY = +1; break;
                        case SDLK_LEFT : movX = -1; break;
                        case SDLK_RIGHT : movX = +1; break;
                    }
                    break;
                case SDL_KEYUP :
                    switch (event.key.keysym.sym) {
                        case SDLK_UP : if(movY<0) movY = 0; break;
                        case SDLK_DOWN : if(movY>0) movY = 0; break;
                        case SDLK_LEFT : if(movX<0) movX = 0; break;
                        case SDLK_RIGHT : if(movX>0) movX = 0; break;
                    }
                    break;
                }
        }
        if (recX + movX >= 0 && recX + movX <= 800-100) {
            recX += (2*movX);
        }
        if (recY + movY >= 0 && recY + movY <= 600-100) {
            recY += (2*movY);
        }
        affichage.afficherRectangle(recX, recY, 100, 100);
        SDL_Delay(16);
    }
    affichage.detruireFenetre();
}

void JeuGraphique::jeuSprite() {
    jeu.initPartie();
    int dimX = jeu.getGrille().getDimX();
    int dimY = jeu.getGrille().getDimY();
    affichage.initFenetre(800, 600);
    SDL_Event event;
    bool running = true;
    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                running = false;
            }
        }
        for(int i = 0; i < dimX; i++) {
            for(int j = 0; j < dimY; j++) {
                int type_bloc = jeu.getGrille().infoCase(i, j).getType();
                affichage.afficherSprite(i, j, type_bloc, 64);
            }
        }
        SDL_Delay(16);
    }
    affichage.detruireFenetre();
}

void JeuGraphique::boucleJeuMain() {
    nouvellePartie(64);
}

void JeuGraphique::nouvellePartie(int taille_bloc) {
    joueur1movX = 0;
    joueur1movY = 0;
    joueur2movX = 0;
    joueur2movY = 0;
    jeu.initPartie();
    affichage.initFenetre(jeu.getGrille().getDimX()*taille_bloc, jeu.getGrille().getDimY()*taille_bloc);
    afficherPartie(taille_bloc);
    bool running = true;
    while(running) {
        tourDeJeu(running);
        afficherPartie(taille_bloc);
        SDL_Delay(33);
    }
}

void JeuGraphique::afficherPartie(int taille_bloc) {
    affichage.clearRendu();
    int dimX = jeu.getGrille().getDimX();
    int dimY = jeu.getGrille().getDimY();
    for(int i = 0; i < dimX; i++) {
        for(int j = 0; j < dimY; j++) {
            int type_bloc = jeu.getGrille().infoCase(i, j).getType();
            affichage.afficherSprite(i, j, type_bloc, taille_bloc);
        }
    }
    float J1X = jeu.getJoueur1().getExactX();
    float J1Y = jeu.getJoueur1().getExactY();
    affichage.afficherSprite(J1X, J1Y, 3, taille_bloc);
    float J2X = jeu.getJoueur2().getExactX();
    float J2Y = jeu.getJoueur2().getExactY();
    affichage.afficherSprite(J2X, J2Y, 4, taille_bloc);
    for(int i = 0; i < jeu.getBombes().size(); i++)
        affichage.afficherSprite(jeu.getBombes().at(i).getPosX(), jeu.getBombes().at(i).getPosY(), 5, taille_bloc);
    for(int i = 0; i < jeu.getExplosions().size(); i++)
        affichage.afficherRectangle(jeu.getExplosions().at(i).getPosX()*taille_bloc, jeu.getExplosions().at(i).getPosY()*taille_bloc, taille_bloc, taille_bloc);
    affichage.afficherRendu();
}

void JeuGraphique::tourDeJeu(bool& stillRunning) {
    char movJ1 = ' ';
    char bombJ1 = ' ';
    char movJ2 = ' ';
    char bombJ2 = ' ';
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT : stillRunning = false; break;
                case SDL_KEYDOWN :
                    switch (event.key.keysym.sym) {
                        case SDLK_z : joueur1movY = -1; break;
                        case SDLK_s : joueur1movY = +1; break;
                        case SDLK_q : joueur1movX = -1; break;
                        case SDLK_d : joueur1movX = +1; break;
                    }
                    switch (event.key.keysym.sym) {
                        case SDLK_UP : joueur2movY = -1; break;
                        case SDLK_DOWN : joueur2movY = +1; break;
                        case SDLK_LEFT : joueur2movX = -1; break;
                        case SDLK_RIGHT : joueur2movX = +1; break;
                    }
                    if(event.key.keysym.sym == SDLK_SPACE)
                        bombJ1 = 'X';
                    if(event.key.keysym.sym == SDLK_0)
                        bombJ2 = 'X';
                    break;
                case SDL_KEYUP :
                    switch (event.key.keysym.sym) {
                        case SDLK_z : if(joueur1movY<0) joueur1movY = 0; break;
                        case SDLK_s : if(joueur1movY>0) joueur1movY = 0; break;
                        case SDLK_q : if(joueur1movX<0) joueur1movX = 0; break;
                        case SDLK_d : if(joueur1movX>0) joueur1movX = 0; break;
                    }
                    switch (event.key.keysym.sym) {
                        case SDLK_UP : if(joueur2movY<0) joueur2movY = 0; break;
                        case SDLK_DOWN : if(joueur2movY>0) joueur2movY = 0; break;
                        case SDLK_LEFT : if(joueur2movX<0) joueur2movX = 0; break;
                        case SDLK_RIGHT : if(joueur2movX>0) joueur2movX = 0; break;
                    }
                    break;
            }
    }
    convertirTouches(joueur1movX, joueur1movY, movJ1);
    convertirTouches(joueur2movX, joueur2movY, movJ2);
    jeu.actionsJoueurs(movJ1, bombJ1, movJ2, bombJ2);
    jeu.avancerPartie();
    if((!jeu.getJoueur1().estVivant()) || (!jeu.getJoueur2().estVivant()))
        stillRunning = false;
}

void JeuGraphique::convertirTouches(int joueurMovX, int joueurMovY, char& mov) {
    if(joueurMovX == 1)
        mov = 'R';
    if(joueurMovX == -1)
        mov = 'L';
    if(joueurMovY == 1)
        mov = 'D';
    if(joueurMovY == -1)
        mov = 'U';
}