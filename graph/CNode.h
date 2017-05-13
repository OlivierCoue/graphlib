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
	/**********************************
	Default constructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : initialisation of a node
	**********************************/
	CNode();

	/**********************************
	One parameter constructor
	**********************************
	Input : an unsigned int (uiId)
	Required : nothing
	Output : nothing
	Consequence : initialisation a node and set the uiNODid
	**********************************/
	CNode(unsigned int uiId);

	/**********************************
	Clone constructor
	**********************************
	Input : object of type CNode (NODobj)
	Required : nothing
	Output : nothing
	Consequence : initialisation of a node by copy of NODobj
	**********************************/
	CNode(CNode & NODobj);

	/**********************************
	Destructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : delete plaNODinArcs and plaNODoutArcs
	**********************************/
	~CNode();

	/**********************************
	uiNODid getter
	**********************************
	Input : nothing
	Required : nothing
	Output : the value of uiNODid
	Consequence : nothing
	**********************************/
	unsigned int NODgetId();

	/**********************************
	Arc In getter
	**********************************
	Input : an unsigned int (uiIndex)
	Required : nothing
	Output : an arc from the the list plaNODinArcs at the position uiIndex
	Consequence : nothing
	**********************************/
	CArc * NODgetInArcByIndex(unsigned int uiIndex);

	/**********************************
	Arc Out getter
	**********************************
	Input : an unsigned int (uiIndex)
	Required : nothing
	Output : an arc from the the list plaNODoutArcs at the position uiIndex
	Consequence : nothing
	**********************************/
	CArc * NODgetOutArcByIndex(unsigned int uiIndex);

	/**********************************
	Arc Int count getter
	**********************************
	Input : nothing
	Required : nothing
	Output : a unsigned int representing the number of arcs plaNODinArcs
	Consequence : nothing
	**********************************/
	unsigned int NODgetInArcsCount();

	/**********************************
	Arc Out count getter
	**********************************
	Input : nothing
	Required : nothing
	Output : a unsigned int representing the number of arcs plaNODoutArcs
	Consequence : nothing
	**********************************/
	unsigned int NODgetOutArcsCount();

	/**********************************
	Arc In adder
	**********************************
	Input : an unsigned int (uiNodeDestinationId)
	Required : nothing
	Output : nothing
	Consequence : add a new arc in the list plaNODinArcs, 
		this arc got uiNodeDestinationId as destination
	**********************************/
	void NODaddArcIn(unsigned int uiNodeDestinationId);

	/**********************************
	Arc Out adder
	**********************************
	Input : an unsigned int (uiNodeDestinationId)
	Required : nothing
	Output : nothing
	Consequence : add a new arc in the list plaNODoutArcs,
		this arc got uiNodeDestinationId as destination
	**********************************/
	void NODaddArcOut(unsigned int uiNodeDestinationId);

	/**********************************
	Arc In deleter
	**********************************
	Input : an unsigned int (uiNodeDestinationId)
	Required : nothing
	Output : nothing
	Consequence : remove a arc in the list plaNODinArcs that have 
		uiNodeDestinationId as destination
	**********************************/
	void NODdeleteArcIn(unsigned int uiNodeDestinationId);

	/**********************************
	Arc Out deleter
	**********************************
	Input : an unsigned int (uiNodeDestinationId)
	Required : nothing
	Output : nothing
	Consequence : remove a arc in the list plaNODoutArcs that have
		uiNodeDestinationId as destination
	**********************************/
	void NODdeleteArcOut(unsigned int uiNodeDestinationId);

	/**********************************
	Neighbours getter
	**********************************
	Input : nothing
	Required : nothing
	Output : a list representing the ids of all neighbours of the current node
	Consequence : nothing
	**********************************/
	CList<unsigned int> * NODgetNeighbours();

	/**********************************
	Display
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : display the node in the default output
	**********************************/
	void NODdisplay();
};

#endif