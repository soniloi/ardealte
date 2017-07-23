#include <sstream>

#include "gtest/gtest.h"
#include "ardealte/simple_dictionary.h"
#include "ardealte/puzzle.h"

TEST(PuzzleTest, InitAllFalse) {
	const int size = 5;
	bool * pattern = new bool[size * size]();
	SimpleDictionary dictionary;

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
	SimpleDictionary dictionary;

	Puzzle puzzle(size, pattern, &dictionary);

	std::stringstream ss;
	ss << puzzle;
	delete [] pattern;

	ASSERT_EQ("[ ][ ]|||\n|||[ ]|||\n[ ][ ][ ]\n", ss.str());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
