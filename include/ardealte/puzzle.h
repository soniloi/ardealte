#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include "ardealte/tile.h"

class Puzzle {

private:
	static const unsigned int buffer_size = 1;
	unsigned int actual_size;
	unsigned int visible_size;
	std::vector<std::vector<Tile>> tiles;
	static std::vector<Tile> createClosedTileRow(unsigned int size);

public:
	Puzzle(unsigned int size, bool * pattern);
	~Puzzle();
	friend std::ostream& operator <<(std::ostream &stream, const Puzzle& puzzle);
};

#endif
