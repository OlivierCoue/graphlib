#ifndef CGRAPHFILEREADERTESTER_H
#define CGRAPHFILEREADERTESTER_H

#include <fstream>
#include <iostream>
#include "CGraphFileReader.h"
#include "CGraph.h"

class CGraphFileReaderTester
{
public:
	/**********************************
	Tester
	**********************************
	Input : nothing
	Required : A file "test_files/test.txt" containing the following content
		"
		NBSommets=2
		NBArcs=2
		Sommets=[
		Numero=8
		Numero=12
		]
		Arcs=[
		Debut=8, Fin=12
		Debut=12, Fin=8
		]
		"
	Output : nothing
	Consequence : a serie of test is made one the class CGraphFileReader
	**********************************/
 	static void GFRTmakeTest();
};


#endif