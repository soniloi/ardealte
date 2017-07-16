#include "gtest/gtest.h"
#include "../../../include/ardealte/tile.h"

TEST(TileTest, InitNotOpen) {
	Tile tile;
	ASSERT_FALSE(tile.isOpen());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
