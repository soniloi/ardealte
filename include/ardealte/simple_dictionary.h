#ifndef SIMPLE_DICTIONARY_H
#define SIMPLE_DICTIONARY_H

#include <regex>
#include <string>
#include <vector>

#include "ardealte/dictionary.h"

class SimpleDictionary : public Dictionary {

public:
	SimpleDictionary();
	void insert(std::string term);
	bool lookup(std::string term) const;
	std::vector<std::string> getMatches(std::string pattern, std::set<std::string> excludes) const;

private:
	std::set<std::string> terms;
};

#endif
