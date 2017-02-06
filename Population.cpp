#include "Population.hh"

Population::Population(int nbrElements, int dnaLength): _nbrElements(nbrElements)
{
	this->_elements = new Entity[_nbrElements];
	for (int i = 0 ; i < nbrElements ; i++)
	{
		this->_elements[i] = Entity(dnaLength);
	}
}

Population::Population(int nbrTotalElements, int nbrNewElements, int dnaLength, Entity *NewPeople)
{
	this->_elements = new Entity[nbrTotalElements];
	this->_nbrElements = nbrTotalElements;
	for (int i = 0 ; i < nbrNewElements ; i++) {
		this->_elements[i] = NewPeople[i];
	}
	for (int j = nbrNewElements ; j < this->_nbrElements ; j++)
	{
		this->_elements[j] = Entity(dnaLength);
	}
}


void Population::displayPopulation() const
{
	for (int i = 0 ; i < this->_nbrElements ; i++)
	{
		std::cout << this->_elements[i].getDna() << " potentiel = " << this->_elements[i].getPotential() << " taille = " << this->_elements[i].getDna().length() << std::endl;
	}
}

int Population::getNbrElements() const
{
	return (this->_nbrElements);
}

Population::~Population()
{
	delete this->_elements;
}