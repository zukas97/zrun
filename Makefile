LIBS = -lfltk
CFLAGS = -ggdb -Wall

build:
	g++ -c ./src/main.cpp $(LIBS) $(CFLAGS) -o main.o
	g++ -c ./src/init.cpp $(LIBS) $(CFLAGS) -o init.o
	g++ -c ./src/backend.cpp $(LIBS) $(CFLAGS) -o backend.o
	g++ main.o init.o backend.o $(LIBS) $(CFLAGS) -o zrun
	rm *.o
