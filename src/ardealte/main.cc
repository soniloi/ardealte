#include <iostream>

#include "ardealte/main.h"
#include "ardealte/puzzle.h"

int main() {

	const int size = 5;
	bool * pattern = new bool[size * size] {
		false, true, true, true, false,
		false, true, false, true, false,
		true, true, true, true, true,
		false, true, true, false, true,
		false, false, true, true, true
	};

	Puzzle puzzle(size, pattern);

	std::cout << puzzle.getDisplayNumbersStr();
	std::cout << puzzle.getEntriesStr();

	delete [] pattern;

	return 0;
}
