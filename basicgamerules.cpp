//Kenny O., Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2
//CS220 Final Project SP20
//bascigamerules.cpp

#include "basicgamerules.h"
#include "maze.h"
#include "game.h"
#include "tile.h"
#include "position.h"
#include "entity.h"
#include "textui.h"


BasicGameRules::BasicGameRules(){
}

BasicGameRules::~BasicGameRules() {
}


bool BasicGameRules::allowMove(Game *game, Entity *actor, const Position &source, const Position &dest) const {
  bool move = false;
	Entity *en = game->getEntityAt(dest);
  //check if destination tile is unoccupied and if the tile's checkMoveOnto function allows the move
  if(source.distanceFrom(dest) == 1) {
		const Tile *tile = game->getMaze()->getTile(dest);
    //checks if dest is unoccupied:
    if(tile->getGlyph() != "#" && tile->checkMoveOnto(actor, dest, source) == MoveResult::ALLOW) {
      move = true;
    }
    //CASE2
    //if theres something that has property v(moveable) and that the tile adjacent to the tile in the same direction
		else if(en != nullptr ) {
      if(en->hasProperty('v')) {
				Position new_dest = dest;
				new_dest.displace(game->getUI()->getMoveDirection());
				return allowMove(game, actor, dest, new_dest);
			}
		}
		else if(en->hasProperty('m')) {
	    move = true;
	  }
	}
		return move;
}

void BasicGameRules::enactMove(Game *game, Entity *actor, const Position &dest) const {
  //if theres an inanimate object                                                                                                                             
 Entity *en = game->getEntityAt(dest);
  if(en != nullptr && en->hasProperty('v')) {
    Position new_dest	= dest;
    new_dest.displace(game->getUI()->getMoveDirection());
    if(game->getEntityAt(new_dest) != nullptr) {
      BasicGameRules::enactMove(game, actor, new_dest); 
    }
    else {
      en->setPosition(new_dest);
    }
  }

  //carries out move if the move's approved
  if(game->getGameRules()->allowMove(game, actor, actor->getPosition(),dest)) {
    actor->setPosition(dest);
  }

}

GameResult BasicGameRules::checkGameResult(Game *game) const {
  GameResult result = GameResult::UNKNOWN;
	Game::EntityVec h_vec = game->getEntitiesWithProperty('h');
	Game::EntityVec m_vec = game->getEntitiesWithProperty('m');
  
  Entity *h = h_vec[0];
  Entity *m = m_vec[0];

  Position hp = h->getPosition();
  Position mp = m->getPosition();

  
  
  if(game->getMaze()->getTile(hp)->isGoal()){
    result = GameResult::HERO_WINS;
  }
  else if(hp == mp) {
      result = GameResult::HERO_LOSES;
  }
  return result;
  
}
