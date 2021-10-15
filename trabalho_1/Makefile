# Makefile template
# Ricardo Santos Siqueira

CC = g++
LD = $(CC)

CFLAGS = -Wall 
LFLAGS = $(CFLAGS)

OBJS = main.o Menu.o FileResolver.o

TARGET = main

FileResolver.o: FileResolver.cpp
	$(CC) $(CFLAGS) -c FileResolver.cpp

Menu.o: Menu.cpp
	$(CC) $(CFLAGS) -c Menu.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) -o $(TARGET) $(OBJS) 

clean:
	rm $(OBJS) $(TARGET)

test:
	make all; ./main; make clean
