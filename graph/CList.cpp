
template<class MType>
CList<MType>::CList() {
	uiLSTSize = 0;
	pLSThead = nullptr;
	pLSTtail = nullptr;
}

template<class MType>
CList<MType>::CList(CList<MType> & LSTobj) {
	unsigned int uiLoop;
	uiLSTSize = 0;
	for (uiLoop = 0; uiLoop < LSTobj.LSTgetSize(); uiLoop++)
		LSTaddElementEnd(new CElement<MType>(LSTobj.LSTgetElementAt(uiLoop)));
}

template<class MType>
CList<MType>::~CList() {
	LSTempty();
}

template<class MType>
unsigned int CList<MType>::LSTgetSize() {
	return uiLSTSize;
}

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

template<class MType>
void CList<MType>::LSTempty() {
	while (uiLSTSize > 0)
		LSTremoveElementAt(uiLSTSize - 1);
}

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