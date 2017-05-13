
#include "stdafx.h"
#include "CGraph.h"

/**********************************
Default constructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : initialisation of a graph
**********************************/
CGraph::CGraph() {
	plaNODnodes = new CList<CNode>;
}

/**********************************
Clone constructor
**********************************
Input : object of type CGraph (GRAobj)
Required : nothing
Output : nothing
Consequence : initialisation of a graph by copy of GRAobj
**********************************/
CGraph::CGraph(CGraph & GRAobj) {
}

/**********************************
Destructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : finalise the object
**********************************/
CGraph::~CGraph() {
}

/**********************************
Node adder
**********************************
Input : an unsigned int (uiNodeId)
Required : nothing
Output : nothing
Consequence : add a new node in the list plaNODnodes,
this arc got uiNodeId as id
**********************************/
void CGraph::GRAaddNode(unsigned int uiNodeId) {
	plaNODnodes->LSTaddElementEnd(new CElement<CNode>(new CNode(uiNodeId)));
}

CNode * CGraph::GRAgetNodeById(unsigned int uiNodeId) {
	unsigned int uiLoop;
	for (uiLoop = 0; uiLoop < plaNODnodes->LSTgetSize(); uiLoop++)
		if (plaNODnodes->LSTgetElementAt(uiLoop)->NODgetId() == uiNodeId)
			return plaNODnodes->LSTgetElementAt(uiLoop);
	throw new CException(NODE_DONT_EXIST);
}

/**********************************
Arc adder
**********************************
Input : two an unsigned int, one for the start node id  (uiFromNodeId)
and one for the destination node id (uiToNodeId)
Required : nothing
Output : nothing
Consequence : add a new arc in the related nodes
**********************************/
void CGraph::GRAaddArc(unsigned int uiFromNodeId, unsigned int uiToNodeId) {
	try {
		GRAgetNodeById(uiFromNodeId)->NODaddArcOut(uiToNodeId);
		GRAgetNodeById(uiToNodeId)->NODaddArcIn(uiFromNodeId);
	}catch(CException * EXCobj){
		cerr << "Cannot add arc, the start or destination node do not exist";
	}
}

/**********************************
Arc deleted
**********************************
Input : two an unsigned int, one for the start node id  (uiFromNodeId)
and one for the destination node id (uiToNodeId)
Required : nothing
Output : nothing
Consequence : delete an arc in the related nodes
**********************************/
void CGraph::GRAdeleteArc(unsigned int uiFromNodeId, unsigned int uiToNodeId) {
	CNode * NODfrom = GRAgetNodeById(uiFromNodeId);
	CNode * NODto = GRAgetNodeById(uiToNodeId);
	NODfrom->NODdeleteArcOut(uiToNodeId);
	NODto->NODdeleteArcIn(uiFromNodeId);
}

/**********************************
Node deleted
**********************************
Input : an unsigned int (uiNodeId)
Required : nothing
Output : nothing
Consequence : delete the node that have uiNodeId as id in the list plaNODnodes
**********************************/
void CGraph::GRAdeleteNode(unsigned int uiNodeId) {
	unsigned int uiLoop, NODrelatedNodeId;
	CNode * NODtoDelete = GRAgetNodeById(uiNodeId);
	for (uiLoop = 0; uiLoop < NODtoDelete->NODgetInArcsCount(); uiLoop++) {
		NODrelatedNodeId = NODtoDelete->NODgetInArcByIndex(uiLoop)->ARCgetNodeDestId();
		GRAgetNodeById(NODrelatedNodeId)->NODdeleteArcOut(uiNodeId);
	}

	for (uiLoop = 0; uiLoop < NODtoDelete->NODgetOutArcsCount(); uiLoop++) {
		NODrelatedNodeId = NODtoDelete->NODgetOutArcByIndex(uiLoop)->ARCgetNodeDestId();
		GRAgetNodeById(NODrelatedNodeId)->NODdeleteArcIn(uiNodeId);
	}

	for (uiLoop = 0; uiLoop < plaNODnodes->LSTgetSize(); uiLoop++)
		if (plaNODnodes->LSTgetElementAt(uiLoop)->NODgetId() == uiNodeId)
			plaNODnodes->LSTremoveElementAt(uiLoop);
}

/**********************************
Nodes count getter
**********************************
Input : nothing
Required : nothing
Output : a unsigned int representing the number of nodes in plaNODnodes
Consequence : nothing
**********************************/
unsigned int CGraph::GRAgetNodesCount() {
	return plaNODnodes->LSTgetSize();
}

/**********************************
Node getter
**********************************
Input : an unsigned int (uiIndex)
Required : nothing
Output : a unsigned int representing id of the node at the position uiIndex
in the list plaNODnodes
Consequence : nothing
**********************************/
unsigned int CGraph::GRAgetNodeIdByIndex(unsigned int uiIndex) {
	return plaNODnodes->LSTgetElementAt(uiIndex)->NODgetId();
}

/**********************************
Neighbours of node x getter
**********************************
Input : an unsigned in (uiNodeId)
Required : nothing
Output : a list representing the ids of all neighbours of the node
that have uiNodeId as id
Consequence : nothing
**********************************/
CList<unsigned int> * CGraph::GRAgetNodeNeighboursById(unsigned int uiNodeId) {
	return GRAgetNodeById(uiNodeId)->NODgetNeighbours();
}

/**********************************
Display
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : display the node in the default output
**********************************/
void CGraph::GRAdisplay() {
	unsigned int uiLoop;
	cout << "Nodes: "<< endl;
	for (uiLoop = 0; uiLoop < plaNODnodes->LSTgetSize(); uiLoop++)
		cout << plaNODnodes->LSTgetElementAt(uiLoop)->NODgetId() << " ";
	cout << "\nArcs: " << endl;
	for (uiLoop = 0; uiLoop < plaNODnodes->LSTgetSize(); uiLoop++)
		plaNODnodes->LSTgetElementAt(uiLoop)->NODdisplay();
}