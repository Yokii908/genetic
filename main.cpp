#include "Population.hh"
#include "Selection.hh"

int main(int argc, char *argv[]) {
	Population * test;

	if (argc > 1) {
		srand(time(NULL));
		std::string target = argv[1];
		test = new Population(500, target.length());
		startSelection(test, target);
		// delete test;
	} else {
		std::cout << "fdp" << std::endl;
	}
}
