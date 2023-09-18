CXX = g++
OBJECTS = trip.cpp trip.h main.cpp
FLAGS = -std=c++20
SOURCE - $(wildcard *.cpp)

demo: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o demo

%.o: %.cpp
	$(CXX) -c $^

run: demo
	./demo

echo:
	echo $(SOURCE)

clean:
	rm-f*.o demo