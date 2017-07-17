#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include "ardealte/tile.h"

class Puzzle {

private:
	unsigned int size;
	std::vector<std::vector<Tile>> tiles;

public:
	Puzzle(unsigned int size, bool * pattern);
	~Puzzle();
	friend std::ostream& operator <<(std::ostream &stream, const Puzzle& puzzle);
};

#endif
