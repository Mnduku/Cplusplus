output: battlebot.o battlebotmain.o
	g++ battlebot.o battlebotmain.o -o battlebots

battlebotmain.o: battlebotmain.cpp
	g++ -c battlebotmain.cpp

battlebot.o: battlebot.cpp battlebot.h
	g++ -c battlebot.cpp
clean:
	rm *.o output
