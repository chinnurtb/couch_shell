INC =../inc
OBJ=obj
LIB =../lib
LIBS=-lm

CC=gcc
CFLAGS=-I$(INC) -Wall

_DEPS = cosh.h main.c
DEPS = $(patsubst %,$(INC)/%,$(_DEPS))

_OBJECTS = main.o
OBJECTS = $(patsubst %,$(OBJ)/%,$(_OBJECTS))


$(OBJ)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

all: cosh

cosh: $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $@ $^

.PHONY: clean

clean:
	\rm -f *~ $(INC)/*~ 
	\rm -f $(OBJ)/*.o 
	\rm -f cosh
	\rm -f core
