#include <iostream>
#include <string>

#include "ardealte/puzzle.h"

Puzzle::Puzzle(unsigned int size, bool * pattern, Dictionary * dictionary) {

	this->actual_size = size + Puzzle::buffer_size * 2;
	this->visible_size = size;

	this->dictionary = dictionary;
	this->initBoard(pattern);
	this->discoverEntries();
}

Puzzle::~Puzzle() {
	for (auto it = this->entries.begin(); it != this->entries.end(); it++) {
		delete (*it);
	}
}

std::string Puzzle::getDisplayNumbersStr() const {

	std::stringstream display;
	for (unsigned int i = Puzzle::buffer_size; i <= this->visible_size; ++i) {

		for (unsigned int j = Puzzle::buffer_size; j <= this->visible_size; ++j) {
			Tile tile = tiles[i][j];
			if (tile.isOpen()) {
				display << "[";
				if (tile.getDisplayNumber() != 0) {
					display << tile.getDisplayNumber();
				} else {
					display << " ";
				}
				display << "]";
			} else {
				display << "|||";
			}
		}

		display << std::endl;
	}

	return display.str();
}

std::vector<Entry *> Puzzle::getEntries() const {
	return this->entries;
}

std::ostream& operator <<(std::ostream& stream, const Puzzle& puzzle) {

	for (unsigned int i = Puzzle::buffer_size; i <= puzzle.visible_size; ++i) {

		for (unsigned int j = Puzzle::buffer_size; j <= puzzle.visible_size; ++j) {
			stream << puzzle.tiles[i][j];
		}

		stream << std::endl;
	}

	return stream;
}

bool Puzzle::startsWord(unsigned int i, unsigned int j, Direction direction) {

	if (!this->tiles[i][j].isOpen()) {
		return false;
	}

	if (direction == Direction::ACROSS) {
		return !this->tiles[i][j-1].isOpen() && this->tiles[i][j+1].isOpen();
	}

	return !this->tiles[i-1][j].isOpen() && this->tiles[i+1][j].isOpen();
}

std::vector<Tile> Puzzle::createClosedTileRow(unsigned int size) {
	std::vector<Tile> row;
	for (unsigned int i = 0; i < size; ++i) {
		row.push_back(Tile(false));
	}
	return row;
}

void Puzzle::initBoard (bool * pattern) {
	this->tiles.push_back(Puzzle::createClosedTileRow(this->actual_size)); // Top buffer row

	for (unsigned int i = 0; i < this->visible_size; ++i) {

		std::vector<Tile> row;
		row.push_back(Tile(false)); // Left buffer column

		for (unsigned int j = 0; j < this->visible_size; ++j) {

			Tile tile(pattern[i * this->visible_size + j]);
			row.push_back(tile);
		}

		row.push_back(Tile(false)); // Right buffer column
		this->tiles.push_back(row);
	}
}

void Puzzle::createEntry(unsigned int entry_index, Direction direction, std::vector<Tile *> tiles) {
	Entry * entry = new Entry(entry_index, direction, tiles);
	this->entries.push_back(entry);
	for (auto it = tiles.begin(); it != tiles.end(); it++) {
		(*it)->setEntry(direction, entry);
	}
}

void Puzzle::discoverEntries() {
	this->tiles.push_back(Puzzle::createClosedTileRow(this->actual_size)); // Bottom buffer row

	unsigned int entry_index = 1;
	for (unsigned int i = Puzzle::buffer_size; i <= this->visible_size; ++i) {
		for (unsigned int j = Puzzle::buffer_size; j <= this->visible_size; ++j) {
			unsigned int current_entry_index = entry_index;
			if (this->startsWord(i, j, Direction::ACROSS)) {
				tiles[i][j].setDisplayNumber(current_entry_index);
				entry_index = current_entry_index + 1 ;

				std::vector<Tile *> entry_tiles;
				unsigned int k = j;
				do {
					entry_tiles.push_back(&tiles[i][k++]);
				} while (tiles[i][k].isOpen());

				this->createEntry(current_entry_index, Direction::ACROSS, entry_tiles);
			}
			if (this->startsWord(i, j, Direction::DOWN)) {
				tiles[i][j].setDisplayNumber(current_entry_index);
				entry_index = current_entry_index + 1;

				std::vector<Tile *> entry_tiles;
				unsigned int k = i;
				do {
					entry_tiles.push_back(&tiles[k++][j]);
				} while (tiles[k][j].isOpen());

				this->createEntry(current_entry_index, Direction::DOWN, entry_tiles);
			}
		}
	}

	std::default_random_engine rng;
	std::map<Entry *, std::set<std::string>> invalid_matches;

	bool finished = false;
	while (!finished) {
		finished = true;
		for (auto it = this->entries.begin(); it != this->entries.end(); it++) {
			Entry * entry = *it;
			std::set<std::string> excludes = invalid_matches[entry];
			std::cout << "Seeking match for [" << entry->getId() << "] \"" << entry->getSolution() << "\" ";
			if (!entry->isComplete()) {
				std::string current = entry->getSolution();
				std::vector<std::string> matches = this->dictionary->getMatches(current, excludes);
				if (matches.empty()) {
					finished = false;
					std::vector<Entry *> crossEntries = entry->getCrossings();
					std::vector<Entry *> filteredCrossEntries;
					for (auto it = crossEntries.begin(); it != crossEntries.end(); it++) {
						if ((*it)->isComplete()) {
							filteredCrossEntries.push_back(*it);
						}
					}
					if (!filteredCrossEntries.empty()) {
						std::uniform_int_distribution<int> distribution(0, filteredCrossEntries.size()-1);
						int index = distribution(rng);
						Entry * crossEntry = filteredCrossEntries[index];
						invalid_matches[crossEntry].insert(crossEntry->getSolution());
						crossEntry->setComplete(false);
						crossEntry->clearUniqueTiles();
						std::cout << "No matches found, rolling back [" << crossEntry->getId() << "]";
					} else {
						std::cout << "No matches found to roll back, giving up";
						finished = true;
					}
					std::cout << std::endl;
					break;
				} else {
					std::uniform_int_distribution<int> distribution(0, matches.size()-1);
					int index = distribution(rng);
					std::string match = matches[index];
					entry->setComplete(true);
					entry->setSolution(match);
					std::cout << matches.size() << " matches found, attempting \"" << match << "\"";
				}
			}
			std::cout << std::endl;
		}
	}

}
