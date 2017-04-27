
#include "stdafx.h"
#include "CArc.h"

CArc::CArc() {
	uiARCnodeDestId = 0;
}

CArc::CArc(unsigned int uiNodeDestId) {
	uiARCnodeDestId = uiNodeDestId;
}

CArc::CArc(CArc & ARCobj) {
}

CArc::~CArc() {
}

unsigned int CArc::ARCgetNodeDestId() {
	return uiARCnodeDestId;
}