#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <regex>
#include <string>
#include <set>

class Dictionary {

public:
	Dictionary();
	void insert(std::string term);
	bool lookup(std::string term) const;
	std::set<std::string> getMatches(std::string pattern) const;

private:
	std::set<std::string> terms;
};

#endif
