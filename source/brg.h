#ifndef BRG_HH
#define BRG_HH

#include <cstdlib>
#include <forward_list>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "doctest.h"
#include "graph.h"

using namespace std;

Graph BinomialRandomGraph(const size_t n, double p);

#endif // BRG_HH
