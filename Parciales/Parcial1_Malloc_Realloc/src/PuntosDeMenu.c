/*
 * PuntosDeMenu.c
 *
 *  Created on: 26 may 2022
 *      Author: Usuario Programador
 */

#include "PuntosDeMenu.h"
#define EMPTY 0
#define FULL -1
#define MINIMOIDS 0
#define MAXIMOSIDS 1000
#define MAXIMOCADENA 51
//////////////
#define ACTIVO 1
#define INACTIVO -1
#define LIBERADO 0
#define PENDIENTE -1
#define FINALIZADO 0
/////////////
#define REINTENTOS 3
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define OPCIONFREE 1
#define OPCIONBUSY 0

void menuAltaLocalidad(localidad* arrayLocalidadPoint[],int lenPointer)
{
	addLocalidad(arrayLocalidadPoint, "Avellaneda", 1 ,lenPointer);
	addLocalidad(arrayLocalidadPoint, "Lanus", 2 ,lenPointer);
	addLocalidad(arrayLocalidadPoint, "Gerli", 3 ,lenPointer);
	addLocalidad(arrayLocalidadPoint, "Wilde", 4 ,lenPointer);
	addLocalidad(arrayLocalidadPoint, "Sarandi", 5 ,lenPointer);
}

int puntoDeMenuAltaPerson(Person* arrayPersonPoint[],int lenPointer)
{
	int auxPointerFree;
	char auxName[MAXIMOCADENA];
	char auxLastName[MAXIMOCADENA];
	char direccion[MAXIMOCADENA];
	int auxDia;
	int auxAnio;
	int auxMes;
	int auxEdad;
	int retorno = RETORNONEGATIVO;
	//Person* pPerson;

	if(arrayPersonPoint != NULL && lenPointer > 0)
	{
		auxPointerFree=person_searchPointerArray(arrayPersonPoint,OPCIONFREE,lenPointer);
	 	if(auxPointerFree!=RETORNONEGATIVO)
	 	{
	 		if(ingresPerson(auxName, auxLastName, direccion,
					&auxAnio, &auxMes, &auxDia, &auxEdad, MAXIMOCADENA)==RETORNOPOSITIVO)
	 		{
	 			retorno = RETORNOPOSITIVO;
	 			arrayPersonPoint[auxPointerFree] = person_newParametros(auxName, auxLastName, direccion,
	 					auxAnio, auxMes, auxDia, auxEdad, MAXIMOCADENA);

	 			if(arrayPersonPoint[auxPointerFree]==NULL)
	 			{
	 				puts("Algo fallo en la asignacion de la persona en arrayPersonPoint");
	 				retorno = RETORNONEGATIVO;
	 			}
	 		}
	 	}
	 	else
	 	{
	 		puts("No hay free Array Pointer");
	 	}

	}
	return retorno;
}

int puntoDeMenuModificarPerson(Person* arrayPersonPoint[],int lenPointer)
{
	int opcion;
	int auxPosicion;
	int auxPointeBussy;
	int retorno=RETORNONEGATIVO;
	if(arrayPersonPoint != NULL && lenPointer > 0)
	{
		auxPointeBussy=person_searchPointerArray(arrayPersonPoint,OPCIONBUSY,lenPointer);
		if(auxPointeBussy != RETORNONEGATIVO)
		{
			if(utnGetNumero(&opcion, "Ingrese ID a modificar o 0 para cancelar: \n", "Error 1 \n", "Reintentar? \n", MINIMOIDS, MAXIMOSIDS, 2)==RETORNOPOSITIVO)
			{
				if(opcion != 0)
				{
					if(person_findOnePersonById(arrayPersonPoint, opcion, &auxPosicion, lenPointer)==RETORNOPOSITIVO)
					{
						changePerson(arrayPersonPoint[auxPosicion], lenPointer);
						retorno=RETORNOPOSITIVO;
					}
					else
					{
						puts("No se encontro a nadie activo con ese ID ");
					}
				}
				else
				{
					puts("Modificacion Cancelada");
				}

			}
			else
			{
				puts("Error al ingresar ID ");
			}
		}
		else
		{
			puts("No hay Cencistas dados de alta. ");
		}

	}

	return retorno;
}

