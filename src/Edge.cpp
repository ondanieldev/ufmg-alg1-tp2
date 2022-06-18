#include "Edge.h"

Edge::Edge(int src, int dst, int weight)
{
  this->src = src;
  this->dst = dst;
  this->weight = weight;
}

int Edge::getSrc()
{
  return this->src;
}

int Edge::getDst()
{
  return this->dst;
}

int Edge::getWeight()
{
  return this->weight;
}
