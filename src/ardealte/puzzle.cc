#include <iostream>
#include <string>

#include "ardealte/puzzle.h"

Puzzle::Puzzle(unsigned int size, bool * pattern) {

	this->actual_size = size + Puzzle::buffer_size * 2;
	this->visible_size = size;

	this->initBoard(pattern);
	this->discoverEntries();
}

Puzzle::~Puzzle() {
}

std::string Puzzle::getDisplayNumbersStr() const {

	std::stringstream display;
	for (unsigned int i = Puzzle::buffer_size; i <= this->visible_size; ++i) {

		for (unsigned int j = Puzzle::buffer_size; j <= this->visible_size; ++j) {
			Tile tile = tiles[i][j];
			if (tile.isOpen()) {
				display << "[";
				if (tile.getDisplayNumber() != 0) {
					display << tile.getDisplayNumber();
				} else {
					display << " ";
				}
				display << "]";
			} else {
				display << "|||";
			}
		}

		display << std::endl;
	}

	return display.str();
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

bool Puzzle::startsWord(unsigned int i, unsigned int j) {

	if (!this->tiles[i][j].isOpen()) {
		return false;
	}

	return (!this->tiles[i][j-1].isOpen() && this->tiles[i][j+1].isOpen())
		|| (!this->tiles[i-1][j].isOpen() && this->tiles[i+1][j].isOpen());
}

std::vector<Tile> Puzzle::createClosedTileRow(unsigned int size) {
	std::vector<Tile> row;
	for (unsigned int i = 0; i < size; ++i) {
		row.push_back(Tile(false));
	}
	return row;
}

void Puzzle::initBoard (bool * pattern) {
	this->tiles.push_back(Puzzle::createClosedTileRow(this->actual_size)); // Top buffer row

	for (unsigned int i = 0; i < this->visible_size; ++i) {

		std::vector<Tile> row;
		row.push_back(Tile(false)); // Left buffer column

		for (unsigned int j = 0; j < this->visible_size; ++j) {

			Tile tile(pattern[i * this->visible_size + j]);
			row.push_back(tile);
		}

		row.push_back(Tile(false)); // Right buffer column
		this->tiles.push_back(row);
	}
}

void Puzzle::discoverEntries() {
	this->tiles.push_back(Puzzle::createClosedTileRow(this->actual_size)); // Bottom buffer row

	unsigned int entry_index = 1;
	for (unsigned int i = Puzzle::buffer_size; i <= this->visible_size; ++i) {
		for (unsigned int j = Puzzle::buffer_size; j <= this->visible_size; ++j) {
			if (this->startsWord(i, j)) {
				tiles[i][j].setDisplayNumber(entry_index++);
			}
		}
	}
}
