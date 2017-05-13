#ifndef CARC_H
#define CARC_H

#include <iostream>

using namespace std;

class CArc {
private:
	unsigned int uiARCnodeDestId;
public:
	/**********************************
	Default constructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : initialisation of an arc
	**********************************/
	CArc();

	/**********************************
	One parameter constructor
	**********************************
	Input : an unsigned int (uiNodeDestId)
	Required : nothing
	Output : nothing
	Consequence : initialisation an arc and set the uiARCnodeDestId
	**********************************/
	CArc(unsigned int uiNodeDestId);

	/**********************************
	Clone constructor
	**********************************
	Input : object of type CArc (ARCobj)
	Required : nothing
	Output : nothing
	Consequence : initialisation of an arc by copy of ARCobj
	**********************************/
	CArc(CArc & ARCobj);

	/**********************************
	Destructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : finalise the object
	**********************************/
	~CArc();

	/**********************************
	uiARCnodeDestId getter
	**********************************
	Input : nothing
	Required : nothing
	Output : the value of uiARCnodeDestId
	Consequence : nothing
	**********************************/
	unsigned int ARCgetNodeDestId();
};

#endif