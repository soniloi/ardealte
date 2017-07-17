#ifndef TILE_H
#define TILE_H

#include <ostream>

class Tile {

private:
	static const std::string DISPLAY_CLOSED;
	static const std::string DISPLAY_OPEN;
	bool open;

public:
	Tile(bool open);
	bool isOpen() const;
	friend std::ostream& operator <<(std::ostream &stream, const Tile& tile);
};

#endif
