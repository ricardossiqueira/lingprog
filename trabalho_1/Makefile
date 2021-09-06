# Makefile template
# Ricardo Santos Siqueira

CC = g++
LD = g++

CFLAGS = -Wall
LFLAGS = -Wall

PATH_TO_PYTHON_DEV = /home/ricardoss/.asdf/installs/python/3.9-dev/include/python3.9
PYTHON_DEV_VERSION = python3.9

PYFLAGS = -I$(PATH_TO_PYTHON_DEV) -l$(PYTHON_DEV_VERSION)

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
