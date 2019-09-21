#include "graph.h"

#include <iostream>
#include <unordered_set>

#include "doctest.h"

using namespace std;

//Invariant: |G.size()| = |visited|, v in G, s = 0 on main call.
void DFS(const Graph& G, size_t v, vector<bool>& visited, size_t& s, function<void(const Graph&,size_t,const vector<bool>&)> callback) {
    visited[v] = true;
    s++;
    if (callback) callback(G,v,visited);
    for(size_t i : G.adj[v]) {
        if (!visited[i]) DFS(G, i, visited, s, callback);
    }
}

void DFS(const Graph& G, size_t v, vector<bool>& visited) {
    size_t s = 0;
    DFS(G,v,visited,s,NULL);
}

Graph::Graph(std::set<Vertex> V, std::set<Edge> E) {
    adj.resize(V.size());
    for (auto v : V) vert.push_back(v);
    for (size_t i = 0; i < vert.size(); i++) vert[i].id = i;
    for (size_t i = 0; i < vert.size(); i++) {
        for (auto e : E) {
            if (e.first.id == i) adj[i].push_front(e.second.id);
            if (e.second.id == i) adj[i].push_front(e.first.id);
        }
    }
}

Graph::Graph(std::set<size_t> V, std::set<std::pair<size_t,size_t>> E) {
    vert.resize(V.size());
    adj.resize(V.size());
    for (auto v : V) vert[v].id = v;
    for (size_t i = 0; i < vert.size(); i++) {
        for (auto e : E) {
            if (e.first == i) adj[i].push_front(e.second);
            if (e.second == i) adj[i].push_front(e.first);
        }
    }
}

//Returns: A vector of vertex such that each vertex belongs to a distinct connected component of an undirected graph.
vector<Graph::Vertex> Graph::getConnectedComponents() const {
    vector<bool>      visited(size(),false);
    vector<Vertex>    L;

    for(size_t i = 0; i < size(); i++) {
        if (!visited[i]) {
            DFS(*this, i, visited);
            L.push_back(vert[i]);
        }
    }

    return L;
}
TEST_CASE("Testing Graph::getConnectedComponents()") {
            CHECK(Graph().getConnectedComponents().size() == 0);
            CHECK(Graph({0,1,2},{{1,2},{0,2},{1,0}}).getConnectedComponents().size() == 1);
            CHECK(Graph({0,1,2},{{},{},{}}).getConnectedComponents().size() == 3);
            CHECK(Graph({0,1,2},{{1,2},{2,0},{0,1}}).getConnectedComponents().size() == 1);
            CHECK(Graph({0,1,2,3},{{0,1},{2,3}}).getConnectedComponents().size() == 2);
}

namespace std {
    template<>
    struct hash<std::pair<size_t, size_t>> {
        inline size_t operator()(const std::pair<size_t, size_t> &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second);
        }
    };
}

void Graph::print() const {
    unordered_set<pair<size_t,size_t>> visited;

    cout << "graph {" << endl;
    for(size_t i = 0; i<size(); i++) {
        for (size_t j : adj[i]) {
            if (visited.count(pair<size_t,size_t>(j,i)) == 0) {
                cout << "\t" << i << " -- " << j << endl;
                visited.insert(make_pair(i,j));
            }
        }
    }
    cout << "}" << endl;
}




