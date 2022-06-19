#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "Graph.h"
#include "Edge.h"

using namespace std;

void assertRange(int value, int min, int max, string name)
{
  if (value < min || value > max)
  {
    throw invalid_argument(name + " (" + to_string(value) + ") must be a value between " + to_string(min) + " and " + to_string(max) + ".");
  }
}

int main()
{
  try
  {
    int N, M, Q, maxM, i, u, v, w;

    cin >> N >> M >> Q;
    maxM = min(N * (N - 1), 1000);
    assertRange(N, 2, 100, "N");
    assertRange(M, 1, maxM, "M");
    assertRange(Q, 1, 1000, "Q");

    Graph graph = Graph(N);

    for (i = 0; i < M; ++i)
    {
      cin >> u >> v >> w;
      assertRange(u, 1, N, "u");
      assertRange(v, 1, N, "v");
      assertRange(w, 1, 100000, "w");
      if (u == v)
        throw invalid_argument("u and v must not be equal");
      graph.addEdge(u - 1, v - 1, w);
    }

    for (i = 0; i < Q; ++i)
    {
      cin >> u >> v;
      assertRange(u, 1, N, "u");
      assertRange(v, 1, N, "v");
      if (u == v)
        throw invalid_argument("u and v must not be equal");
      cout << graph.maxWeight(u - 1, v - 1) << endl;
    }
  }
  catch (const invalid_argument &e)
  {
    cerr << e.what() << endl;
  }
}