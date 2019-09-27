#include "graph.h"
#include "doctest.h"

#include <cmath>

using namespace std;

void setVertexCoordRand(Graph::Vertex& v) {
	v.x = rand();
	v.y = rand();
}

double distance(Graph::Vertex a, Graph::Vertex b) {
	double x_diff = a.x - b.x;
	double y_diff = a.y - b.y;
	return std::sqrt(x_diff * x_diff + y_diff * y_diff);
}

Graph RandomGeometricGraph(const size_t n, double r) {
	r = clamp(r,0,1) * RAND_MAX;
	
	Graph rgg;
	rgg.vert.resize(n);
	rgg.adj.resize(n);
	for (size_t i = 0; i < n; ++i) {
		setVertexCoordRand(rgg.vert[i]);
	}
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = i + 1; j < n; ++j) {
			if (distance(rgg.vert[i], rgg.vert[j]) < r) {
				rgg.adj[i].push_front(j);
				rgg.adj[j].push_front(i);
			}
		}
	}
	return rgg;
}
