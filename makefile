all:bin/main

bin/main: obj/main.o obj/Bloc.o obj/Grille.o obj/Bombe.o obj/Joueur.o
	g++ -Wall -o bin/main obj/main.o obj/Bloc.o obj/Grille.o obj/Bombe.o obj/Joueur.o

obj/main.o: src/main.cpp src/Bloc.h src/Grille.h src/Bombe.h src/Joueur.h
	g++ -Wall -c src/main.cpp -o obj/main.o

obj/Bloc.o: src/Bloc.cpp src/Bloc.h
	g++ -Wall -c src/Bloc.cpp -o obj/Bloc.o

obj/Grille.o: src/Grille.cpp src/Bloc.h src/Grille.h
	g++ -Wall -c src/Grille.cpp -o obj/Grille.o

obj/Bombe.o: src/Bombe.cpp src/Bombe.h
	g++ -Wall -c src/Bombe.cpp -o obj/Bombe.o

obj/Joueur.o: src/Joueur.cpp src/Joueur.h
	g++ -Wall -c src/Joueur.cpp obj/Joueur.o

clean:
	rm bin/* obj/*
