#ifndef PUZZLE_H
#define PUZZLE_H

#include "tile.h"

class Puzzle {

private:
	unsigned int size;
	Tile ** tiles;

public:
	Puzzle(unsigned int size);
	~Puzzle();
	void print();
};

#endif
