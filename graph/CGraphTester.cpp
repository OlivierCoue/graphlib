
#include "stdafx.h"
#include <assert.h>
#include "CGraphTester.h"
#include "CGraph.h"
#include "CList.h"
#include "CElement.h"
#include "CGraphOperation.h"

/**********************************
Tester
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : a serie of test is made one the class CGraph
**********************************/
static void GRATmakeTest();
void CGraphTester::GRATmakeTest() {

	CGraph * GRAtest = new CGraph();

	GRAtest->GRAaddNode(1);
	GRAtest->GRAaddNode(2);
	GRAtest->GRAaddNode(3);
	GRAtest->GRAaddNode(4);
	GRAtest->GRAaddNode(5);

	assert(GRAtest->GRAgetNodesCount() == 5);
	assert(GRAtest->GRAgetNodeIdByIndex(0) == 1);
	assert(GRAtest->GRAgetNodeIdByIndex(1) == 2);
	assert(GRAtest->GRAgetNodeIdByIndex(2) == 3);
	assert(GRAtest->GRAgetNodeIdByIndex(3) == 4);
	assert(GRAtest->GRAgetNodeIdByIndex(4) == 5);

	GRAtest->GRAaddArc(1, 2);
	GRAtest->GRAaddArc(1, 3);
	GRAtest->GRAaddArc(2, 3);
	GRAtest->GRAaddArc(2, 4);
	GRAtest->GRAaddArc(2, 5);
	GRAtest->GRAaddArc(5, 2);
	
	assert(GRAtest->GRAgetNodeNeighboursById(1)->LSTgetSize() == 2);
	assert(GRAtest->GRAgetNodeNeighboursById(2)->LSTgetSize() == 3);
	assert(GRAtest->GRAgetNodeNeighboursById(5)->LSTgetSize() == 1);

	cout << "CGraph tests successfully passed" << endl;

}