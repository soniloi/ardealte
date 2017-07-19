#include "ardealte/dictionary.h"

Dictionary::Dictionary() {
}

void Dictionary::insert(std::string term) {
	this->terms.push_back(term);
}

bool Dictionary::lookup(std::string term) const {
	return std::find(this->terms.begin(), this->terms.end(), term) != this->terms.end();
}
