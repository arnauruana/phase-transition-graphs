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
	cout << "Where n is the amount of vertex (natural number), and p and r are decimal numbers in the range 0-1, or intervals wiritten in the form low:hight:step" << endl;
	cout << endl;
	cout << "Options:" << endl;
	cout << " -p         (Default) Print the graph." << endl;
	cout << " -c         Print the number of connected componenets." << endl;
	cout << " -c k       Like C but do it k times and output a CSV space separated table." << endl;
	cout << " -s         Print the size of the maximum connected component." << endl;
	cout << " -s k       Like S but do it k times and output a CSV space separated table." << endl;
	cout << " -k         Print whether the graph is complete or not." << endl;
	cout << " -k k       Like K but do it k times and output a CSV space separated table." << endl;
	cout << " -r         Print whether the graph is regular or not." << endl;
	cout << " -r k       Like R but do it k times and output a CSV space separated table." << endl;
	exit(0);
}

bool isComplete(const Graph& gr) {
	unsigned v = gr.vert.size();
	unsigned e = gr.edges;
	return e == v * (v - 1) / 2;
}

bool isRegular(const Graph& gr) {
	unsigned degree = gr.mat.at(0).size();
	for (unsigned i = 1; i < gr.mat.size(); ++i) {
		if (gr.mat.at(i).size() != degree)
			return false;
	}
	return true;
}

int maximum(const vector<int>& vec) {
	int max = -1; // cannot be connected components with negative numbers
	for (unsigned i = 0; i < vec.size(); ++i) {
		int elem = vec.at(i);
		if (elem > max)
			max =	elem;
	}
	return max;
}

vector<std::string> split(const std::string& s, char delimiter) {
	vector<std::string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
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

		auto zlist = split(string(argv[3]), ':');
		double z, z1, z2;
		if (zlist.size() == 1) {
			std::istringstream a1(argv[3]); a1 >> z;
			z1 = z;
			z2 = 1.0;
		}
		else {
			std::istringstream a1(zlist[0]); a1 >> z;
			std::istringstream a2(zlist[1]); a2 >> z1;
			std::istringstream a3(zlist[2]); a3 >> z2;
		}

		char option = 'p';
		if (argc >= 5 && argv[4][0] == '-') option = argv[4][1];
		unsigned int k = 1;
		if ((argc == 6) && (option == 'c' || option == 'k' || option == 's' || option == 'r')) {
			std::istringstream a4(argv[5]); a4 >> k;
		}

		for(; z<=z1; z += z2) {
			for (unsigned int i = 0; i < k; i++) {
				Graph G;
				bool printPos = false;
				if (std::string(argv[1]) == "brg") {
					G = BinomialRandomGraph(n,z);
				} else if (std::string(argv[1]) == "rgg") {
					G = RandomGeometricGraph(n,z);
					printPos = true;
				}
				switch (option) {
					case 'r': // APARTAT E
						// cout << "Is regular: ";
						// cout << (isRegular(G) ? "Yes" : "No"); // human-readable
						cout << isRegular(G) << ' '; // machine-readable
						// cout << endl;
						break;
					case 'k': // APARTAT E
						// cout << "Is complete: ";
						// cout << (isComplete(G) ? "Yes" : "No"); // human-readable
						cout << isComplete(G) << ' '; // machine-readable
						// cout << endl;
						break;
					case 's': // APARTAT D
						// cout << "Maximum size: ";
						cout << maximum(G.getConnectedComponents()) << ' ';
						// cout << endl;
						break;
					case 'c': // APARTAT C
						// cout << "Connected components: ";
						cout << G.getConnectedComponents().size() << ' ';
						// cout << endl;
						break;
					case 'p':
					default: G.print(printPos);
				}
			}
			cout << endl;
		}
	} else printHelp();


	return 0;
}
