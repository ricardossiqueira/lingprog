# Makefile template
# Ricardo Santos Siqueira

CC = g++
LD = $(CC)

CFLAGS = -Wall 
LFLAGS = $(CFLAGS)

OBJS = main.o Filme.o Catalogo.o helperFunctions.o

TARGET = main

helperFunctions.o: helperFunctions.cpp
	$(CC) $(CFLAGS) $(PYFLAGS) -c helperFunctions.cpp

Catalogo.o: Catalogo.cpp
	$(CC) $(CFLAGS) $(PYFLAGS) -c Catalogo.cpp

Filme.o: Filme.cpp
	$(CC) $(CFLAGS) $(PYFLAGS) -c Filme.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) $(PYFLAGS) -c main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) $(PYFLAGS) -o $(TARGET) $(OBJS) 

clean:
	rm $(OBJS) $(TARGET)

test:
	make all; ./main; make clean
