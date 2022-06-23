/*
 * GetterSetters.c
 *
 *  Created on: 2 jun 2022
 *      Author: Usuario Programador
 */
#include "ArrayCencista.h"
#include "GetterSetters.h"

#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1

int person_setterIdCensista(Person* pPerson, int idC)
{
	int retorno=RETORNONEGATIVO;
	if(pPerson != NULL && idC>0)
	{
		pPerson->idCensista=idC;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int person_setterDiaNacimientoCensista(Person* pPerson, int dia)
{
	int retorno=RETORNONEGATIVO;
	if(pPerson != NULL && dia>0 && dia<31)
	{
		pPerson->fechaNacimiento.dia=dia;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


