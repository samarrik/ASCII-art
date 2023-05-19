FLAGS = g++ -Wall -pedantic -std=c++17
HEADERS = $(wildcard src/*.h)
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(wildcard src/*.o)

all: compile doc

compile:
	$(FLAGS) $(SOURCES)

run:

clean:
	rm $(OBJECTS)

doc: Doxyfile $(HEADERS)
	doxygen Doxyfile


#*devnotes
#1. wildcard is a function which replaces a string with strings which have it as a substring
