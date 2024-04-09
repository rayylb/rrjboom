#include "JeuGraphique.h"
#include <iostream>

JeuGraphique::JeuGraphique() {
    joueur1movX = 0;
    joueur1movY = 0;
    joueur2movX = 0;
    joueur2movY = 0;
    taille_grille = 1;
}

void JeuGraphique::boucleJeuMain() {
    bool quit = false;
    while(!quit) {
        bool play = boucleMenu(quit);
        if(play && !quit)
            nouvellePartie(64, quit);
    }
}

bool JeuGraphique::boucleMenu(bool& mainQuit) {
    int dimX = 800;
    int dimY = 600;
    affichage.initFenetre(dimX, dimY);

    SDL_Rect r; //DIMENSIONS BOUTON
    r.w = dimX * 0.5;
    r.h = dimY / 6;
    r.x = (dimX / 2) - (r.w / 2);
    r.y = dimY*0.35;
    SDL_Color colorFront = {0, 0, 0, 255};
    SDL_Color colorBack = {255, 255, 100, 255};
    SDL_Color colorRect = {255, 0, 0, 255};

    Button buttons[3];
    for(int i = 0; i < 3; i++) {
        buttons[i].textColor = colorFront;
        buttons[i].backColor = colorBack;
        buttons[i].rectColor = colorRect;
    }
    buttons[0].text = "Play";
    buttons[0].rect = r;
    r.y = dimY * 0.55;
    r.w = dimX * 0.8;
    r.x = (dimX / 2) - (r.w / 2);
    switch (taille_grille) {
        case 1 : buttons[1].text = "Grille : petite"; break;
        case 2 : buttons[1].text = "Grille : moyenne"; break;
        case 3 : buttons[1].text = "Grille : grande"; break;
        default : buttons[1].text = "Grille : petite"; break;
    }
    buttons[1].rect = r;
    r.y = dimY*0.75;
    r.w = dimX * 0.5;
    r.x = (dimX / 2) - (r.w / 2);
    buttons[2].text = "Quit";
    buttons[2].rect = r;
    
    bool quit = false;
    SDL_Event event;
    int x, y;
    
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                affichage.detruireFenetre();
                mainQuit = true;
                return false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE: affichage.detruireFenetre();
                        mainQuit = true;
                        return false;
                        break;
                    default: break;
                }
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&x, &y);
                SDL_Point p = {x, y};
                for (int i = 0; i < 3; i++) {
                    if (SDL_PointInRect(&p, &buttons[i].rect)) {
                        if (i == 0) {
                            affichage.detruireFenetre();
                            return true;
                        }
                        else if (i==1) {
                            switch (taille_grille) {
                                case 1 : taille_grille = 2; buttons[1].text = "Grille : moyenne"; break;
                                case 2 : taille_grille = 3; buttons[1].text = "Grille : grande"; break;
                                case 3 : taille_grille = 1; buttons[1].text = "Grille : petite"; break;
                                default : break;
                            }
                        }
                        else if (i == 2) {
                            affichage.detruireFenetre();
                            mainQuit = true;
                            return false;
                        }
                    }
                }
            }
        }
        afficherMenu(buttons);
    }
    affichage.detruireFenetre();
    mainQuit = true;
    return false;
}

