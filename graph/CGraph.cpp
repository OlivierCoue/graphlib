
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
	throw new CException(1, "The node do not exist");
}

void CGraph::GRAaddArc(unsigned int uiFromNodeId, unsigned int uiToNodeId) {
	try {
		GRAgetNodeById(uiFromNodeId)->NODaddArcOut(uiToNodeId);
		GRAgetNodeById(uiToNodeId)->NODaddArcIn(uiToNodeId);
	}catch(CException * EXCobj){
		cerr << "Cannot add arc, the start or destination node do not exist";
	}
}

void CGraph::GRAdeleteArc(unsigned int uiFromNodeId, unsigned int uiToNodeId) {
	CNode * NODfrom = GRAgetNodeById(uiFromNodeId);
	CNode * NODto = GRAgetNodeById(uiToNodeId);
	NODfrom->NODdeleteArcOut(uiToNodeId);
	NODto->NODdeleteArcIn();
}

void CGraph::GRAdisplay() {
	unsigned int uiLoop;
	for (uiLoop = 0; uiLoop < plaNODnodes->LSTgetSize(); uiLoop++)
		plaNODnodes->LSTgetElementAt(uiLoop)->NODdisplay();
}