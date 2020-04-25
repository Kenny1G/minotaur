#include "wall.h"

Wall::Wall(){}
Wall::~Wall(){}

MoveResult Wall::checkMoveOnto(Entity *entity, const Position &fromPos, const Position &tilePos) const{}


bool Wall::isGoal() const{}


std::string Wall::getGlyph() const{}