#include "maze.h"
#include "position.h"
#include "tile.h"
#include "tilefactory.h"

Maze::Maze(int width, int height):
m_width(width),
m_height(height),
m_tiles(new TileVec(width * height))
{
}

Maze::~Maze(){
	for (TileVec::iterator it = m_tiles->begin(); it != m_tiles->end(); ++it) {
		delete *it;
	}
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
	if (inBounds(pos)) {
		m_tiles->at(posToIndex(pos)) = tile;
	}
}

// Get the Tile at the specified Position.
const Tile *Maze::getTile(const Position &pos) const {
	return m_tiles->at(posToIndex(pos));
}

// Read a description of a Maze from specified istream, and return it.
Maze *Maze::read(std::istream &in) {
	//initialize Maze
	int tHeight, tWidth;
	Tile *tile_ptr;
	TileFactory *tf = TileFactory::getInstance();

	in >> tWidth >> tHeight;
	if (tWidth == 0 || tHeight == 0) {
		return nullptr;
	}
	Maze *mz = new Maze(tWidth, tHeight);

	//populate Maze
	char tile_char;
	in.get(tile_char); // get rid of last \n
	for(int r = 0; r < tHeight; ++r) {
		for (int c = 0; c < (tWidth); ++c) {
			in.get(tile_char);
			if  (tile_char != '\n') {
				tile_ptr = tf->createFromChar(tile_char);
				if (tile_ptr == nullptr) return nullptr; 
				const Position *tPos = new Position(c,r);
				mz->m_tiles->at(mz->posToIndex(*tPos)) = tile_ptr; 
			}
		}
		in.get(tile_char);
		if (tile_char != '\n')  return nullptr;
	}	
	
	return mz;
}

int Maze::posToIndex(const Position &pos) const {
	return ((pos.getY() * m_width) + pos.getX());
}

