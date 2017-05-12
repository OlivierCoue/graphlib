#ifndef CLIST_H
#define CLIST_H

#include "stdafx.h"
#include <iostream>
#include "CElement.h"
#include "CException.h"

using namespace std;

template <class MType>
class CList{
private:
	unsigned int uiLSTSize;
	CElement<MType> * pLSThead;
	CElement<MType> * pLSTtail;
public:
	CList();
	CList(CList<MType> & LSTobj);
	~CList();
	unsigned int LSTgetSize();
	void LSTaddElementEnd(CElement<MType> * pELTobj);
	MType * LSTgetElementAt(unsigned int uiIndex);
	void LSTremoveElementAt(unsigned int uiIndex);
	void LSTempty();
	void LSTdisplay();
};

#include "CList.cpp"

#endif