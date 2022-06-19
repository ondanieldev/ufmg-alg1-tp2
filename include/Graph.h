/**
 * @file Graph.h
 * @brief TAD to store cities as a graph
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#include "Neighbor.h"

class Graph
{
private:
  int nodes;
  std::vector<Neighbor> *adjacencyList;

public:
  Graph(){};
  Graph(int nodes);
  ~Graph();
  void addEdge(int src, int dst, int w);
  void print(int src);
  int maxWeight(int src, int dst);
};

#endif