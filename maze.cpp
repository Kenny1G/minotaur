#include "maze.h"

Maze::Maze(int width, int height)
{

}
Maze::~Maze(){

}

// Get the width of the Maze
int Maze::getWidth() const {

}

// Get the height of the Maze
int Maze::getHeight() const {

}

// Return true if the specified position is in bounds
// according to the Maze's width and height.
bool Maze::inBounds(const Position &pos) const {

}

// Set a Tile at the specified Position.  The Maze assumes responsibility
// for deleting the Tile.
void Maze::setTile(const Position &pos, Tile *tile) {

}

// Get the Tile at the specified Position.
const Tile Maze::*getTile(const Position &pos) const {

}

// Read a description of a Maze from specified istream, and return it.
static Maze Maze::*read(std::istream &in) {

}

