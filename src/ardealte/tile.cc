#include "../../include/ardealte/tile.h"

Tile::Tile() {
	this->open = false;
}

bool Tile::isOpen() {
	return this->open;
}

void Tile::setOpen(bool open) {
	this->open = open;
}
