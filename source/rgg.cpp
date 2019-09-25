#include "rgg.h"

struct Vertex {
	double x, y; //Coordinates, between 0-999 (TO-DO: Is this the correct approach?)
};

void vertexCoordRand(vector<Vertex> v) {
	for (size_t i = 0; i < n; i++) {
		v[i].x = rand() % 1000;
		v[i].y = rand() % 1000;
	}
}

bool distance(vector<Vertex> v, int i, double r) {
	double x_diff = v[i].x - v[i + 1].x;
	double y_diff = v[i].y - v[i + 1].y;
	double dist = std::sqrt(x_diff * x_diff + y_diff * y_diff);
	if (dist < r) return true;
	return false;
}

Graph RandomGeometricGraph(const size_t n, double r) {
  Graph rgg;
  rgg.adj = vector<forward_list<size_t>> (n);
  vector<Vertex>(n) v;
  vertexCoordRand(v);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i + 1; j < n; ++j) {
      if (distance(v, i, r)) rgg.adj[i].push_front(j);
    }
  }
  return rgg;
}