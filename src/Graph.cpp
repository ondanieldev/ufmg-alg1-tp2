#include <list>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "Graph.h"
#include "Neighbor.h"

// as the max weight allowed is 100000, infinity may be 100001
#define INFINITY 100001

/**
 * @brief construct a new Graph:: Graph object
 *
 * @param nodes amount of vertexes in the graph
 */
Graph::Graph(int nodes)
{
  this->adjacencyList = new std::vector<Neighbor>[nodes];
  this->nodes = nodes;
}

/**
 * @brief destroy the Graph:: Graph object
 *
 */
Graph::~Graph()
{
  delete[] adjacencyList;
}

/**
 * @brief add edge by creating a neighbor and adding it to src's adjacency list
 *
 * @param src source vertex id
 * @param dst destination vertex id
 * @param w weight of the edge between source and destination
 */
void Graph::addEdge(int src, int dst, int w)
{
  Neighbor neighbor = Neighbor(dst, w);
  this->adjacencyList[src].push_back(neighbor);
}

/**
 * @brief print all src neighbors and its edge weight with the src
 *
 * @param src source vertex id
 */
void Graph::print(int src)
{
  std::cout << src << ": " << std::endl;
  for (auto &neighbor : this->adjacencyList[src])
  {
    std::cout << neighbor.key << " (" << neighbor.weight << ")\t";
  }
  std::cout << std::endl;
}

/**
 * @brief find the widest path between src and all other nodes
 *
 * @param src source vertex id
 * @param dst destination vertex id
 * @return max capacity (min weight value) on the widest path between source and destination
 */
int Graph::maxWeight(int src, int dst)
{
  // stores the max capacity from the src to each vertex
  int pi[this->nodes];
  // stores all vertexes in the graph (works as a priority queue/heap)
  std::list<int> allVertexes;

  // set up initial max capacities null and add all vertexes to the priority queue
  for (int v = 0; v < this->nodes; ++v)
  {
    pi[v] = INFINITY * (-1);
    allVertexes.push_back(v);
  }
  pi[src] = INFINITY;

  while (!allVertexes.empty())
  {
    // "u" is the vertex with the largest weight in the queue
    int u = allVertexes.front();
    for (auto &v : allVertexes)
    {
      if (pi[v] > pi[u])
      {
        u = v;
      }
    }
    allVertexes.remove(u);

    // skip unoptmized vertex
    if (pi[u] == (INFINITY * (-1)))
    {
      break;
    }

    // for each neighbor of "u" find the better edge to take (the max weigthed one)
    for (auto &neighbor : this->adjacencyList[u])
    {
      // the better weight is the max(neighbor weight, min(current vertex weight, weight bwteen current vertex and its neighbor))
      int betterWeight = std::max(pi[neighbor.key], std::min(pi[u], neighbor.weight));
      if (betterWeight > pi[neighbor.key])
      {
        pi[neighbor.key] = betterWeight;
      }
    }
  }

  // after calculating all widest paths between the src and the other vertex, return the max capacity between the src and the dst
  return pi[dst];
}