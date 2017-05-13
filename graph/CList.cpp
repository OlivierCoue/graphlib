
/**********************************
Default constructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : initialisation of an empty list
**********************************/
template<class MType>
CList<MType>::CList() {
	uiLSTSize = 0;
	pLSThead = nullptr;
	pLSTtail = nullptr;
}

/**********************************
Clone constructor
**********************************
Input : object of type CList<MType> (LSTobj)
Required : nothing
Output : nothing
Consequence : initialisation of a list by copy of LSTobj
**********************************/
template<class MType>
CList<MType>::CList(CList<MType> & LSTobj) {
	unsigned int uiLoop;
	uiLSTSize = 0;
	for (uiLoop = 0; uiLoop < LSTobj.LSTgetSize(); uiLoop++)
		LSTaddElementEnd(new CElement<MType>(LSTobj.LSTgetElementAt(uiLoop)));
}

/**********************************
Destructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : empty the list by calling LSTempty
**********************************/
template<class MType>
CList<MType>::~CList() {
	LSTempty();
}

/**********************************
List size getter
**********************************
Input : nothing
Required : nothing
Output : a unsigned int representing the size of the list
Consequence : nothing
**********************************/
template<class MType>
unsigned int CList<MType>::LSTgetSize() {
	return uiLSTSize;
}

/**********************************
Element adder
**********************************
Input : object of type CElement<MType> (pELTobj)
Required : nothing
Output : nothing
Consequence : add an element at the end of the list
**********************************/
template<class MType>
void CList<MType>::LSTaddElementEnd(CElement<MType> * pELTobj) {
	if (pLSThead == nullptr) {
		pELTobj->ELTsetNext(nullptr);
		pLSThead = pELTobj;
		pLSTtail = pELTobj;
	} else {
		pLSTtail->ELTsetNext(pELTobj);
		pLSTtail = pLSTtail->ELTgetNext();
	}
	uiLSTSize++;
}

/**********************************
Element getter
**********************************
Input : object of type CElement<MType> (pELTobj)
Required : nothing
Output : the element in the list at the position uiIndex
Consequence : nothing
**********************************/
template<class MType>
MType * CList<MType>::LSTgetElementAt(unsigned int uiIndex) {
	unsigned int uiLoop;
	CElement<MType> * ELTtoReturn = pLSThead;

	if (uiIndex >= uiLSTSize)
		throw new CException(OUT_OF_BOUND);

	for (uiLoop = 0; uiLoop < uiIndex; uiLoop++) {
		ELTtoReturn = ELTtoReturn->ELTgetNext();
	}
	return ELTtoReturn->ELTgetValue();
}

/**********************************
Element deleter
**********************************
Input : a unsigned int (uiIndex)
Required : nothing
Output : nothing
Consequence : remove an element of the list a the position passed as parameter
**********************************/
template<class MType>
void CList<MType>::LSTremoveElementAt(unsigned int uiIndex) {
	unsigned int uiLoop;
	CElement<MType> * ELTtoRemove = pLSThead;
	CElement<MType> * ELTtoRemoveParent = pLSThead;

	if (uiIndex >= uiLSTSize)
		throw new CException(OUT_OF_BOUND);

	if (uiIndex == 0) {
		CElement<MType> * pELTsavedHead = pLSThead;
		pLSThead = pLSThead->ELTgetNext();
		delete pELTsavedHead;
	} else {
		for (uiLoop = 0; uiLoop < uiIndex; uiLoop++) {
			ELTtoRemoveParent = ELTtoRemove;
			ELTtoRemove = ELTtoRemove->ELTgetNext();
		}
		ELTtoRemoveParent->ELTsetNext(ELTtoRemove->ELTgetNext());
		delete ELTtoRemove;
	}
	uiLSTSize--;
}

/**********************************
Empty
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : remove all element in the list
**********************************/
template<class MType>
void CList<MType>::LSTempty() {
	while (uiLSTSize > 0)
		LSTremoveElementAt(uiLSTSize - 1);
}

/**********************************
Display
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : display the list in the default output
**********************************/
template<class MType>
void CList<MType>::LSTdisplay() {
	CElement<MType> * pELTloop = pLSThead;
	cout << "head -> ";
	while (pELTloop != nullptr) {
		cout << *pELTloop->ELTgetValue() << " -> ";
		pELTloop = pELTloop->ELTgetNext();
	}
	cout << "tail" << endl;
}