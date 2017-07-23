#include "ardealte/simple_dictionary.h"

SimpleDictionary::SimpleDictionary() {
}

void SimpleDictionary::insert(std::string term) {
	this->terms.insert(term);
}

bool SimpleDictionary::lookup(std::string term) const {
	return this->terms.find(term) != this->terms.end();
}

std::vector<std::string> SimpleDictionary::getMatches(std::string pattern, std::set<std::string> excludes) const {
	std::vector<std::string> matches;
	for (auto it = this->terms.begin(); it != this->terms.end(); it++) {
		std::string term = (*it);
		if (std::regex_match(term, std::regex(pattern)) && excludes.find(term) == excludes.end()) {
			matches.push_back(term);
		}
	}
	return matches;
}
