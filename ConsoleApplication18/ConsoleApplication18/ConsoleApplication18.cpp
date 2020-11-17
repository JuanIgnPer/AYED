#include <iostream>
#include "..\..\Headers\dinamica.hpp"

int main()
{
	cout << "Pilas" << endl;
	/*
	Desarrollar un procedimiento que ingrese por teclado un conjunto de Apellidos de
	estudiantes y los imprima en orden inverso al de ingreso. */
	cout << "----------------------------" << endl;
	cout << "Ejercicio 6" << endl;
	/*imprimirApellidosOrdenInverso();*/

	/*
	Dada una pila desarrollar un procedimiento que ordene la misma de acuerdo al valor
	de sus nodos y la retorne. (Ordenado de mayor a menor)
	*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 7" << endl;
	/*
	Nodo* pila = NULL;
	push(pila, 20);
	push(pila, 3);
	push(pila, 15);
	ordenarPila(pila);

	while (pila != NULL) {
		cout << pop(pila) << endl;
	}*/

	cout << "Colas" << endl;
	/*Colas*/
	/*Dada una cola, desarrollar un procedimiento que elimine 2 nodos de la misma (indicar
	con un parámetro 'S'/'N' si ello fue‚ o no posible)*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 1" << endl;
	/*NodoEstudiante* cfte = NULL;
	NodoEstudiante* cfin = NULL;
	est aux;
	aux.legajo = 123444;
	strcpy(aux.nya, "pepe");
	aux.curso = 1053;
	encolarEstudiante(cfte, cfin, aux);

	aux.legajo = 1345678;
	strcpy(aux.nya, "ale");
	aux.curso = 1051;
	encolarEstudiante(cfte, cfin, aux);

	aux.legajo = 0;
	strcpy(aux.nya, "");
	aux.curso = 0;
	char resultado = eliminarNodos(cfte, cfin, 3);
	if (resultado == 'S') {
		cout << "Se pudo eliminar la cantidad pedida" << endl;
	}
	else {
		cout << "No se pudo eliminar la cantidad pedida" << endl;
	}
	while (cfte != NULL) {
		aux = desencolarEstudiante(cfte, cfin);
		cout << aux.legajo << endl;
		cout << aux.nya << endl;
		cout << aux.curso << endl;
	}*/

	/*Dada una cola, desarrollar una función que devuelva la cantidad de nodos que tiene.*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 2" << endl;
	/*NodoEstudiante* cfte = NULL;
	NodoEstudiante* cfin = NULL;
	est aux;
	aux.legajo = 123444;
	strcpy(aux.nya, "pepe");
	aux.curso = 1053;
	encolarEstudiante(cfte, cfin, aux);

	aux.legajo = 1345678;
	strcpy(aux.nya, "ale");
	aux.curso = 1051;
	encolarEstudiante(cfte, cfin, aux);

	aux.legajo = 0;
	strcpy(aux.nya, "");
	aux.curso = 0;
	cout << "En la cola hay:" << contarNodos(cfte, cfin) << " nodos" << endl;

	while (cfte != NULL) {
		aux = desencolarEstudiante(cfte, cfin);
		cout << aux.legajo << endl;
		cout << aux.nya << endl;
		cout << aux.curso << endl;
	}
	*/

	/*Dadas dos colas COLA y COLB, desarrollar un procedimiento que genere una única cola
	COLC a partir de ellas. (Primero los nodos de COLA y luego los de COLB).*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 3" << endl;
	/*NodoEstudiante* cfte1 = NULL;
	NodoEstudiante* cfin1 = NULL;
	NodoEstudiante* cfte2 = NULL;
	NodoEstudiante* cfin2 = NULL;
	NodoEstudiante* cfte3 = NULL;
	NodoEstudiante* cfin3 = NULL;
	est aux;

	aux.legajo = 123444;
	strcpy(aux.nya, "pepe");
	aux.curso = 1053;
	encolarEstudiante(cfte1, cfin1, aux);

	aux.legajo = 1345678;
	strcpy(aux.nya, "ale");
	aux.curso = 1051;
	encolarEstudiante(cfte1, cfin1, aux);

	aux.legajo = 4451;
	strcpy(aux.nya, "vir");
	aux.curso = 1043;
	encolarEstudiante(cfte2, cfin2, aux);

	aux.legajo = 654;
	strcpy(aux.nya, "facu");
	aux.curso = 1034;
	encolarEstudiante(cfte2, cfin2, aux);

	unirColas(cfte1, cfin1, cfte2, cfin2, cfte3, cfin3);

	while (cfte3 != NULL) {
		aux = desencolarEstudiante(cfte3, cfin3);
		cout << aux.legajo << endl;
		cout << aux.nya << endl;
		cout << aux.curso << endl;
	}
	*/

	/*Dada una cola, imprimirla en orden natural si tiene más de 100 nodos, caso contrario
	imprimirla en orden inverso.*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 4" << endl;
	/*
	NodoEstudiante* cfte = NULL;
	NodoEstudiante* cfin = NULL;
	est aux;
	aux.legajo = 123444;
	strcpy(aux.nya, "pepe");
	aux.curso = 1053;
	encolarEstudiante(cfte, cfin, aux);

	aux.legajo = 1345678;
	strcpy(aux.nya, "ale");
	aux.curso = 1051;
	encolarEstudiante(cfte, cfin, aux);
	imprimirCola(cfte, cfin);
	*/

	/*Dadas dos colas COLA y COLB, desarrollar un procedimiento que genere otra cola COLC
	por apareo del campo LEGAJO del registro (define orden creciente en ambas).
	Nota: COLA y COLB dejan de ser útiles después del apareo.*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 5" << endl;
	/*
	NodoEstudiante* cfte1 = NULL;
	NodoEstudiante* cfin1 = NULL;
	NodoEstudiante* cfte2 = NULL;
	NodoEstudiante* cfin2 = NULL;
	NodoEstudiante* cfte3 = NULL;
	NodoEstudiante* cfin3 = NULL;
	est aux;
	aux.legajo = 123444;
	strcpy(aux.nya, "pepe");
	aux.curso = 1053;
	encolarEstudiante(cfte1, cfin1, aux);

	aux.legajo = 153444;
	strcpy(aux.nya, "ale");
	aux.curso = 1051;
	encolarEstudiante(cfte1, cfin1, aux);

	aux.legajo = 654;
	strcpy(aux.nya, "vir");
	aux.curso = 1043;
	encolarEstudiante(cfte2, cfin2, aux);

	aux.legajo = 4451;
	strcpy(aux.nya, "facu");
	aux.curso = 1034;
	encolarEstudiante(cfte2, cfin2, aux);

	apareo(cfte1, cfin1, cfte2, cfin2, cfte3, cfin3);

	while (cfte3 != NULL) {
		aux = desencolarEstudiante(cfte3, cfin3);
		cout << aux.legajo << endl;
		cout << aux.nya << endl;
		cout << aux.curso << endl;
	}
	*/
}
