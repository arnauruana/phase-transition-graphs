#define DOCTEST_CONFIG_IMPLEMENT
#define DEBUG 0
#include "doctest.h"
#include "graph.h"

#include <string>
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	doctest::Context ctx;
	ctx.applyCommandLine(argc, argv);
	ctx.setOption("no-breaks", true);
	int res = 0;
	if (DEBUG || (argc > 1 && std::string(argv[1]) == "debug")) {
		srand(time(NULL));
		res = ctx.run();
		return res;
	}

	
	Graph G({0,1,2},{{1,2},{0,2},{1,0}});
	G.print();

	return 0;
}
