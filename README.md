# RRJBoom 💣  
Jeu Bomberman à 2 joueurs en version Textuel et Graphique.  
Réalisé dans le cadre de l'UE LIFAPCD.  
  
<ins>Compatibilité :</ins>  
Le projet peut être build et run sur Linux et Windows 32-bit, à condition d'avoir SDL2, SDL_image, SDL_ttf, et SDL_mixer déjà installé.
  
<ins>Comment jouer ?</ins>  
Menus : cliquez sur les boutons avec la souris.  
En jeu : controlez les joueurs avec le clavier et appuyez sur 'P' pour mettre en pause.  
    Joueur 1 : ZQSD (mouvement) + ESPACE (bombe).  
    Joueur 2 : Flèches (mouvement) + 0 (bombe).  
  
<ins>Outils utilisés :</ins>  
SDL2 pour l'interface graphique.  
CMake pour build le projet.  
Doxygen pour la documentation.  
  
## Build  
``cd rrjboom/build``  
``cmake ..`` (Crée le makefile, pas besoin de le faire à chaque fois.)  
``make``  
  
## Run  
Version textuel :  
``cd rrjboom/build``  
``./BombTex``  
  
Version graphique :  
``cd rrjboom/build``  
``./BombGraph``  

Commande pour build en accéléré + run la version graphique en même temps :  
``make -j 8 && ./BombGraph``  
  
## Documentation  
``cd rrjboom``  
``doxygen doc/doxyfile`` (Génère la doc, pas besoin de le faire à chaque fois.)  
Sous Linux : ``firefox doc/html/index.html``  
Sous Mac : ``open -a firefox doc/html/index.html``
