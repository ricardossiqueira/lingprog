# Makefile template
# Ricardo Santos Siqueira

CC = g++
LD = g++

CFLAGS = -Wall
LFLAGS = -Wall

OBJS = Relogio.o main.o

TARGET = main

# Objs
# file.o: file.cpp file.hpp
# 	$(CC) $(CFLAGS) -c file.cpp

relogio.o: Relogio.cpp Relogio.hpp
	$(CC) $(CFLAGS) -c Relogio.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm $(OBJS) $(TARGET)

test:
	make clean; make all && ./$(TARGET)
