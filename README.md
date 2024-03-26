# RRJBoom 💣  
Jeu Bomberman à 2 joueurs en version Textuel et Graphique.  
Réalisé dans le cadre de l'UE LIFAPCD.  
  
Graphical interface with SDL2.  
Build with CMake.  
Documentation with Doxygen.  
  
## Build  
``cd rrjboom/build``  
``cmake ..``  
``make``  
  
## Run  
Text version:  
``cd rrjboom/build``  
``./BombTex``  
  
Graphical version:  
``cd rrjboom/build``  
``./BombGraph``  

Fast launch:  
``make -j 8 && ./BombGraph``  
  
## Doc  
``cd rrjboom``  
``doxygen doc/doxyfile``  
``firefox doc/html/index.html``  