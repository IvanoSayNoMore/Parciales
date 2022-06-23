/*
 * Localidad.h
 *
 *  Created on: 27 may 2022
 *      Author: Usuario Programador
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "utnInPuts.h"

typedef struct{
	int id;
	char localidades[51];
	int isEmpty;
}localidad;

int localidad_initArrayPointer(localidad* arrayPointerLocalidad[],int lenPointer);
int localidad_searchPointerArray(localidad* arrayPunteros[],int option, int lenPunteros);
localidad* localidad_newParametros(char localidades[],int idLocalidad,int lenCadena);
int addLocalidad(localidad* arrayLocalidadPoint[],char localidad[],int idLocalidad,int lenPointer);
localidad* localidad_new(void);

#endif /* LOCALIDAD_H_ */
