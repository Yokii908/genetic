#include "Selection.hh"

bool startSelection(Population *population, std::string target, int mutationRate) {
	static int nbPopulation = 0;
	nbPopulation++;

	Entity *NewEntities = new Entity[population->getNbrElements() / 2];

	std::vector<int> probabilityMappedList;

	for (int i = 0; i < population->getNbrElements(); i++) {
		population->_elements[i].affectPotential(target);
		probabilityMappedList.insert(
		    probabilityMappedList.end(),
		    population->_elements[i].getPotential(), i);
		;
		if (population->_elements[i].getPotential() ==
		    pow(target.length(), 2)) {
			std::cout << population->_elements[i].getDna()
				  << std::endl;
			std::cout << "found in " << nbPopulation
				  << " generations" << std::endl;
			return (true);
		}
	}
	for (int j = 0; j < population->getNbrElements() / 2; j++) {
		NewEntities[j] = crossOver(probabilityMappedList, *population, mutationRate);
		while (NewEntities[j].getDna().length() == 0) {
			// std::cout << "EMPTY" << std::endl;
			NewEntities[j] =
			    crossOver(probabilityMappedList, *population, mutationRate);
		}
	}

	Population *NewPopulation = new Population(
	    population->getNbrElements(), population->getNbrElements() / 2,
	    target.length(), NewEntities);

	for (int i = 0; i < population->getNbrElements() / 2; i++) {
		std::cout << NewPopulation->_elements[i].getDna() << std::endl;
		/*if (NewPopulation->_elements[i].getDna().length() == 0)
		{
			std::cout << "empty" << std::endl;
		}*/
	}

	delete[] NewEntities;

	startSelection(NewPopulation, target, mutationRate);

	// delete NewPopulation;
	return (false);
}

Entity crossOver(std::vector<int> v, Population &population, int mutationRate) {
	Entity FirstParent = population._elements[v[rand() % v.size()]];
	Entity SecondParent = population._elements[v[rand() % v.size()]];

	if (SecondParent.getDna() == FirstParent.getDna()) {
		crossOver(v, population, mutationRate);
	} else {
		// std::string DnaFinal = "";
		int MiddleOfString = FirstParent.getDna().length() / 2 +
				     (FirstParent.getDna().length() % 2);

		std::string FirstHalf =
		    FirstParent.getDna().substr(0, MiddleOfString);
		std::string SecondHalf = SecondParent.getDna().substr(
		    MiddleOfString, MiddleOfString);

		/*for (int i = 0 ; i < FirstParent.getDna().length() ; i++)
		{
			if (i % 2 == 0)
			{
				DnaFinal += FirstParent.getDna()[i];
			}
			else
			{
				DnaFinal += SecondParent.getDna()[i];
			}
		}*/

		std::string DnaFinal = FirstHalf + SecondHalf;

		Entity Child = Entity(DnaFinal);

		if (Child.getDna().length() == 0) {
			std::cout << "WTF" << std::endl;
		}

		mutation(Child, mutationRate);
		return (Child);
	}
	// replace(Child, population);
	return (0);
}

void mutation(Entity &Child, int mutationRate) {
	for (size_t i = 0; i < Child.getDna().length(); i++) {
		int randNbr = rand() % 100;
		if (randNbr < mutationRate) {
			Child.setPartialDna(i);
		}
	}
	// replace(Child, population);
}

/*void replace(Entity &Child, Population &population)
{
	int test = rand() % population.getNbrElements();
	Population NewPopulation = Population(5000, 20);
	population._elements[test] = Child;
	std::cout << Child.getDna() << std::endl;
	//startSelection(NewPopulation, "coucou");
}*/
