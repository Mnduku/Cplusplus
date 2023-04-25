output: menu.o courselist.o course.o student.o
	g++ courselist.o menu.o student.o course.o -o School

menu.o: menu.cpp
	g++ -c menu.cpp

courselist.o: courselist.h courselist.cpp
	g++ -c courselist.cpp

course.o: course.h course.cpp
	g++ -c course.cpp

student.o: student.h student.cpp
	g++ -c student.cpp
target:
	rm *.o
