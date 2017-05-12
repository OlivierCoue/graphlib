#include "stdafx.h"
#include "CException.h"

/**********************************
Constructeur par d�faut
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : rien
Entra�ne : initialisation de l'objet
**********************************/
CException::CException() {
}

/**********************************
Constructeur de recopie
**********************************
Entr�e : un objet de type CException
Necessite : n�ant
Sortie : rien
Entra�ne : initialisation de l'objet
**********************************/
CException::CException(CException & EXCobj) {
	uiEXCValue = EXCobj.uiEXCValue;
}

/**********************************
Constructeur � un argument
**********************************
Entr�e : la valeur de l'erreur
Necessite : n�ant
Sortie : rien
Entra�ne : initialisation de l'objet
**********************************/
CException::CException(unsigned int uiValue) {
	uiEXCValue = uiValue;
	cout << endl << "Exception code: " << uiValue << endl;
}

/**********************************
Destructeur
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : rien
Entra�ne : finalisation de l'objet
**********************************/
CException::~CException() {
}

/**********************************
Accesseur �criture uiEXCValue
**********************************
Entr�e : un entier non sign�
Necessite : n�ant
Sortie : rien
Entra�ne : modification de uiEXCValue
**********************************/
void CException::EXCSetValue(unsigned int uiValue) {
	uiEXCValue = uiValue;
}

/**********************************
Accesseur lecture uiEXCValue
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : uiEXCValue
Entra�ne :rien
**********************************/
unsigned int CException::EXCGetValue() {
	return uiEXCValue;
}

/**********************************
Accesseur lecture pcEXCMessage
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : pcEXCMessage
Entra�ne :rien
**********************************/

unsigned int CException::EXCGetMessage() {
	return switch (uiEX)
	{
	default:
		break;
	};
}