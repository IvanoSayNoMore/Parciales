/*
 * printPrint.c
 *
 *  Created on: 26 may 2022
 *      Author: Usuario Programador
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "printPrint.h"

#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define PENDIENTE -1
#define FINALIZADO 0
#define OPCIONFREE 1
#define OPCIONBUSY 0
#define EMPTY 0
#define FULL -1

/////////////Person
int person_printArray(Person* arrayPointer[], int lenPointer)
{
	int retorno=RETORNONEGATIVO;
	int i;
	if(arrayPointer != NULL && lenPointer > 0)
	{
		printf("\n----lista-----\n");
		for(i=0;i<lenPointer;i++)
		{
			if(arrayPointer[i]!=NULL)
			{
				retorno=RETORNOPOSITIVO;
				person_printOnePerson(arrayPointer[i]);
			}
		}
	}
	return retorno;
}

void person_printOnePerson(Person* onePerson)
{
	//printf("Nombre %s\nId: %d\nApellido: %s\n",onePerson->dataPerson.name,onePerson->idCensista,onePerson->dataPerson.lastName);
	printf("\n|  %3d\t  |   %s\t   |  %s\t ",onePerson->idCensista,onePerson->dataPerson.lastName,onePerson->dataPerson.name);

}

int person_printListByStatus(Person* listPerson[],char mensaje[],int order,int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	if(listPerson!=NULL)
	{
		printf("Los censistas %s son:\n",mensaje);

		for(int i=0;i<lenPerson;i++)
		{
			if(listPerson[i] != NULL)
			{
				if(listPerson[i]->estadoActual == order)//ACTIVO
				{
					person_printOnePerson(listPerson[i]);
					retorno=RETORNOPOSITIVO;
				}
			}
		}
	}

	return retorno;
}


//////////////DatosCenso
int datosCenso_printAllZona(datosCenso* arrayPointerDatosCenso[],Person* arrayPointerPerson[],localidad* arrayPointerLocalidad[], int opcion,int lenPointerDatos,int lenPointerPerson,int lenPointerLocalidad )
{
	int retorno=RETORNONEGATIVO;
	int i;
	int flagIdCensista=RETORNOPOSITIVO;
	if(arrayPointerDatosCenso != NULL && arrayPointerPerson != NULL && lenPointerDatos > 0&& lenPointerPerson > 0)
	{
		if(datosCenso_searchPointerArray(arrayPointerDatosCenso, opcion, lenPointerDatos) != RETORNONEGATIVO)
		{
			puts("----------------------------------------------------------------------------------------------------------------------\n");
			puts("------------ Datos Censista -------------------- listado de zonas ----------------------------------------------------\n");
			puts("-----------------------------------------|---------- CENSADOS -------------|------------------------------------------\n");
			puts("|Id Cesista |   Apellido   |   Nombre    |   Insitu | Virtual | Ausentes   |    Zona de Censo    |  Localidad         \n");
			puts("----------------------------------------------------------------------------------------------------------------------\n");

			for(i=0;i<lenPointerDatos;i++)
			{	flagIdCensista=RETORNOPOSITIVO;
				if(arrayPointerDatosCenso[i] != NULL )
				{
					// flagIdCensista=RETORNONEGATIVO;
					if(arrayPointerDatosCenso[i]->idCensista==0)
					{
						printf("La zona aun no fue asignada a ningun censista\t\t\t\t   ");

						flagIdCensista=RETORNONEGATIVO;
					}
					//printf("%d\n",flagIdCensista);
					if(flagIdCensista==RETORNOPOSITIVO)
					{
						for(int j=0;j<lenPointerPerson;j++)
						{

							//printf("id Cen %d \n id datoscen %d\n",arrayPointerPerson[j]->idCensista,arrayPointerDatosCenso[i]->idCensista);
							if(arrayPointerPerson[j] != NULL &&
									arrayPointerDatosCenso[i]->idCensista==arrayPointerPerson[j]->idCensista )
							{
								if(arrayPointerDatosCenso[i]->estadoCenso==FINALIZADO)
								{
									person_printOnePerson(arrayPointerPerson[j]);
									datosCenso_printDatosCenso(arrayPointerDatosCenso[i]);
									break;//rompe for j
								}
								else
								{
									person_printOnePerson(arrayPointerPerson[j]);
									printf("|  No se han cargado datos\t   ");
									break;
								}

							}
						}

					}//fin validacion FlagidCensista
					datosCenso_printZonaLocalidad(arrayPointerDatosCenso[i], arrayPointerLocalidad,lenPointerLocalidad);
					retorno=RETORNOPOSITIVO;
				}
			}
		}
		else
		{
			puts("Aun no hay zonas cargadas");
		}

	}
	return retorno;
}

int datosCenso_printZonaLocalidad(datosCenso* datoZona, localidad* listlocalidad[],int lenLocalidad)
{
	int retorno=RETORNONEGATIVO;
	for(int i=0;i<lenLocalidad;i++)
	{
		if(datoZona->localidadZona==listlocalidad[i]->id)
		{
			printf("|%s\t         | %s   \n", datoZona->zonaCenso,listlocalidad[i]->localidades);
			retorno=RETORNOPOSITIVO;
			break;
		}
	}
	return retorno;
}

void datosCenso_printZonaCenso(datosCenso* onedZonaCenso)
{
	printf("%s  ",onedZonaCenso->zonaCenso);
}

void datosCenso_printDatosCenso(datosCenso* oneDatosCenso)
{
	printf("| %d\t    | %d     | %d\t   ",oneDatosCenso->ausentes,oneDatosCenso->censadosInSitu,oneDatosCenso->censadosVirtual);
}
int datosCenso_printZonaById(datosCenso* datoZona[], int lenZona)
{
	int retorno=RETORNONEGATIVO;
	puts("_____________________________________________");
	puts("|  ID Zona  |   Zona     |   Id Localidad   |");
	if(datoZona!=NULL)
	{
		for(int i=0;i<lenZona;i++)
		{
			if(datoZona[i]!=NULL && datoZona[i]->estadoCenso!=PENDIENTE)
			{
				datosCenso_printDatosZona(datoZona[i]);
			}
		}
	}
	return retorno;
}

void datosCenso_printDatosZona(datosCenso* oneDatosZona)
{
	printf("| %3d       |\t%s\t |  %3d         |\n",oneDatosZona->idZona,oneDatosZona->zonaCenso,oneDatosZona->localidadZona);

}
//////////////Localidad
int localidad_printArray(localidad* arrayPointer[], int lenPointer)
{
	int retorno=RETORNONEGATIVO;
	int i;
	if(arrayPointer != NULL && lenPointer > 0)
	{
		printf("\n----lista-----\n");
		for(i=0;i<lenPointer;i++)
		{
			if(arrayPointer[i]!=NULL)
			{
				localidad_printOneLocalidad(arrayPointer[i]);
			}
		}
	}
	return retorno;
}

void localidad_printOneLocalidad(localidad* oneLocalidad)
{
	printf("NId: %d\nLocalidad: %s\n",oneLocalidad->id,oneLocalidad->localidades);

}

int localidad_printPersonByLocalidad(Person* listPerson[],datosCenso* listdatosCenso[],localidad* localidades[],int lenPerson,int lenLocalidad,int lenDatoCenso)
{
	int retorno=RETORNONEGATIVO;
	int auxLocalidad;
	int auxPosLocalidad;
	if(localidades != NULL && listPerson != NULL && listdatosCenso != NULL)
		{
			localidad_printArray(localidades, lenLocalidad);
			if(utnGetNumero(&auxLocalidad, "Seleccione el numero que de localidad que corresponda o 0 para cancelar\n",
						"Error al seleccionar Localidad", "Opcion incorrecta. Desea reintentar?\n",0, lenLocalidad, 3)==RETORNOPOSITIVO)
			{

				if(localidad_findLocalidadById(localidades, auxLocalidad, &auxPosLocalidad, lenLocalidad)==RETORNOPOSITIVO)
				{

					puts("----------------------------------------------------------------------------------------------------------------------\n");
					puts("------------ Datos Censista ------------------------------------------------------------------------------------------\n");
					puts("-----------------------------------------|---------------------------------|------------------------------------------\n");
					puts("|Id Cesista |   Apellido   |   Nombre    |                 |    Zona de Censo    |  Localidad                         \n");
					puts("----------------------------------------------------------------------------------------------------------------------\n");
					for(int i=0;i<lenPerson;i++)
					{
						if(listPerson[i]!=NULL)
						{
							for(int j=0;j<lenDatoCenso;j++)
							{
								if(listdatosCenso[j]!=NULL)
								{
									if(listPerson[i]->idCensista==listdatosCenso[j]->idCensista && listdatosCenso[j]->localidadZona==auxLocalidad)
									{
										person_printOnePerson(listPerson[i]);
										printf("%s\t  ",listdatosCenso[j]->zonaCenso);
										localidad_printOneLocalidad(localidades[auxPosLocalidad]);
										//printOneLocalidad(punteroLocalidad);
										retorno=RETORNOPOSITIVO;
									}
								}
							}
						}
					}


				}
			}


		}
	return retorno;
}

int localidad_findLocalidadById(localidad* listlocalidad[],int id,int* posicion, int lenLocalidad)
{
	int retorno=RETORNONEGATIVO;
	int i;
	for(i=0;i<lenLocalidad;i++)
	{
		if(listlocalidad[i]!=NULL && listlocalidad[i]->id==id )
		{
			retorno=RETORNOPOSITIVO;
			*posicion=i;
			break;
		}
	}

	return retorno;
}


