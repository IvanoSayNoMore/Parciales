/*
 ============================================================================
 Name        : Parcial1_conMemoriaDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayCencista.h"
#include "ArrayZona.h"
#include "PuntosDeMenu.h"
#include "Localidad.h"
#include "printPrint.h"
#define MINIMOOPCION 1
#define MAXIMOOPCION 11
#define MAXIMOPUNTEROSCENSISTAS 10
#define MAXIMOPUNTEROSZONAS 30
#define MAXIMOPUNTEROSOCALIDADES 5
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int index = 0;

	Person* pPerson[MAXIMOPUNTEROSCENSISTAS];
    datosCenso* pDatosCenso[MAXIMOPUNTEROSZONAS];
    localidad* pLocalidades[MAXIMOPUNTEROSOCALIDADES];


    person_initArrayPointer(pPerson, MAXIMOPUNTEROSCENSISTAS);
    datosCenso_initArrayPointer(pDatosCenso, MAXIMOPUNTEROSZONAS);
    localidad_initArrayPointer(pLocalidades, MAXIMOPUNTEROSOCALIDADES);


    menuAltaLocalidad(pLocalidades,MAXIMOPUNTEROSOCALIDADES);
    localidad_printArray(pLocalidades, MAXIMOPUNTEROSOCALIDADES);

    do{
    	if(utnGetNumero(&opcion, "\nOpcion 1: Cargar censista\nOpcion 2: Modificar datos de censista \nOpcion 3: Baja censista\nOpcion 4: Cargar Zona\nOpcion 5: Asignar Zona\nOpcion 6: Cargar datos \nOpcion 7: Mostrar censista\nOpcion 8: Mostrar Zonas\nOpcion 9: INFORMES \n10-HARDCODE\n"
    			,"", "Error al ingresar Opcion. Desea reintentar?Ingrese SI si desea continuar.\n", MINIMOOPCION,
				MAXIMOOPCION, REINTENTOS)==RETORNOPOSITIVO)
    	{
    	 	switch(opcion)
			{

			case 1://Cargar Censista
				if(puntoDeMenuAltaPerson(pPerson, MAXIMOPUNTEROSCENSISTAS)==RETORNOPOSITIVO)
				{
					index++;
				}

				break;

			case 2://Modificar
				puntoDeMenuModificarPerson(pPerson, MAXIMOPUNTEROSCENSISTAS);
					break;

			case 3://Borrar
				puntoDeMenuEliminarPerson(pPerson, MAXIMOPUNTEROSCENSISTAS);
					break;

			case 4://Cargar Zona
				puntoDeMenuAltaZona(pDatosCenso, pLocalidades, MAXIMOPUNTEROSZONAS, MAXIMOPUNTEROSOCALIDADES);
					break;

			case 5://Asignar Zona
				puntoDeMenuAsignarZona(pDatosCenso, pPerson, MAXIMOPUNTEROSZONAS, MAXIMOPUNTEROSOCALIDADES);
				   break;

			case 6://Cargar datos
				puntoDeMenuCargarDatosZona(pDatosCenso, pPerson, MAXIMOPUNTEROSCENSISTAS, MAXIMOPUNTEROSZONAS);
				break;

			case 7://Mostrar Censistas
				puntoDeMenuImprimirCensistas(pPerson, MAXIMOPUNTEROSCENSISTAS);
				break;
			case 8:
				datosCenso_printAllZona(pDatosCenso,pPerson,pLocalidades,0,MAXIMOPUNTEROSZONAS,MAXIMOPUNTEROSCENSISTAS,MAXIMOPUNTEROSOCALIDADES);
				//printAllZone(datosZona, datosPersona, datosCenso, localidades, MAXIMOCENSISTAS, MAXIMOLOCALIDADES, MAXIMOZONAS);
				//menuItemOrdenamientos(datosZona, datosCenso, datosPersona, MAXIMOZONAS, MAXIMOCENSISTAS);
				break;
			case 9:
				//menuItemInformes(datosZona, datosCenso, datosPersona, localidades, MAXIMOZONAS, MAXIMOCENSISTAS);
				break;
			case 10://LA PRUEBA DE FUEGO
			//	menuItemHardCode(datosZona, datosCenso, datosPersona, MAXIMOZONAS, MAXIMOCENSISTAS);
				puntoDeMenuHardcode(pDatosCenso,pPerson,MAXIMOPUNTEROSZONAS,MAXIMOPUNTEROSCENSISTAS);
				break;
			case 11:
			//	menuItemOrdenamientos(datosZona, datosCenso, datosPersona, MAXIMOZONAS, MAXIMOCENSISTAS);
				break;
			default:
				puts("Error en la seleccion\n");
				break;

			}//Fin Switch

    	}//Fin if elegir opcion
    	else
    	{
    		puts("\n Adios \n");
    		opcion=-2;

    	}

    }while(opcion!=-2);

	return EXIT_SUCCESS;
}
