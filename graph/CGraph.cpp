
#include "stdafx.h"
#include "CGraph.h"

CGraph::CGraph() {
	plaNODnodes = new CList<CNode>;
}

CGraph::CGraph(CGraph & GRAobj) {
}

CGraph::~CGraph() {
}

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

void CGraph::GRAaddArc(unsigned int uiFromNodeId, unsigned int uiToNodeId) {
	try {
		GRAgetNodeById(uiFromNodeId)->NODaddArcOut(uiToNodeId);
		GRAgetNodeById(uiToNodeId)->NODaddArcIn(uiFromNodeId);
	}catch(CException * EXCobj){
		cerr << "Cannot add arc, the start or destination node do not exist";
	}
}

void CGraph::GRAdeleteArc(unsigned int uiFromNodeId, unsigned int uiToNodeId) {
	CNode * NODfrom = GRAgetNodeById(uiFromNodeId);
	CNode * NODto = GRAgetNodeById(uiToNodeId);
	NODfrom->NODdeleteArcOut(uiToNodeId);
	NODto->NODdeleteArcIn(uiFromNodeId);
}

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

unsigned int CGraph::GRAgetNodesCount() {
	return plaNODnodes->LSTgetSize();
}

unsigned int CGraph::GRAgetNodeIdByIndex(unsigned int uiIndex) {
	return plaNODnodes->LSTgetElementAt(uiIndex)->NODgetId();
}

CList<unsigned int> * CGraph::GRAgetNodeNeighboursById(unsigned int uiNodeId) {
	return GRAgetNodeById(uiNodeId)->NODgetNeighbours();
}

void CGraph::GRAdisplay() {
	unsigned int uiLoop;
	cout << "Nodes: "<< endl;
	for (uiLoop = 0; uiLoop < plaNODnodes->LSTgetSize(); uiLoop++)
		cout << plaNODnodes->LSTgetElementAt(uiLoop)->NODgetId() << " ";
	cout << "\nArcs: " << endl;
	for (uiLoop = 0; uiLoop < plaNODnodes->LSTgetSize(); uiLoop++)
		plaNODnodes->LSTgetElementAt(uiLoop)->NODdisplay();
}