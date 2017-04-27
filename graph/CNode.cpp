
#include "stdafx.h"
#include "CNode.h"

CNode::CNode() {
	uiNODid = 0;
	plaNODinArcs = new CList<CArc>();
	plaNODoutArcs = new CList<CArc>();
}

CNode::CNode(unsigned int uiId) {
	uiNODid = uiId;
	plaNODinArcs = new CList<CArc>();
	plaNODoutArcs = new CList<CArc>();
}

CNode::CNode(CNode & NODobj) {
}

CNode::~CNode() {
	delete plaNODinArcs;
	delete plaNODoutArcs;
}

unsigned int CNode::NODgetId() {
	return uiNODid;
}

void CNode::NODaddArcIn(unsigned int uiNodeDestinationId) {
	plaNODinArcs->LSTaddElementEnd(new CElement<CArc>(new CArc(uiNodeDestinationId)));
}

void CNode::NODaddArcOut(unsigned int uiNodeDestinationId) {
	plaNODoutArcs->LSTaddElementEnd(new CElement<CArc>(new CArc(uiNodeDestinationId)));
}

void CNode::NODdisplay() {
	unsigned int uiLoop;
	cout << endl << "Node ID: " << uiNODid << endl;
	cout << "Arcs in:" << endl;
	for (uiLoop = 0; uiLoop < plaNODinArcs->LSTgetSize(); uiLoop++) {
		cout << "destination: " << plaNODinArcs->LSTgetElementAt(uiLoop)->ARCgetNodeDestId() << endl;
	}
	cout << "Arcs out:" << endl;
	for (uiLoop = 0; uiLoop < plaNODoutArcs->LSTgetSize(); uiLoop++) {
		cout << "destination: " << plaNODoutArcs->LSTgetElementAt(uiLoop)->ARCgetNodeDestId() << endl;
	}
}