#include "Entity.hh"

Entity::Entity() {}

Entity::Entity(int length) : _dna(""), _dnaLength(length), _potential(0) {
	for (int i = 0; i < this->_dnaLength; i++) {
		char c = (char)(rand() % (127 - 32)) + 32;
		this->_dna += c;
	}
}

Entity::Entity(std::string InitDna): _dna(InitDna), _potential(0), _dnaLength(InitDna.length()) {
}

std::string Entity::getDna() const { return (this->_dna); }

void Entity::affectPotential(std::string target) {
	int potential = 0;
	size_t i;

	for (i = 0; i < target.length(); i++) {
		if (this->_dna[i] == target[i]) {
			potential += 1;
		}
	}
	this->_potential = pow(potential, 2);
	// this->_potential = potential;
}

int Entity::getPotential() const { return (this->_potential); }

void Entity::setDna(std::string NewDna) { this->_dna = NewDna; }

void Entity::setPartialDna(int index) {
	this->_dna[index] = (char)(rand() % (127 - 32)) + 32;
}

void Entity::setPotential(int NewPotential) { this->_potential = NewPotential; }

Entity::Entity(Entity const &ObjB)
    : _dna(ObjB._dna), _dnaLength(ObjB._dnaLength), _potential(0) {}

/*Entity Entity::operator=(Entity &ObjB)
{
	Entity Copy = Entity(ObjB);
	return (ObjB);
}*/
