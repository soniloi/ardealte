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

	std::stringstream ss;
	ss << puzzle;
	delete [] pattern;

	ASSERT_EQ("|||||||||||||||\n|||||||||||||||\n|||||||||||||||\n|||||||||||||||\n|||||||||||||||\n", ss.str());
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

	std::stringstream ss;
	ss << puzzle;
	delete [] pattern;

	ASSERT_EQ("[ ][ ]|||\n|||[ ]|||\n[ ][ ][ ]\n", ss.str());
}

int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
