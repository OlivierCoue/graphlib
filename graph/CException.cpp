#include "stdafx.h"
#include "CException.h"

	/**********************************
	Default constructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : initialize an empty object
	**********************************/
CException::CException() {
}

	/**********************************
	Clone constructor
	**********************************
	Input : object of type CException
	Required : nothing
	Output : nothing
	Consequence : initialization of an exception by copy of EXCobj
	**********************************/
CException::CException(CException & EXCobj) {
	uiEXCValue = EXCobj.uiEXCValue;
}

	/**********************************
	Constructor with one argument
	**********************************
	Input : integer representing the error value
	Required : nothing
	Output : nothing
	Consequence : initialization of the object
	**********************************/
CException::CException(unsigned int uiValue) {
	uiEXCValue = uiValue;
	cout << endl << "Exception code: " << uiValue << endl;
}

	/**********************************
	Destructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : finalize the object
	**********************************/
CException::~CException() {
}

	/**********************************
	Setter uiEXCValue
	**********************************
	Input : unsigned integer
	Required : nothing
	Output : nothing
	Consequence : modify uiEXCValue
	**********************************/
void CException::EXCSetValue(unsigned int uiValue) {
	uiEXCValue = uiValue;
}

	/**********************************
	Getter uiEXCValue
	**********************************
	Input : nothing
	Required : nothing
	Output : uiEXCValue
	Consequence : nothing
	**********************************/
unsigned int CException::EXCGetValue() {
	return uiEXCValue;
}

	/**********************************
	Get message corresponding to the value
	**********************************
	Input : nothing
	Required : nothing
	Output : characters array corresponding to uiEXCValue
	Consequence : nothing
	**********************************/
char * CException::EXCGetMessage() {
	char * pcMessage;
	switch (uiEXCValue)
	{
	case 1: pcMessage = _strdup("The node do not exist"); break;
	case 2: pcMessage = _strdup("Key not found"); break;
	case 3: pcMessage = _strdup("Cannot open file"); break;
	case 4: pcMessage = _strdup("Index out of bound"); break;
	default:pcMessage = _strdup("Unknown exception"); break;
		break;
	};
	return pcMessage;
}
