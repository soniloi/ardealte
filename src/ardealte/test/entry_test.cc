#include <vector>

#include "gtest/gtest.h"
#include "ardealte/entry.h"
#include "ardealte/tile.h"

TEST(EntryTest, AcrossId) {
	std::vector<Tile *> tiles;
	Entry entry(7, Direction::ACROSS, tiles);

	ASSERT_EQ("7A", entry.getId());
}

TEST(EntryTest, DownId) {
	std::vector<Tile *> tiles;
	Entry entry(39, Direction::DOWN, tiles);

	ASSERT_EQ("39D", entry.getId());
}

TEST(EntryTest, GetSolutionUnset) {

	Tile tile(true);

	std::vector<Tile *> tiles;
	tiles.push_back(&tile);

	Entry entry(0, Direction::ACROSS, tiles);

	ASSERT_EQ(".", entry.getSolution());
}

TEST(EntryTest, GetSolutionSet) {

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

	std::vector<Tile *> tiles;
	tiles.push_back(&tile1);
	tiles.push_back(&tile2);
	tiles.push_back(&tile3);
	tiles.push_back(&tile4);
	tiles.push_back(&tile5);
	tiles.push_back(&tile6);

	Entry entry(0, Direction::ACROSS, tiles);

	ASSERT_EQ("garden", entry.getSolution());
}

TEST(EntryTest, SetGetSolutionLengthMatch) {

	Tile tile(true);

	std::vector<Tile *> tiles;
	tiles.push_back(&tile);

	Entry entry(0, Direction::ACROSS, tiles);
	entry.setSolution("a");

	ASSERT_EQ("a", entry.getSolution());
}

TEST(EntryTest, SetGetSolutionLengthNotMatch) {

	Tile tile(true);

	std::vector<Tile *> tiles;
	tiles.push_back(&tile);

	Entry entry(0, Direction::ACROSS, tiles);
	ASSERT_DEATH({entry.setSolution("cat");}, ".");
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
