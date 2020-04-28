//Kenny O., Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2
//CS220 Final Project SP20
//bascigamerules.cpp

#inlcude "basicgamerule.h"

BasicGameRules::BasicGameRules(const BasicGameRules &){
}

BasicGameRules::~BasicGameRules() {
}

bool BasicGameRule::allowMove(Game *game, Entity *actor, const Position &source, const Position &dest) const {
  
}

void BasicGameRule::enactMove(Game *game, Entity *actor, const Position &dest) const {

}

GameResult BasicGameRule::checkGameResult(Game *game) const {

}
