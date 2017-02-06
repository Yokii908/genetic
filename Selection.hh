#ifndef SELECTION_HH
#define SELECTION_HH

#include "Population.hh"
#include <Vector>
#include <algorithm>

bool startSelection(Population&, std::string);

Entity crossOver(std::vector<int>, Population&);
void mutation(Entity&);
//void replace(Entity&, Population&);

#endif