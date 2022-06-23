/*
 * ArrayZona.c
 *
 *  Created on: 27 may 2022
 *      Author: Usuario Programador
 */

#include "ArrayZona.h"
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

datosCenso* datosCenso_new(void)
{
	return (datosCenso*) malloc(sizeof(datosCenso)*2);
}

int datosCenso_initArrayPointer(datosCenso* arrayPointerdatosCenso[],int lenPointer)
{
	int retorno=RETORNONEGATIVO;
	if(arrayPointerdatosCenso != NULL && lenPointer > 0)
	{
		int i;
		retorno=RETORNOPOSITIVO;
		for(i=0;i<lenPointer;i++)
		{
			arrayPointerdatosCenso[i] = NULL;
		}
	}

	return retorno;
}

datosCenso* DatosCenso_newParametrosZona(int localidad, char zona[],int lenCadena)
{
	datosCenso* punteroDatoCenso = NULL;
	int auxId;
	punteroDatoCenso = datosCenso_new();
	if(punteroDatoCenso != NULL)
	{
		contadorIdZone(&auxId);
		strncpy(punteroDatoCenso->zonaCenso,zona,lenCadena);
		punteroDatoCenso->localidadZona=localidad;
		punteroDatoCenso->idZona=auxId;
		punteroDatoCenso->idCensista=EMPTY;
	}
	else
	{
		puts("PunteroZona == null");
	}
	return punteroDatoCenso;
}



int datosCenso_ingressZone(int* localidad, char zona[],int lenLocalidad,int lenCadena)
{
	int retorno=RETORNONEGATIVO;
	char auxChar[lenCadena];
	int auxLocalidad;

	if(utnGetNumero(&auxLocalidad, "Seleccione el numero que de localidad que corresponda o 0 para cancelar\n",
			"Error al seleccionar Localidad", "Opcion incorrecta. Desea reintentar?\n",0, lenLocalidad, REINTENTOS)==RETORNOPOSITIVO)
	{
		if(auxLocalidad==0)
		{
			puts("Se cancela la carga de ZONA");

		}
		else
		{
			if(utnIngressStringChar(auxChar, "\nIngrese la nueva zona : \n", lenCadena)==RETORNOPOSITIVO)
			{
				strncpy(zona,auxChar,lenCadena);
				*localidad=auxLocalidad;
				retorno=RETORNOPOSITIVO;
			}

		}

	}

	return retorno;
}

int datosCenso_searchPointerArray(datosCenso* arrayPunteros[],int option, int lenPunteros)
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

int datosCenso_assignZone(datosCenso* zona[],int posicionPointer,int idCensista)
{
	int retorno=RETORNONEGATIVO;
	if(zona != NULL )
	{
		zona[posicionPointer]->idCensista=idCensista;
		zona[posicionPointer]->estadoCenso=PENDIENTE;
	}

	return retorno;
}

int datosCenso_addDataCenso(datosCenso* datoCenso,int idCensista,int censadosInSitu,int censadosVirtual, int ausentes)
{
	int retorno=RETORNONEGATIVO;
	if(datoCenso != NULL)
	{
		datoCenso->idCensista=idCensista;
		datoCenso->ausentes=ausentes;
		datoCenso->censadosInSitu=censadosInSitu;
		datoCenso->censadosVirtual=censadosVirtual;
		datoCenso->estadoCenso=FINALIZADO;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int datosCenso_ingressDateCenso(int* ausentes, int* inSitu, int* virtual)
{
	int auxInt;
	int continuar=RETORNONEGATIVO;
	int flagOk=RETORNOPOSITIVO;
	int retorno=RETORNONEGATIVO;

	do{
		//ausentes
		if(utnGetNumero(&auxInt, "Ingrese la cantidad de ausentes en el censo\n",
				"Error al seleccionar Localidad", "Desea reintentar?",MINOPCIONLOCALIDAD, 10000, REINTENTOS)==RETORNOPOSITIVO)
		{
			*ausentes=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}
		//InSitu
		if(utnGetNumero(&auxInt, "Ingrese la cantidad censados InSitu en el censo\n",
				"Error al seleccionar Localidad", "Desea reintentar?",MINOPCIONLOCALIDAD, 10000, REINTENTOS)==RETORNOPOSITIVO)
		{
			*inSitu=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}
		//Virtual
		if(utnGetNumero(&auxInt, "Ingrese la cantidad cennsados virtual \n",
				"Error al seleccionar Localidad", "Desea reintentar?",MINOPCIONLOCALIDAD, 10000, REINTENTOS)==RETORNOPOSITIVO)
		{
			*virtual=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}

	}while(continuar==1);

	retorno=flagOk;


	return retorno;
}

int datosCenso_findOnePointerByIdPerson(datosCenso* arrayPointer[],int idPerson,int* spaceFound, int lenPointer)
{
	int retorno=RETORNONEGATIVO;
	int i;
	if(arrayPointer != NULL && lenPointer > 0)
	{
		for(i=0;i<lenPointer;i++)
		{
			if(arrayPointer[i] != NULL && arrayPointer[i]->idCensista == idPerson  )
			{
				*spaceFound=i;
				retorno=RETORNOPOSITIVO;
				break;
			}
		}
	}
	return retorno;
}

int datosCenso_findOnePointerZonaById(datosCenso* list[], int id,int* posicion,int lenZona)
{
	int retorno=RETORNONEGATIVO;
	int i;
	for(i=0;i<lenZona;i++)
	{
		if(list[i] != NULL && list[i]->idZona == id )
		{
			retorno=RETORNOPOSITIVO;
			*posicion=i;
			break;
		}
	}

	return retorno;
}
