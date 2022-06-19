#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <list>
#include <algorithm>

#include "Graph.h"
#include "Neighbor.h"

#define INFINITY 100001

Graph::Graph(int nodes)
{
  this->adjacencyList = new std::vector<Neighbor>[nodes];
  this->nodes = nodes;
}

Graph::~Graph()
{
  delete[] adjacencyList;
}

void Graph::addEdge(int src, int dst, int w)
{
  Neighbor neighbor = Neighbor(dst, w);
  this->adjacencyList[src].push_back(neighbor);
}

void Graph::print(int src)
{
  std::cout << src << ": " << std::endl;
  for (auto &neighbor : this->adjacencyList[src])
  {
    std::cout << neighbor.key << " (" << neighbor.weight << ")\t";
  }
  std::cout << std::endl;
}

int Graph::maxWeight(int src, int dst)
{
  int pi[this->nodes];
  std::list<int> allVertexes;

  for (int v = 0; v < this->nodes; ++v)
  {
    pi[v] = INFINITY * (-1);
    allVertexes.push_back(v);
  }
  pi[src] = INFINITY;

  while (!allVertexes.empty())
  {
    int u = allVertexes.front();
    for (auto &v : allVertexes)
    {
      if (pi[v] > pi[u])
      {
        u = v;
      }
    }
    allVertexes.remove(u);

    if (pi[u] == (INFINITY * (-1)))
    {
      break;
    }

    for (auto &neighbor : this->adjacencyList[u])
    {
      int betterWeight = std::max(pi[neighbor.key], std::min(pi[u], neighbor.weight));
      if (betterWeight > pi[neighbor.key])
      {
        pi[neighbor.key] = betterWeight;
      }
    }
  }

  return pi[dst];
}