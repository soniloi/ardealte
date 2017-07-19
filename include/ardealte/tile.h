#ifndef TILE_H
#define TILE_H

#include <ostream>

class Entry;

class Tile {

public:
	Tile(bool open);
	bool isOpen() const;
	char getLetter() const;
	void setLetter(char letter);
	unsigned int getDisplayNumber() const;
	void setDisplayNumber(unsigned int display_number);
	Entry * getAcrossEntry() const;
	void setAcrossEntry(Entry * entry);
	Entry * getDownEntry() const;
	void setDownEntry(Entry * entry);
	friend std::ostream& operator <<(std::ostream &stream, const Tile& tile);

private:
	static const std::string DISPLAY_CLOSED;
	static const std::string DISPLAY_OPEN;
	static const unsigned int DEFAULT_DISPLAY_NUMBER = 0;
	static const char WILDCARD = '.';
	bool open;
	char letter = Tile::WILDCARD;
	unsigned int display_number = Tile::DEFAULT_DISPLAY_NUMBER;
	Entry * across_entry = NULL;
	Entry * down_entry = NULL;
};

#endif
