#include "stdafx.h"
#include "CGraphFileReaderTester.h"

using namespace std;
void CGraphFileReaderTester::GFRTmakeTest() {
	CGraphFileReader::GFRcreateGraph("test_files/test_2.txt")->GRAdisplay();
}