#include <iostream>

#include "ardealte/simple_dictionary.h"
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

	SimpleDictionary dictionary;
	dictionary.insert("ear");
	dictionary.insert("kin");
	dictionary.insert("run");
	dictionary.insert("sent");
	dictionary.insert("sit");
	dictionary.insert("sneak");
	dictionary.insert("ta");
	dictionary.insert("tea");

	Puzzle puzzle(size, pattern, &dictionary);

	std::cout << puzzle.getDisplayNumbersStr();
	std::cout << puzzle.getEntriesStr();

	delete [] pattern;

	return 0;
}
