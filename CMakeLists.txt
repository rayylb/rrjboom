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

# Set the path to the custom CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Custom module to find SDL2_image
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(BombTex ${SRCS_CORE} ${HEADERS_CORE} ${TEXT})
add_executable(BombGraph ${SRCS_CORE} ${HEADERS_CORE} ${GRAPH})

# Link against SDL2 and SDL2_image libraries
target_link_libraries(BombTex PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(BombGraph PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
