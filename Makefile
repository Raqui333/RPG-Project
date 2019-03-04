CXX = clang++
CXXFLAGS = -std=c++17
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
BIN = rpg

all: $(BIN)

rpg: $(OBJ)
	$(CXX) $^ -o $@ $(CXXFLAGS)

.PHONY: clean

clean:
	@rm src/*.o 2> /dev/null
	@rm rpg 2> /dev/null
