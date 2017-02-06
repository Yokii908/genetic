#ifndef ENTITY_HH
#define ENTITY_HH

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>


class Entity
{
	private:
		std::string _dna;
		int _dnaLength;
		int _potential;

	public:
		Entity(int);
		Entity();
		Entity(std::string);
		std::string getDna() const;
		void affectPotential(std::string);
		int getPotential() const;
		void setPotential(int);

		void setPartialDna(int);

		void setDna(std::string);

		Entity(Entity const &ObjB);
		//Entity operator=(Entity&);
};

#endif