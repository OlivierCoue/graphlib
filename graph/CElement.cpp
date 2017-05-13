
/**********************************
Default constructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : initialisation of an element
**********************************/
template<class MType>
CElement<MType>::CElement() {
	pELTnext = nullptr;
	ptELTvalue = nullptr;
}

/**********************************
Clone constructor
**********************************
Input : object of type CElement<MType> (ELTobj)
Required : nothing
Output : nothing
Consequence : initialisation of a list by copy of ELTobj
**********************************/
template<class MType>
CElement<MType>::CElement(CElement<MType> & ELTobj) {
	ptELTvalue = new MType(ELTobj);
}

/**********************************
One parameter constructor
**********************************
Input : an unsigned int (ptValue)
Required : nothing
Output : nothing
Consequence : initialisation a element and set the value
**********************************/
template<class MType>
CElement<MType>::CElement(MType * ptValue) {
	pELTnext = nullptr;
	ptELTvalue = ptValue;
}

/**********************************
ptELTvalue getter
**********************************
Input : nothing
Required : nothing
Output : the value of ptELTvalue
Consequence : nothing
**********************************/
template<class MType>
MType * CElement<MType>::ELTgetValue() {
	return ptELTvalue;
}

/**********************************
ptELTvalue setter
**********************************
Input : an MType object (pValue)
Required : nothing
Output : nothing
Consequence : set the value of ptELTvalue with pValue
**********************************/
template<class MType>
void CElement<MType>::ELTsetValue(MType * pValue) {
	ptELTvalue = pValue;
}

/**********************************
pELTnext getter
**********************************
Input : nothing
Required : nothing
Output : the value of pELTnext
Consequence : nothing
**********************************/
template<class MType>
CElement<MType> * CElement<MType>::ELTgetNext() {
	return pELTnext;
}

/**********************************
pELTnext setter
**********************************
Input : an MType object (ELTobj)
Required : nothing
Output : nothing
Consequence : set the value of pELTnext with pELTnext
**********************************/
template<class MType>
void CElement<MType>::ELTsetNext(CElement<MType> * ELTobj) {
	pELTnext = ELTobj;
}
