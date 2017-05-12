#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include "stdafx.h"
#include <string.h>
#include <iostream>

#define NODE_DONT_EXIST 1
#define KEY_NOT_FOUND 2
#define CANNOT_OPEN_FILE 3
#define OUT_OF_BOUND 4

using namespace std;

class CException {
private:
	unsigned int uiEXCValue;
public:
	/**********************************
	Constructeur par défaut
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : rien
	Entraîne : initialisation de l'objet
	**********************************/
	CException();

	/**********************************
	Constructeur de recopie
	**********************************
	Entrée : un objet de type CException
	Necessite : néant
	Sortie : rien
	Entraîne : initialisation de l'objet
	**********************************/
	CException(CException & EXCobj);

	/**********************************
	Constructeur à un argument
	**********************************
	Entrée : la valeur de l'erreur
	Necessite : néant
	Sortie : rien
	Entraîne : initialisation de l'objet
	**********************************/
	CException(unsigned int uiValue);

	/**********************************
	Destructeur
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : rien
	Entraîne : finalisation de l'objet
	**********************************/
	~CException();

	/**********************************
	Accesseur écriture uiEXCValue
	**********************************
	Entrée : un entier non signé
	Necessite : néant
	Sortie : rien
	Entraîne : modification de uiEXCValue
	**********************************/
	void EXCSetValue(unsigned int uiValue);

	/**********************************
	Accesseur lecture uiEXCValue
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : uiEXCValue
	Entraîne :rien
	**********************************/
	unsigned int EXCGetValue();

	char * EXCGetMessage();
};

#endif 