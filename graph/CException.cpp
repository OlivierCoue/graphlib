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
Conversion du code erreur en message
**********************************
Entrée : rien
Necessite : néant
Sortie : chaine de caractère représentant le message
Entraîne :rien
**********************************/

char * CException::EXCGetMessage() {
	char * pcMessage;
	switch (uiEXCValue)
	{
	case 1: pcMessage = _strdup("The node do not exist"); break;
	case 2: pcMessage = _strdup("Key not found"); break;
	case 3: pcMessage = _strdup("Index out of bound"); break;
	default:pcMessage = _strdup("Unknown exception"); break;
		break;
	};
	return pcMessage;
}