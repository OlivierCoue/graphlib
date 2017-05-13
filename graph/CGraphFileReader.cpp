#include "stdafx.h"
#include "CGraphFileReader.h"

	/**********************************
	Get value in characters array from a key
	**********************************
	Input : - characters array representing the source of search
			- characters array representing the key to find
	Required : nothing
	Output : integer representing the value corresponding to the key
	Consequence : nothing
	**********************************/
int CGraphFileReader::GFRgetValueInArrayFromKey(char * pcArray, char * pcKey) {
	char * pcPos;
	pcPos = strstr(pcArray,pcKey);
	if(pcPos == nullptr)
		throw new CException(KEY_NOT_FOUND);
	pcPos = strchr(pcPos, '=');
	pcPos++;
	return atoi(pcPos);
}

	/**********************************
	Create graph from file
	**********************************
	Input : characters array representing the file name and path
	Required : nothing
	Output : pointer on CGraph objet respresenting the graph of the file
	Consequence : nothing
	**********************************/
CGraph* CGraphFileReader::GFRcreateGraph(char * pcFilename) {
	CParser parser(pcFilename);
	unsigned int uiNbNodes=atoi(parser.PRSgetValueFromKey("NBSommets"));
	unsigned int uiNbArcs=atoi(parser.PRSgetValueFromKey("NBArcs"));
	unsigned int uiNodesCount, uiArcsCount;
	unsigned int uiNodeId, valDeb, valFin;
	CGraph * pGRAgraph = new CGraph();
	char ** ppcNodesArray = parser.PRSgetArrayFromKey("Sommets");
	for(uiNodesCount=0; uiNodesCount < uiNbNodes; uiNodesCount++) {
		uiNodeId = GFRgetValueInArrayFromKey(ppcNodesArray[uiNodesCount], "Numero");
		pGRAgraph->GRAaddNode(uiNodeId);
	}
	char ** ppcArcsArray = parser.PRSgetArrayFromKey("Arcs");
	for(uiArcsCount=0; uiArcsCount < uiNbArcs; uiArcsCount++) {
		valDeb = GFRgetValueInArrayFromKey(ppcArcsArray[uiArcsCount], "Debut");
		valFin = GFRgetValueInArrayFromKey(ppcArcsArray[uiArcsCount], "Fin");
		pGRAgraph->GRAaddArc(GFRgetValueInArrayFromKey(ppcArcsArray[uiArcsCount], "Debut"),GFRgetValueInArrayFromKey(ppcArcsArray[uiArcsCount], "Fin"));
	}
	return pGRAgraph;
}
