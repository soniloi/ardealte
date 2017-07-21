#include "ardealte/dictionary.h"

Dictionary::Dictionary() {
}

void Dictionary::insert(std::string term) {
	this->terms.insert(term);
}

bool Dictionary::lookup(std::string term) const {
	return this->terms.find(term) != this->terms.end();
}

std::set<std::string> Dictionary::getMatches(std::string pattern, std::set<std::string> excludes) const {
	std::set<std::string> matches;
	for (auto it = this->terms.begin(); it != this->terms.end(); it++) {
		std::string term = (*it);
		if (std::regex_match(term, std::regex(pattern)) && excludes.find(term) == excludes.end()) {
			matches.insert(term);
		}
	}
	return matches;
}
