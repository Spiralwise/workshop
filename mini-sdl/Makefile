CPP=gcc
CFLAGS=-O3
LDFLAGS=-lSDL -lSDL_image
EXEC=minisdl

all: ${EXEC}

${EXEC}: ${EXEC}.o
	${CPP} $(CFLAGS) -o ${EXEC} ${EXEC}.o ${LDFLAGS}

${EXEC}.o: main.c
	${CPP} $(CFLAGS) -o ${EXEC}.o -c main.c

clean:	
	rm -fr *.o

mrproper: clean
	rm -fr ${EXEC}
