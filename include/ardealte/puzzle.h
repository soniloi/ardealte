#ifndef PUZZLE_H
#define PUZZLE_H

#include "../../include/ardealte/tile.h"

class Puzzle {

private:
	unsigned int size;
	Tile ** tiles;

public:
	Puzzle(unsigned int size);
	~Puzzle();
	void init(bool ** pattern);
	void print();
};

#endif
