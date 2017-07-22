#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <regex>
#include <string>
#include <vector>

class Dictionary {

public:
	Dictionary();
	void insert(std::string term);
	bool lookup(std::string term) const;
	std::vector<std::string> getMatches(std::string pattern, std::set<std::string> excludes) const;

private:
	std::set<std::string> terms;
};

#endif