int puntoDeMenuEliminarPerson(Person* arrayPersonPoint[],int lenPointer)
{

	int retorno=RETORNONEGATIVO;
	int auxPointeBussy;
	int auxId;

	if(arrayPersonPoint != NULL && lenPointer > 0)
	{
		auxPointeBussy=person_searchPointerArray(arrayPersonPoint,OPCIONBUSY,lenPointer);
		if(auxPointeBussy != RETORNONEGATIVO)
		{
			if(utnGetNumero(&auxId, "Ingrese ID a Eliminar: \n", "Error 1 \n", "Reintentar? \n"
					,MINIMOIDS, MAXIMOSIDS, 2)==RETORNOPOSITIVO)
			{
				if(person_deletPersonById(arrayPersonPoint, auxId, lenPointer)==RETORNOPOSITIVO)
				{
					puts("Borrado OK");
				}
				else
				{
					puts("No se encontro el ID indicado ");
				}
			}
			else
			{
				puts("Error al ingresar ID");
			}
		}
		else
		{
			puts("No hay Cencistas dados de alta. ");
		}
	}
	return retorno;
}

int puntoDeMenuAltaZona(datosCenso* arrayDatosPointer[],  localidad* arrayLocalidadPointer[],int lenZona,int lenLocalidad)
{
	int retorno=RETORNONEGATIVO;
	int auxLocalidad;
	char auxZona[MAXIMOCADENA];
	int auxPointerFree;

	if(arrayDatosPointer != NULL && arrayLocalidadPointer != NULL)
	{
		auxPointerFree=datosCenso_searchPointerArray(arrayDatosPointer, OPCIONFREE, lenZona);
		if(auxPointerFree!=RETORNONEGATIVO)
		{
			localidad_printArray(arrayLocalidadPointer, lenLocalidad);
			if(datosCenso_ingressZone(&auxLocalidad, auxZona, lenLocalidad,MAXIMOCADENA)==RETORNOPOSITIVO)
			{
				retorno = RETORNOPOSITIVO;

				arrayDatosPointer[auxPointerFree] = DatosCenso_newParametrosZona(auxLocalidad, auxZona, 51);
	 			if(arrayDatosPointer[auxPointerFree]==NULL)
	 			{
	 				puts("Algo fallo en la alta de la zona en arrayDatosPointer");
	 				retorno = RETORNONEGATIVO;
	 			}
	 			else
	 			{
	 				puts("Alta ok ");
	 			}
			}
			else
			{
				puts("Error en la carga de ZONA");
			}
		}
		else
		{
			puts("No se espacios para cargar Zonas ");
		}

	}


	return retorno;
}

int puntoDeMenuAsignarZona(datosCenso* listZona[],Person* listPerson[], int lenZona,int lenPerson)
{
	int posicionPerson;
	int auxIdZona;

	int auxIdPerson;
	int posicionZona;
	int retorno=RETORNONEGATIVO;

	if(listZona != NULL && listPerson != NULL)
	{
		posicionZona=datosCenso_searchPointerArray(listZona, OPCIONBUSY, lenZona);
		posicionPerson=person_searchPointerArray(listPerson, OPCIONBUSY, lenPerson);

		if(posicionZona != RETORNONEGATIVO && posicionPerson != RETORNONEGATIVO)
		{
			datosCenso_printZonaById(listZona, lenZona);
			if(utnGetNumero(&auxIdZona, "Ingrese el id de la zona para asignar\n",
			"Error al seleccionar opcion\n", "Desea reintentar?\n", 1, 20, REINTENTOS)==RETORNOPOSITIVO)
			{
				if(datosCenso_findOnePointerZonaById(listZona,auxIdZona, &posicionZona, lenZona)==RETORNOPOSITIVO)
				{
					if(listZona[posicionZona] != NULL && listZona[posicionZona]->idCensista==0)
					{
						person_printListByStatus(listPerson, "LIBERADO",LIBERADO, lenPerson);
						if(utnGetNumero(&auxIdPerson, "Ingrese el id del censista a asignar o 0 para camcelar \n",
								"Error al seleccionar censista\n", "Desea reintentar?\n", MINIMOIDS, MAXIMOSIDS, REINTENTOS)==RETORNOPOSITIVO)
						{
							if(auxIdPerson==0)
							{
								puts("se cancela la asignacion");
							}
							else
							{
								if(person_findOnePersonById(listPerson, auxIdPerson, &posicionPerson, lenPerson)==RETORNOPOSITIVO)
								{
									if(person_validAssigZona(listPerson[posicionPerson], listZona[posicionZona],auxIdPerson, lenPerson)==RETORNOPOSITIVO)
									{
										puts("Se asigno correctamente");
									}
									else
									{
										puts("Actualmente , el id seleccionado esta inactivo o tiene una zona asignada.  ");
									}
								}//busca censista por id
							}
						}
					}//verifica pendiente
					else
					{
						puts("La zona solicitada ya tiene un Censista asignado");
					}
				}

			}
		}
		else
		{
			puts("No hay zonas o personas cargadas ");
		}

	}

	return retorno;
}

