/*
 * ArrayZona.h
 *
 *  Created on: 27 may 2022
 *      Author: Usuario Programador
 */

#ifndef ARRAYZONA_H_
#define ARRAYZONA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include "utnInPuts.h"

typedef struct {
	int idCensista;
	int idZona;
	int localidadZona;
	char zonaCenso[15];
	int estadoCenso;
	int totalCensados;
	int censadosInSitu;
	int censadosVirtual;
	int ausentes;
}datosCenso;


int datosCenso_initArrayPointer(datosCenso* array[],int lenPointer);

int datosCenso_ingressZone(int* localidad, char zona[],int lenLocalidad,int lenCadena);

datosCenso* DatosCenso_newParametrosZona(int localidad, char zona[],int lenCadena);

int datosCenso_assignZone(datosCenso* zona[],int posicionPointer,int idCensista);

int datosCenso_searchPointerArray(datosCenso* arrayPunteros[],int option, int lenPunteros);

int datosCenso_ingressDateCenso(int* ausentes, int* inSitu, int* virtual);

int datosCenso_addDataCenso(datosCenso* datoCenso,int idCensista,int censadosInSitu,int censadosVirtual, int ausentes);

int datosCenso_findOnePointerZonaById(datosCenso* list[], int id,int* posicion,int lenZona);

int datosCenso_findOnePointerByIdPerson(datosCenso* arrayPointer[],int idPerson,int* spaceFound, int lenPointer);

#endif /* ARRAYZONA_H_ */
