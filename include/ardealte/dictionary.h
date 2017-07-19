#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <set>

class Dictionary {

public:
	Dictionary();
	void insert(std::string term);
	bool lookup(std::string term) const;

private:
	std::set<std::string> terms;
};

#endif
