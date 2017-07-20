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
	ASSERT_EQ(NULL, tile.getEntry(Direction::ACROSS));
	ASSERT_EQ(&entry, tile.getEntry(Direction::DOWN));
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
	ASSERT_EQ(&entry, tile1.getEntry(Direction::ACROSS));
	ASSERT_EQ(NULL, tile1.getEntry(Direction::DOWN));
	ASSERT_EQ(&entry, tile2.getEntry(Direction::ACROSS));
	ASSERT_EQ(NULL, tile2.getEntry(Direction::DOWN));
	ASSERT_EQ(&entry, tile3.getEntry(Direction::ACROSS));
	ASSERT_EQ(NULL, tile3.getEntry(Direction::DOWN));
	ASSERT_EQ(&entry, tile4.getEntry(Direction::ACROSS));
	ASSERT_EQ(NULL, tile4.getEntry(Direction::DOWN));
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

TEST(EntryTest, ClearUniqueTilesAllUnique) {

	Tile tile1(true);
	tile1.setLetter('c');
	Tile tile2(true);
	tile2.setLetter('a');
	Tile tile3(true);
	tile3.setLetter('t');

	std::vector<Tile *> tiles;
	tiles.push_back(&tile1);
	tiles.push_back(&tile2);
	tiles.push_back(&tile3);

	Entry entry(0, Direction::ACROSS, tiles);
	entry.clearUniqueTiles();

	ASSERT_EQ("...", entry.getSolution());
}

TEST(EntryTest, ClearUniqueTilesWithCrossing) {

	Tile tile1(true);
	tile1.setLetter('c');
	Tile tile2(true);
	tile2.setLetter('a');
	Tile tile3(true);
	tile3.setLetter('t');
	Tile tile4(true);
	tile4.setLetter('m');

	std::vector<Tile *> acrossTiles;
	acrossTiles.push_back(&tile1);
	acrossTiles.push_back(&tile2);
	acrossTiles.push_back(&tile3);

	std::vector<Tile *> downTiles;
	downTiles.push_back(&tile2);
	downTiles.push_back(&tile4);

	Entry acrossEntry(0, Direction::ACROSS, acrossTiles);
	Entry downEntry(0, Direction::DOWN, downTiles);

	acrossEntry.clearUniqueTiles();

	ASSERT_EQ(".a.", acrossEntry.getSolution());
	ASSERT_EQ("am", downEntry.getSolution());
}

TEST(EntryTest, GetCrossingsNoCrossings) {

	Tile tile1(true);
	tile1.setLetter('c');
	Tile tile2(true);
	tile2.setLetter('a');
	Tile tile3(true);
	tile3.setLetter('t');

	std::vector<Tile *> tiles;
	tiles.push_back(&tile1);
	tiles.push_back(&tile2);
	tiles.push_back(&tile3);

	Entry entry(0, Direction::ACROSS, tiles);
	std::vector<Entry *> crossings = entry.getCrossings();

	ASSERT_TRUE(crossings.empty());
}

TEST(EntryTest, GetCrossingsWithCrossings) {

	Tile tile1(true);
	tile1.setLetter('c');
	Tile tile2(true);
	tile2.setLetter('a');
	Tile tile3(true);
	tile3.setLetter('t');
	Tile tile4(true);
	tile4.setLetter('m');

	std::vector<Tile *> acrossTiles;
	acrossTiles.push_back(&tile1);
	acrossTiles.push_back(&tile2);
	acrossTiles.push_back(&tile3);

	std::vector<Tile *> downTiles;
	downTiles.push_back(&tile2);
	downTiles.push_back(&tile4);

	Entry acrossEntry(0, Direction::ACROSS, acrossTiles);
	Entry downEntry(0, Direction::DOWN, downTiles);

	std::vector<Entry *> crossings = acrossEntry.getCrossings();

	ASSERT_EQ(1, crossings.size());
	ASSERT_EQ(&downEntry, crossings[0]);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
