#ifndef ENTRY_H
#define ENTRY_H

#include <sstream>
#include <vector>
#include "ardealte/tile.h"

enum class Direction {
	ACROSS,
	DOWN
};

class Entry {

public:
	Entry(unsigned int entry_index, Direction direction, std::vector<Tile *> tiles);
	unsigned int getLength() const;
	std::string getId() const;
	std::string getSolution() const;

private:
	unsigned int entry_index;
	Direction direction;
	std::vector<Tile *> tiles;
};

#endif
