#include <vector>

#include "gtest/gtest.h"
#include "ardealte/dictionary.h"

TEST(DictionaryTest, LookupNotInserted) {
	Dictionary dictionary;
	ASSERT_FALSE(dictionary.lookup("tree"));
}

TEST(DictionaryTest, LookupInserted) {
	Dictionary dictionary;
	dictionary.insert("shrub");
	ASSERT_TRUE(dictionary.lookup("shrub"));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
