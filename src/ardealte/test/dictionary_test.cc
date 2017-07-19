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

TEST(DictionaryTest, GetMatchesNone) {
	Dictionary dictionary;
	dictionary.insert("shrub");
	std::set<std::string> matches = dictionary.getMatches("tree");
	ASSERT_TRUE(matches.empty());
}

TEST(DictionaryTest, GetMatchesSingle) {
	Dictionary dictionary;
	dictionary.insert("shrub");

	std::set<std::string> matches = dictionary.getMatches("s.r.b");
	ASSERT_EQ(1, matches.size());
	ASSERT_TRUE(matches.find("shrub") != matches.end());
}

TEST(DictionaryTest, GetMatchesMultiple) {
	Dictionary dictionary;
	dictionary.insert("shrub");
	dictionary.insert("shawl");
	dictionary.insert("sheep");

	std::set<std::string> matches = dictionary.getMatches("sh...");
	ASSERT_EQ(3, matches.size());
	ASSERT_TRUE(matches.find("shrub") != matches.end());
	ASSERT_TRUE(matches.find("shawl") != matches.end());
	ASSERT_TRUE(matches.find("sheep") != matches.end());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
