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
	/**********************************
	Default constructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : initialisation of an element
	**********************************/
	CElement();

	/**********************************
	Clone constructor
	**********************************
	Input : object of type CElement<MType> (ELTobj)
	Required : nothing
	Output : nothing
	Consequence : initialisation of a list by copy of ELTobj
	**********************************/
	CElement(CElement<MType> & ELTobj);

	/**********************************
	One parameter constructor
	**********************************
	Input : an unsigned int (ptValue)
	Required : nothing
	Output : nothing
	Consequence : initialisation a element and set the value
	**********************************/
	CElement(MType * ptValue);

	/**********************************
	ptELTvalue setter
	**********************************
	Input : an MType object (pValue)
	Required : nothing
	Output : nothing
	Consequence : set the value of ptELTvalue with pValue
	**********************************/
	void ELTsetValue(MType * pValue);

	/**********************************
	ptELTvalue getter
	**********************************
	Input : nothing
	Required : nothing
	Output : the value of ptELTvalue
	Consequence : nothing
	**********************************/
	MType * ELTgetValue();

	/**********************************
	pELTnext getter
	**********************************
	Input : nothing
	Required : nothing
	Output : the value of pELTnext
	Consequence : nothing
	**********************************/
	CElement<MType> * ELTgetNext();

	/**********************************
	pELTnext setter
	**********************************
	Input : an MType object (ELTobj)
	Required : nothing
	Output : nothing
	Consequence : set the value of pELTnext with pELTnext
	**********************************/
	void ELTsetNext(CElement<MType> * ELTobj);
};

#include "CElement.cpp"

#endif