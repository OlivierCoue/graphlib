#ifndef CNODE_H
#define CNODE_H

#include <iostream>
#include "CList.h"
#include "CElement.h"
#include "CArc.h"

using namespace std;

class CNode {
private:
	unsigned int uiNODid;
	CList<CArc> * plaNODinArcs;
	CList<CArc> * plaNODoutArcs;
public:
	CNode();
	CNode(unsigned int uiId);
	CNode(CNode & NODobj);
	~CNode();
	unsigned int NODgetId();
	CArc * NODgetInArcByIndex(unsigned int uiIndex);
	CArc * NODgetOutArcByIndex(unsigned int uiIndex);
	unsigned int NODgetInArcsCount();
	unsigned int NODgetOutArcsCount();
	void NODaddArcIn(unsigned int uiNodeDestinationId);
	void NODaddArcOut(unsigned int uiNodeDestinationId);
	void NODdeleteArcIn(unsigned int uiNodeDestinationId);
	void NODdeleteArcOut(unsigned int uiNodeDestinationId);
	CList<unsigned int> * NODgetNeighbours();
	void NODdisplay();
};

#endif