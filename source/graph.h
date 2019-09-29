#ifndef GRAPHDEV_GRAPH_H
#define GRAPHDEV_GRAPH_H

#include <vector>
#include <forward_list>
#include <set>
#include <functional>
#include <algorithm>

class Graph {
public:
	typedef struct {
		size_t id;
		double x, y; //Used on RGG only.
	} Vertex;
	typedef std::pair<Vertex, Vertex> Edge;

	Graph() = default;
	Graph(std::set<Vertex> V, std::set<Edge> E);

	//Invariant: V={0,...,n}, E = {<v_i,v_j>} such that v_i,v_j in V and v_i != v_j;
	Graph(std::set<size_t> V, std::set<std::pair<size_t,size_t>> E);

	std::vector<Vertex> vert;
	std::vector<std::forward_list<size_t>> adj; //Adjacency list by id.

	std::vector<Vertex> getConnectedComponents() const;
	size_t size() const { return adj.size(); }

	// Prints the graph in dot (GraphViz) format. Look online to render.
	void print(bool withPos = false) const;
};

Graph BinomialRandomGraph(size_t n, double p);
Graph RandomGeometricGraph(size_t n, double r);

//Included in C++17, defined here for compativility with C++11 compilers.
#if __cplusplus <= 201402L
namespace std {
	inline double clamp(const double& v, const double& lo, const double& hi) {
		return std::max(std::min(v,hi),lo);
	}
}
#endif
#endif //GRAPHDEV_GRAPH_H
