/*
 * Alumno.h
 *
 *  Created on: 25 may 2022
 *      Author: Usuario Programador
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
typedef struct{
	int id;
	char nombre[51];
	float altura;
}Alumno;

Alumno* alumno_new(void);
Alumno* alumno_newParametros(char* nombre, float altura, int id);
int alumno_initArray(Alumno* arrayPunteros[], int lenPunteros);
int alumno_printArray(Alumno* arrayPunteros[], int lenPunteros);
int alumno_searchFreeArray(Alumno* arrayPunteros[], int lenPunteros);
#endif /* ALUMNO_H_ */
