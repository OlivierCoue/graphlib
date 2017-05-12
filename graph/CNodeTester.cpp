#include "stdafx.h"
#include <assert.h>
#include "CNodeTester.h"
#include "CNode.h"

void CNodeTester::NODTmakeTest() {

	CNode * NODtest = new CNode(1);

	NODtest->NODaddArcIn(1);
	NODtest->NODaddArcIn(2);
	NODtest->NODaddArcOut(3);
	NODtest->NODaddArcOut(4);

	assert(NODtest->NODgetInArcsCount() == 2);
	assert(NODtest->NODgetInArcByIndex(0)->ARCgetNodeDestId() == 1);
	assert(NODtest->NODgetInArcByIndex(1)->ARCgetNodeDestId() == 2);

	assert(NODtest->NODgetOutArcsCount() == 2);
	assert(NODtest->NODgetOutArcByIndex(0)->ARCgetNodeDestId() == 3);
	assert(NODtest->NODgetOutArcByIndex(1)->ARCgetNodeDestId() == 4);

	cout << "CNode tests successfully passed" << endl;
}