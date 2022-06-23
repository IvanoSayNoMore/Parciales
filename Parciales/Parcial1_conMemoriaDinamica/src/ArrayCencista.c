/*
 * ArrayCencista.c
 *
 *  Created on: 26 may 2022
 *      Author: Usuario Programador
 */

#include "ArrayCencista.h"
#define PENDIENTE -1
#define FINALIZADO 0
///
#define EMPTY 0
#define FULL -1
///
#define REINTENTOS 3
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MAXIMOCADENA 51
///
#define ACTIVO 1
#define INACTIVO -1
#define LIBERADO 0
///
#define OPCIONFREE 1
#define OPCIONBUSY 0

/////
Person* person_newMalloc(void)
{
	return (Person*) malloc(sizeof(Person));
}

Person* person_newRealocc(Person* pPerson,int size)
{
	return (Person*) realloc(pPerson,sizeof(Person)*size);
}

int person_initArrayPointer(Person* arrayPointerPerson[],int lenPointer)
{
	int retorno=RETORNONEGATIVO;

	if(arrayPointerPerson != NULL && lenPointer > 0)
	{

		int i;
		retorno=RETORNOPOSITIVO;
		for(i=0;i<lenPointer;i++)
		{
			arrayPointerPerson[i] = NULL;
		}

	}

	return retorno;
}

int person_searchPointerArray(Person* arrayPunteros[],int option, int lenPunteros)
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

int person_findOnePersonById(Person* arrayPointer[],int idPerson,int* spaceFound, int lenPointer)
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

int person_validAssigZona(Person* listPerson,datosCenso* zona,int idCensista,int lenPerson)
{

	int retorno=RETORNONEGATIVO;

	if(zona != NULL && listPerson != NULL && listPerson->estadoActual==LIBERADO)
	{
		person_assignZone(zona, idCensista);
		listPerson->estadoActual=ACTIVO;
		retorno=RETORNOPOSITIVO;
	}

	return retorno;

}

int person_assignZone(datosCenso* zona,int idCensista)
{
	int retorno=RETORNONEGATIVO;
	if(zona != NULL )
	{
		zona->idCensista=idCensista;
		zona->estadoCenso=PENDIENTE;
	}

	return retorno;
}



int person_deletPersonById(Person* arrayPointer[],int idPerson, int lenPointer)
{
	int retorno = RETORNONEGATIVO;
	int auxPointeBussy;
	if(arrayPointer != NULL && idPerson >0 && lenPointer >= 0)
	{
		if(person_findOnePersonById(arrayPointer, idPerson, &auxPointeBussy, lenPointer)==RETORNOPOSITIVO)
		{
			if(person_deletIndexArray(arrayPointer, auxPointeBussy)==RETORNOPOSITIVO)
			{
				retorno=RETORNOPOSITIVO;
			}
		}
	}

	return retorno;
}

int person_deletIndexArray(Person* arrayPointer[], int index)
{
	int retorno=RETORNONEGATIVO;
	if(arrayPointer != NULL && arrayPointer[index] != NULL)
	{
		retorno=RETORNOPOSITIVO;
		free(arrayPointer[index]);

		arrayPointer[index] = NULL ;
	}
	return retorno;
}
/////

