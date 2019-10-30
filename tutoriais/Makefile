flags = -lglut -lGLU -lGL -Wall

all: build

run: build
	./run

build: 1-PrintBasicShapes.o 2-Animation.o 3-MouseClick.o

1-PrintBasicShapes.o: 1-PrintBasicShapes.cpp
	@g++ 1-PrintBasicShapes.cpp -o run1 $(flags)

2-Animation.o: 2-Animation.cpp
	@g++ 2-Animation.cpp -o run2 $(flags)

3-MouseClick.o: 3-MouseClick.cpp
	@g++ 3-MouseClick.cpp -o run3 $(flags)

clean:
	@rm run* *.o
