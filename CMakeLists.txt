cmake_minimum_required(VERSION 3.0)

project(Bomberman)

set(SRCS_CORE
    src/Core/Bloc.cpp
    src/Core/Grille.cpp
    src/Core/Bombe.cpp
    src/Core/Explosion.cpp
    src/Core/Joueur.cpp
    src/Core/Partie.cpp
    )
    
set(HEADERS_CORE
    src/Core/Bloc.h
    src/Core/Grille.h
    src/Core/Bombe.h
    src/Core/Explosion.h
    src/Core/Joueur.h
    src/Core/Partie.h
    )

set(TEXT
    src/JeuTextuel/AffichageTexte.cpp
    src/JeuTextuel/AffichageTexte.h
    src/JeuTextuel/main.cpp
    )

set(GRAPH
    src/JeuGraphique/AffichageGraphique.cpp
    src/JeuGraphique/AffichageGraphique.h
    src/JeuGraphique/main.cpp
    )

add_executable(BombTex ${SRCS_CORE} ${HEADERS_CORE} ${TEXT})

#add_executable(BombGraph ${SRCS_CORE} ${HEADERS_CORE} ${GRAPH})