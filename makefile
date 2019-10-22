compile:
		g++ main.cpp points.cpp -o points

run:
		g++ main.cpp points.cpp -o points
		./points

valgrind: compile
		valgrind --leak-check=yes ./points
