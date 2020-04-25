#include "floor.h"
#include "tile.h"
Floor::Floor()
{}
Floor::~Floor()
{}

MoveResult Floor::checkMoveOnto(Entity *entity, const Position &fromPos, const Position &tilePos) const
{
	return MoveResult::ALLOW;
}


bool Floor::isGoal() const
{
	return true;
}


std::string Floor::getGlyph() const
{
	return "";
}
