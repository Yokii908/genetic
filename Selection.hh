#ifndef SELECTION_HH
#define SELECTION_HH

#include <vector>
#include <algorithm>
#include "Population.hh"

bool startSelection(Population*, std::string);

Entity crossOver(std::vector<int>, Population&);
void mutation(Entity&);
// void replace(Entity&, Population&);

#endif
