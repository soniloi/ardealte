#include "ardealte/tile.h"

const std::string Tile::DISPLAY_OPEN = "[ ]";
const std::string Tile::DISPLAY_CLOSED = "|||";

Tile::Tile(bool open) {
	this->open = open;
}

bool Tile::isOpen() const {
	return this->open;
}

char Tile::getLetter() const {
	return this->letter;
}

void Tile::setLetter(char letter) {
	this->letter = letter;
}

unsigned int Tile::getDisplayNumber() const {
	return this->display_number;
}

void Tile::setDisplayNumber(unsigned int display_number) {
	this->display_number = display_number;
}

std::ostream& operator <<(std::ostream& stream, const Tile& tile) {

	std::string display = Tile::DISPLAY_CLOSED;
	if (tile.open) {
		display = Tile::DISPLAY_OPEN;
	}

	stream << display;

	return stream;
}
