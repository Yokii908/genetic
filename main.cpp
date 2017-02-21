#include "Population.hh"
#include "Selection.hh"

int main(int argc, char *argv[]) {

	if (argc == 4 && atoi(argv[2]) >= 100)
	{
		srand(time(NULL));
		std::string target = argv[1];
		int sizePopulation = atoi(argv[2]);
		int mutationRate = atoi(argv[3]);
		Population *test = new Population(sizePopulation, target.length());
		startSelection(test, target, mutationRate);
	}
	else if (argc != 4)
	{
		std::cout << "Usage: ./genetic target population_size mutation_rate" << std::endl;
	}
	else if (atoi(argv[2]) < 100)
	{
		std::cout << "please enter a higher population size" << std::endl;
	}
	
}