#include "graph.h"
#include "doctest.h"

#include <cstdlib>
#include <forward_list>
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*struct Vertex {
	double x, y; //Coordinates, between 0-999 (TO-DO: Is this the correct approach?)
};*/

void vertexCoordRand(vector<Graph::Vertex> v) {
	size_t n = v.size();
	for (size_t i = 0; i < n; i++) {
		v[i].x = rand() % 1000;
		v[i].y = rand() % 1000;
	}
}

//This does not work, you must compare i with j, not with i+1.
bool distance(vector<Graph::Vertex> v, int i, double r) {
	double x_diff = v[i].x - v[i + 1].x;
	double y_diff = v[i].y - v[i + 1].y;
	double dist = std::sqrt(x_diff * x_diff + y_diff * y_diff);
	if (dist < r) return true;
	return false;
}

Graph RandomGeometricGraph(const size_t n, double r) {
	Graph rgg;
	rgg.vert.resize(n);
	rgg.adj.resize(n);
	vertexCoordRand(rgg.vert);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = i + 1; j < n; ++j) {
			if (distance(rgg.vert, i, r)) rgg.adj[i].push_front(j);
		}
	}
	return rgg;
}
