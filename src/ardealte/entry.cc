#include "ardealte/entry.h"

Entry::Entry(unsigned int entry_index, Direction direction, std::vector<Tile *> tiles) {
	this->entry_index = entry_index;
	this->direction = direction;
	this->tiles = tiles;
	this->complete = false;

	for (auto it = this->tiles.begin(); it != this->tiles.end(); it++) {
		(*it)->setEntry(this, direction);
	}
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

bool Entry::isComplete() const {
	return this->complete;
}

void Entry::setComplete(bool complete) {
	this->complete = complete;
}

std::string Entry::getSolution() const {
	std::string solution;
	for (unsigned int i = 0; i < this->tiles.size(); ++i) {
		solution += tiles[i]->getLetter();
	}
	return solution;
}

void Entry::setSolution(std::string solution) {
	assert(solution.length() == this->tiles.size());
	for (unsigned int i = 0; i < solution.length(); ++i) {
		tiles[i]->setLetter(solution[i]);
	}
}

void Entry::clearUniqueTiles() {
	for (auto it = this->tiles.begin(); it != this->tiles.end(); it++) {
		Tile * tile = (*it);
		Entry * crossEntry = this->getCrossEntry(tile);
		if (!crossEntry) {
			tile->resetLetter();
		}
	}
}

std::vector<Entry *> Entry::getCrossings() {

	std::vector<Entry *> crossings;
	for (auto it = this->tiles.begin(); it != this->tiles.end(); it++) {
		Entry * crossEntry = this->getCrossEntry(*it);
		if (crossEntry) {
			crossings.push_back(crossEntry);
		}
	}

	return crossings;
}

Entry * Entry::getCrossEntry(Tile * intersection) {

	Direction crossDirection = Direction::ACROSS;
	if (this->direction == Direction::ACROSS) {
		crossDirection = Direction::DOWN;
	}

	return intersection->getEntry(crossDirection);
}