//Kenny O, Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2 
//CS220 Final Project SP20
//uicontrol.cpp

#include "uicontrol.h"
#include "game.h"
#include "ui.h"
UIControl::UIControl() {
}
UIControl::~UIControl() {
}

Direction UIControl::getMoveDirection(Game *game, Entity *entity) {
	return game->getUI()->getMoveDirection();
}
bool UIControl::isUser() const {
	return true;
}
