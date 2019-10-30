flags = -lglut -lGLU -lGL -Wall

all: build

run: build
	./run

build: 1-PrintBasicShapes.o 2-Animation.o

1-PrintBasicShapes.o: 1-PrintBasicShapes.cpp
	@g++ 1-PrintBasicShapes.cpp -o run1 $(flags)

2-Animation.o: 2-Animation.cpp
	@g++ 2-Animation.cpp -o run2 $(flags)

clean:
	@rm run* *.o
