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
	Constructeur par d�faut
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : rien
	Entra�ne : initialisation de l'objet
	**********************************/
	CException();

	/**********************************
	Constructeur de recopie
	**********************************
	Entr�e : un objet de type CException
	Necessite : n�ant
	Sortie : rien
	Entra�ne : initialisation de l'objet
	**********************************/
	CException(CException & EXCobj);

	/**********************************
	Constructeur � un argument
	**********************************
	Entr�e : la valeur de l'erreur
	Necessite : n�ant
	Sortie : rien
	Entra�ne : initialisation de l'objet
	**********************************/
	CException(unsigned int uiValue);

	/**********************************
	Destructeur
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : rien
	Entra�ne : finalisation de l'objet
	**********************************/
	~CException();

	/**********************************
	Accesseur �criture uiEXCValue
	**********************************
	Entr�e : un entier non sign�
	Necessite : n�ant
	Sortie : rien
	Entra�ne : modification de uiEXCValue
	**********************************/
	void EXCSetValue(unsigned int uiValue);

	/**********************************
	Accesseur lecture uiEXCValue
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : uiEXCValue
	Entra�ne :rien
	**********************************/
	unsigned int EXCGetValue();

	char * EXCGetMessage();
};

#endif 