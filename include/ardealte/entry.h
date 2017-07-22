#ifndef ENTRY_H
#define ENTRY_H

#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

#include "ardealte/direction.h"
#include "ardealte/tile.h"

class Entry {

public:
	Entry(unsigned int entry_index, Direction direction, std::vector<Tile *> tiles);
	unsigned int getLength() const;
	std::string getId() const;
	bool isComplete() const;
	void setComplete(bool complete);
	std::string getSolution() const;
	void setSolution(std::string solution);
	void clearUniqueTiles();
	std::vector<Entry *> getCrossings();

private:
	unsigned int entry_index;
	Direction direction;
	std::vector<Tile *> tiles;
	bool complete;

	Entry * getCrossEntry(Tile * intersection);
};

#endif
