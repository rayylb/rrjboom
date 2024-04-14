# RRJBoom 💣  
Bomberman à 2 joueurs en version Textuel et Graphique.  
Réalisé dans le cadre de l'UE LIFAPCD par :  
 - Rayane LABZIZI p2201104  
 - Rym ZERZOUH p2201467  
 - Julien CHATAIGNER p2208504  
  
<ins>Compatibilité :</ins>  
Le projet peut être build et run sur Linux, Mac et Windows 32-bit, à condition d'avoir les outils utilisés déjà installé (voir plus bas.)  
Les commandes listées plus bas marchent seulement sous Mac et Linux, Windows utilise des commandes différentes.  
  
<ins>Outils utilisés :</ins>  
Le code a été ralisé en C++.  
SDL2 pour l'interface graphique (avec les extensions image, ttf, et mixer.)  
CMake pour build le projet.  
Doxygen pour la documentation.  
  
<ins>Organisation du code :</ins>  
 - /data : Où sont rangés les fichiers images, musiques, etc.
 - /doc : Documentation générée avec Doxygen + Diagramme des classes et Présentation pour la soutenance
 - /build : Pour compiler avec CMake, l'exécutable se trouvera dans ce dossier
 - /src : Le code en lui-même, séparé en 3 modules :
   - /src/Core : Le cœur du jeu, qui marche indépendamment de l'interface utilisée
   - /src/JeuTextuel : La version textuel du jeu, qui utilise le Core
   - /src/JeuGraphique : La version graphique du jeu, qui utilise le Core
  
## Comment Jouer  
Ce jeu s'inspire de la célèbre franchise Bomberman. Ici, deux joueurs s'affronte dans un terrain avec comme seul arme des bombes qu'il peuvent poser sur le terrain. Chaque joueur est limité en nombre de bombes et en puissance de bombes, mais ses dernières peuvent détruire des blocs du terrain où se cachent des bonus pour les améliorer !  
Le jeu comporte actuellement 3 types de bonus et 3 tailles de grilles différentes.  
Une partie se termine dès qu'un joueur touche l'explosion d'une bombe ou finit par une égalité si le temps est écoulé.  
  
<ins>Contrôles du jeu :</ins>  
Menus : Cliquez sur les boutons avec la souris.  
En jeu : Contrôlez les joueurs avec le clavier et appuyez sur 'P' pour mettre en pause.  
 - Joueur 1 : ZQSD (mouvement) + ESPACE (bombe).  
 - Joueur 2 : Flèches (mouvement) + 0 (bombe).  
  
## Build le projet  
``cd rrjboom/build``  
``cmake ..`` (Crée le makefile, pas besoin de le faire à chaque fois.)  
``make``  
  
## Exécuter le projet  
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
