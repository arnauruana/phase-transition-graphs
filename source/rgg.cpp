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

Graph RandomGeometricGraph(size_t n, double r) {
	r = clamp(r,0,1) * RAND_MAX;

	Graph rgg;
	rgg.vert.resize(n);
	rgg.adj.resize(n);
	rgg.mat = vector<vector<bool>> (n, vector<bool> (n, false));
	for (size_t i = 0; i < n; ++i) {
		setVertexCoordRand(rgg.vert[i]);
	}
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = i + 1; j < n; ++j) {
			if (distance(rgg.vert[i], rgg.vert[j]) < r) {
				++rgg.edges;
				rgg.adj[i].push_front(j);
				rgg.adj[j].push_front(i);
				rgg.mat.at(i).at(j) = true;
				rgg.mat.at(j).at(i) = true;
			}
		}
	}
	return rgg;
}
TEST_CASE("Testing RandomGeometricGraph Generator") {
	CHECK(RandomGeometricGraph(10,0.0).getConnectedComponents().size() == 10);
	CHECK(RandomGeometricGraph(320,0.0).getConnectedComponents().size() == 320);
	CHECK(RandomGeometricGraph(10,1.0).getConnectedComponents().size() == 1);
	CHECK(RandomGeometricGraph(320,1.0).getConnectedComponents().size() == 1);
}
TEST_CASE("Testing RandomGeometricGraph Generator with Seed") {
	// The following test has been done visually using print().
	// Here we are only checking that the results are still the same.

	srand(1234);
	Graph g0 = RandomGeometricGraph(10,0.2);
	CHECK(g0.adj.size() == 10);
	CHECK(g0.getConnectedComponents().size() == 6);
}
