// graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CGraphFileReaderTester.h"
#include "CListTester.h"
#include "CNodeTester.h"
#include "CGraphTester.h"
#include "CException.h"

using namespace std;

int main(int argc, char* argv[])
{
	try {
		CListTester::LSTTmakeTest();
		//CNodeTester::NODTmakeTest();
		CGraphTester::GRATmakeTest();
		CGraphFileReaderTester::test();
	} catch (CException * pEXCobj) {
		cout << pEXCobj->EXCGetMessage();
	}

	return 0;
}