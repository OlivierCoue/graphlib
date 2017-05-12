// graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CGraphFileReaderTester.h"
#include "CListTester.h"
#include "CNodeTester.h"
#include "CGraphTester.h"
#include "CException.h"
#include "CGraphOperation.h"

#define MAKE_TEST

using namespace std;

int main(int argc, char* argv[])
{
	#ifdef MAKE_TEST
	CListTester::LSTTmakeTest();
	CNodeTester::NODTmakeTest();
	CGraphTester::GRATmakeTest();
	CGraphFileReaderTester::GFRTmakeTest();
	#endif // MAKE_TEST
	
	if (argc == 1) {
		cerr << "No input files" << endl;
		exit(-1);
	}

	CGraph * graph = CGraphFileReader::GFRcreateGraph(argv[1]);

	cout << "Normal graph:"<<endl;
	graph->GRAdisplay();

	CGraph * swappedGraph = CGraphOperation::GROgetSwappedArcsGraph(graph);

	cout << "\nSwapped graph:"<<endl;
	swappedGraph->GRAdisplay();

	return 0;
}