# Makefile template
# Ricardo Santos Siqueira

CC = g++
LD = $(CC)

CFLAGS = -Wall 
LFLAGS = $(CFLAGS)

OBJS = main.o Cadastro.o Paciente.o

TARGET = main

Paciente.o: Paciente.cpp
	$(CC) $(CFLAGS) $(PYFLAGS) -c Paciente.cpp

Cadastro.o: Cadastro.cpp
	$(CC) $(CFLAGS) $(PYFLAGS) -c Cadastro.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) $(PYFLAGS) -c main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) $(PYFLAGS) -o $(TARGET) $(OBJS) 

clean:
	rm $(OBJS) $(TARGET)

test:
	make all; ./main; make clean
