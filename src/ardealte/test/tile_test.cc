#include <sstream>

#include "gtest/gtest.h"
#include "ardealte/tile.h"

TEST(TileTest, InitNotOpen) {
	Tile tile(false);
	ASSERT_FALSE(tile.isOpen());
}

TEST(TileTest, InitOpen) {
	Tile tile(true);
	ASSERT_TRUE(tile.isOpen());
}

TEST(TileTest, StreamNotOpen) {
	Tile tile(false);
	std::stringstream ss;
	ss << tile;
	ASSERT_EQ("|||", ss.str());
}

TEST(TileTest, StreamOpen) {
	Tile tile(true);
	std::stringstream ss;
	ss << tile;
	ASSERT_EQ("[ ]", ss.str());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
