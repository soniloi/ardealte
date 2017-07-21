#include <iostream>

#include "ardealte/dictionary.h"
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

	Dictionary dictionary;

	Puzzle puzzle(size, pattern, &dictionary);

	std::cout << puzzle.getDisplayNumbersStr();
	std::cout << puzzle.getEntriesStr();

	delete [] pattern;

	return 0;
}
