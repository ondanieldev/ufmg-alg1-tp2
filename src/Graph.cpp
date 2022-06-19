#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <list>
#include <algorithm>

#include "Graph.h"
#include "Edge.h"

#define INFINITY 100001

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

int Graph::maxWeight(int src, int dst)
{
  int pi[this->nodes];
  std::list<int> priorityQueue;

  for (int v = 0; v < this->nodes; ++v)
  {
    pi[v] = INFINITY * (-1);
    priorityQueue.push_back(v);
  }
  pi[src] = INFINITY;

  while (!priorityQueue.empty())
  {
    int u = priorityQueue.front();
    for (auto &v : priorityQueue)
    {
      if (pi[v] > pi[u])
      {
        u = v;
      }
    }
    priorityQueue.remove(u);

    if (pi[u] == (INFINITY * (-1)))
    {
      break;
    }

    for (auto &edge : this->adjacencyList[u])
    {
      int betterWeight = std::max(pi[edge.dst], std::min(pi[u], edge.weight));
      if (betterWeight > pi[edge.dst])
      {
        pi[edge.dst] = betterWeight;
      }
    }
  }

  return pi[dst];
}