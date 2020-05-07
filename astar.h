// Kenny O., Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2                                   
// CS220 Final Project SP20
// astar.h

#ifndef ASTAR_H
#define ASTAR_H

#include <map>
#include <vector>
#include <queue>

class Maze;
class Position;
class Game;
class AStar {
private:
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
	Game *m_game;
  Maze *m_maze;
  Position *m_start;
  Position *m_goal;
  AStar(const AStar &);
  AStar &operator=(const AStar &);
public:
  AStar(Game*, Maze*, Position*, Position*);
  ~AStar();
  
  std::map<Position, Position> search();

private:
  int h(Position);
  std::vector<Position> getNeighbors(Position source);

};
  
#endif //ASTAR_H