flags = -lglut -lGLU -lGL -Wall

all: build

run: build
	./run

build: 1-PrintBasicShapes.o

1-PrintBasicShapes.o: 1-PrintBasicShapes.cpp
	@g++ 1-PrintBasicShapes.cpp -Wall -o run1  $(flags)

clean:
	@rm run* *.o
