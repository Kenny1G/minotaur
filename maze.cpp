#include "maze.h"
#include "position.h"
#include "tile.h"
#include "tilefactory.h"

Maze::Maze(int width, int height):
m_width(width),
m_height(height)
{
}
Maze::~Maze(){

}

// Get the width of the Maze
int Maze::getWidth() const {
	return m_width;
}

// Get the height of the Maze
int Maze::getHeight() const {
	return m_height;
}

// Return true if the specified position is in bounds
// according to the Maze's width and height.
bool Maze::inBounds(const Position &pos) const {
	return pos.inBounds(m_width, m_height);	
}

// Set a Tile at the specified Position.  The Maze assumes responsibility
// for deleting the Tile.
void Maze::setTile(const Position &pos, Tile *tile) {
	m_tiles[posToIndex(pos)] = tile;
}

// Get the Tile at the specified Position.
const Tile *Maze::getTile(const Position &pos) const {
	return m_tiles[posToIndex(pos)];
}

// Read a description of a Maze from specified istream, and return it.
Maze *Maze::read(std::istream &in) {
	//initialize Maze
	int tHeight, tWidth;
	in >> tWidth >> tHeight;
	Maze *mz = new Maze(tWidth, tHeight);

	//populate Maze
	char tile_char;
	TileFactory *tf = TileFactory::getInstance();
	for(int i = 0; i < tHeight * tWidth; ++i) {
		in >> tile_char;
		Tile *tile_ptr = tf->createFromChar(tile_char);
		if (tile_ptr == nullptr) {
			return nullptr;
		}
		mz->m_tiles.push_back(tile_ptr);
	}	
	return mz;
}

int Maze::posToIndex(const Position &pos) const {
	return ((pos.getY() * m_width) + pos.getX());
}

