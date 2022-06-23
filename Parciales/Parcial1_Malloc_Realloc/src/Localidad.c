/*
 * Localidad.c
 *
 *  Created on: 27 may 2022
 *      Author: Usuario Programador
 */
#include "Localidad.h"

#define EMPTY 0
#define FULL -1
#define PENDIENTE -1
#define FINALIZADO 0
#define REINTENTOS 3
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MAXOPCIONLOCALIDAD 5
#define MINOPCIONLOCALIDAD 1
#define OPCIONFREE 1
#define OPCIONBUSY 0

localidad* localidad_new(void)
{
	return (localidad*) malloc(sizeof(localidad));
}

int localidad_initArrayPointer(localidad* arrayPointerLocalidad[],int lenPointer)
{
	int retorno=RETORNONEGATIVO;
	if(arrayPointerLocalidad != NULL && lenPointer > 0)
	{
		int i;
		retorno=RETORNOPOSITIVO;
		for(i=0;i<lenPointer;i++)
		{
			arrayPointerLocalidad[i] = NULL;
		}
	}
	return retorno;
}

int addLocalidad(localidad* arrayLocalidadPoint[],char localidad[],int idLocalidad,int lenPointer)
{
	int retorno=RETORNONEGATIVO;
	int auxPointerFree;

	auxPointerFree=localidad_searchPointerArray(arrayLocalidadPoint, OPCIONFREE, lenPointer);
 	if(auxPointerFree!=RETORNONEGATIVO)
 	{
 		arrayLocalidadPoint[auxPointerFree]=localidad_newParametros(localidad, idLocalidad, 51);
 		if(arrayLocalidadPoint[auxPointerFree]==NULL)
 		{
				puts("Algo fallo en la asignacion de la persona en arrayLocalidadPoint");
				retorno = RETORNONEGATIVO;
 		}
 	}
 	else
 	{
	/*for(int i=0;i<MaxLocalidad;i++)
	{
		if(listalocalidad[i].isEmpty==EMPTY)
		{
			listalocalidad[i].isEmpty=FULL;
			listalocalidad[i].id=idLocalidad;
			strncpy(listalocalidad[i].localidades,localidad,lenLocalidad);
			retorno=RETORNOPOSITIVO;
			break;
		}
	}*/
 	}
	return retorno;

}

localidad* localidad_newParametros(char localidades[],int idLocalidad,int lenCadena)
{
	localidad* punteroLocalidad = NULL;

	punteroLocalidad = localidad_new();
	if(punteroLocalidad != NULL)
	{
		punteroLocalidad->id=idLocalidad;
		strncpy(punteroLocalidad->localidades,localidades,lenCadena);
	}
	else
	{
		puts("PunteroPerson == null");
	}
	return punteroLocalidad;
}

int localidad_searchPointerArray(localidad* arrayPunteros[],int option, int lenPunteros)
{
	int retorno=RETORNONEGATIVO;
	int i;
	if(arrayPunteros != NULL && lenPunteros > 0)
	{
		retorno=-2;
		for(i=0;i<lenPunteros;i++)
		{
			if(option == OPCIONFREE && arrayPunteros[i] == NULL)
			{
				retorno=i;
				break;
			}
			if(option == OPCIONBUSY && arrayPunteros[i] != NULL)
			{
				retorno=i;
				break;
			}

		}
	}
	return retorno;
}

