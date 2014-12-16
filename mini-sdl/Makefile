CPP=gcc
CFLAGS=-O3
INCFLAGS=-I/usr/local/include
LDFLAGS=-L/usr/local/lib -lSDL -lSDL_image -lfmodex64-4.44.49
EXEC=minisdl

all: ${EXEC}

${EXEC}: ${EXEC}.o
	${CPP} $(CFLAGS) -o ${EXEC} ${EXEC}.o ${LDFLAGS}

${EXEC}.o: main.c
	${CPP} $(CFLAGS) -o ${EXEC}.o -c main.c ${INCFLAGS}

clean:	
	rm -fr *.o

mrproper: clean
	rm -fr ${EXEC}
