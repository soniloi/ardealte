#include <iostream>
#include <string>

#include "ardealte/puzzle.h"

Puzzle::Puzzle(unsigned int size, bool * pattern) {

	this->actual_size = size + Puzzle::buffer_size * 2;
	this->visible_size = size;

	this->tiles.push_back(Puzzle::createClosedTileRow(this->actual_size)); // Top buffer row

	for (unsigned int i = 0; i < size; ++i) {

		std::vector<Tile> row;
		row.push_back(Tile(false)); // Left buffer column

		for (unsigned int j = 0; j < size; ++j) {

			Tile tile(pattern[i * size + j]);
			row.push_back(tile);
		}

		row.push_back(Tile(false)); // Right buffer column
		this->tiles.push_back(row);
	}

	this->tiles.push_back(Puzzle::createClosedTileRow(this->actual_size)); // Bottom buffer row
}

Puzzle::~Puzzle() {
}

std::vector<Tile> Puzzle::createClosedTileRow(unsigned int size) {
	std::vector<Tile> row;
	for (unsigned int i = 0; i < size; ++i) {
		row.push_back(Tile(false));
	}
	return row;
}

std::ostream& operator <<(std::ostream& stream, const Puzzle& puzzle) {

	for (unsigned int i = Puzzle::buffer_size; i <= puzzle.visible_size; ++i) {

		for (unsigned int j = Puzzle::buffer_size; j <= puzzle.visible_size; ++j) {
			stream << puzzle.tiles[i][j];
		}

		stream << std::endl;
	}

	return stream;
}
