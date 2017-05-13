#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include "stdafx.h"
#include <string.h>
#include <iostream>

#define NODE_DONT_EXIST 1
#define KEY_NOT_FOUND 2
#define CANNOT_OPEN_FILE 3
#define OUT_OF_BOUND 4

using namespace std;

class CException {
private:
	unsigned int uiEXCValue;
public:
	/**********************************
	Default constructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : initialize an empty object
	**********************************/
	CException();

	/**********************************
	Clone constructor
	**********************************
	Input : object of type CException
	Required : nothing
	Output : nothing
	Consequence : initialization of an exception by copy of EXCobj
	**********************************/
	CException(CException & EXCobj);

	/**********************************
	Constructor with one argument
	**********************************
	Input : integer representing the error value
	Required : nothing
	Output : nothing
	Consequence : initialization of the object
	**********************************/
	CException(unsigned int uiValue);

	/**********************************
	Destructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : finalize the object
	**********************************/
	~CException();

	/**********************************
	Setter uiEXCValue
	**********************************
	Input : unsigned integer
	Required : nothing
	Output : nothing
	Consequence : modify uiEXCValue
	**********************************/
	void EXCSetValue(unsigned int uiValue);

	/**********************************
	Getter uiEXCValue
	**********************************
	Input : nothing
	Required : nothing
	Output : uiEXCValue
	Consequence : nothing
	**********************************/
	unsigned int EXCGetValue();

	/**********************************
	Get message corresponding to the value
	**********************************
	Input : nothing
	Required : nothing
	Output : characters array corresponding to uiEXCValue
	Consequence : nothing
	**********************************/
	char * EXCGetMessage();
};

#endif 