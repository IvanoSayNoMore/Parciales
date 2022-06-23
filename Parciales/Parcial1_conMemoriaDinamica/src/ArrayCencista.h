/*
 * ArrayCencista.h
 *
 *  Created on: 26 may 2022
 *      Author: Usuario Programador
 */

#ifndef ARRAYCENCISTA_H_
#define ARRAYCENCISTA_H_
#include "ArrayZona.h"
#include "utnInPuts.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[51];
	char lastName[51];
	int edad;
}dataPerson;

typedef struct{
	int dia;
	int mes;
	int anio;
}fecha;

typedef struct{
	char direccion[51];
}DataHome;

typedef struct{
	int idCensista;
	dataPerson dataPerson;
	fecha fechaNacimiento;
	DataHome direccion;
	int estadoActual;//Activo Inactivo Liberado
	int isEmpty;
}Person;
////
Person* person_newMalloc();

Person* person_newRealocc(Person* pPerson,int size);

Person* person_newParametros(char name[],char lastName[],char direccion[],int anio,int mes,int dia, int edad,int lenCadena);

int person_initArrayPointer(Person* arrayPointerPerson[],int lenPointer);

int person_findOnePersonById(Person* arrayPointer[],int idPerson,int* spaceFound, int lenPointer);

int person_deletPersonById(Person* arrayPointer[],int idPerson, int lenPointer);

int person_searchPointerArray(Person* arrayPunteros[],int option, int lenPunteros);

int person_deletIndexArray(Person* arrayPointer[], int index);

int person_assignZone(datosCenso* zona,int idCensista);

int person_validAssigZona(Person* listPerson,datosCenso* zona,int idCensista,int lenPerson);

void person_soap(Person* list[],int posicionA, int posicionB);

int person_sortPersonByLastName(Person* listPerson[], int lenPerson);

////

int changePerson(Person* person,int lenCadena);

int changeDate(int* dia, int* mes, int* anio, char* direccion,int lenCadena);

int ingresPerson(char name[],char lastName[],char direccion[],int* anio,int* mes,int* dia, int* edad,int lenCadena);
#endif /* ARRAYCENCISTA_H_ */
