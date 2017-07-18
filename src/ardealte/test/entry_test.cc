#include <vector>

#include "gtest/gtest.h"
#include "ardealte/entry.h"
#include "ardealte/tile.h"

TEST(EntryTest, GetSolutionNull) {

	Tile tile(true);

	std::vector<Tile> tiles;
	tiles.push_back(tile);

	Entry entry(tiles);

	ASSERT_EQ(1, entry.getSolution().length());
}

TEST(EntryTest, GetSolutionNotNull) {

	Tile tile1(true);
	tile1.setLetter('g');
	Tile tile2(true);
	tile2.setLetter('a');
	Tile tile3(true);
	tile3.setLetter('r');
	Tile tile4(true);
	tile4.setLetter('d');
	Tile tile5(true);
	tile5.setLetter('e');
	Tile tile6(true);
	tile6.setLetter('n');

	std::vector<Tile> tiles;
	tiles.push_back(tile1);
	tiles.push_back(tile2);
	tiles.push_back(tile3);
	tiles.push_back(tile4);
	tiles.push_back(tile5);
	tiles.push_back(tile6);

	Entry entry(tiles);

	ASSERT_EQ("garden", entry.getSolution());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
