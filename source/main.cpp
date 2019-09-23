#include <cstdlib>
#include <string>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <set>
using std::set;

#include <utility>
using std::pair;
using std::make_pair;

#define DOCTEST_CONFIG_IMPLEMENT
#define DEBUG 0
#include "doctest.h"
#include "graph.h"


set<size_t> verts(const size_t n) {
  set<size_t> verts;
  for (size_t i = 0; i < n; ++i) {
    verts.insert(i);
  }
  return verts;
}

Graph BinomialRandomGraph(const size_t n, double p) {
  if (p < 0) p = 0;
  else if (p > 1) p = 1;
  p *= 100;
  double countIF = 0; // DEBUG
  double countEL = 0; // DEBUG
  set<pair<size_t, size_t>> edges;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i + 1; j < n; ++j) {
      double x = rand() % 100;
      if (x < p) {
        edges.insert(make_pair(i,j));
        ++countIF; // DEBUG
        cout << "IF \t" << x << "\t" << p << endl; // DEBUG
      }
      else { // DEBUG
        ++countEL; // DEBUG
        cout << "ELSE \t" << x << "\t" << p << endl; // DEBUG
      }
    }
  }
  cout << endl; // DEBUG
  cout << countIF << '\t' << (countIF/(countIF+countEL))*100. << endl; // DEBUG
  cout << countEL << '\t' << (countEL/(countIF+countEL))*100. << endl << endl; // DEBUG
  return Graph(verts(n), edges);
}

// DEBUG {
  inline void debugBRG() {
    cout << endl << "=============================" << endl << endl;
    int n;
    double p;
    while (cin >> n >> p) {
      Graph BRG = BinomialRandomGraph(n, p);
      BRG.print();
      cout << endl;
    }
  }
// } DEBUG

int main(int argc, char** argv) {
    doctest::Context ctx;
    ctx.applyCommandLine(argc, argv);
    ctx.setOption("no-breaks", true);
    int res = 0;
    if (DEBUG || (argc > 1 && std::string(argv[1]) == "debug")) {
        res = ctx.run();
        debugBRG(); // tests for BinomialRandomGraph function
        return res;
    }

    Graph G({0,1,2},{{1,2},{0,2},{1,0}});
    G.print();

    return 0;
}
