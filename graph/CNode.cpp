
#include "stdafx.h"
#include "CNode.h"

/**********************************
Default constructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : initialisation of a node
**********************************/
CNode::CNode() {
	uiNODid = 0;
	plaNODinArcs = new CList<CArc>();
	plaNODoutArcs = new CList<CArc>();
}

/**********************************
One parameter constructor
**********************************
Input : an unsigned int (uiId)
Required : nothing
Output : nothing
Consequence : initialisation a node and set the uiNODid
**********************************/
CNode::CNode(unsigned int uiId) {
	uiNODid = uiId;
	plaNODinArcs = new CList<CArc>();
	plaNODoutArcs = new CList<CArc>();
}

/**********************************
Clone constructor
**********************************
Input : object of type CNode (NODobj)
Required : nothing
Output : nothing
Consequence : initialisation of a node by copy of NODobj
**********************************/
CNode::CNode(CNode & NODobj) {
}

/**********************************
Destructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : delete plaNODinArcs and plaNODoutArcs
**********************************/
CNode::~CNode() {
	delete plaNODinArcs;
	delete plaNODoutArcs;
}

/**********************************
uiNODid getter
**********************************
Input : nothing
Required : nothing
Output : the value of uiNODid
Consequence : nothing
**********************************/
unsigned int CNode::NODgetId() {
	return uiNODid;
}

/**********************************
Arc In getter
**********************************
Input : an unsigned int (uiIndex)
Required : nothing
Output : an arc from the the list plaNODinArcs at the position uiIndex
Consequence : nothing
**********************************/
CArc * CNode::NODgetInArcByIndex(unsigned int uiIndex) {
	return plaNODinArcs->LSTgetElementAt(uiIndex);
}


/**********************************
Arc Out getter
**********************************
Input : an unsigned int (uiIndex)
Required : nothing
Output : an arc from the the list plaNODoutArcs at the position uiIndex
Consequence : nothing
**********************************/
CArc * CNode::NODgetOutArcByIndex(unsigned int uiIndex) {
	return plaNODoutArcs->LSTgetElementAt(uiIndex);
}

/**********************************
Arc Int count getter
**********************************
Input : nothing
Required : nothing
Output : a unsigned int representing the number of arcs plaNODinArcs
Consequence : nothing
**********************************/
unsigned int CNode::NODgetInArcsCount() {
	return plaNODinArcs->LSTgetSize();
}

/**********************************
Arc Out count getter
**********************************
Input : nothing
Required : nothing
Output : a unsigned int representing the number of arcs plaNODoutArcs
Consequence : nothing
**********************************/
unsigned int CNode::NODgetOutArcsCount() {
	return plaNODoutArcs->LSTgetSize();
}

/**********************************
Arc In adder
**********************************
Input : an unsigned int (uiNodeDestinationId)
Required : nothing
Output : nothing
Consequence : add a new arc in the list plaNODinArcs,
this arc got uiNodeDestinationId as destination
**********************************/
void CNode::NODaddArcIn(unsigned int uiNodeDestinationId) {
	plaNODinArcs->LSTaddElementEnd(new CElement<CArc>(new CArc(uiNodeDestinationId)));
}

/**********************************
Arc Out adder
**********************************
Input : an unsigned int (uiNodeDestinationId)
Required : nothing
Output : nothing
Consequence : add a new arc in the list plaNODoutArcs,
this arc got uiNodeDestinationId as destination
**********************************/
void CNode::NODaddArcOut(unsigned int uiNodeDestinationId) {
	plaNODoutArcs->LSTaddElementEnd(new CElement<CArc>(new CArc(uiNodeDestinationId)));
}

/**********************************
Arc In deleter
**********************************
Input : an unsigned int (uiNodeDestinationId)
Required : nothing
Output : nothing
Consequence : remove a arc in the list plaNODinArcs that have
uiNodeDestinationId as destination
**********************************/
void CNode::NODdeleteArcIn(unsigned int uiNodeDestinationId) {
	unsigned int uiLoopCount;
	for (uiLoopCount = 0; uiLoopCount < plaNODinArcs->LSTgetSize(); uiLoopCount++) {
		int destId = plaNODinArcs->LSTgetElementAt(uiLoopCount)->ARCgetNodeDestId();
		if (plaNODinArcs->LSTgetElementAt(uiLoopCount)->ARCgetNodeDestId() == uiNodeDestinationId) {
			plaNODinArcs->LSTremoveElementAt(uiLoopCount);
			return;
		}
	}
}

/**********************************
Arc Out deleter
**********************************
Input : an unsigned int (uiNodeDestinationId)
Required : nothing
Output : nothing
Consequence : remove a arc in the list plaNODoutArcs that have
uiNodeDestinationId as destination
**********************************/
void CNode::NODdeleteArcOut(unsigned int uiNodeDestinationId) {
	unsigned int uiLoopCount;
	for(uiLoopCount = 0; uiLoopCount < plaNODoutArcs->LSTgetSize();uiLoopCount++) {
		int destId = plaNODoutArcs->LSTgetElementAt(uiLoopCount)->ARCgetNodeDestId();
		if(plaNODoutArcs->LSTgetElementAt(uiLoopCount)->ARCgetNodeDestId() == uiNodeDestinationId) {
			plaNODoutArcs->LSTremoveElementAt(uiLoopCount);
			return;
		}
	}
}

/**********************************
Neighbours getter
**********************************
Input : nothing
Required : nothing
Output : a list representing the ids of all neighbours of the current node
Consequence : nothing
**********************************/
CList<unsigned int> * CNode::NODgetNeighbours() {
	unsigned int uiLoop;
	CList<unsigned int> * pluiNeighboursIds = new CList<unsigned int>();
	for (uiLoop = 0; uiLoop < plaNODoutArcs->LSTgetSize(); uiLoop++) {
		unsigned int * uiNodeId = new unsigned int;
		*uiNodeId = plaNODoutArcs->LSTgetElementAt(uiLoop)->ARCgetNodeDestId();
		pluiNeighboursIds->LSTaddElementEnd(new CElement<unsigned int>(uiNodeId));
	}
	return pluiNeighboursIds;
}

/**********************************
Display
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : display the node in the default output
**********************************/
void CNode::NODdisplay() {
	unsigned int uiLoop;
	for (uiLoop = 0; uiLoop < plaNODoutArcs->LSTgetSize(); uiLoop++) {
		cout << uiNODid << " -----> " << plaNODoutArcs->LSTgetElementAt(uiLoop)->ARCgetNodeDestId() << endl;
	}
}