CC = g++
LD = g++

CFLAGS = -Wall
LFLAGS = -Wall

OBJS = helpers.o nacional.o estadual.o main.o

TARGET = trabalho_1

# Regras pro make dos arquivos obj
nacional.o: nacional.hpp nacional.cpp
	$(CC) $(CFLAGS) -c nacional.cpp

estadual.o: estadual.hpp estadual.cpp
	$(CC) $(CFLAGS) -c estadual.cpp

helpers.o: helpers.hpp helpers.cpp
	$(CC) $(CFLAGS) -c helpers.cpp

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

# Regra make all -> target
all: $(TARGET)

# Regra pra make do target
$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) -o $(TARGET) $(OBJS)
	
# Regra pra clean de todos os objs e o target
clean:
	rm $(OBJS) $(TARGET)