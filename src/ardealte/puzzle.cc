#include <iostream>
#include <string>

#include "../../include/ardealte/puzzle.h"

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

void Puzzle::print() {
	for (unsigned int i = 0; i < this->size; ++i) {
		for (unsigned int j = 0; j < this->size; ++j) {

			std::string display = "|||";
			if (this->tiles[i][j].isOpen()) {
				display = "[ ]";
			}

			std::cout << display;
		}
		std::cout << std::endl;
	}
}
