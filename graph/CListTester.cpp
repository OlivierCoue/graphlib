
#include "stdafx.h"
#include "CListTester.h"
#include "CList.h"
#include "CElement.h"
#include "CException.h"

void CListTester::LSTTmakeTest() {
	cout << "Starting CList tests" << endl;

	int iValueElem0 = 0;
	int iValueElem1 = 1;
	int iValueElem2 = 2;
	int iValueElem3 = 3;
		
	CList<int> * LSTlist = new CList<int>();

	if (LSTlist->LSTgetSize() != 0)
		throw new CException(1, "CTestFailedExcpetion");
	
	LSTlist->LSTaddElementEnd(new CElement<int>(&iValueElem0));
	if (*LSTlist->LSTgetElementAt(0) != 0)
		throw new CException(1, "CTestFailedExcpetion");

	LSTlist->LSTaddElementEnd(new CElement<int>(&iValueElem1));
	if (*LSTlist->LSTgetElementAt(1) != 1)
		throw new CException(1, "CTestFailedExcpetion");

	LSTlist->LSTaddElementEnd(new CElement<int>(&iValueElem2));
	if (*LSTlist->LSTgetElementAt(2) != 2)
		throw new CException(1, "CTestFailedExcpetion");

	CList<int> * LSTlistCpy = new CList<int>(*LSTlist);

	LSTlist->LSTremoveElementAt(0);
	if (*LSTlist->LSTgetElementAt(0) != 1)
		throw new CException(1, "CTestFailedExcpetion");

	LSTlist->LSTaddElementEnd(new CElement<int>(&iValueElem3));
	if (*LSTlist->LSTgetElementAt(2) != 3)
		throw new CException(1, "CTestFailedExcpetion");

	LSTlist->LSTremoveElementAt(1);
	if (*LSTlist->LSTgetElementAt(1) != 3)
		throw new CException(1, "CTestFailedExcpetion");

	LSTlist->LSTempty();
	if (LSTlist->LSTgetSize() != 0)
		throw new CException(1, "CTestFailedExcpetion");
	delete LSTlist;

	if (LSTlistCpy->LSTgetSize() != 3)
		throw new CException(1, "CTestFailedExcpetion");
	if (*LSTlistCpy->LSTgetElementAt(0) != 0)
		throw new CException(1, "CTestFailedExcpetion");
	if (*LSTlistCpy->LSTgetElementAt(1) != 1)
		throw new CException(1, "CTestFailedExcpetion");
	if (*LSTlistCpy->LSTgetElementAt(2) != 2)
		throw new CException(1, "CTestFailedExcpetion");

	delete LSTlistCpy;

	cout << "CList tests successfully passed" << endl;
}