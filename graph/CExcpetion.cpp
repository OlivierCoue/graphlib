#include "stdafx.h"
#include "CException.h"

/**********************************
Constructeur par défaut
**********************************
Entrée : rien
Necessite : néant
Sortie : rien
Entraîne : initialisation de l'objet
**********************************/
CException::CException() {
}

/**********************************
Constructeur de recopie
**********************************
Entrée : un objet de type CException
Necessite : néant
Sortie : rien
Entraîne : initialisation de l'objet
**********************************/
CException::CException(CException & EXCobj) {
	uiEXCValue = EXCobj.uiEXCValue;
}

/**********************************
Constructeur à un argument
**********************************
Entrée : la valeur de l'erreur
Necessite : néant
Sortie : rien
Entraîne : initialisation de l'objet
**********************************/
CException::CException(unsigned int uiValue) {
	uiEXCValue = uiValue;
	cout << endl << "Exception code: " << uiValue << endl;
}

/**********************************
Destructeur
**********************************
Entrée : rien
Necessite : néant
Sortie : rien
Entraîne : finalisation de l'objet
**********************************/
CException::~CException() {
}

/**********************************
Accesseur écriture uiEXCValue
**********************************
Entrée : un entier non signé
Necessite : néant
Sortie : rien
Entraîne : modification de uiEXCValue
**********************************/
void CException::EXCSetValue(unsigned int uiValue) {
	uiEXCValue = uiValue;
}

/**********************************
Accesseur lecture uiEXCValue
**********************************
Entrée : rien
Necessite : néant
Sortie : uiEXCValue
Entraîne :rien
**********************************/
unsigned int CException::EXCGetValue() {
	return uiEXCValue;
}

/**********************************
Accesseur lecture pcEXCMessage
**********************************
Entrée : rien
Necessite : néant
Sortie : pcEXCMessage
Entraîne :rien
**********************************/

unsigned int CException::EXCGetMessage() {
	return switch (uiEX)
	{
	default:
		break;
	};
}