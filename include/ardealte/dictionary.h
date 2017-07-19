#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <algorithm>
#include <string>
#include <vector>

class Dictionary {

public:
	Dictionary();
	void insert(std::string term);
	bool lookup(std::string term) const;

private:
	std::vector<std::string> terms;
};

#endif