int puntoDeMenuCargarDatosZona(datosCenso* arrayDatosPointer[],Person* listPersonPointer[],int lenPerson,int lenZona)
{
	int retorno=RETORNONEGATIVO;
	int auxId;
	int posicionZona;
	int posicionPerson;
	int spaceFound;
	int auxAusentes;
	int auxInSitu;
	int auxVirtual;
	if(arrayDatosPointer != NULL && lenZona > 0)
	{
		posicionZona=datosCenso_searchPointerArray(arrayDatosPointer, OPCIONFREE, lenZona);
		posicionPerson=person_searchPointerArray(listPersonPointer, OPCIONFREE, lenPerson);

		if(posicionPerson != RETORNONEGATIVO && posicionZona != RETORNONEGATIVO)
		{
			person_printListByStatus(listPersonPointer, "Activos", ACTIVO, lenPerson);

			if(utnGetNumero(&auxId, "\nIngrese el ID a del censista que cargara datos o 0 si desea cancelar:\n", "Ocurrio un error al ingresar el ID\n"
								, "Error al ingresar Opcion. Desea reintentar?\n", MINIMOIDS, MAXIMOSIDS, REINTENTOS)==RETORNOPOSITIVO)
			{
				if(auxId!=0)
				{
					if(person_findOnePersonById(listPersonPointer, auxId,&spaceFound, lenPerson)==RETORNOPOSITIVO)
					{
						if(listPersonPointer[spaceFound]->estadoActual==ACTIVO)
						{
							if(datosCenso_findOnePointerByIdPerson(arrayDatosPointer, auxId, &spaceFound, lenZona)==RETORNOPOSITIVO)
							{
								if(datosCenso_ingressDateCenso(&auxAusentes, &auxInSitu, &auxVirtual)==RETORNOPOSITIVO)
								{

									if(datosCenso_addDataCenso(arrayDatosPointer[spaceFound], auxId,
											auxInSitu, auxVirtual, auxAusentes)==RETORNOPOSITIVO)
									{
										listPersonPointer[spaceFound]->estadoActual=LIBERADO;
										printf("Los datos se del Censista %s han cargado correctamente \n  ",listPersonPointer[spaceFound]->dataPerson.lastName);

									}

								}
								else
								{
									puts("Error al cargar datos de censo\n ");
								}
							}

						}
						else
						{
							puts("El censista no tiene zonas asignadas\n ");
						}


					}
					else
					{
						puts("No se encontraron cencistas con el ID ingresado");
					}
				}
				else
				{
					puts("Se cancela la carga");
				}
			}
		}
	}

	return retorno;
}

int pointMenuPrint(Person* arrayPersonPoint[],int lenPointer)
{
	int retorno=RETORNOPOSITIVO;
	person_printArray(arrayPersonPoint,lenPointer);
	return retorno;
}

int puntoDeMenuImprimirCensistas(Person* listPerson[],int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	int auxOpcion;
	if(listPerson!=NULL)
	{
		if(person_searchPointerArray(listPerson,OPCIONBUSY,lenPerson)!=RETORNONEGATIVO)
		{
			if(utnGetNumero(&auxOpcion, "Ingrese:\n 0-Si desea ver todos los censistas\n1- Si desea ver los censistas Activos si\n2- Si desea ver los censista INACTIVOS\n3- Para ver los liberados\n4-Para cancelar \n",
						"Error al seleccionar censista\n", "Desea reintentar?\n", 0, 4, REINTENTOS)==RETORNOPOSITIVO)
				{
					retorno=RETORNOPOSITIVO;
					switch(auxOpcion)
					{

					case 0:
						if(person_printArray(listPerson, lenPerson)==RETORNONEGATIVO)
						{
							puts("No se encontraron cencistas");
						}
						break;
					case 1:
						if(person_printListByStatus(listPerson, "ACTIVOS", ACTIVO, lenPerson)==RETORNONEGATIVO)
						{
							puts("No se encontraron Censistas activos");
						}
						break;
					case 2:
						if(person_printListByStatus(listPerson, "INACTIVO", INACTIVO, lenPerson)==RETORNONEGATIVO)
						{
							puts("No se encontraron cencistas inactivos");
						}
						break;
					case 3:
						if(person_printListByStatus(listPerson, "LIBERADO", LIBERADO, lenPerson)==RETORNONEGATIVO)
						{
							puts("No se encontraron cencistas liberados");
						}
						break;
					case 4:

						puts("Se cancela el informe");
						break;
					}
				}
		}
		else
		{
			puts("No se encontraron Censistas. \n");
		}

	}

	return retorno;
}

