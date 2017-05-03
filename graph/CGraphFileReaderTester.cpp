#include "stdafx.h"
#include "CGraphFileReaderTester.h"

using namespace std;
void CGraphFileReaderTester::GFRTmakeTest() {
	CGraph * graph = CGraphFileReader::GFRcreateGraph("test_files/test_2.txt");
	graph->GRAdeleteArc(1,2);
	graph->GRAdisplay();
}