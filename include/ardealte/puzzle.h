#ifndef PUZZLE_H
#define PUZZLE_H

#include <map>
#include <random>
#include <sstream>
#include <vector>

#include "ardealte/dictionary.h"
#include "ardealte/entry.h"
#include "ardealte/tile.h"

class Puzzle {

public:
	Puzzle(unsigned int size, bool * pattern, Dictionary * dictionary);
	~Puzzle();
	std::string getDisplayNumbersStr() const;
	std::string getEntriesStr() const;
	friend std::ostream& operator <<(std::ostream &stream, const Puzzle& puzzle);

private:
	static const unsigned int buffer_size = 1;
	Dictionary * dictionary;
	unsigned int actual_size;
	unsigned int visible_size;
	std::vector<std::vector<Tile>> tiles;
	std::vector<Entry *> entries;

	static std::vector<Tile> createClosedTileRow(unsigned int size);
	void initBoard (bool * pattern);
	void discoverEntries();
	bool startsWord(unsigned int i, unsigned int j, Direction direction);
	void createEntry(unsigned int entry_index, Direction direction, std::vector<Tile *> tiles);
};

#endif