int puntoDeMenuHardcode(datosCenso* listZona[],Person* listPerson[], int lenZona,int lenPerson)
{
	//int retorno=RETORNONEGATIVO;
	int auxPointerFree;
	int posicionPerson;
	int posicionZona;
	//int auxIdZona;
	//int auxIdPerson;

	//Alta person
	auxPointerFree=person_searchPointerArray(listPerson, OPCIONFREE, lenPerson);
	listPerson[auxPointerFree] = person_newParametros("Ivano", "Fabelon", "Madrid 1188",
			1993, 04, 19, 29, MAXIMOCADENA);
	if(listPerson[auxPointerFree]!=NULL)
	{
		puts("Alta OK 1");
	}

	auxPointerFree=person_searchPointerArray(listPerson, OPCIONFREE, lenPerson);
	listPerson[auxPointerFree] = person_newParametros("Ivano", "Fabelon", "Madrid 1188",
			1993, 04, 19, 29, MAXIMOCADENA);
	if(listPerson[auxPointerFree]!=NULL)
	{
		puts("Alta OK 2");
	}


	auxPointerFree=person_searchPointerArray(listPerson, OPCIONFREE, lenPerson);
	listPerson[auxPointerFree] = person_newParametros("Aldana", "Medina", "Aristobulo 1188",
			1994, 02, 04, 30, MAXIMOCADENA);
	if(listPerson[auxPointerFree]!=NULL)
	{
		puts("Alta OK 3");
		//retorno = RETORNONEGATIVO;
	}

	auxPointerFree=person_searchPointerArray(listPerson, OPCIONFREE, lenPerson);
	listPerson[auxPointerFree] =person_newParametros("Enano", "Zazu", "Madrid 1188",
			1999, 05, 12, 19, MAXIMOCADENA);

	if(listPerson[auxPointerFree]!=NULL)
	{
		puts("Alta OK 4");
		//retorno = RETORNONEGATIVO;
	}

	auxPointerFree=datosCenso_searchPointerArray(listZona, OPCIONFREE, lenZona);
	listZona[auxPointerFree] = DatosCenso_newParametrosZona(2,"OESTE", 51);
	if(listZona[auxPointerFree]==NULL)
	{
		puts("Algo fallo en la asignacion de la zona en arrayDatosPointer");
	}
	else
	{
		puts("Alta ok ");
	}

	auxPointerFree=datosCenso_searchPointerArray(listZona, OPCIONFREE, lenZona);
	if(auxPointerFree!=RETORNONEGATIVO)
	{
		listZona[auxPointerFree] = DatosCenso_newParametrosZona(2,"este", 51);
		if(listZona[auxPointerFree]!=NULL)
		{
			puts("Alta Zona OK");
		}
	}

	auxPointerFree=datosCenso_searchPointerArray(listZona, OPCIONFREE, lenZona);
	if(auxPointerFree!=RETORNONEGATIVO)
	{
		listZona[auxPointerFree] = DatosCenso_newParametrosZona(3,"Picante", 51);
		if(listZona[auxPointerFree]!=NULL)
		{
			puts("Alta Zona OK");
		}
	}

	auxPointerFree=datosCenso_searchPointerArray(listZona, OPCIONFREE, lenZona);
	if(auxPointerFree!=RETORNONEGATIVO)
	{
		listZona[auxPointerFree] = DatosCenso_newParametrosZona(5, "Bomberos", 51);
		if(listZona[auxPointerFree]!=NULL)
		{
			puts("Alta Zona OK");
		}
	}

	auxPointerFree=datosCenso_searchPointerArray(listZona, OPCIONFREE, lenZona);
	if(auxPointerFree!=RETORNONEGATIVO)
	{
		listZona[auxPointerFree] = DatosCenso_newParametrosZona(4, "Onsari", 51);
		if(listZona[auxPointerFree]!=NULL)
		{
			puts("Alta Zona OK");
		}
	}

	auxPointerFree=datosCenso_searchPointerArray(listZona, OPCIONFREE, lenZona);
	if(auxPointerFree!=RETORNONEGATIVO)
	{
		listZona[auxPointerFree] = DatosCenso_newParametrosZona(1, "Centro", 51);
		if(listZona[auxPointerFree]!=NULL)
		{
			puts("Alta Zona OK");
		}
	}

////Asignar Zona

	if(datosCenso_findOnePointerZonaById(listZona,1, &posicionZona, lenZona)==RETORNOPOSITIVO)
	{
		if(person_findOnePersonById(listPerson, 1, &posicionPerson, lenPerson)==RETORNOPOSITIVO)
		{
			if(person_validAssigZona(listPerson[posicionPerson], listZona[posicionZona],1, lenPerson)==RETORNOPOSITIVO)
			{
				puts("Se asigno correctamente a");
			}
		}//busca censista por id
	}

	if(datosCenso_findOnePointerZonaById(listZona,2, &posicionZona, lenZona)==RETORNOPOSITIVO)
	{
		if(person_findOnePersonById(listPerson, 2, &posicionPerson, lenPerson)==RETORNOPOSITIVO)
		{
			if(person_validAssigZona(listPerson[posicionPerson], listZona[posicionZona],2, lenPerson)==RETORNOPOSITIVO)
			{
				puts("Se asigno correctamente b ");
			}
		}//busca censista por id
	}

	if(datosCenso_findOnePointerZonaById(listZona,3, &posicionZona, lenZona)==RETORNOPOSITIVO)
	{
		if(person_findOnePersonById(listPerson, 3, &posicionPerson, lenPerson)==RETORNOPOSITIVO)
		{
			if(person_validAssigZona(listPerson[posicionPerson], listZona[posicionZona],3, lenPerson)==RETORNOPOSITIVO)
			{
				puts("Se asigno correctamente c");
			}
		}//busca censista por idc
	}

	return 0;


}

