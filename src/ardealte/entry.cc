#include "ardealte/entry.h"

Entry::Entry(unsigned int entry_index, Direction direction, std::vector<Tile *> tiles) {
	this->entry_index = entry_index;
	this->direction = direction;
	this->tiles = tiles;
}

unsigned int Entry::getLength() const {
	return this->tiles.size();
}

std::string Entry::getId() const {
	std::stringstream ss;
	ss << this->entry_index;
	if (this->direction == Direction::ACROSS) {
		ss << "A";
	} else {
		ss << "D";
	}
	return ss.str();
}

std::string Entry::getSolution() const {
	std::string solution;
	for (unsigned int i = 0; i < this->tiles.size(); ++i) {
		solution += tiles[i]->getLetter();
	}
	return solution;
}

void Entry::setSolution(std::string solution) {
	for (unsigned int i = 0; i < solution.length(); ++i) {
		tiles[i]->setLetter(solution[i]);
	}
}
