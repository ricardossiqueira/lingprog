# Makefile template
# Ricardo Santos Siqueira

CC = g++
LD = g++

CFLAGS = -Wall
LFLAGS = -Wall

OBJS = Graph.o Edge.o Vertice.o main.o

TARGET = main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Graph.o: Graph.cpp Graph.hpp
	$(CC) $(CFLAGS) -c Graph.cpp

Edge.o: Edge.cpp Edge.hpp
	$(CC) $(CFLAGS) -c Edge.cpp

Vertice.o: Vertice.cpp Vertice.hpp
	$(CC) $(CFLAGS) -c Vertice.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm $(OBJS) $(TARGET)


test:
	make clean; make all && ./main