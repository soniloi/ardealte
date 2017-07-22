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
	std::set<std::string> excludes;

	std::vector<std::string> matches = dictionary.getMatches("tree", excludes);
	ASSERT_TRUE(matches.empty());
}

TEST(DictionaryTest, GetMatchesSingle) {
	Dictionary dictionary;
	dictionary.insert("shrub");
	dictionary.insert("berry");
	std::set<std::string> excludes;

	std::vector<std::string> matches = dictionary.getMatches("s.r.b", excludes);
	ASSERT_EQ(1, matches.size());
	ASSERT_TRUE(std::find(matches.begin(), matches.end(), "shrub") != matches.end());
}

TEST(DictionaryTest, GetMatchesMultiple) {
	Dictionary dictionary;
	dictionary.insert("shrub");
	dictionary.insert("berry");
	dictionary.insert("shawl");
	dictionary.insert("sheep");
	std::set<std::string> excludes;

	std::vector<std::string> matches = dictionary.getMatches("sh...", excludes);
	ASSERT_EQ(3, matches.size());
	ASSERT_TRUE(std::find(matches.begin(), matches.end(), "shrub") != matches.end());
	ASSERT_TRUE(std::find(matches.begin(), matches.end(), "shawl") != matches.end());
	ASSERT_TRUE(std::find(matches.begin(), matches.end(), "sheep") != matches.end());
}

TEST(DictionaryTest, GetMatchesExcludes) {
	Dictionary dictionary;
	dictionary.insert("shrub");
	dictionary.insert("shawl");
	dictionary.insert("sheep");
	std::set<std::string> excludes;
	excludes.insert("shrub");
	excludes.insert("sheep");

	std::vector<std::string> matches = dictionary.getMatches("sh...", excludes);
	ASSERT_EQ(1, matches.size());
	ASSERT_TRUE(std::find(matches.begin(), matches.end(), "shawl") != matches.end());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
