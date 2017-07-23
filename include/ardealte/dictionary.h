#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <set>
#include <string>
#include <vector>

class Dictionary {

public:
	virtual ~Dictionary(){}
	virtual void insert(std::string term) = 0;
	virtual bool lookup(std::string term) const = 0;
	virtual std::vector<std::string> getMatches(std::string pattern, std::set<std::string> excludes) const = 0;
};

#endif
