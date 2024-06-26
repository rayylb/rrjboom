cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

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
    src/Core/Bonus.h
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
    src/JeuGraphique/Button.h
    src/JeuGraphique/AffichageGraphique.cpp
    src/JeuGraphique/AffichageGraphique.h
    src/JeuGraphique/JeuGraphique.cpp
    src/JeuGraphique/JeuGraphique.h
    src/JeuGraphique/Timer.cpp
    src/JeuGraphique/Timer.h
    src/JeuGraphique/main.cpp
    )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_executable(BombTex ${SRCS_CORE} ${HEADERS_CORE} ${TEXT})
add_executable(BombGraph ${SRCS_CORE} ${HEADERS_CORE} ${GRAPH})

target_include_directories(BombGraph PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
    )

if(WIN32) # Windows
    target_link_libraries(BombGraph PRIVATE 
        SDL2::SDL2main
        SDL2::SDL2
        SDL2_ttf::SDL2_ttf
        SDL2_image::SDL2_image;
        SDL2_mixer::SDL2_mixer;
    )
else() # Apple & Linux     
    target_link_libraries(BombGraph PRIVATE 
        SDL2
        SDL2_ttf
        SDL2_image
        SDL2_mixer
    )
endif()
