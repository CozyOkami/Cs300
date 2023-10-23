FILE = lab08
SRC_FILES = lab08.cpp

build: $(SRC_FILES)
	g++ -std=c++11 -o $(FILE) $(SRC_FILES)

.PHONY: db

db:
	gdb -tui $(FILE)

run:
	./$(FILE)
