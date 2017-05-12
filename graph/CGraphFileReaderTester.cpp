#include "stdafx.h"
#include <assert.h>
#include "CGraphFileReaderTester.h"
#include "CGraphOpertation.h"

using namespace std;
void CGraphFileReaderTester::GFRTmakeTest() {

	CGraph * GRAtest = CGraphFileReader::GFRcreateGraph("test_files/test.txt");

	assert(GRAtest->GRAgetNodesCount() == 2);
	assert(GRAtest->GRAgetNodeIdByIndex(0) == 8);
	assert(GRAtest->GRAgetNodeIdByIndex(1) == 12);
	assert(GRAtest->GRAgetNodeNeighboursById(8)->LSTgetSize() == 1);
	assert(*GRAtest->GRAgetNodeNeighboursById(8)->LSTgetElementAt(0) == 12);
	assert(GRAtest->GRAgetNodeNeighboursById(12)->LSTgetSize() == 1);
	assert(*GRAtest->GRAgetNodeNeighboursById(12)->LSTgetElementAt(0) == 8);

	cout << "CGraphFileReader tests successfully passed" << endl;

}