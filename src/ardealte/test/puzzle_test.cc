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

TEST(PuzzleTest, GetVisibleTilesAllFalse) {

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

	delete [] pattern;
}

TEST(PuzzleTest, GetVisibleTilesMixed) {

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

	std::stringstream ss;
	ss << puzzle;
	delete [] pattern;

	ASSERT_EQ("[ ][ ]|||\n|||[ ]|||\n[ ][ ][ ]\n", ss.str());
}

int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
