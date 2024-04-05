# RRJBoom 💣  
Jeu Bomberman à 2 joueurs en version Textuel et Graphique.  
Réalisé dans le cadre de l'UE LIFAPCD.  
  
<ins>Compatibilité :</ins>  
Le projet peut être build et run sur Linux et Windows 32-bit, à condition d'avoir SDL2 déjà installé.
  
<ins>Outils utilisés :</ins>  
SDL2 pour l'interface graphique.  
CMake pour build le projet.  
Doxygen pour la documentation.  
  
## Build  
``cd rrjboom/build``  
``cmake ..`` (Crée le makefile, pas besoin de le faire à chaque fois.)  
``make``  
  
## Run  
<ins>Version textuel :</ins>  
``cd rrjboom/build``  
``./BombTex``  
  
<ins>Version graphique :</ins>  
``cd rrjboom/build``  
``./BombGraph``  

<ins>Commande pour build en accéléré + run la version graphique en même temps :</ins>  
``make -j 8 && ./BombGraph``  
  
## Documentation  
``cd rrjboom``  
``doxygen doc/doxyfile`` (Génère la doc, pas besoin de le faire à chaque fois.)  
``firefox doc/html/index.html``  