int ingresPerson(char name[],char lastName[],char direccion[],int* anio,int* mes,int* dia, int* edad,int lenCadena)
{
	int retorno=RETORNONEGATIVO;
	char auxChar[lenCadena];
	int auxInt;
	int flagOk=RETORNOPOSITIVO;
	int continuar=0;

	do{
		//Nombre
		if(utnIngressStringChar(auxChar, "\nIngrese su nombre: \n", lenCadena)==0)
		{

			strncpy(name,auxChar,lenCadena);
		}
		else
		{
			flagOk=-1;
			break;
		}

		//Apellido
		if(utnIngressStringChar(auxChar, "\nIngrese su apellido: \n", lenCadena)==RETORNOPOSITIVO)
		{

			strncpy(lastName,auxChar,lenCadena);
		}
		else
		{
			flagOk=-1;
			break;
		}

		///Dia Nacimiento
		if(utnGetNumero(&auxInt, "\nIngrese el dia de nacimiento .\n","Reintente\n", "Error. Desea reintentar?\n", 1,31, REINTENTOS)==RETORNOPOSITIVO)
		{

			*dia=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}

		///Mes Nacimiento
		if(utnGetNumero(&auxInt, "\nIngrese el mes de nacimiento .\n","Reintente\n", "Error. Desea reintentar?\n", 1,12, REINTENTOS)==RETORNOPOSITIVO)
		{
			*mes=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}

		///Anio Nacimiento
		if(utnGetNumero(&auxInt, "\nIngrese el año de nacimiento .\n","Reintente \n", "Error. Desea reintentar?\n", 1,2000, REINTENTOS)==RETORNOPOSITIVO)
		{
			*anio=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}


		///Anio Nacimiento
		if(utnGetNumero(&auxInt, "\nIngrese su edad .\n","Reintente \n", "Error. Desea reintentar?\n", 18,99, REINTENTOS)==RETORNOPOSITIVO)
		{
			*edad=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}

		//Direccion
		if(utnIngresarAlfanumerico(auxChar, "Ingrese su domicilio \n", REINTENTOS, lenCadena)==RETORNOPOSITIVO)
		{
			strncpy(direccion,auxChar,lenCadena);
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

Person* person_newParametros(char name[],char lastName[],char direccion[],int anio,int mes,int dia, int edad,int lenCadena)
{
	Person* punteroPerson = NULL;
	int auxId;
	punteroPerson = person_newMalloc();
	if(punteroPerson != NULL)
	{
		contadorId(&auxId);
		punteroPerson->idCensista=auxId;
		strncpy(punteroPerson->dataPerson.name,name,lenCadena);
		strncpy(punteroPerson->dataPerson.lastName,lastName,lenCadena);
		punteroPerson->fechaNacimiento.dia=dia;
		punteroPerson->fechaNacimiento.mes=mes;
		punteroPerson->fechaNacimiento.anio=anio;
		punteroPerson->dataPerson.edad=edad;
		strncpy(punteroPerson->direccion.direccion,direccion,lenCadena);
		punteroPerson->estadoActual=LIBERADO;
	}
	else
	{
		puts("PunteroPerson == null");
	}

	return punteroPerson;
}




int changePerson(Person* person,int lenCadena)
{
	int retorno=RETORNONEGATIVO;
	int continuar;
	int auxInt;
	int auxDia;
	int auxMes;
	int auxAnio;
	char auxDireccion[lenCadena];
	int opcion;
	char auxChar[lenCadena];


	do{
		printf("Su nombre actual es %s\nSu Apellido actual es %s\n",person->dataPerson.name,person->dataPerson.lastName);
		printf("Su edad es %d y su fecha de nacimiento es el : %d/%d/%d\n",
				person->dataPerson.edad,person->fechaNacimiento.dia,person->fechaNacimiento.mes,person->fechaNacimiento.anio);

		puts("----------------------------------\n");
		if(utnGetNumero(&opcion, "Ingrese la op que desea modificar.\n1-Nombre\n2-Apellido\n3-edad \n4-Direccion o fecha de nacimiento\n0-Para cancelar la modificacion\n "
				,"\nPor favor, ingrese solo numeros\n", "Error al ingresar Opcion. Desea reintentar?\n", 1, 8, REINTENTOS)==RETORNOPOSITIVO)
		{
			switch(opcion)
			{
			case 1:
				if(utnIngressStringChar(auxChar, "\nIngrese su nombre: \n", lenCadena)==RETORNOPOSITIVO)
				{
					utnToupper(auxChar);
					printf("Cambio exitoso, el nuevo nombre es el de %s\n",auxChar);

					strncpy(person->dataPerson.name,auxChar,lenCadena);
					retorno=RETORNOPOSITIVO;
					break;
				}
				else
				{
					retorno=RETORNONEGATIVO;
					break;
				}

			case 2:
				if(utnIngressStringChar(auxChar, "\nIngrese su apellido: \n", lenCadena)==RETORNOPOSITIVO)
				{
					utnToupper(auxChar);
					printf("Cambio exitoso, el nuevo apellido es el de %s\n",auxChar);

					strncpy(person->dataPerson.lastName,auxChar,lenCadena);
					retorno=RETORNOPOSITIVO;
					break;
				}
				else
				{
					retorno=RETORNONEGATIVO;
					break;
				}

			case 3:
				if(utnGetNumero(&auxInt, "\nIngrese su edad\n", "Error al ingresar edad\n", "Error al ingresar edad, desea volver a ingresar?\n", 0, 5, REINTENTOS)==RETORNOPOSITIVO)
				{
					person->dataPerson.edad=auxInt;
					printf("Cambio exitoso, el nuevo tipo es el de %d\n",auxInt);

					retorno=RETORNOPOSITIVO;
					break;
				}
				else
				{

					retorno=RETORNONEGATIVO;
					break;
				}

				//
			case 4:
				if(changeDate(&auxDia, &auxMes, &auxAnio, auxDireccion, lenCadena)==RETORNOPOSITIVO)
				{
					person->fechaNacimiento.anio=auxAnio;
					person->fechaNacimiento.dia=auxDia;
					person->fechaNacimiento.mes=auxMes;
					strncpy(person->direccion.direccion,auxDireccion,lenCadena);
					break;
				}
				else
				{
					retorno=RETORNONEGATIVO;
					break;
				}

			case 0:
				puts("Se cancela la opcion modificar\n");
				retorno=RETORNOPOSITIVO;
				break;

			default :
				retorno=RETORNONEGATIVO;
				puts("Error de opcion\n");

			}//Fin Switch

		}//Fin If utnGetNumero
		if(retorno==RETORNOPOSITIVO)
		{
			continuar=utnVerificacionConChar( "Desea continuar con la opcion de cambio de datos personales ? \n",
								"Seleccione que desea modificar\n", "Finaliza la modificacion de datos personales" , 0);
		}
		else
		{
			continuar=utnVerificacionConChar( "Ocurrio un error al modificar,desea continuar el cambio de datos personales ?\n",
								"Seleccione que desea modificar\n", "Finaliza la modificacion de datos personales " , 0);
		}

	}while(continuar==RETORNOPOSITIVO);


	return retorno;
}

int changeDate(int* dia, int* mes, int* anio, char* direccion,int lenCadena)
{
	int retorno;
	int opcion;
	int auxInt;
	char auxChar[lenCadena];

	if(utnGetNumero(&opcion, "Ingrese la op que desea modificar.\n1-Nombre\n2-Apellido\n3-edad \n4-Direccion \n-0-Si desea cancelar \n "
					,"\nPor favor, ingrese solo numeros\n", "Error al ingresar Opcion. Desea reintentar?\n", 0, 4, REINTENTOS)==RETORNOPOSITIVO)
	{
		switch(opcion)
		{
		case 1:
			if(utnGetNumero(&auxInt, "\nIngrese dia de nacimiento\n", "Error al ingresar dia de nacimiento\n", "Error al ingresar dia, desea reintentar?", 0, 5, REINTENTOS)==RETORNOPOSITIVO)
			{
				*dia=auxInt;
				retorno=RETORNOPOSITIVO;
				break;
			}
			else
			{
				retorno=RETORNONEGATIVO;
				break;
			}

		case 2:
			if(utnGetNumero(&auxInt, "\nIngrese mes de nacimiento\n", "Error al ingresar mes de nacimiento\n", "Error al ingresar mes,desea reintentar?\n", 0, 5, REINTENTOS)==RETORNOPOSITIVO)
			{
				*mes=auxInt;
				retorno=RETORNOPOSITIVO;
				printf("Cambio exitoso, el nuevo mes de nacimiento es el de %d\n",auxInt);
				break;
			}
			else
			{
				retorno=RETORNONEGATIVO;
				break;
			}

		case 3:
			if(utnGetNumero(&auxInt, "\nIngrese año de nacimiento\n", "Error al ingresar año de nacimiento\n", "Error al ingresar año,desea reintentar?\n", 0, 5, REINTENTOS)==RETORNOPOSITIVO)
			{
				*anio=auxInt;
				retorno=RETORNOPOSITIVO;
				printf("Cambio exitoso, el nuevo año de nacimiento es el de %d\n",auxInt);
				break;
			}
			else
			{

				retorno=RETORNONEGATIVO;
				break;
			}
		case 4:
			//Direccion

			if(utnIngresarAlfanumerico(auxChar, "Ingrese su domicilio \n", REINTENTOS, lenCadena)==RETORNOPOSITIVO)
			{
				strncpy(direccion,auxChar,lenCadena);
				retorno=RETORNOPOSITIVO;
				break;
			}
			else
			{
				retorno=RETORNONEGATIVO;
				break;
			}
		case 0:
			retorno=RETORNONEGATIVO;
			break;
		}


	}

	return retorno;

}

int person_sortPersonByLastName(Person* listPerson[], int lenPerson)
{
	int retorno;

	int estaOrdenado;
	int j;
	int valor;

	do{
		estaOrdenado=0;
		j=0;
		for(int i=0; i<lenPerson-1; i++)
		{
			if(listPerson[i]!=NULL)
			{
				for(j=i+1;j<lenPerson;j++)
				{
					if(listPerson[j]!=NULL)
					{
						valor=(strcmp(listPerson[i]->dataPerson.lastName,listPerson[j]->dataPerson.lastName)>0);
						if(valor>0)
						{
							estaOrdenado=1;
							person_soap(listPerson, i,j);
							retorno=RETORNOPOSITIVO;
							break;
						}
					}

				}
			}

		}//Fin for i
		lenPerson--;
	}while(estaOrdenado==1);


	return retorno;
}

void person_soap(Person* list[],int posicionA, int posicionB)
{
	Person* auxPassenger;
	auxPassenger = list[posicionA];
	list[posicionA] = list[posicionB];
	list[posicionB] = auxPassenger;

}

