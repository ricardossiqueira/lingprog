# Makefile template
# Ricardo Santos Siqueira

CC = g++
LD = $(CC)

CFLAGS = -Wall
LFLAGS = $(CFLAGS)

OBJS = main.o\
			Cadastro.o\
			Paciente.o\
			helperFunctions.o\
			CardioPacient.o\
			PediatricPacient.o\
			AlreadyExistsException.o\
			NotFoundException.o

TARGET = main

AlreadyExistsException.o: AlreadyExistsException.cpp
	$(CC) $(CFLAGS) -c AlreadyExistsException.cpp

NotFoundException.o: NotFoundException.cpp
	$(CC) $(CFLAGS) -c NotFoundException.cpp

CardioPacient.o: CardioPacient.cpp
	$(CC) $(CFLAGS) -c CardioPacient.cpp

helperFunctions.o: helperFunctions.cpp
	$(CC) $(CFLAGS) -c helperFunctions.cpp

Paciente.o: Paciente.cpp
	$(CC) $(CFLAGS) -c Paciente.cpp

Cadastro.o: Cadastro.cpp
	$(CC) $(CFLAGS) -c Cadastro.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) -o $(TARGET) $(OBJS) 

clean:
	rm $(OBJS) $(TARGET)

test:
	make all; ./main; make clean
