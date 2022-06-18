/*
  TAD to store map as a graph
  - graph implemented using adjacency list
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Edge.h"

class Graph
{
private:
  int nodes;
  std::vector<Edge> *adjacencyList;

public:
  Graph(){};
  Graph(int nodes);
  ~Graph();
  void addEdge(int src, int dst, int w);
  void print(int src);
  int maxWeight(int src, int dst);
};

#endif