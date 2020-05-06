#include "textui.h"
#include "position.h"
#include "game.h"
#include "maze.h"
#include "tile.h"
#include "floor.h"
#include "wall.h"
#include "goal.h"
#include "entity.h"
#include "gamerules.h"
#include <iostream>
#include <sstream>


TextUI::TextUI():
m_msg("")
{}

TextUI::~TextUI() {}

Direction TextUI::getMoveDirection() {
  std::string input_token;
  std::cout << "Your move (u/d/l/r): ";
  std::cin >> input_token;

  switch (input_token.at(0)) 
  {
    case ('u'): return Direction::UP;
    case ('d'): return Direction::DOWN;
    case ('l'): return Direction::LEFT;
    case ('r'): return Direction::RIGHT;
    default:
     std::cout << "Unknown direction ";
     return getMoveDirection();
  }
}

void TextUI::displayMessage(const std::string &msg, bool) {
  m_msg = msg;
}

void TextUI::render(Game *game) {
  // print maze
	Maze *m = game->getMaze();
	int w = m->getWidth();
	int h = m->getHeight();
	for(int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			Position currentPos = Position(x,y);
			Entity *currentEntity = game->getEntityAt(currentPos);
			if ( currentEntity == nullptr) {
				std::cout << m->getTile(currentPos)->getGlyph();
			}
			else {
				std::cout << currentEntity->getGlyph();
			}
		}
		std::cout << std::endl;
	}
  
  if (!m_msg.empty()) {
			std::cout << ": " << m_msg << std::endl;
    m_msg = "";
  }
}
