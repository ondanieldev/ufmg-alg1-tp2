#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>

#include "Graph.h"
#include "Edge.h"

Graph::Graph(int nodes)
{
  this->adjacencyList = new std::vector<Edge>[nodes];
  this->nodes = nodes;
}

Graph::~Graph()
{
  delete[] adjacencyList;
}

void Graph::addEdge(int src, int dst, int w)
{
  Edge edge = Edge(src, dst, w);
  this->adjacencyList[src].push_back(edge);
}

void Graph::print(int src)
{
  std::cout << src << ": " << std::endl;
  for (auto &edge : this->adjacencyList[src])
  {
    std::cout << edge.dst << " (" << edge.weight << ")\t";
  }
  std::cout << std::endl;
}
