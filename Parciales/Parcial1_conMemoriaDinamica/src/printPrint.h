/*
 * printPrint.h
 *
 *  Created on: 26 may 2022
 *      Author: Usuario Programador
 */

#ifndef PRINTPRINT_H_
#define PRINTPRINT_H_

#include "ArrayCencista.h"
#include "Localidad.h"
#include "ArrayZona.h"

//////////////Person
int person_printArray(Person* arrayPointer[], int lenPointer);
void person_printOnePerson(Person* onePerson);
int person_printListByStatus(Person* listPerson[],char mensaje[],int order,int lenPerson);


//////////////DatosCenso
int datosCenso_printArray(datosCenso* arrayPointer[], int lenPointer);
void datosCenso_printZonaCenso(datosCenso* onedZonaCenso);
void datosCenso_printDatosCenso(datosCenso* oneDatosCenso);
void datosCenso_printDatosZona(datosCenso* oneDatosZona);
int datosCenso_printZonaById(datosCenso* datoZona[], int lenZona);
int datosCenso_printAllZona(datosCenso* arrayPointerDatosCenso[],Person* arrayPointerPerson[],localidad* arrayPointerLocalidad[], int opcion,int lenPointerDatos,int lenPointerPerson,int lenPointerLocalidad );

int datosCenso_printZonaLocalidad(datosCenso* datoZona, localidad* listlocalidad[],int lenLocalidad);
//////////////Localidad
int localidad_printArray(localidad* arrayPointer[], int lenPointer);
void localidad_printOneLocalidad(localidad* oneLocalidad);
int localidad_findLocalidadById(localidad* listlocalidad[],int id,int* posicion, int lenLocalidad);
int localidad_printPersonByLocalidad(Person* listPerson[],datosCenso* listdatosCenso[],localidad* localidades[],int lenPerson,int lenLocalidad,int lenDatoCenso);




#endif /* PRINTPRINT_H_ */
