/*
 ============================================================================
 Name        : Parcial_1_ConMemoriaDinamica.c
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
#include "Alumno.h"
#define LIMITEPUNTEROALUMNO 100
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
int main(void) {
	setbuf(stdout, NULL);
	Alumno* arrayPunterosAlumno[LIMITEPUNTEROALUMNO];
	int indiceLibre;
	if(alumno_initArray(arrayPunterosAlumno, LIMITEPUNTEROALUMNO)==RETORNOPOSITIVO)
	{
		puts("init ok ");

	 	indiceLibre=alumno_searchFreeArray(arrayPunterosAlumno,LIMITEPUNTEROALUMNO);
		if(indiceLibre>=0)
		{
			arrayPunterosAlumno[indiceLibre] = alumno_newParametros("Ivano", 1.70, 1);
		}

		indiceLibre=alumno_searchFreeArray(arrayPunterosAlumno,LIMITEPUNTEROALUMNO);
		if(indiceLibre>=0)
		{
			arrayPunterosAlumno[indiceLibre] = alumno_newParametros("Aldana", 1.60, 2);
		}
		alumno_printArray(arrayPunterosAlumno, LIMITEPUNTEROALUMNO);
	}
	else
	{
		puts("pincho");
	}


	return EXIT_SUCCESS;
}
