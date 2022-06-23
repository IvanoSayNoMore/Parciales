/*
 * Alumno.c
 *
 *  Created on: 25 may 2022
 *      Author: Usuario Programador
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#define RETORNONEGATIVO -1
#define RETORNOPOSITIVO 0

Alumno* alumno_new(void)
{
	return (Alumno*) malloc(sizeof(Alumno));
}

Alumno* alumno_newParametros(char* nombre, float altura, int id)
{
	Alumno* punteroAlumno = NULL;
	punteroAlumno = alumno_new();
	if(punteroAlumno != NULL)
	{
		strncpy(punteroAlumno->nombre,nombre,50);
		punteroAlumno->altura=altura;
		punteroAlumno->id=id;
	}
	return punteroAlumno;
}

int alumno_initArray(Alumno* arrayPunteros[], int lenPunteros)
{
	int retorno=RETORNONEGATIVO;
	int i;
	if(arrayPunteros != NULL && lenPunteros > 0)
	{
		retorno=RETORNOPOSITIVO;
		for(i=0;i<lenPunteros;i++)
		{
			arrayPunteros[i] = NULL;
		}
	}
	return retorno;
}

int alumno_searchFreeArray(Alumno* arrayPunteros[], int lenPunteros)
{
	int retorno=RETORNONEGATIVO;
	int i;
	if(arrayPunteros != NULL && lenPunteros > 0)
	{
		retorno=-2;
		for(i=0;i<lenPunteros;i++)
		{
			if(arrayPunteros[i]==NULL)
			{

				retorno=i;
				printf("posicion %d\n",i);
				break;
			}
		}
	}
	return retorno;
}

int alumno_printArray(Alumno* arrayPunteros[], int lenPunteros)
{
	int retorno=RETORNONEGATIVO;
	int i;
	printf("\n----lista-----\n");
	if(arrayPunteros != NULL && lenPunteros > 0)
	{
		printf("\n----lista-----\n");
		for(i=0;i<lenPunteros;i++)
		{
			if(arrayPunteros[i]!=NULL)
			{
				printf("Nombre %s\nId: %d\nAltura%.2f\n",arrayPunteros[i]->nombre,arrayPunteros[i]->id,arrayPunteros[i]->altura);
			}
		}
	}
	return retorno;
}
