#include <sstream>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "ardealte/dictionary.h"
#include "ardealte/puzzle.h"

using ::testing::_;
using ::testing::Return;

class MockDictionary : public Dictionary {
public:
	MOCK_METHOD1(insert, void(std::string term));
	MOCK_CONST_METHOD1(lookup, bool(std::string term));
	MOCK_CONST_METHOD2(getMatches, std::vector<std::string>(std::string pattern, std::set<std::string> excludes));
};

TEST(PuzzleTest, InitAllFalse) {

	const int size = 5;
	bool * pattern = new bool[size * size]();
	MockDictionary dictionary;

	Puzzle puzzle(size, pattern, &dictionary);

	std::vector<std::vector<Tile *>> visible = puzzle.getVisibleTiles();
	ASSERT_EQ(size, visible.size());
	for (unsigned int i = 0; i < visible.size(); ++i) {

		std::vector<Tile *> row = visible[i];
		ASSERT_EQ(size, row.size());

		for (unsigned int j = 0; j < row.size(); ++j) {
			Tile * tile = row[j];
			ASSERT_FALSE(tile->isOpen());
		}
	}

	std::vector<Entry *> entries = puzzle.getEntries();
	ASSERT_EQ(0, entries.size());

	delete [] pattern;
}

TEST(PuzzleTest, InitMixed) {

	const int size = 3;
	bool * pattern = new bool[size * size] {
		true, true, false,
		false, true, false,
		true, true, true
	};
	MockDictionary dictionary;
	std::vector<std::string> matches;
	EXPECT_CALL(dictionary, getMatches("..", _)).WillOnce(Return(matches));

	Puzzle puzzle(size, pattern, &dictionary);

	std::vector<std::vector<Tile *>> visible = puzzle.getVisibleTiles();
	ASSERT_EQ(size, visible.size());
	for (unsigned int i = 0; i < visible.size(); ++i) {
		std::vector<Tile *> row = visible[i];
		ASSERT_EQ(size, row.size());

		for (unsigned int j = 0; j < row.size(); ++j) {
			Tile * tile = row[j];
			ASSERT_EQ(pattern[i * size + j], tile->isOpen());
		}
	}

	std::vector<Entry *> entries = puzzle.getEntries();
	ASSERT_EQ(3, entries.size());

	Entry * entry0 = entries[0];
	Entry * entry1 = entries[1];
	Entry * entry2 = entries[2];
	ASSERT_EQ(2, entry0->getLength());
	ASSERT_EQ(3, entry1->getLength());
	ASSERT_EQ(3, entry2->getLength());
	ASSERT_EQ("1A", entry0->getId());
	ASSERT_EQ("2D", entry1->getId());
	ASSERT_EQ("3A", entry2->getId());

	std::vector<Entry *> entry0_crossings = entry0->getCrossings();
	std::vector<Entry *> entry1_crossings = entry1->getCrossings();
	std::vector<Entry *> entry2_crossings = entry2->getCrossings();
	ASSERT_EQ(1, entry0_crossings.size());
	ASSERT_EQ(2, entry1_crossings.size());
	ASSERT_EQ(1, entry2_crossings.size());
	ASSERT_EQ(entry1, entry0_crossings[0]);
	ASSERT_EQ(entry0, entry1_crossings[0]);
	ASSERT_EQ(entry2, entry1_crossings[1]);
	ASSERT_EQ(entry1, entry2_crossings[0]);


	delete [] pattern;
}

int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
