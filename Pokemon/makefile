output: map.o pokemon.o game.o
	g++ map.o pokemon.o game.o -o Pokesimulator

game.o: game.cpp
	g++ -c game.cpp

map.o: map.cpp map.h
	g++ -c map.cpp

pokemon.o: pokemon.cpp pokemon.h
	g++ -c pokemon.cpp
clean:
	rm *.o
