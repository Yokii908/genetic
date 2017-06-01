#include "genetic.h"
#include "Population.hh"
#include "Selection.hh"

int main(int argc, char *argv[]) {
        if (argc != 2)
        {
                std::cerr << "Usage: ./genetic target population_size mutation_rate" << std::endl;
                return (1);
        }
        srand(time(NULL));
        std::string target = argv[1];
        Population *test = new Population(target.length());
        startSelection(test, target);
}
