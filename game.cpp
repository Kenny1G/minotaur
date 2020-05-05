#include "game.h"
#include "entity.h"
#include "maze.h"
#include "ui.h"
#include "gamerules.h"
#include "entitycontroller.h"
#include "uicontrol.h"
#include "chasehero.h"
#include "astarchasehero.h"
#include "inanimate.h"
#include <vector>
#include <iostream>
#include <sstream>

Game::Game():
m_lastMove(Direction::NONE),
m_maze(nullptr),
m_ui(nullptr),
m_gameRules(nullptr),
m_entities(new EntityVec)
{}
Game::~Game() {
	for (EntityVec::iterator it = m_entities->begin(); it != m_entities->end(); ++it) {
		delete *it;
	}
	delete m_maze;
	delete m_ui;
	delete m_gameRules;
	delete m_entities;
}

// Add an Entity to the sequence of entities. The Game object assumes
// responsibility for deleting it.
void Game::addEntity(Entity *entity) {
	m_entities->push_back(entity);
}

// Get the Entity at the specified Position.  Return nullptr if
// there is no Entity at the specified Position.
Entity* Game::getEntityAt(const Position &pos) {
	Entity *entity = nullptr;
		for (EntityVec::iterator it = m_entities->begin(); it != m_entities->end(); ++it) {
			if ((*it)->getPosition() == pos) {
				entity = *it;
			}
		}
		return entity;
}

// Get a vector of pointers to Entity objects that have the
// specified property. The vector could be empty if no Entity objects
// have the specified property.
Game::EntityVec Game::getEntitiesWithProperty(char prop) const {
	EntityVec ev;
	for(EntityVec::iterator it = m_entities->begin(); it != m_entities->end(); ++it) {
		if((*it)->hasProperty(prop)) {
			ev.push_back(*it);
		}
	}
	return ev;
}

// Let the Entity objects take turns in round-robin fashion until
// the GameRules object determines that the hero has won or lost.
// Should call the render member function on the UI object just before
// an Entity whose EntityController is controlled by the user takes
// a turn.
void Game::gameLoop() {
	GameResult result = m_gameRules->checkGameResult(this);
	while (result == GameResult::UNKNOWN) {
		for (EntityVec::iterator it = m_entities->begin(); it != m_entities->end(); ++it) {
			if ((*it)->getController()->isUser()) {
				m_ui->render(this);
			}
			takeTurn(*it);
			result = m_gameRules->checkGameResult(this);
			if(result != GameResult::UNKNOWN) {
				break;
			}
		}
	}
	if (result == GameResult::HERO_LOSES) {
		m_ui->displayMessage("DEFEAT");
	} 
	else {
		m_ui->displayMessage("VICTORY");
	}
	m_ui->render(this);

}

// Let specified actor Entity take a turn.
// This is public so that it can be called from
// unit tests.  It is mainly intended to be called from
// the gameLoop member function.
void Game::takeTurn(Entity *actor) {
	EntityController *controller = actor->getController();

	Direction toWherestDoIGo = controller->getMoveDirection(this, actor);
	if(!actor->hasProperty('v')) {
		m_lastMove = toWherestDoIGo;
	}
	Position fromWherestDoICome = actor->getPosition();
	int x = fromWherestDoICome.getX();
	int y = fromWherestDoICome.getY();

	switch (toWherestDoIGo) {
		case Direction::DOWN:
			y++;
			break;
		case Direction::UP:
			y--;
			break;
		case Direction::LEFT:
			x--;
			break;
		case Direction::RIGHT:
			x++;
			break;
		default:
			return;
			break;
	}

	Position *wherestILand = new Position(x,y);
	if (m_gameRules->allowMove(this, actor, fromWherestDoICome, *wherestILand)) {
		m_gameRules->enactMove(this, actor, *wherestILand);
	}
	else {
		if (controller->isUser()) {
			m_ui->displayMessage("Illegal Move",false);
		}
	}
	delete wherestILand;
}

// Read initial Game data from the specified istream, and return
// the resulting Game object.
Game *Game::loadGame(std::istream &in) {
	//valorant is the name of our game :)
	Game *valorant = new Game();
	valorant->setMaze(Maze::read(in));

	int x,y;
	std::string entire;
	getline(in, entire);
	std::stringstream str(entire);
	unsigned int index = 0;
	while(index < entire.length()) {
		Entity *ent = new Entity();
		std::string properties;
		str >> properties;
		if (properties.length() != 3) {
			delete ent;
			return nullptr;
		}
		ent->setGlyph(properties.substr(0,1));
		switch (properties.at(1)) {
			case 'u':
				ent->setController(new UIControl());
				break;
			case 'c':
				ent->setController(new ChaseHero());
				break;
			case 'a':
				ent->setController(new AStarChaseHero());
				break;
			case 'i':
				ent->setController(new Inanimate());
				break;
			default:
				return nullptr;
		}
		ent->setProperties(properties.substr(2));
		index += 4;
		str >> x >> y;
		Position pos = Position(x,y);
		int sizeofX = std::to_string(x).length();
		int sizeofY = std::to_string(y).length();

		index += sizeofX + sizeofY + 2;
		ent->setPosition(pos);
		valorant->addEntity(ent);
	}
return valorant;
}


/*Setters and Getters*/

// Get a const reference to the Game object's internal vector
// of pointers to Entity objects.
const Game::EntityVec& Game::getEntities() const {
	return *m_entities;
}

// Set the Maze object. The Game object assumes responsibility for
// deleting it.
void Game::setMaze(Maze *maze) {
	m_maze = maze;
}

// Set the UI object. The Game object assumes responsibility for
// deleting it.
void Game::setUI(UI *ui) {
	m_ui = ui;
}

// Set the GameRules object. The Game object assumes responsibility for
// deleting it.
void Game::setGameRules(GameRules *gameRules) {
	m_gameRules = gameRules;
}
// Get the Maze object.
Maze* Game::getMaze() {
	return m_maze;
}

// Get the UI object.
UI* Game::getUI() {
	return m_ui;
}

// Get the GameRules object.
GameRules* Game::getGameRules() {
	return m_gameRules;
}

