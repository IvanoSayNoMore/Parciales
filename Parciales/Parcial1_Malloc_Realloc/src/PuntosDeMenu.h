/*
 * PuntosDeMenu.h
 *
 *  Created on: 26 may 2022
 *      Author: Usuario Programador
 */

#ifndef PUNTOSDEMENU_H_
#define PUNTOSDEMENU_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayZona.h"
#include "Localidad.h"
#include "printPrint.h"
#include "utnInPuts.h"
#include "ArrayCencista.h"

void menuAltaLocalidad(localidad* arrayLocalidadPoint[],int lenPointer);

int puntoDeMenuAltaPerson(Person* arrayPersonPoint[],int lenPointer);
int puntoDeMenuModificarPerson(Person* arrayPersonPoint[],int lenPointer);
int puntoDeMenuEliminarPerson(Person* arrayPersonPoint[],int lenPointer);
int puntoDeMenuAltaZona(datosCenso* arrayDatosPointer[],localidad* arrayLocalidadPointer[],int lenZona,int lenLocalidad);
int puntoDeMenuAsignarZona(datosCenso* listZona[],Person* listPerson[], int lenZona,int lenPerson);
int puntoDeMenuCargarDatosZona(datosCenso* arrayDatosPointer[],Person* listPersonPointer[],int lenPerson,int lenZona);
int pointMenuPrint(Person* arrayPersonPoint[],int lenPointer);
int puntoDeMenuImprimirCensistas(Person* listPerson[],int lenPerson);
int puntoDeMenuHardcode(datosCenso* listZona[],Person* listPerson[], int lenZona,int lenPerson);

int pointMenuPrint(Person* arrayPersonPoint[],int lenPointer);



#endif /* PUNTOSDEMENU_H_ */
