#include "../../include/ardealte/tile.h"

Tile::Tile(bool open) {
	this->open = open;
}

bool Tile::isOpen() const {
	return this->open;
}

std::ostream& operator <<(std::ostream& stream, const Tile& tile) {

	std::string display = "|||";
	if (tile.open) {
		display = "[ ]";
	}

	stream << display;

	return stream;
}
