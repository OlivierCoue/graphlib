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
	CNode * GRAgetNodeById(unsigned int uiNodeId);
public:
	CGraph();
	CGraph(CGraph & GRAobj);
	~CGraph();
	void GRAaddNode(unsigned int uiNodeId);
	void GRAaddArc(unsigned int uiFromNodeId, unsigned int uiToNodeId);
	void GRAdeleteArc(unsigned int uiFromNodeId, unsigned int uiToNodeId);
	void GRAdeleteNode(unsigned int uiNodeId);
	unsigned int GRAgetNodesCount();
	unsigned int GRAgetNodeIdByIndex(unsigned int uiIndex);
	CList<unsigned int> * GRAgetNodeNeighboursById(unsigned int uiNodeId);
	void GRAdisplay();
};

#endif