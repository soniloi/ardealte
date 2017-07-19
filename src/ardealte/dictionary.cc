#include "ardealte/dictionary.h"

Dictionary::Dictionary() {
}

void Dictionary::insert(std::string term) {
	this->terms.insert(term);
}

bool Dictionary::lookup(std::string term) const {
	return this->terms.find(term) != this->terms.end();
}
