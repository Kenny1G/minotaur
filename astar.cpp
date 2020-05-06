// Kenny O., Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2                                   
// CS220 Final Project SP20                                                                         
// astar.cpp 

#include "position.h"
#include "astar.h"
#include "game.h"
#include "tile.h"
#include "maze.h"
#include "entity.h"
#include <queue>
#include <map>

#include <iostream>

typedef struct {
  typedef std::pair<int, Position> PQElement;
  std::priority_queue<PQElement, std::vector<PQElement>,
                 std::greater<PQElement>> elements;


  inline bool empty() const {
     return elements.empty();
  }

  inline void put(int priority,Position pos) {
    elements.emplace(priority, pos);
  }

  Position get() {
    Position best_item = elements.top().second;
    elements.pop();
    return best_item;
  }
}PriorityQueue;

using std::vector; using std::priority_queue; using std::map;

AStar::AStar(Maze *maze, Position *start, Position *goal):
m_maze(maze),
m_start(start),
m_goal(goal) {
}


AStar::~AStar() {}

std::map<Position, Position> AStar::search() {
  PriorityQueue board;
  map<Position, Position> camefrom;
  map<Position, int> cost_so_far;
  
  board.put(0, *m_start);
  camefrom[*m_start] = *m_start;
  cost_so_far[*m_start] = 0;

  while(!board.empty()) {
    Position curr = board.get();

    if (curr == *m_goal){
      break;
    }
		for (std::vector<Position>::iterator it = getNeighbors(curr).begin(); it != getNeighbors(curr).end(); it++) {
			std::cout << it->getX() << " " << it->getY() <<std::endl;
		}
    
    for(Position next : getNeighbors(curr)){
      int new_cost = cost_so_far[curr] + 1;
      if(cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next]){
					cost_so_far[next] = new_cost;
					int priority = new_cost + h(next);
					board.put(priority, next);
					camefrom[next] = curr;
      }
    }
  }
  return camefrom;
}

int AStar::h(Position source) {
  //h(n) function calls distanceFrom on the positions
  int d = source.distanceFrom(*m_goal);
  return d;
}

vector<Position> AStar::getNeighbors(Position source) {
  Entity *victoria = new Entity();
  vector<Position> neigh;
  victoria->setPosition(source);

  for (int i = 0; i < m_maze->getHeight(); i++) {
    for (int c = 0; c < m_maze->getWidth(); c++) {
      Position *curr = new Position (c, i);
      if((std::abs(source.getX() - curr->getX()) == 1 && source.getY() - curr->getY() == 0) || (std::abs(source.getY() - curr->getY()) == 1 && source.getX() - curr->getX() == 0)) {
				if (m_maze->getTile(*curr)->checkMoveOnto(victoria, source, *curr) == MoveResult::ALLOW) {
						neigh.push_back(*curr);
						delete curr;
				}
      }
    }
  }
  delete victoria;
  return neigh;
}
