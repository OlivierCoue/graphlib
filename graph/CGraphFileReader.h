#ifndef CGRAPHFILEREADER_H
#define CGRAPHFILEREADER_H

#include <fstream>
#include <iostream>
#include "CParser.h"
#include "CGraph.h"
#include "CException.h"

using namespace std;
class CGraphFileReader
{
private:
	static int GFRgetValueInArrayFromKey(char * pcArray, char * pcKey);
	//static int GFRgetIntAfterSymbol(ifstream * pfFile, char cSymbol);
public:
	static CGraph* GFRcreateGraph(char * pcFilename);
};
#endif