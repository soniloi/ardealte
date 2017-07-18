#ifndef PUZZLE_H
#define PUZZLE_H

#include <sstream>
#include <vector>

#include "ardealte/entry.h"
#include "ardealte/tile.h"

class Puzzle {

public:
	Puzzle(unsigned int size, bool * pattern);
	~Puzzle();
	std::string getDisplayNumbersStr() const;
	friend std::ostream& operator <<(std::ostream &stream, const Puzzle& puzzle);

private:
	static const unsigned int buffer_size = 1;
	unsigned int actual_size;
	unsigned int visible_size;
	std::vector<std::vector<Tile>> tiles;

	static std::vector<Tile> createClosedTileRow(unsigned int size);
	void initBoard (bool * pattern);
	void discoverEntries();
	bool startsWord(unsigned int i, unsigned int j, Direction direction);
};

#endif
