# Makefile template
# Ricardo Santos Siqueira

CC = g++
LD = $(CC)

CFLAGS = -Wall 
LFLAGS = $(CFLAGS)

OBJS = main.o

TARGET = main

main.o: main.cpp
	$(CC) $(CFLAGS) $(PYFLAGS) -c main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) $(PYFLAGS) -o $(TARGET) $(OBJS) 

clean:
	rm $(OBJS) $(TARGET)

test:
	make all; ./main; make clean