void JeuGraphique::nouvellePartie(int taille_bloc, bool& mainQuit) {
    int dimX = (((GRILLE_DIMX_MAX - 1) / 3) * taille_grille) + 1; 
    int dimY = (((GRILLE_DIMY_MAX - 1) / 3) * taille_grille) + 1; 
    jeu.initPartie(dimX, dimY);
    affichage.initFenetre(jeu.getGrille().getDimX()*taille_bloc, (jeu.getGrille().getDimY()*taille_bloc)+100);
    timer.start();
    joueur1movX = 0;
    joueur1movY = 0;
    joueur2movX = 0;
    joueur2movY = 0;
    Button affTemps;
    affTemps.rect.x = (affichage.getDimX()/2) - 100;
    affTemps.rect.y = affichage.getDimY() - 90;
    affTemps.rect.w = 200;
    affTemps.rect.h = 80;
    affTemps.text = "0:00";
    affTemps.rectColor = {255, 255, 255, 255};
    affTemps.backColor = {200, 200, 255, 255};
    affTemps.textColor = {255, 255, 255, 255};
    
    bool running = true;
    SDL_Event event;
    afficherPartie(taille_bloc, affTemps);
    affichage.jouerMusique();
    while(running) {
        tourDeJeu(running, mainQuit);
        afficherPartie(taille_bloc, affTemps);
        SDL_Delay(33);
        while(timer.isPaused()) {
            afficherPartie(taille_bloc, affTemps);
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    timer.unpause();
                    running = false;
                    mainQuit = true;
                }
                if (event.type == SDL_KEYDOWN) {
                    if (event.key.keysym.sym == SDLK_p)
                        timer.unpause();
                }
            }
        }
        if((taille_grille*60)-(timer.tempsTimer()/1000) < 0)
            running = false;
    }
    if(!mainQuit) finDePartie(mainQuit);
    affichage.detruireFenetre();
}

void JeuGraphique::finDePartie(bool& mainQuit) {
    SDL_Color colorFront = {0, 0, 0, 255};
    SDL_Color colorBack = {255, 255, 100, 255};
    SDL_Color colorRect = {255, 0, 0, 255};
    int dimX = affichage.getDimX();
    int dimY = affichage.getDimY();

    Button buttons[3];
    for(int i = 0; i < 3; i++) {
        buttons[i].textColor = colorFront;
        buttons[i].backColor = colorBack;
        buttons[i].rectColor = colorRect;
    }
    buttons[0].rectColor = colorBack;
    buttons[0].rect.x = affichage.getDimX() * 0.1;
    buttons[0].rect.y = affichage.getDimY() * 0.2;
    buttons[0].rect.w = affichage.getDimX() * 0.8;
    buttons[0].rect.h = affichage.getDimY() * 0.2;
    if(jeu.getJoueur1().estVivant() == jeu.getJoueur2().estVivant()) 
        buttons[0].text = "Draw game...";
    else if (!jeu.getJoueur1().estVivant())
        buttons[0].text = "Player 2 won!";
    else
        buttons[0].text = "Player 1 won!";
    buttons[1].rect.w = dimX * 0.5;
    buttons[1].rect.h = dimY / 6;
    buttons[1].rect.x = (dimX / 4);
    buttons[1].rect.y = dimY*0.5;
    buttons[1].text = "Replay";
    buttons[2].rect.w = dimX * 0.5;
    buttons[2].rect.h = dimY / 6;
    buttons[2].rect.x = (dimX / 4);
    buttons[2].rect.y = dimY*0.7;
    buttons[2].text = "Quit";
    
    SDL_Color fond = {255, 255, 200, 255};
    bool quit = false;
    SDL_Event event;
    int x, y;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {quit = true; mainQuit = true;}
            if (event.type == SDL_KEYDOWN) {
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {quit = true; mainQuit = true;}
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&x, &y);
                SDL_Point p = {x, y};
                for (int i = 1; i < 3; i++) {
                    if (SDL_PointInRect(&p, &buttons[i].rect)) {
                        if (i==1) {
                            quit = true;
                        }
                        else if (i==2) {
                            quit = true;
                            mainQuit = true;
                        }
                    }
                }
            }
        }
        affichage.clearRendu(fond);
        affichage.afficherTexte(buttons[0]);
        affichage.afficherTexte(buttons[1]);
        affichage.afficherTexte(buttons[2]);
        affichage.afficherRectangle(buttons[0].rect, buttons[0].rectColor);
        affichage.afficherRectangle(buttons[1].rect, buttons[1].rectColor);
        affichage.afficherRectangle(buttons[2].rect, buttons[2].rectColor);
        affichage.afficherRendu();
    }
}

