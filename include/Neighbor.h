/*
  TAD to store vertex neighbors
  - @attr key
    is the neighbor id
  - @attr weight
    is the edge weight between the vertex and its neighbor
*/

#ifndef NEIGHBOR_H
#define NEIGHBOR_H

class Neighbor
{
private:
  int key;
  int weight;

public:
  Neighbor(){};
  Neighbor(int key, int weight);

  friend class Graph;
};

#endif