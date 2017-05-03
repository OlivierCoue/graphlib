#ifndef CGRAPH_H
#define CGRAPH_H

#include <iostream>
#include "CList.h"
#include "CElement.h"
#include "CNode.h"
#include "CException.h"

using namespace std;

class CGraph {
private:
	CList<CNode> * plaNODnodes;
public:
	CGraph();
	CGraph(CGraph & GRAobj);
	~CGraph();
	void GRAaddNode(unsigned int uiNodeId);
	CNode * GRAgetNodeById(unsigned int uiNodeId);
	void GRAaddArc(unsigned int uiFromNodeId, unsigned int uiToNodeId);
	void GRAdeleteArc(unsigned int uiFromNodeId, unsigned int uiToNodeId);
	void GRAdisplay();
};

#endif