void JeuGraphique::tourDeJeu(bool& stillRunning, bool& mainQuit) {
    char movJ1 = ' ';
    char bombJ1 = ' ';
    char movJ2 = ' ';
    char bombJ2 = ' ';
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT : stillRunning = false; mainQuit = true; break;
                case SDL_KEYDOWN :
                    if(event.key.keysym.sym == SDLK_p) timer.pause();
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

void JeuGraphique::afficherMenu(Button buttons[]) {
    SDL_Color fond = {255, 255, 200, 255};
    affichage.clearRendu(fond);
    affichage.afficherTexte(buttons[0]);
    affichage.afficherTexte(buttons[1]);
    affichage.afficherTexte(buttons[2]);
    affichage.afficherRectangle(buttons[0].rect, buttons[0].rectColor);
    affichage.afficherRectangle(buttons[1].rect, buttons[1].rectColor);
    affichage.afficherRectangle(buttons[2].rect, buttons[2].rectColor);
    affichage.afficherSprite(0, 0, 14, 0);
    affichage.afficherRendu();
}

void JeuGraphique::afficherPartie(int taille_bloc, Button affTemps) {
    affichage.clearRendu();

    //AFFICHAGE GRILLE
    int dimX = jeu.getGrille().getDimX();
    int dimY = jeu.getGrille().getDimY();
    for(int i = 0; i < dimX; i++) {
        for(int j = 0; j < dimY; j++) {
            int type_bloc = jeu.getGrille().infoCase(i, j).typeBloc();
            affichage.afficherSprite(i, j, type_bloc, taille_bloc);
        }
    }
    Bloc testCase;
    for(int i = 0; i < jeu.getExplosions().size(); i++) {
        testCase = jeu.getGrille().infoCase(jeu.getExplosions().at(i).getPosX(), jeu.getExplosions().at(i).getPosY());
        if(testCase.estDestructible() || testCase.onPeutMarcher())
            affichage.afficherSprite(jeu.getExplosions().at(i).getPosX(), jeu.getExplosions().at(i).getPosY(), 5, taille_bloc);
    }
    for(int i = 0; i < jeu.getBombes().size(); i++)
        affichage.afficherSprite(jeu.getBombes().at(i).getPosX(), jeu.getBombes().at(i).getPosY(), 3, taille_bloc);
    float J1X = jeu.getJoueur1().getExactX();
    float J1Y = jeu.getJoueur1().getExactY();
    affichage.afficherSprite(J1X, J1Y, 6+jeu.getJoueur1().getDirection(), taille_bloc);
    float J2X = jeu.getJoueur2().getExactX();
    float J2Y = jeu.getJoueur2().getExactY();
    affichage.afficherSprite(J2X, J2Y, 6+jeu.getJoueur2().getDirection(), taille_bloc);

    ///AFFICHAGE BANNIERE
    if (timer.isPaused()) {
        affTemps.text = "PAUSE";
    }
    else {
    int secondes = timer.tempsTimer()/1000;
    secondes = (taille_grille*60) - secondes;
    int minutes = secondes/60;
    secondes = secondes%60;
    affTemps.text = std::to_string(minutes) + ":";
    if(secondes < 10)
        affTemps.text = affTemps.text + "0";
    affTemps.text = affTemps.text + std::to_string(secondes);
    }
    affichage.afficherTexte(affTemps);
    affichage.afficherRectangle(affTemps.rect, affTemps.rectColor);

    affichage.afficherRendu();
}

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
    jeu.initPartie(GRILLE_DIMX_MAX, GRILLE_DIMY_MAX);
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
                int type_bloc = jeu.getGrille().infoCase(i, j).typeBloc();
                affichage.afficherSprite(i, j, type_bloc, 64);
            }
        }
        SDL_Delay(16);
    }
    affichage.detruireFenetre();
}