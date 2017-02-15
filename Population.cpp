#include "Population.hh"

Population::Population(int nbrElements, int dnaLength)
    : _nbrElements(nbrElements) {
	int i;

	this->_elements = new Entity[_nbrElements];
	for (i = 0; i < nbrElements; i++) {
		this->_elements[i] = Entity(dnaLength);
	}
}

Population::Population(int nbrTotalElements, int nbrNewElements, int dnaLength,
		       Entity *NewPeople) {
	int i;
	int j;

	this->_elements = new Entity[nbrTotalElements];
	this->_nbrElements = nbrTotalElements;
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
