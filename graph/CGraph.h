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
	/**********************************
	Default constructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : initialisation of a graph
	**********************************/
	CGraph();

	/**********************************
	Clone constructor
	**********************************
	Input : object of type CGraph (GRAobj)
	Required : nothing
	Output : nothing
	Consequence : initialisation of a graph by copy of GRAobj
	**********************************/
	CGraph(CGraph & GRAobj);

	/**********************************
	Destructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : finalise the object
	**********************************/
	~CGraph();

	/**********************************
	Node adder
	**********************************
	Input : an unsigned int (uiNodeId)
	Required : nothing
	Output : nothing
	Consequence : add a new node in the list plaNODnodes,
		this arc got uiNodeId as id
	**********************************/
	void GRAaddNode(unsigned int uiNodeId);

	/**********************************
	Arc adder
	**********************************
	Input : two an unsigned int, one for the start node id  (uiFromNodeId)
		and one for the destination node id (uiToNodeId)
	Required : nothing
	Output : nothing
	Consequence : add a new arc in the related nodes
	**********************************/
	void GRAaddArc(unsigned int uiFromNodeId, unsigned int uiToNodeId);

	/**********************************
	Arc deleted
	**********************************
	Input : two an unsigned int, one for the start node id  (uiFromNodeId)
		and one for the destination node id (uiToNodeId)
	Required : nothing
	Output : nothing
	Consequence : delete an arc in the related nodes
	**********************************/
	void GRAdeleteArc(unsigned int uiFromNodeId, unsigned int uiToNodeId);

	/**********************************
	Node deleted
	**********************************
	Input : an unsigned int (uiNodeId)
	Required : nothing
	Output : nothing
	Consequence : delete the node that have uiNodeId as id in the list plaNODnodes
	**********************************/
	void GRAdeleteNode(unsigned int uiNodeId);

	/**********************************
	Nodes count getter
	**********************************
	Input : nothing
	Required : nothing
	Output : a unsigned int representing the number of nodes in plaNODnodes
	Consequence : nothing
	**********************************/
	unsigned int GRAgetNodesCount();

	/**********************************
	Node getter
	**********************************
	Input : an unsigned int (uiIndex)
	Required : nothing
	Output : a unsigned int representing id of the node at the position uiIndex
		in the list plaNODnodes
	Consequence : nothing
	**********************************/
	unsigned int GRAgetNodeIdByIndex(unsigned int uiIndex);

	/**********************************
	Neighbours of node x getter
	**********************************
	Input : an unsigned in (uiNodeId)
	Required : nothing
	Output : a list representing the ids of all neighbours of the node
		that have uiNodeId as id
	Consequence : nothing
	**********************************/
	CList<unsigned int> * GRAgetNodeNeighboursById(unsigned int uiNodeId);

	/**********************************
	Display
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : display the node in the default output
	**********************************/
	void GRAdisplay();
};

#endif