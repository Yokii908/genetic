#ifndef POPULATION_HH
#define POPULATION_HH

#include "genetic.h"
#include "Entity.hh"

class Population {
       private:
	int _nbrElements = POP_SIZE;

       public:
	Entity *_elements;
	Population(int);
	Population(int, Entity *);
	~Population();
	void displayPopulation() const;

	int getNbrElements() const;
};

#endif
