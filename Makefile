CC = gcc
CFLAGS = -g -O2 -c


LDFLAGS = -g -Wall 
EXE = ap

C_FILES:= $(wildcard src/*.c)
OBJ_FILES:= $(patsubst src/%.c,bin/%.o,$(C_FILES))

default: all

all: bin $(OBJ_FILES) $(EXE)

bin:
	mkdir -p bin


bin/%.o : src/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ $<

$(EXE) : $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ $(GRAPHICS_LIBS) -o $(EXE) -lm