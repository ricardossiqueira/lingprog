# Makefile template
# Ricardo Santos Siqueira

CC = g++
LD = g++

CFLAGS = -Wall
LFLAGS = -Wall

OBJS=

TARGET=

# Objs
# file.o: file.cpp file.hpp
# 	$(CC) $(CFLAGS) -c file.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm $(OBJS) $(TARGET)
