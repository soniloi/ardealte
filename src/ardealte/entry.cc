#include "ardealte/entry.h"

Entry::Entry(std::vector<Tile> tiles) {
	this->tiles = tiles;
}

std::string Entry::getSolution() const {
	std::string solution;
	for (unsigned int i = 0; i < this->tiles.size(); ++i) {
		solution += tiles[i].getLetter();
	}
	return solution;
}
