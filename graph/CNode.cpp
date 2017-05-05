
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

CArc * CNode::NODgetInArcByIndex(unsigned int uiIndex) {
	return plaNODinArcs->LSTgetElementAt(uiIndex);
}

CArc * CNode::NODgetOutArcByIndex(unsigned int uiIndex) {
	return plaNODoutArcs->LSTgetElementAt(uiIndex);
}

unsigned int CNode::NODgetInArcsCount() {
	return plaNODinArcs->LSTgetSize();
}

unsigned int CNode::NODgetOutArcsCount() {
	return plaNODoutArcs->LSTgetSize();
}

void CNode::NODaddArcIn(unsigned int uiNodeDestinationId) {
	plaNODinArcs->LSTaddElementEnd(new CElement<CArc>(new CArc(uiNodeDestinationId)));
}

void CNode::NODaddArcOut(unsigned int uiNodeDestinationId) {
	plaNODoutArcs->LSTaddElementEnd(new CElement<CArc>(new CArc(uiNodeDestinationId)));
}

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

void CNode::NODdisplay() {
	unsigned int uiLoop;
	for (uiLoop = 0; uiLoop < plaNODoutArcs->LSTgetSize(); uiLoop++) {
		cout << uiNODid << " -----> " << plaNODoutArcs->LSTgetElementAt(uiLoop)->ARCgetNodeDestId() << endl;
	}
}