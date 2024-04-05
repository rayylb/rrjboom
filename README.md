# RRJBoom 💣  
Jeu Bomberman à 2 joueurs en version Textuel et Graphique.  
Réalisé dans le cadre de l'UE LIFAPCD.  
  
<ins>Compatibilité :</ins>  
Le projet peut être build et run seulement sur Linux.
  
__Outils utilisés :__  
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
``firefox doc/html/index.html``  
