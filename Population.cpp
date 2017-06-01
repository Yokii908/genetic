#include "Population.hh"

Population::Population(int dnaLength) {
	int i;

	this->_elements = new Entity[_nbrElements];
	for (i = 0; i < POP_SIZE; i++) {
		this->_elements[i] = Entity(dnaLength);
	}
}

Population::Population(int nbrNewElements, int dnaLength,
		       Entity *NewPeople) {
	int i;
	int j;

	this->_elements = new Entity[POP_SIZE];
	this->_nbrElements = POP_SIZE;
	for (i = 0; i < nbrNewElements; i++) {
		this->_elements[i] = NewPeople[i];
	}
	for (j = nbrNewElements; j < this->_nbrElements; j++) {
		this->_elements[j] = Entity(dnaLength);
	}
}

void Population::displayPopulation() const {
	int i;

	for (i = 0; i < this->_nbrElements; i++) {
		std::cout << this->_elements[i].getDna() << " potentiel = "
			  << this->_elements[i].getPotential() << " taille = "
			  << this->_elements[i].getDna().length() << std::endl;
	}
}

int Population::getNbrElements() const { return (this->_nbrElements); }

Population::~Population() { delete this->_elements; }
