CC=g++
CFLAGS= -std=c++11 -I.
SRC = src

_DEPS = cmdata.h
_OBJ = test_run.o cmdata.o

DEPS = $(patsubst %,$(SRC)/%,$(_DEPS))
OBJ = $(patsubst %,$(SRC)/%,$(_OBJ))

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make_regc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
