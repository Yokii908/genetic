#ifndef POPULATION_HH
#define POPULATION_HH

#include "Entity.hh"

class Population {
       private:
	int _nbrElements;

       public:
	Entity *_elements;
	Population(int, int);
	Population(int, int, int, Entity *);
	~Population();
	void displayPopulation() const;

	int getNbrElements() const;
};

#endif
