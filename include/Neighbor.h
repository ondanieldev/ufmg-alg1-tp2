/**
 * @file Neighbor.h
 * @brief TAD to store vertex neighbors
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