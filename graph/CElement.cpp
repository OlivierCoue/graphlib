
template<class MType>
CElement<MType>::CElement() {
	pELTnext = nullptr;
	ptELTvalue = nullptr;
}

template<class MType>
CElement<MType>::CElement(CElement<MType> & ELTobj) {
	ptELTvalue = new MType(ELTobj);
}

template<class MType>
CElement<MType>::CElement(MType * ptValue) {
	pELTnext = nullptr;
	ptELTvalue = ptValue;
}

template<class MType>
MType * CElement<MType>::ELTgetValue() {
	return ptELTvalue;
}

template<class MType>
void CElement<MType>::ELTsetValue(MType * pValue) {
	ptELTvalue = pValue;
}

template<class MType>
CElement<MType> * CElement<MType>::ELTgetNext() {
	return pELTnext;
}

template<class MType>
void CElement<MType>::ELTsetNext(CElement<MType> * ELTobj) {
	pELTnext = ELTobj;
}
