#ifndef TILE_H
#define TILE_H

#include <ostream>

class Tile {

private:
	static const std::string DISPLAY_CLOSED;
	static const std::string DISPLAY_OPEN;
	static const unsigned int DEFAULT_DISPLAY_NUMBER = 0;
	bool open;
	char letter = '\0';
	unsigned int display_number = Tile::DEFAULT_DISPLAY_NUMBER;

public:
	Tile(bool open);
	bool isOpen() const;
	char getLetter() const;
	void setLetter(char letter);
	unsigned int getDisplayNumber() const;
	void setDisplayNumber(unsigned int display_number);
	friend std::ostream& operator <<(std::ostream &stream, const Tile& tile);
};

#endif
