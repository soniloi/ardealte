#ifndef TILE_H
#define TILE_H

#include <ostream>

class Tile {

public:
	Tile(bool open);
	bool isOpen() const;
	char getLetter() const;
	void setLetter(char letter);
	unsigned int getDisplayNumber() const;
	void setDisplayNumber(unsigned int display_number);
	friend std::ostream& operator <<(std::ostream &stream, const Tile& tile);

private:
	static const std::string DISPLAY_CLOSED;
	static const std::string DISPLAY_OPEN;
	static const unsigned int DEFAULT_DISPLAY_NUMBER = 0;
	static const char WILDCARD = '.';
	bool open;
	char letter = Tile::WILDCARD;
	unsigned int display_number = Tile::DEFAULT_DISPLAY_NUMBER;
};

#endif
