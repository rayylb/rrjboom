all:bin/main

bin/main: obj/main.o obj/Bloc.o obj/Grille.o
	g++ -Wall -o bin/main obj/main.o obj/Bloc.o obj/Grille.o

obj/main.o: src/main.cpp src/Bloc.h src/Grille.h
	g++ -Wall -c src/main.cpp -o obj/main.o

obj/Bloc.o: src/Bloc.cpp src/Bloc.h
	g++ -Wall -c src/Bloc.cpp -o obj/Bloc.o

obj/Grille.o: src/Grille.cpp src/Bloc.h src/Grille.h
	g++ -Wall -c src/Grille.cpp -o obj/Grille.o

clean:
	rm bin/* obj/*
