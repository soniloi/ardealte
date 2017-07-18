#ifndef TILE_H
#define TILE_H

#include <ostream>

class Tile {

private:
	static const std::string DISPLAY_CLOSED;
	static const std::string DISPLAY_OPEN;
	bool open;
	char letter = '\0';

public:
	Tile(bool open);
	bool isOpen() const;
	char getLetter() const;
	void setLetter(char letter);
	friend std::ostream& operator <<(std::ostream &stream, const Tile& tile);
};

#endif
