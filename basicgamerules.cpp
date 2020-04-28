//Kenny O., Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2
//CS220 Final Project SP20
//bascigamerules.cpp

#include "basicgamerules.h"
#include "maze.h"

BasicGameRules::BasicGameRules(const BasicGameRules &){
}

BasicGameRules::~BasicGameRules() {
}


bool BasicGameRules::allowMove(Game *game, Entity *actor, const Position &source, const Position &dest) const {
  bool move = false;
  //check if destination tile is unoccupied and if the tile's checkMoveOnto function allows the move

  //checks if dest is unoccupied:
  /*if(tile.getGlyph() != "#" &&  ) {
    move = true;
    }*/

  //checking that the source is only one away from the destination
  if(source.distanceFrom(dest) == 1) {
    move = true;
  }

  //CASE2
  //if theres something that has property v(moveable) and that the tile adjacent to the tile in the same direction
  /*else if( ) {
    
    }*/
  
  return move;
}

void BasicGameRules::enactMove(Game *game, Entity *actor, const Position &dest) const {

  //carries out move if the move's approved
  if(BasicGameRules::allowmove) {
    actor.setPosition(dest);
  }
  //if theres an inanimate object
}

GameResult BasicGameRules::checkGameResult(Game *game) const {
  GameResult result;
  Tile::Tile = Maze::getTile(dest) 
    //if(actor.hasProperty('h')){
    //  result = HERO_WINS;
    //}
    //else if(entity.hasProperty('m')'s position is the same as the entity w prop 'h') {
    //  result = HERO_LOSES;
    //}
    //else {
    //  result = UNKNOWN;
    //}
  return result;
}
