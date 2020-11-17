#include <iostream>
#include "..\..\Headers\vectores.hpp"
#include "..\..\Headers\dinamica.hpp"

int main()
{
	//Memoria dinamica
	
	//int a = 10;
	//cout << &a << endl; //Informo la posicion de memoria
	//int* p = &a;
	//cout << p << endl; //La posicion de memoria de a

	//int* l = new int();
	//*l = 10;
	//cout << *l << endl;
	//delete l; // Elimino la direccion de memoria
	//cout << *l << endl;

	//Clase 15/8 1:06:09 Dinamica
	//1:53
	//Nodo *lista = new Nodo();
	//(*lista).info = 10;
	//cout << (*lista).info << endl;
	//lista->info = 15;
	//cout << lista->info << endl;

	/*Listas*/

	/*Ejercicio 1*/
	cout << "Ejercicio 1" << endl;
	cout << "Agregando nodos a lista ..." << endl;
	Nodo* lista = NULL;
	agregarNodo(lista, 10);
	agregarNodo(lista, 11);
	agregarNodo(lista, 20);
	agregarNodo(lista, 50);
	agregarNodo(lista, 4);

	/*Ejercicio 2*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 2" << endl;
	cout << "Mostrando datos de la lista ..." << endl;
	mostrar(lista);

	/*Ejercicio 3*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 3" << endl;
	cout << "Liberando lista ..." << endl;
	liberar(lista);

	/*Ejercicio 4*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 4" << endl;
	cout << "Buscando el valor 4 en la lista ..." << endl;
	agregarNodo(lista, 0);
	agregarNodo(lista, 10);
	agregarNodo(lista, 11);
	agregarNodo(lista, 20);
	agregarNodo(lista, 4);
	Nodo* buscado;
	buscado = buscar(lista, 4);
	if (buscado != NULL) {
		cout << "El valor fue encontrado" << endl;
	}
	else {
		cout << "El valor no se encuentra" << endl;
	}
	
	/*Ejercicio 5*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 5" << endl;
	cout << "Eliminando el valor 4 de la lista ..." << endl;
	eliminar(lista, 4);
	mostrar(lista);

	/*Ejercicio 6*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 6" << endl;
	cout << "Eliminando el primer nodo de la lista ..." << endl;
	cout << "El nro. del primer nodo es " << eliminarPrimerNodo(lista) << endl;
	mostrar(lista);

	/*Ejercicio 7*/
	cout << "----------------------------" << endl;
	cout << "Ejercicio 7" << endl;
	cout << "Insertando nodos ordenados..." << endl;
	insertarOrdenado(lista, 0);
	insertarOrdenado(lista, 10);
	insertarOrdenado(lista, 11);
	insertarOrdenado(lista, 20);
	insertarOrdenado(lista, 50);
	insertarOrdenado(lista, 4);
	insertarOrdenado(lista, 1);
	insertarOrdenado(lista, 100);
	insertarOrdenado(lista, 2);
	mostrar(lista);


	liberar(lista);
}