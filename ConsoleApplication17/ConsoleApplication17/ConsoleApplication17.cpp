#include <iostream>
#include "..\..\Headers\vectores.hpp"
#include "..\..\Headers\dinamica.hpp"

int main()
{
	/*Ejercicio 8*/
	/*
	cout << "----------------------------" << endl;
	cout << "Ejercicio 8" << endl;
	cout << "Lista sin ordenar..." << endl;
	Nodo* lista = NULL;
	agregarNodo(lista, 0);
	agregarNodo(lista, 10);
	agregarNodo(lista, 11);
	agregarNodo(lista, 20);
	agregarNodo(lista, 50);
	agregarNodo(lista, 4);
	agregarNodo(lista, 1);
	agregarNodo(lista, 100);
	agregarNodo(lista, 2);
	mostrar(lista);
	cout << "Ordenando la lista p..." << endl;
	ordenar(lista);
	mostrar(lista);
	liberar(lista);
	*/

	/*Ejercicio 9*/
	/*
	cout << "----------------------------" << endl;
	cout << "Ejercicio 9" << endl;
	ordenar(lista);
	bool encontrado;
	Nodo* nodoBuscado = buscaEInsertaOrdenado(lista, 200, encontrado);
	cout << nodoBuscado->info << endl;
	if (encontrado) {
		cout << "El nodo ya existia" << endl;
	}
	else {
		cout << "El nodo fue insertado" << endl;
	}
	mostrar(lista);
	liberar(lista);
	*/

	/*Pilas*/
	/*
	LIFO : 	Ejemplo de los platos
	Push
	Pop
	*/
	/*Push - Pop*/
	/*
	cout << "Pilas" << endl;
	cout << "----------------------------" << endl;
	cout << "Push y Pop" << endl;
	Nodo* pila = NULL;
	push(pila, 90);
	push(pila, 100);
	push(pila, 1);
	push(pila, 5);
	push(pila, 20);
	push(pila, 50);

	while (pila != NULL) {
		cout << pop(pila) << endl;
	}
	*/


	/*Colas.*/
	/*FIFO : Ejemplo de la fila de los supermercado
	Encolar
	Desencolar
	Tiene dos punteros, colaFte y colaFin al principio ambos apuntan a null
	Si tiene un solo elemento ambos apuntan a ese elemento
	Agregamos desde el fin y sacamos desde el fte
	cFin apunta siempre al ultimo nodo,
	cFte siempre apunta al primero

	*/
	/*Encolar - Desencolar*/
	/*
	cout << "Colas" << endl;
	cout << "----------------------------" << endl;
	cout << "Encolar y desencolar" << endl;
	Nodo* colaFrente = NULL;
	Nodo* colaFin = NULL;

	encolar(colaFrente, colaFin, 4);
	encolar(colaFrente, colaFin, 10);
	encolar(colaFrente, colaFin, 50);
	encolar(colaFrente, colaFin, 100);
	encolar(colaFrente, colaFin, 1);

	while (colaFrente != NULL) {
		cout << desencolar(colaFrente, colaFin)<< endl;
	}
	*/
	
	cout << "Pilas" << endl;

	/*Dada una pila y un valor X, desarrollar un procedimiento que elimine los 2 primeros
	nodos de la pila y deje el valor X como primero. (Primero = para salir de la pila)*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 1" << endl;
	/*
	Nodo* pila = NULL;
	push(pila, 90);
	push(pila, 100);
	push(pila, 1);
	int x;
	cout << "Ingrese el valor X" << endl;
	cin >> x;

	eliminarLosDosPrimerosNodos(pila, x);
	*/

	/*Dada una pila y un valor X, desarrollar un procedimiento que inserte X como tercer
	valor de la pila. Retornar un parámetro con valor 'S' o 'N' según haya sido exitoso o no
	el requerimiento.*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 2" << endl;
	/*
	Nodo* pila = NULL;
	push(pila, 90);
	push(pila, 100);
	push(pila, 1);
	int x;
	cout << "Ingrese el valor X" << endl;
	cin >> x;
	char exitoso;
	colocarEnTercerLugar(pila, x, exitoso);
	if (exitoso == 'S') {
		cout << "Se pudo realizar el req" << endl;
	}
	else {
		cout << "No se pudo realizar el req" << endl;
	}
	while (pila != NULL) {
		cout << pop(pila) << endl;
	}
	*/

	/*Dada una pila y dos valores X e Y, desarrollar un procedimiento que inserte el valor X
	en la posición Y de la pila si es posible.*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 3" << endl;
	/*
	Nodo* pila = NULL;
	push(pila, 90);
	push(pila, 100);
	push(pila, 4);
	push(pila, 1);
	int x , y;
	cout << "Ingrese el valor X" << endl;
	cin >> x;
	cout << "Ingrese el valor y" << endl;
	cin >> y;
	char exitoso;
	colocarEnPosicionYLugar(pila, x, y, exitoso);
	if (exitoso == 'S') {
		cout << "Se pudo realizar el req" << endl;
	}
	else {
		cout << "No se pudo realizar el req" << endl;
	}
	while (pila != NULL) {
		cout << pop(pila) << endl;
	}
	*/

	/*
	Dada una pila y dos valores X e Y, desarrollar un procedimiento que reemplace cada
	valor igual a X que se encuentre en la pila por el valor Y retornando la pila modificada.
	En caso de no haber ningún valor igual a X retornar la pila sin cambio.
	*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 4" << endl;
	/*
	Nodo* pila = NULL;
	push(pila, 90);
	push(pila, 100);
	push(pila, 4);
	push(pila, 1);
	int x, y;
	cout << "Ingrese el valor X" << endl;
	cin >> x;
	cout << "Ingrese el valor y" << endl;
	cin >> y;
	reemplazarXporY(pila, x, y);
	while (pila != NULL) {
		cout << pop(pila) << endl;
	}
	*/

	/*
	Definir una función INVERSA que evalúe dos conjuntos de caracteres separados por un
	punto y retorne True si los conjuntos son inversos (ej: ABcDe.eDcBA) o False si no lo
	son. Los conjuntos deben ingresarse letra por letra por teclado.*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 5" << endl;
	/*
	NodoInv* colaFte = NULL;
	NodoInv* colaFin = NULL;
	char c;
	cout << "Ingrese el caracter" << endl;
	cin >> c;
	while (c != '0') {
		encolarInv(colaFte, colaFin, c);
		cout << "Ingrese el caracter" << endl;
		cin >> c;
	}
	bool esInversa = inversa(colaFte, colaFin);
	if (esInversa) {
		cout << "Los caracteres son inversos" << endl;
	}
	else {
		cout << "Los caracteres no son inversos" << endl;
	}
	*/
}