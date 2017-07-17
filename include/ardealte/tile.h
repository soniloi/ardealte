#ifndef TILE_H
#define TILE_H

class Tile {

private:
	bool open;

public:
	Tile();
	bool isOpen();
	void setOpen(bool open);
};

#endif
