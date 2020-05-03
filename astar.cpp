// Kenny O., Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2                                   
// CS220 Final Project SP20                                                                         
// astar.cpp 

#include "position.h"
#include "astar.h"
#include "game.h"
#include "tile.h"
#include "maze.h"
#include "entity.h"

using std::map; using std::vector; using std::priority_queue; using std::unordered_map;

AStar::AStar(Maze m_maze, Position m_start, Position m_goal) {
  m_maze = m_maze;
  m_start = m_start;
  m_goal = m_goal;
}


AStar::~AStar() {}

map<Position, Position> AStar::search() {
  priority_queue<Position> board;
  map<Position, Postion> camefrom;
  unordered_map<Postion, int> cost_so_far;
  
  board.put(m_start, 0);
  camefrom[m_start] = m_start;
  cost_so_far[m_start] = 0;

  while(!board.empty()) {
    Postion curr = board.get();

    if (curr == m_goal){
      break;
    }
    
    for(Postion next: checkNeighbors(curr)){
      int new_cost = cost_so_far[curr] + 1;
      if(cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next]){
	cost_so_far[next] = new_cost;
	int priority = new_cost + h(next, m_goal);
	board.put(next, priority);
	camefrom[next] = curr;
      }
    }
  }
  return camefrom;
}

int AStar::h(Postion source, Position goal) {
  //h(n) function calls distanceFrom on the positions
  int d = source.distanceFrom(goal);
  return d;
}

vector<Position> AStar::checkNeighbors(Position source) {
  Entity *victoria = new Entity();
  vector<Position> neigh;
  victoria.setPosition(source);

  for (int i = 0; i < m_maze.getHeight(); i++) {
    for (int c = 0; c < m_maze.getWidth(); c++) {
      Position *curr = new Position (c, i);
      if(std::abs(source.getX() - curr->getX()) == 1 && source.getY() - curr.getY() == 0 || std::abs(source.getY() - curr->getY()) == 1 && source.getX() - curr.getX() == 0) {
	if (m_maze.getTile(curr).checkMoveOnto(victoria, source, m_maze.getTile(curr)) == MoveDirection::ALLOW) {
	    neigh.push_back(curr);
	    delete curr;
	}
      }
    }
  }
  delete victoria;
  return neigh;
}
