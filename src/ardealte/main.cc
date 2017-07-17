#include <iostream>

#include "../../include/ardealte/main.h"
#include "../../include/ardealte/puzzle.h"

int main() {

	const int size = 5;
	bool **pattern = new bool*[size];
	for (int i = 0; i < size; ++i) {
		pattern[i] = new bool[size]{true, false, true, true, false};
	}

	Puzzle puzzle(size, pattern);
	puzzle.print();

	for (int i = 0; i < size; ++i) {
		delete [] pattern[i];
	}
	delete [] pattern;

	return 0;
}
