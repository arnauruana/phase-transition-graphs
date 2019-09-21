#include <iostream>
#include <vector>
#include <forward_list>
#include <functional>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

//Adjacency list representation as in Cormen et al. (Introduction to algorithms).
using Vertex = size_t;
using Graph = vector<forward_list<Vertex>>;

//Invariant: |G.size()| = |visited|, v in G, s = 0 on main call.
void DFS(const Graph& G, Vertex v, vector<bool>& visited, size_t& s, function<void(const Graph&,Vertex,vector<bool>&)> callback) {
    visited[v] = true;
    s++;
    if (callback) callback(G,v,visited);
    for(Vertex i : G[v]) {
        if (!visited[i]) DFS(G, i, visited, s, callback);
    }
}

void DFS(const Graph& G, Vertex v, vector<bool>& visited) {
    size_t s = 0;
    DFS(G,v,visited,s,NULL);
}

//Returns: A vector of vertex such that each vertex belongs to a distinct connected component of an undirected graph.
vector<Vertex> connectedComponents(const Graph& G) {
    vector<bool>      visited(G.size(),false);
    vector<Vertex>    L;

    for(Vertex i = 0; i < G.size(); i++) {
        if (!visited[i]) {
            DFS(G, i, visited);
            L.push_back(i);
        }
    }

    return L;
}

TEST_CASE("Testing connectedComponents()") {
    CHECK(connectedComponents({}).size() == 0);
    CHECK(connectedComponents({{1,2},{0,2},{1,0}}).size() == 1);
    CHECK(connectedComponents({{},{},{}}).size() == 3);
    CHECK(connectedComponents({{1},{2},{0}}).size() == 1);
    CHECK(connectedComponents({{1},{0},{3},{2}}).size() == 2);
}
