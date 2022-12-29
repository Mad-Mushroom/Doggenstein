build:
	g++ -Wall -framework GLUT -framework OpenGL -o main main.cpp

build.run:
	g++ -Wall -framework GLUT -framework OpenGL -o main main.cpp
	./main
