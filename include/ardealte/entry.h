#ifndef ENTRY_H
#define ENTRY_H

#include <vector>
#include "ardealte/tile.h"

class Entry {

public:
	Entry(std::vector<Tile> tiles);
	std::string getSolution() const;

private:
	std::vector<Tile> tiles;
};

#endif
