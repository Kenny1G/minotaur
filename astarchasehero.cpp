//Kenny O, Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2 
//CS220 Final Project SP20
//astarchasehero.cpp

#include "astarchasehero.h"
#include "assert.h"
#include "game.h"
#include "entity.h"
#include "position.h"

AStarChaseHero::AStarChaseHero() {
}

AStarChaseHero::~AStarChaseHero() {
}

Direction AStarChaseHero::getMoveDirection(Game *game, Entity *entity) {
  //make direction                                                                                  
  Direction direction = Direction::NONE;

  //find heros                                                                                      
  Game::EntityVec h_vec = game ->getEntitiesWithProperty('h');
  Entity *hero;

  //get positon of minotaur                                                                         
  Position mp = entity->getPosition();
  int x_m = mp.Position::getX();
  int y_m = mp.Position::getY();

  //find which is the closest hero                                                                  
  int dist = hm.Position::distanceFrom(h_vec[0]);
  hero = h_vec[0];
  for (EntityVec::iterator i = h_vec.begin() + 1; i != h_vec.end(); i++) {
    int new_dist = hm.Position::distanceFrom(h_vec[i]);
    if (new_dist < dist) {
      dist = new_dist;
      hero = h_vec[i];
    }
  }

  //position of hero                                                                                
  Position hp = hero->getPosition();
  int x_h = hp.Position::getX();
  int y_h = hp.Position::getY();

  
  return direction;
}

bool AStarChaseHero::isUser() const {
  return false;
}
