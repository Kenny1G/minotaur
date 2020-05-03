// Kenny O., Victoria S.K., Miso R., kosele01, vsubrit1, mrashed2                                   
// CS220 Final Project SP20
// astar.h

#ifndef ASTAR_H
#define ASTAR_H

#include 

class AStar {
private:
  Maze m_maze;
  Position m_start;
  Position m_goal;
  AStar(const Astar &);
  AStar &operator=(const Astar &);
public:
  AStar();
  ~AStar();
  
  std::map<Position, Position> search();

private:
  int h(Position source, Position goal);
  std::vector<Position> checkNeighbors(Position source);

}
  
#endif //ASTAR_H

