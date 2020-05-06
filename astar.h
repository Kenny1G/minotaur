// Kenny O., Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2                                   
// CS220 Final Project SP20
// astar.h

#ifndef ASTAR_H
#define ASTAR_H

#include <map>
#include <vector>

class Maze;
class Position;
class AStar {
private:
  Maze *m_maze;
  Position *m_start;
  Position *m_goal;
  AStar(const AStar &);
  AStar &operator=(const AStar &);
public:
  AStar(Maze*, Position*, Position*);
  ~AStar();
  
  std::map<Position, Position> search();

private:
  int h(Position);
  std::vector<Position> getNeighbors(Position source);

};
  
#endif //ASTAR_H

