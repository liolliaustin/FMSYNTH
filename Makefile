CC = g++
CFLAGS = -g -O2 -c


LDFLAGS = -g -Wall 
EXE = ap

CPP_FILES:= $(wildcard hls_module/*.cpp)
OBJ_FILES:= $(patsubst hls_module/%.cpp,bin/%.o,$(C_FILES))

default: all

all: bin $(OBJ_FILES) $(EXE)

bin:
	mkdir -p bin


bin/%.o : src/%.c
	$(CC) $(CPPFLAGS) $(INC) -o $@ $<

$(EXE) : $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ $(GRAPHICS_LIBS) -o $(EXE) -lm