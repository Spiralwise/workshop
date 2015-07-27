CC=g++
CFLAGS=-W -Wall -g -ansi -pedantic -std=c++11 -I/usr/local/include -I./include
LDFLAGS=-L /usr/local/lib -lGL -lGLEW -lX11 -lglfw
EXEC=opengl-simple
OBJECTS = opengl-simple.o 

all: $(EXEC)

$(EXEC) : $(OBJECTS) 
	$(CC) -o $(EXEC) $(CFLAGS) $(LDFLAGS) $(OBJECTS)

%.o: %.cpp
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	rm -rf *.o

purge: clean
	rm -rf $(EXEC)

