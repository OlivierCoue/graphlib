#ifndef CARC_H
#define CARC_H

#include <iostream>

using namespace std;

class CArc {
private:
	unsigned int uiARCnodeDestId;
public:
	CArc();
	CArc(unsigned int uiNodeDestId);
	CArc(CArc & ARCobj);
	~CArc();
	unsigned int ARCgetNodeDestId();
};

#endif