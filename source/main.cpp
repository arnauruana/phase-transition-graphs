#define DOCTEST_CONFIG_IMPLEMENT
#define TESTING 0
#include "doctest.h"
#include "graph.h"

#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

void printHelp() {
	cout << "Usage: " << endl;
	cout << "        ./graph test" << endl;
	cout << "        ./graph brg n p [OPTIONS]" << endl; 
	cout << "        ./graph rgg n r [OPTIONS]" << endl;
	cout << endl;
	cout << "Options:" << endl;
	cout << " -p     (Default) Print the graph." << endl;
	cout << " -c     Print the number of connected componenets." << endl;
	exit(0);
}

int main(int argc, char** argv) {
	doctest::Context ctx;
	ctx.applyCommandLine(argc, argv);
	ctx.setOption("no-breaks", true);
	int res = 0;
	if (TESTING || (argc > 1 && std::string(argv[1]) == "test")) {
		res = ctx.run();
		return res;
	}
	srand(time(NULL));
	
	if (argc == 1) printHelp();
	
	if (argc >= 4) {
		std::istringstream a0(argv[2]); size_t n; a0 >> n;
		std::istringstream a1(argv[3]); double z; a1 >> z;
		bool printPos = false;
		Graph G;
		if (std::string(argv[1]) == "brg") {
			G = BinomialRandomGraph(n,z);
		} else if (std::string(argv[1]) == "rgg") {
			G = RandomGeometricGraph(n,z);
			printPos = true;
		}
		if (argc == 5 && std::string(argv[4]) == "-c") {
			cout << G.getConnectedComponents().size() << endl;
		} else if (argc == 5 && std::string(argv[4]) == "-p") {
			G.print(printPos);
		} else {
			G.print(printPos);
		}
	} else printHelp();
	

	return 0;
}
