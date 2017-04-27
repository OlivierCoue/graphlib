#ifndef CELEMENT_H
#define CELEMENT_H

#include "stdafx.h"
#include <iostream>

using namespace std;

template <class MType>
class CElement {
private:
	CElement<MType> * pELTnext;
	MType * ptELTvalue;
public:
	CElement();
	CElement(CElement<MType> & ELTobj);
	CElement(MType * ptValue);
	void ELTsetValue(MType * pValue);
	MType * ELTgetValue();
	CElement<MType> * ELTgetNext();
	void ELTsetNext(CElement<MType> * ELTobj);
};

#include "CElement.cpp"

#endif