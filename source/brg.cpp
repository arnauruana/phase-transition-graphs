#include "brg.h"


Graph BinomialRandomGraph(const size_t n, double p) {
  if (p < 0)
    p = 0;
  else if (p > 1)
    p = 1;
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
