.PHONY: clean dirs

BIN=bin
SRC=src
OBJ=obj

all: dirs $(BIN)/toeic

$(BIN)/toeic: $(SRC)/main.cpp $(SRC)/problem.h | $(BIN)
	g++ -Wall -std=c++11 $< $(CXXFLAGS) -o $@

dirs:
	mkdir -p $(SRC) $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ) .vscode/

stat:
	wc src/* test/*