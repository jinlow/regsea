CC=gcc
CFLAGS=-I.
SRC = src

_DEPS = mxdata.h
_OBJ = test_run.o mxdata.o

DEPS = $(patsubst %,$(SRC)/%,$(_DEPS))
OBJ = $(patsubst %,$(SRC)/%,$(_OBJ))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make_regc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
