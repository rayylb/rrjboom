all:bin/main

bin/main: obj/main.o obj/Bloc.o obj/Grille.o
	g++ -Wall -o bin/main obj/main.o obj/Bloc.o obj/Grille.obj

obj/main.o: src/main.cpp src/Bloc.h src/Grille.h
	g++ -Wall -c src/main.cpp -o obj/main.o

obj/Bloc.o: src/Bloc.cpp src/Bloc.h
	g++ -Wall -c src/main.cpp -o obj/main.o

obj/Grille.o: src/Grille.cpp src/Bloc.h src/Grille.h
	g++ -Wall -c src/main.cpp -o obj/main.o