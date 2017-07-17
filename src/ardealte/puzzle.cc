#include <iostream>
#include <string>

#include "ardealte/puzzle.h"

Puzzle::Puzzle(unsigned int size, bool * pattern) {

	this->size = size;

	for (unsigned int i = 0; i < size; ++i) {
		this->tiles.push_back(std::vector<Tile>());

		for (unsigned int j = 0; j < size; ++j) {

			Tile tile(pattern[i * size + j]);
			this->tiles[i].push_back(tile);
		}
	}
}

Puzzle::~Puzzle() {
}

std::ostream& operator <<(std::ostream& stream, const Puzzle& puzzle) {

	for (unsigned int i = 0; i < puzzle.size; ++i) {

		for (unsigned int j = 0; j < puzzle.size; ++j) {
			stream << puzzle.tiles[i][j];
		}

		stream << std::endl;
	}

	return stream;
}
