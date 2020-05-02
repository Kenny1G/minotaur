//Kenny O, Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2 
//CS220 Final Project SP20
//inanimate.cpp


#include "inanimate.h"
Inanimate::Inanimate() {
}

Inanimate::~Inanimate() {
}

Direction Inanimate::getMoveDirection(Game*, Entity*) {
  return Direction::NONE;
}


bool Inanimate::isUser() const {
  return false;
}
