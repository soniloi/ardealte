#include <iostream>
#include <string>

#include "puzzle.h"

Puzzle::Puzzle(unsigned int size) {

	this->size = size;

	this->tiles = new Tile*[size];
	for (unsigned int i = 0; i < size; ++i) {
		this->tiles[i] = new Tile[size]();
	}
}

Puzzle::~Puzzle() {
	for (unsigned int i = 0; i < this->size; ++i) {
		delete [] this->tiles[i];
	}
	delete [] this->tiles;
}

void Puzzle::print() {
	for (unsigned int i = 0; i < this->size; ++i) {
		for (unsigned int j = 0; j < this->size; ++j) {

			std::string display = "|||";
			if (tiles[i][j].isOpen()) {
				display = "[ ]";
			}

			std::cout << display;
		}
		std::cout << std::endl;
	}
}
