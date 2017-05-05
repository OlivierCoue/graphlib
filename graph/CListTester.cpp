
#include "stdafx.h"
#include <assert.h>
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
	
	assert(LSTlist->LSTgetSize() == 0);		
	
	LSTlist->LSTaddElementEnd(new CElement<int>(&iValueElem0));
	assert(*LSTlist->LSTgetElementAt(0) == 0);
		
	LSTlist->LSTaddElementEnd(new CElement<int>(&iValueElem1));
	assert(*LSTlist->LSTgetElementAt(1) == 1);

	LSTlist->LSTaddElementEnd(new CElement<int>(&iValueElem2));
	assert(*LSTlist->LSTgetElementAt(2) == 2);		

	CList<int> * LSTlistCpy = new CList<int>(*LSTlist);

	LSTlist->LSTremoveElementAt(0);
	assert(*LSTlist->LSTgetElementAt(0) == 1);

	LSTlist->LSTaddElementEnd(new CElement<int>(&iValueElem3));
	assert(*LSTlist->LSTgetElementAt(2) == 3);		

	LSTlist->LSTremoveElementAt(1);
	assert(*LSTlist->LSTgetElementAt(1) == 3);

	LSTlist->LSTempty();
	assert(LSTlist->LSTgetSize() == 0);

	delete LSTlist;

	assert(LSTlistCpy->LSTgetSize() == 3);
	assert(*LSTlistCpy->LSTgetElementAt(0) == 0);		
	assert(*LSTlistCpy->LSTgetElementAt(1) == 1);
	assert(*LSTlistCpy->LSTgetElementAt(2) == 2);		

	delete LSTlistCpy;

	cout << "CList tests successfully passed" << endl;
}