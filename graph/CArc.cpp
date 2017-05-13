
#include "stdafx.h"
#include "CArc.h"

/**********************************
Default constructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : initialisation of an arc
**********************************/
CArc::CArc() {
	uiARCnodeDestId = 0;
}

/**********************************
One parameter constructor
**********************************
Input : an unsigned int (uiNodeDestId)
Required : nothing
Output : nothing
Consequence : initialisation an arc and set the uiARCnodeDestId
**********************************/
CArc::CArc(unsigned int uiNodeDestId) {
	uiARCnodeDestId = uiNodeDestId;
}

/**********************************
Clone constructor
**********************************
Input : object of type CArc (ARCobj)
Required : nothing
Output : nothing
Consequence : initialisation of an arc by copy of ARCobj
**********************************/
CArc::CArc(CArc & ARCobj) {
}

/**********************************
Destructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : finalise the object
**********************************/
CArc::~CArc() {
}

/**********************************
uiARCnodeDestId getter
**********************************
Input : nothing
Required : nothing
Output : the value of uiARCnodeDestId
Consequence : nothing
**********************************/
unsigned int CArc::ARCgetNodeDestId() {
	return uiARCnodeDestId;
}