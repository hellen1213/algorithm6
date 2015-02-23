all: Graph.exe

Graph.exe: Graph.o main.o
	g++ Graph.o  main.o -o Graph.exe

Graph.o: Graph.cpp
	g++ -c  Graph.cpp

main.o: main.cpp
	g++  -c  main.cpp

clean:
	rm -f *.o Graph.exe

