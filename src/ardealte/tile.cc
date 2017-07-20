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

void Tile::resetLetter() {
	this->letter = Tile::WILDCARD;
}

unsigned int Tile::getDisplayNumber() const {
	return this->display_number;
}

void Tile::setDisplayNumber(unsigned int display_number) {
	this->display_number = display_number;
}

Entry * Tile::getEntry(Direction direction) const {
	if (direction == Direction::ACROSS) {
		return this->across_entry;
	}
	return this->down_entry;
}

void Tile::setEntry(Entry * entry, Direction direction) {
	if (direction == Direction::ACROSS) {
		this->across_entry = entry;
	} else {
		this->down_entry = entry;
	}
}

std::ostream& operator <<(std::ostream& stream, const Tile& tile) {

	std::string display = Tile::DISPLAY_CLOSED;
	if (tile.open) {
		display = Tile::DISPLAY_OPEN;
	}

	stream << display;

	return stream;
}
