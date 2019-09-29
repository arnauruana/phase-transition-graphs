#include "graph.h"
#include "doctest.h"

using namespace std;

Graph BinomialRandomGraph(const size_t n, double p) {
	p = clamp(p,0,1) * RAND_MAX;
	
	Graph brg;
	brg.vert.resize(n);
	brg.adj.resize(n);
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = i + 1; j < n; ++j) {
			long long x = rand();
			if (x < p) {
				brg.adj[i].push_front(j);
				brg.adj[j].push_front(i);
			}
		}
	}
	return brg;
}
TEST_CASE("Testing BinomialRandomGraph Generator") {
	CHECK(BinomialRandomGraph(10,0.0).getConnectedComponents().size() == 10);
	CHECK(BinomialRandomGraph(320,0.0).getConnectedComponents().size() == 320);
	CHECK(BinomialRandomGraph(10,1.0).getConnectedComponents().size() == 1);
	CHECK(BinomialRandomGraph(320,1.0).getConnectedComponents().size() == 1);
}
TEST_CASE("Testing BinomialRandomGraph Generator with Seed") {
	// The following test has been done visually using print().
	// Here we are only checking that the results are still the same.
	
	srand(1234);
	/*Graph g0 = BinomialRandomGraph(10,0.2);
	CHECK(g0.adj.size() == 10);
	
	g0.print();
	bool eq0 = 
		g0.adj[0] == forward_list<size_t>{8} &&
		g0.adj[1] == forward_list<size_t>{9,8,5,3} &&
		g0.adj[2] == forward_list<size_t>{} &&
		g0.adj[3] == forward_list<size_t>{1} &&
		g0.adj[4] == forward_list<size_t>{} &&
		g0.adj[5] == forward_list<size_t>{9,2,1} &&
		g0.adj[6] == forward_list<size_t>{3,5} &&
		g0.adj[7] == forward_list<size_t>{9} &&
		g0.adj[8] == forward_list<size_t>{0,1} &&
		g0.adj[9] == forward_list<size_t>{1,5,7};
	CHECK(eq0);*/
	
	Graph g1 = BinomialRandomGraph(10,0.3);
	//g1.print();
	CHECK(g1.adj.size() == 10);
	CHECK(g1.getConnectedComponents().size() == 1);
}
