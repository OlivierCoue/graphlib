
#include "stdafx.h"
#include "CGraphTester.h"
#include "CGraph.h"
#include "CList.h"
#include "CElement.h"

void CGraphTester::GRATmakeTest() {
	CGraph * GRAtest = new CGraph();
	GRAtest->GRAaddNode(1);
	GRAtest->GRAaddNode(2);
	GRAtest->GRAaddNode(3);

	GRAtest->GRAgetNodeById(1);
	GRAtest->GRAgetNodeById(2);
	GRAtest->GRAgetNodeById(3);

	GRAtest->GRAaddArc(1, 2);
	GRAtest->GRAaddArc(2, 1);

	GRAtest->GRAdisplay();
}