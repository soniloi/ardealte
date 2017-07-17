#include <iostream>

#include "../../include/ardealte/main.h"
#include "../../include/ardealte/puzzle.h"

int main() {

	const int size = 5;

	Puzzle puzzle(size);
	puzzle.print();

	std::cout << std::endl;

	bool **pattern = new bool*[size];
	for (int i = 0; i < size; ++i) {
		pattern[i] = new bool[size]{true, false, true, true, false};
	}
	puzzle.init(pattern);
	puzzle.print();

	return 0;
}
