#include "brg.h"


void normalize(double& n, const size_t min, const size_t max) {
  if (n < min)
    n = min;
  else if (n > max)
    n = max;
}

Graph BinomialRandomGraph(const size_t n, double p) {
  normalize(p, 0, 1);
  p *= 100;
  Graph brg;
  brg.adj = vector<forward_list<size_t>> (n);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i + 1; j < n; ++j) {
      double x = rand() % 100;
      if (x < p)
        brg.adj[i].push_front(j);
    }
  }
  return brg;
}
