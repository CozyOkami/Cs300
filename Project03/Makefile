FILE = project03
SRC_FILES = project03.cpp

build: $(SRC_FILES)
	g++ -std=c++11 -o $(FILE) $(SRC_FILES)

.PHONY: db

db:
	gdb -tui $(FILE)

run:
	./$(FILE)
