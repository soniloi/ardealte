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

TEST(EntryTest, SingleTile) {

	Tile tile(true);

	std::vector<Tile *> tiles;
	tiles.push_back(&tile);

	Entry entry(0, Direction::DOWN, tiles);

	ASSERT_EQ(".", entry.getSolution());
	ASSERT_EQ(NULL, tile.getAcrossEntry());
	ASSERT_EQ(&entry, tile.getDownEntry());
}

TEST(EntryTest, MultipleTile) {

	Tile tile1(true);
	tile1.setLetter('m');
	Tile tile2(true);
	tile2.setLetter('i');
	Tile tile3(true);
	tile3.setLetter('c');
	Tile tile4(true);
	tile4.setLetter('e');

	std::vector<Tile *> tiles;
	tiles.push_back(&tile1);
	tiles.push_back(&tile2);
	tiles.push_back(&tile3);
	tiles.push_back(&tile4);

	Entry entry(0, Direction::ACROSS, tiles);

	ASSERT_EQ("mice", entry.getSolution());
	ASSERT_EQ(&entry, tile1.getAcrossEntry());
	ASSERT_EQ(NULL, tile1.getDownEntry());
	ASSERT_EQ(&entry, tile2.getAcrossEntry());
	ASSERT_EQ(NULL, tile2.getDownEntry());
	ASSERT_EQ(&entry, tile3.getAcrossEntry());
	ASSERT_EQ(NULL, tile3.getDownEntry());
	ASSERT_EQ(&entry, tile4.getAcrossEntry());
	ASSERT_EQ(NULL, tile4.getDownEntry());
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
