CC = g++
LD = g++

CFLAGS = -Wall
LFLAGS = -Wall

OBJS = helpers.o nacional.o estadual.o main.o

TARGET = trabalho_1

nacional.o: nacional.h nacional.cpp
	$(CC) $(CFLAGS) -c nacional.cpp

estadual.o: estadual.h estadual.cpp
	$(CC) $(CFLAGS) -c estadual.cpp

helpers.o: helpers.h helpers.cpp
	$(CC) $(CFLAGS) -c helpers.cpp

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm $(OBJS) $(TARGET)