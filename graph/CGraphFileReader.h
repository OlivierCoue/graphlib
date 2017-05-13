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
	/**********************************
	Get value in characters array from a key
	**********************************
	Input : - characters array representing the source of search
			- characters array representing the key to find
	Required : nothing
	Output : integer representing the value corresponding to the key
	Consequence : nothing
	**********************************/
	static int GFRgetValueInArrayFromKey(char * pcArray, char * pcKey);
public:

	/**********************************
	Create graph from file
	**********************************
	Input : characters array representing the file name and path
	Required : nothing
	Output : pointer on CGraph objet respresenting the graph of the file
	Consequence : nothing
	**********************************/
	static CGraph* GFRcreateGraph(char * pcFilename);
};
#endif