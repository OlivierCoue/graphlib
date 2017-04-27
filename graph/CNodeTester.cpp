#include "stdafx.h"
#include "CNodeTester.h"
#include "CNode.h"

void CNodeTester::NODTmakeTest() {

	CNode * NODtest = new CNode(1);
	NODtest->NODaddArcIn(1);
	NODtest->NODaddArcIn(2);
	NODtest->NODaddArcOut(3);
	NODtest->NODaddArcOut(4);
	NODtest->NODdisplay();
}