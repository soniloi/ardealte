#include <iomanip>
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
	std::vector<Entry *> entries = puzzle.getEntries();

	std::cout << puzzle.getDisplayNumbersStr();

	std::cout << std::setw(4) << "Id" << std::setw(4) << "Len" << std::setw(12) << "Solution" << std::setw(18) << "Crossings" << std::endl;
	for (auto it = entries.begin(); it != entries.end(); it++) {
		Entry * entry = (*it);
		std::vector<Entry *> crossEntries = entry->getCrossings();
		std::stringstream ss;
		for (auto jt = crossEntries.begin(); jt != crossEntries.end(); jt++) {
			ss << (*jt)->getId() << " ";
		}
		std::cout << std::setw(4) << entry->getId() << std::setw(4) << entry->getLength() << std::setw(12) << entry->getSolution() << std::setw(18) << ss.str() << std::endl;
	}

	delete [] pattern;

	return 0;
}
