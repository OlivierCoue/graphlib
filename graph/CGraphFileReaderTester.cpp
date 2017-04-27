#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "CGraphFileReaderTester.h"

using namespace std;
void CGraphFileReaderTester::test() {
	CGraphFileReader::GFRcreateGraph("test_files/test_1.txt");
}