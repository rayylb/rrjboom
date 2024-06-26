#ifndef _PARTIE_H
#define _PARTIE_H

#include "Grille.h"
#include "Joueur.h"
#include "Bombe.h"
#include "Bonus.h"
#include "Explosion.h"
#include <vector>

/**
 * @class Partie
 * @brief Classe représentant une partie du jeu.
 * Elle contient une grille et deux joueurs. Elle gère les mouvements de joueurs, ainsi que les bombes et les explosions.
*/

class Partie {
    private:
        Grille grille; //La grille de jeu
        Joueur joueur1; //Le joueur 1
        Joueur joueur2; //Le joueur 2
        std::vector<Bombe> bombes; //La liste des bombes posées sur la grille
        std::vector<Explosion> explosions; //La liste des explosions sur la grille

    public:
        Partie();

        /**
         * @brief Fonction qui initialise une partie de jeu
         */
        void initPartie(int grilleX, int grilleY);        

        /**
         * @brief Procédure permettant aux joueurs de se déplacer et de poser des bombes
         * @param movJ1 Mouvement du joueur 1
         * @param bombJ1 Pose de bombe du joueur 1
         * @param movJ2 Mouvement du joueur 2
         * @param bombJ2 Pose de bombe du joueur 2
         */
        void actionsJoueurs(char movJ1, char bombJ1, char movJ2, char bombJ2);

        /**
         * @brief Procédure qui gère les bombes et les explosions
         */
        void avancerPartie();

        /**
         * @brief Procédure qui gère les explosions des bombes
         * @param source Bombe qui a explosé
         */
        void creerExplosions(Bombe source);

        /**
         * @brief Fonction qui indique si la case de coordonnées (posX, posY) est une case explosée par une bombe
         * @param posX Coordonnée horizontale de la case
         * @param posY Coordonnée verticale de la case
         * @return Un booléen indiquant si la case est explosée
         */   
        bool caseEstExplosee(int posX, int posY);

        /**
         * @brief Fonction qui indique si la case de coordonnées (posX, posY) est une case minée par une bombe
         * @param posX Coordonnée horizontale de la case
         * @param posY Coordonnée verticale de la case
         * @return Un booléen indiquant si la case est minée
         */
        bool caseEstMinee(int posX, int posY);

        /**
         * @brief Fonction qui rajouter une explosion sur la grille et vérifie si elle déclenche d'autre bombes
         * @param posX Coordonnée horizontale de la case
         * @param posY Coordonnée verticale de la case
        */
        void pushExplosion(int posX, int posY);

        /**
         * @brief Fonction qui retourne l'adresse mémoire de la grille de la partie
         * @return Un lien vers la grille de jeu
         */
        Grille& getGrille();

        /**
         * @brief Fonction qui retourne l'adresse mémoire du joueur 1
         * @return Un lien vers le joueur 1
         */        
        Joueur& getJoueur1();

        /**
         * @brief Fonction qui retourne l'adresse mémoire du joueur 2
         * @return Un lien vers le joueur 2
         */        
        Joueur& getJoueur2();

        /**
         * @brief Fonction qui retourne la liste des bombes de la partie
         * @return Un lien vers le vecteur de bombes
         */        
        std::vector<Bombe>& getBombes();

        /**
         * @brief Fonction qui retourne la liste des explosions de la partie
         * @return Un lien vers le vecteur d'explosions
         */
        std::vector<Explosion>& getExplosions();
};

#endif