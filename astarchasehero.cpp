//Kenny O, Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2 
//CS220 Final Project SP20
//astarchasehero.cpp

#include "astarchasehero.h"
#include "assert.h"
#include "game.h"
#include "entity.h"
#include "position.h"
#include "astar.h"
#include <map>
#include <bits/stdc++.h>

AStarChaseHero::AStarChaseHero() {
}

AStarChaseHero::~AStarChaseHero() {
}


Direction AStarChaseHero::getMoveDirection(Game *game, Entity *entity) {
  //make direction                                                                                  
  Direction direction = Direction::NONE;
  
  //find heros
  Game::EntityVec h_vec = game ->getEntitiesWithProperty('h');
  
  //get positon of minotaur
  Position mp = entity->getPosition();
	int x_m = mp.getX();
  int y_m = mp.getY();

  Entity *hero;
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
	
	AStar *pathCreator = new AStar(game, game->getMaze(), &mp, &hp);
	std::map<Position, Position> pathMap = pathCreator->search();
	std::vector<Position> reversePath;
	Position wanted = hp;
	while (wanted != mp) {
			reversePath.push_back(wanted);
			wanted = pathMap[wanted];
	}
	std::reverse(reversePath.begin(), reversePath.end());

	int x_new = reversePath.at(0).getX();
	int y_new = reversePath.at(0).getY();

	int y_diff = y_new - y_m;
	int x_diff = x_new - x_m;

	if (y_new == y_m) {
		if (x_diff < 0) {	
			direction = Direction::LEFT;			
		}
		else if(x_diff > 0) {
			direction = Direction::RIGHT;		
		}
	}
	else if(x_new == x_m) {
		if(y_diff < 0) {
			direction = Direction::UP;
		}
		else if(y_diff > 0) {
			direction = Direction::DOWN;
		}
	}
	delete pathCreator;

  return direction;
}

bool AStarChaseHero::isUser() const {
  return false;
}