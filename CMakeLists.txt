cmake_minimum_required(VERSION 3.0)

project(Bomberman)

set(SRCS
    src/main.cpp
    src/Bloc.cpp
    src/Grille.cpp
    src/Bombe.cpp
    )
    
set(HEADERS
    src/Bloc.h
    src/Grille.h
    src/Bombe.h
    )

add_executable(Bomberman ${SRCS} ${HEADERS})