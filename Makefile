build:
	g++ -Wall -framework GLUT -framework OpenGL -framework Cocoa -o main main.cpp

build.run:
	g++ -Wall -framework GLUT -framework OpenGL -framework Cocoa -o main main.cpp
	./main
