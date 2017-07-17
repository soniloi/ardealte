#include <iostream>
#include <string>

#include "../../include/ardealte/puzzle.h"

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

void Puzzle::init(bool ** pattern) {
	for (unsigned int i = 0; i < this->size; ++i) {
		for (unsigned int j = 0; j < this->size; ++j) {
			this->tiles[i][j].setOpen(pattern[i][j]);
		}
	}
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
