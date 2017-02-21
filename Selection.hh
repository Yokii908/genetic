#ifndef SELECTION_HH
#define SELECTION_HH

#include <vector>
#include <algorithm>
#include "Population.hh"

bool startSelection(Population*, std::string, int);

Entity crossOver(std::vector<int>, Population&, int);
void mutation(Entity&, int);
// void replace(Entity&, Population&);

#endif
