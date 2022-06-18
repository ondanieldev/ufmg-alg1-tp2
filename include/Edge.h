#ifndef EDGE_H
#define EDGE_H

class Edge
{
private:
  int src;
  int dst;
  int weight;

public:
  Edge(){};
  Edge(int src, int dst, int weight);
  int getSrc();
  int getDst();
  int getWeight();

  friend class Graph;
};

#endif