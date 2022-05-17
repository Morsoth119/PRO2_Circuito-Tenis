OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Circuito.o Categoria.o Torneo.o Cjn_Jugadores.o Jugador.o
	g++ -o program.exe program.o Circuito.o Categoria.o Torneo.o Cjn_Jugadores.o Jugador.o $(OPTIONS)

Circuito.o: Circuito.cc Circuito.hh Categoria.hh Torneo.hh
	g++ -c Circuito.cc $(OPTIONS)

Categoria.o: Categoria.cc Categoria.hh
	g++ -c Categoria.cc $(OPTIONS)

Torneo.o: Torneo.cc Torneo.hh Categoria.cc BinTree.hh Cjn_Jugadores.hh
	g++ -c Torneo.cc $(OPTIONS)

Cjn_Jugadores.o: Cjn_Jugadores.cc Cjn_Jugadores.hh Jugador.hh
	g++ -c Cjn_Jugadores.cc $(OPTIONS)

Jugador.o: Jugador.cc Jugador.hh
	g++ -c Jugador.cc $(OPTIONS)

program.o: program.cc Circuito.hh Cjn_Jugadores.hh
	g++ -c program.cc $(OPTIONS)

html.zip: DOXYGEN/html
	zip -r html.zip DOXYGEN/html

practica.tar: html.zip program.cc Circuito.hh Circuito.cc Cjn_Jugadores.hh Cjn_Jugadores.cc Categoria.hh Categoria.cc Torneo.hh Torneo.cc Jugador.hh Jugador.cc BinTree.hh Makefile
	tar -cvf practica.tar html.zip program.cc Circuito.hh Circuito.cc Cjn_Jugadores.hh Cjn_Jugadores.cc Categoria.hh Categoria.cc Torneo.hh Torneo.cc Jugador.hh Jugador.cc BinTree.hh Makefile

clean:
	rm *.o &
	rm *.exe &
	rm html.zip &
	rm practica.tar
