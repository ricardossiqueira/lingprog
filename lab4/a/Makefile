# Makefile template
# Ricardo Santos Siqueira

CC = g++
LD = g++

CFLAGS = -Wall
LFLAGS = -Wall

OBJS = agenda.o contato.o main.o

TARGET = main

# Objs
# file.o: file.cpp file.hpp
# 	$(CC) $(CFLAGS) -c file.cpp

contato.o: contato.cpp contato.hpp
	$(CC) $(CFLAGS) -c contato.cpp

agenda.o: agenda.cpp agenda.hpp
	$(CC) $(CFLAGS) -c agenda.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm $(OBJS) $(TARGET)

test:
	make clean; make all && ./$(TARGET)