int puntoDeMenuInformes(datosCenso* listZona[],Person* listPerson[],localidad* localidades[], int lenZona,int lenPerson,int lenLocalidad)
{

	int opcion;


	if(listZona != NULL && listPerson != NULL)
	{
		if(utnGetNumero(&opcion, "\nOpcion 1:Informar cantidad de censistas en estado Activo con zona Pendiente. \nOpcion 2: Mostrar el listado de censistas de Avellaneda, Lanús, Lomas de Zamora o Banfield ordenados alfabéticamente por apellido y nombre.\nOpcion 4. Informar el censista cuya zona fue la más censada (total censados presencial y virtual)\nnOpcion5: Informar el promedio de censos por censista/zona\n"
		    			,"", "Error al ingresar Opcion. Desea reintentar?Ingrese SI si desea continuar.\n", 0,
						5, REINTENTOS)==RETORNOPOSITIVO)
		{
			switch(opcion)
			{
				case 1:
					if(person_printListByStatus(listPerson, "ACTIVOS", ACTIVO, lenPerson)==RETORNONEGATIVO)//    printListCensistaByStatus(listPerson, "ACTIVOS",ACTIVO, lenPerson)==RETORNONEGATIVO)
					{
						puts("No se encontraron Censistas activos");
						break;
					}
					break;
				case 2:
					person_sortPersonByLastName(listPerson, lenPerson);
					person_printArray(listPerson, lenPerson);

					break;
				case 3:
					localidad_printPersonByLocalidad(listPerson, listZona, localidades, lenPerson, lenLocalidad, lenZona);
				//	printPersonByLocalidad(listZona, listPerson, listZona, localidades, lenPerson, 5, lenZona);

					break;
				case 4:
	 			//	if(printPersonByCantidadCensados(listCenso, listPerson, lenZona)==RETORNONEGATIVO)
					{
						puts("Aun no hay datos cargados para realizar los calculos");
					}
					break;

			}
		}
	}
	return 0;
}




























