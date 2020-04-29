//Kenny O., Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2
//CS220 Final Project SP20
//bascigamerules.cpp

#include "basicgamerules.h"
#include "maze.h"
#include "game.h"
#include "tile.h"
#include "position.h"
#include "entity.h"


BasicGameRules::BasicGameRules(const BasicGameRules &){
}

BasicGameRules::~BasicGameRules() {
}


bool BasicGameRules::allowMove(Game *game, Entity *actor, const Position &source, const Position &dest) const {
  bool move = false;
  //check if destination tile is unoccupied and if the tile's checkMoveOnto function allows the move
  if(source.distanceFrom(dest) == 1) {
    //checks if dest is unoccupied:
    if(tile.getGlyph() != "#" && MoveResult::checkMoveOnto == ALLOW) {
      move = true;
    }
    
    
    //CASE2
    //if theres something that has property v(moveable) and that the tile adjacent to the tile in the same direction
    Entity::Entity *en = Game::getEntityAt(dest);
    else if(!en == NULL ) {
      if(en.hasProperty('v') {
	  Position::Position new_dest = dest;
	  new_dest.displace(actor.TextUI::getMoveDirection());
	  return allowMove(game, actor, dest, new_dest);
	}
	else if(en.hasProperty('m') {
	    move = true;
	  }
	  }
	}
      return move;
  }

void BasicGameRules::enactMove(Game *game, Entity *actor, const Position &dest) const {
  //if theres an inanimate object                                                                                                                             
  Entity::Entity *en = Game::getEntityAt(dest);
  if(!en == NULL && en.hasProperty('v')) {
    Position::Position new_dest	= dest;
    new_dest.displace(actor.TEXTUI::getMoveDirection());
    if(Game::getEntityAt(new_dest) != NULL) {
      BasicGameRules::enactMove(game, actor, new_dest); 
    }
    else {
      en.setPosition(new_dest);
    }
  }

  //carries out move if the move's approved
  if(BasicGameRules::allowMove()) {
    actor.setPosition(dest);
  }

}

GameResult BasicGameRules::checkGameResult(Game *game) const {
  GameResult result = UNKNOWN;
  Game::EntityVec h_vec = Game::getEntitiesWithProperty('h');
  Game::EntityVec m_vec = Game::getEntitiesWithProperty('m');
  
  Entity::Entity h = h_vec[0];
  Entity::Entity m = m_vec[0];

  Position::Postion hp = h.Entity::getPosition();
  Position::Postion mp = m.Entity::getPosition();

  
  
  if(hp.isGoal()){
    result = HERO_WINS;
  }
  else if(hp == mp) {
      result = HERO_LOSES;
  }
  return result;
  
}
