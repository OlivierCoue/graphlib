#ifndef CGRAPH_OPERATION_H
#define CGRAPH_OPERATION_H

#include <iostream>
#include "CGraph.h"
#include "CList.h"

using namespace std;

class CGraphOperation {
public:
	/**********************************
	Swapped arcs graph getter
	**********************************
	Input : a graph object CGraph (GRAobj)
	Required : nothing
	Output : a new graph representing GRAobj with all arcs swapped
	Consequence : nothing
	**********************************/
	static CGraph * GROgetSwappedArcsGraph(CGraph * GRAobj);
};

#endif