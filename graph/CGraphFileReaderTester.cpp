#include "stdafx.h"
#include "CGraphFileReaderTester.h"
#include "CGraphOpertation.h"

using namespace std;
void CGraphFileReaderTester::GFRTmakeTest() {
	CGraph * GRAtest = CGraphFileReader::GFRcreateGraph("test_files/test_2.txt");
	GRAtest->GRAdisplay();

	cout << endl << "Swapped: " << endl;

	CGraphOperation::GROgetSwapedArcsGraph(GRAtest)->GRAdisplay();
}