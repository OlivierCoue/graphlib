
#include "stdafx.h"
#include "CGraphOperation.h"

/**********************************
Swapped arcs graph getter
**********************************
Input : a graph object CGraph (GRAobj)
Required : nothing
Output : a new graph representing GRAobj with all arcs swapped
Consequence : nothing
**********************************/
CGraph * CGraphOperation::GROgetSwappedArcsGraph(CGraph * GRAobj) {
	CGraph * GRAswapedArcsGraph = new CGraph();
	unsigned int uiLoopNode, uiLoopNodeNeighbours;

	for (uiLoopNode = 0; uiLoopNode < GRAobj->GRAgetNodesCount(); uiLoopNode++)
		GRAswapedArcsGraph->GRAaddNode(GRAobj->GRAgetNodeIdByIndex(uiLoopNode));

	for (uiLoopNode = 0; uiLoopNode < GRAobj->GRAgetNodesCount(); uiLoopNode++) {
		unsigned int uiNodeId = GRAobj->GRAgetNodeIdByIndex(uiLoopNode);
		CList<unsigned int> * pluiNodeNeighboursIds = GRAobj->GRAgetNodeNeighboursById(uiNodeId);

		for (uiLoopNodeNeighbours = 0; uiLoopNodeNeighbours < pluiNodeNeighboursIds->LSTgetSize(); uiLoopNodeNeighbours++) {
			unsigned int uiNodeNeighbourId = *pluiNodeNeighboursIds->LSTgetElementAt(uiLoopNodeNeighbours);
			GRAswapedArcsGraph->GRAaddArc(uiNodeNeighbourId, uiNodeId);
		}
	}

	return GRAswapedArcsGraph;
}