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
	/**********************************
	Default constructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : initialisation of an empty list
	**********************************/
	CList();

	/**********************************
	Clone constructor
	**********************************
	Input : object of type CList<MType> (LSTobj)
	Required : nothing
	Output : nothing
	Consequence : initialisation of a list by copy of LSTobj
	**********************************/
	CList(CList<MType> & LSTobj);

	/**********************************
	Destructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : empty the list by calling LSTempty
	**********************************/
	~CList();

	/**********************************
	List size getter
	**********************************
	Input : nothing
	Required : nothing
	Output : a unsigned int representing the size of the list
	Consequence : nothing
	**********************************/
	unsigned int LSTgetSize();

	/**********************************
	Element adder
	**********************************
	Input : object of type CElement<MType> (pELTobj)
	Required : nothing
	Output : nothing
	Consequence : add an element at the end of the list
	**********************************/
	void LSTaddElementEnd(CElement<MType> * pELTobj);

	/**********************************
	Element getter
	**********************************
	Input : object of type CElement<MType> (pELTobj)
	Required : nothing
	Output : the element in the list at the position uiIndex
	Consequence : nothing
	**********************************/
	MType * LSTgetElementAt(unsigned int uiIndex);

	/**********************************
	Element deleter
	**********************************
	Input : a unsigned int (uiIndex)
	Required : nothing
	Output : nothing
	Consequence : remove an element of the list a the position passed as parameter
	**********************************/
	void LSTremoveElementAt(unsigned int uiIndex);

	/**********************************
	Empty
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : remove all element in the list
	**********************************/
	void LSTempty();

	/**********************************
	Display
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : display the list in the default output
	**********************************/
	void LSTdisplay();
};

#include "CList.cpp"

#endif