#ifndef CGRAPH_OPERATION_H
#define CGRAPH_OPERATION_H

#include <iostream>
#include "CGraph.h"
#include "CList.h"

using namespace std;

class CGraphOperation {
public:
	static CGraph * GROgetSwappedArcsGraph(CGraph * GRAobj);
};

#endif