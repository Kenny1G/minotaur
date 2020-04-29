#include "game.h"
#include "entity.h"

Game::Game():
m_maze(0),
m_ui(0),
m_gameRules(0)
{}
Game::~Game() {}

// Add an Entity to the sequence of entities. The Game object assumes
// responsibility for deleting it.
void Game::addEntity(Entity *entity) {

}

// Get the Entity at the specified Position.  Return nullptr if
// there is no Entity at the specified Position.
Entity* Game::getEntityAt(const Position &pos) {
	return nullptr;
}

// Get a const reference to the Game object's internal vector
// of pointers to Entity objects.
const Game::EntityVec& Game::getEntities() const {

}

// Get a vector of pointers to Entity objects that have the
// specified property. The vector could be empty if no Entity objects
// have the specified property.
Game::EntityVec Game::getEntitiesWithProperty(char prop) const {

}

// Let the Entity objects take turns in round-robin fashion until
// the GameRules object determines that the hero has won or lost.
// Should call the render member function on the UI object just before
// an Entity whose EntityController is controlled by the user takes
// a turn.
void Game::gameLoop() {

}

// Let specified actor Entity take a turn.
// This is public so that it can be called from
// unit tests.  It is mainly intended to be called from
// the gameLoop member function.
void Game::takeTurn(Entity *actor) {

}

// Read initial Game data from the specified istream, and return
// the resulting Game object.
static Game Game::*loadGame(std::istream &in) {

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

