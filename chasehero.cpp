// Kenny O., Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2
// CS220 Final Project SP20
//chasehero.cpp
#include "chasehero.h"
#include "position.h"
#include "game.h"
#include "entity.h"
#include "gamerules.h"

ChaseHero::ChaseHero() {

}
ChaseHero::~ChaseHero() {

}

Direction ChaseHero::getMoveDirection(Game *game, Entity *entity) {
  //determine horizontal and vertical distance from min to hero
  //largest distance of vert and horz, moves that way
  //if equal move horizontal


  //make direction
  Direction direction = Direction::NONE;
  
  //find heros
  Game::EntityVec h_vec = game ->getEntitiesWithProperty('h');
  Entity *hero;
  
  //get positon of minotaur
  Position mp = entity->getPosition();

  int x_m = mp.getX();
  int y_m = mp.getY();


  hero = h_vec[0];
	  //find which is the closest hero
  int dist = mp.distanceFrom(h_vec[0]->getPosition());
  for (Game::EViterator i = h_vec.begin() + 1; i != h_vec.end(); i++) {
    int new_dist = mp.distanceFrom((*i)->getPosition());
    if (new_dist < dist) {
      dist = new_dist;
      hero = *i;
    }
  }


  //position of hero
  Position hp = hero->getPosition();
  int x_h = hp.getX();
  int y_h = hp.getY();

 
  //Get distance from minitaur to hero
  int x_dif = x_h - x_m;
  int x_dif_abs = x_dif;
  if(x_dif < 0) {
		 x_dif_abs = -x_dif_abs;
  }
  int y_dif = y_h - y_m;

  int y_dif_abs = y_dif;
  if (y_dif < 0) {
    y_dif_abs = -y_dif_abs;
  }
  
  //dertemine direction
  if (x_dif_abs > y_dif_abs){
    if (x_dif < 0) {
      direction = Direction::LEFT;
    }
    else {
      direction = Direction::RIGHT;
    }
  }
  else if (x_dif_abs < y_dif_abs) {
        if (y_dif < 0) {
      direction = Direction::UP;
    }
    else {
      direction = Direction::DOWN;
    }
  }
  else {
    if (x_dif < 0) {
      direction = Direction::LEFT;
    }
    else {
      direction = Direction::RIGHT;
    }
  }


  return direction;
}

bool ChaseHero::isUser() const {
  return false;
}
