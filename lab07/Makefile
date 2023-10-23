FILE = evilhangman
SRC_FILES = Hangman.cpp Evilhangman.cpp main.cpp

build: $(SRC_FILES)
	g++ -std=c++11 -o $(FILE) $(SRC_FILES)

.PHONY: db

db:
	gdb -tui $(FILE)

run:
	./$(FILE)
