#include "../../include/ardealte/tile.h"

Tile::Tile(bool open) {
	this->open = open;
}

bool Tile::isOpen() {
	return this->open;
}

void Tile::setOpen(bool open) {
	this->open = open;
}
