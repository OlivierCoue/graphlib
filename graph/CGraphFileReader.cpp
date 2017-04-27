#include "stdafx.h"
#include "CGraphFileReader.h"

/*int CGraphFileReader::GFRgetIntAfterSymbol(ifstream * pfFile, char cSymbol) {
	int iValue;
	pfFile->ignore(128, cSymbol);
	*pfFile >> iValue;
	return iValue;
}*/

void CGraphFileReader::GFRcreateGraph(char * pcFilename) {
	CParser parser(pcFilename);

	unsigned int uiNbNodes=atoi(parser.PRSgetValueFromKey("NBSommets"));
	unsigned int uiNbArcs=atoi(parser.PRSgetValueFromKey("NBArcs"));
	unsigned int uiNodesCount, uiArcsCount;
	int val, valDeb, valFin;
	// create empty Cgraph
	char ** ppcNodesArray = parser.PRSgetArrayFromKey("Sommets");
	for(uiNodesCount=0; uiNodesCount < uiNbNodes; uiNodesCount++) {
		val = GFRgetValueInArrayFromKey(ppcNodesArray[uiNodesCount], "Numero");
		// add node : graph->GRAaddNode(GFRgetValueInArrayFromKey(ppcNodesArray[uiNodesCount], "Numero"));
	}
	char ** ppcArcsArray = parser.PRSgetArrayFromKey("Arcs");
	for(uiArcsCount=0; uiArcsCount < uiNbArcs; uiArcsCount++) {
		valDeb = GFRgetValueInArrayFromKey(ppcArcsArray[uiArcsCount], "Debut");
		valFin = GFRgetValueInArrayFromKey(ppcArcsArray[uiArcsCount], "Fin");
		// add arc : graph->GRAaddArc(GFRgetValueInArrayFromKey(ppcArcsArray[uiArcsCount], "Debut"),GFRgetValueInArrayFromKey(ppcArcsArray[uiArcsCount], "Fin"));
	}

	// return *graph;
}

int CGraphFileReader::GFRgetValueInArrayFromKey(char * pcArray, char * pcKey) {
	char * pcPos;
	pcPos = strstr(pcArray,pcKey);
	if(pcPos == nullptr)
		throw new CException(5,"CKeyNotFoundException");
	pcPos = strchr(pcPos, '=');
	pcPos++;
	return atoi(pcPos);
}