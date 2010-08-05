include ../Makefile.head

_HDEPS = cosh.h
HDEPS = $(patsubst %,$(INC)/%,$(_DEPS))

DEPS = main.c

_OBJECTS = main.o
OBJECTS = $(patsubst %,$(OBJ)/%,$(_OBJECTS))

all: $(EXE)/cosh

$(EXE)/cosh: $(OBJECTS)
	-test -d $(EXE) || mkdir $(EXE)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

.PHONY: clean

clean:
	\rm -f *~ $(INC)/*~ 
	\rm -f $(OBJ)/*.o 
	\rm -f $(EXE)/cosh
	\rm -f $(EXE)/core

$(OBJ)/%.o: %.c $(HDEPS) $(DEPS)
	-test -d $(OBJ) || mkdir $(OBJ)
	$(CC) $(CFLAGS) -c -o $@ $<

