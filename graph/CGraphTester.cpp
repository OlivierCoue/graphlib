
#include "stdafx.h"
#include "CGraphTester.h"
#include "CGraph.h"
#include "CList.h"
#include "CElement.h"
#include "CGraphOpertation.h"

void CGraphTester::GRATmakeTest() {
	CGraph * GRAtest = new CGraph();
	GRAtest->GRAaddNode(1);
	GRAtest->GRAaddNode(2);
	GRAtest->GRAaddNode(3);
	GRAtest->GRAaddNode(4);
	GRAtest->GRAaddNode(5);

	GRAtest->GRAaddArc(1, 2);
	GRAtest->GRAaddArc(1, 3);
	GRAtest->GRAaddArc(2, 3);
	GRAtest->GRAaddArc(2, 4);
	GRAtest->GRAaddArc(2, 5);
	GRAtest->GRAaddArc(5, 2);
	
	//GRAtest->GRAdeleteNode(2);

	GRAtest->GRAdisplay();

	cout << "Swaped graph" << endl;
	CGraphOperation::GROgetSwappedArcsGraph(GRAtest)->GRAdisplay();
}