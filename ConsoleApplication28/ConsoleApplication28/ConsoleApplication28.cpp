#include "..\..\Headers\dinamica.hpp"
#include <iostream>

/*EJ 1*/
struct NodoChar
{
    char info;
    NodoChar* sig;
};
void agregarNodoChar(NodoChar*& p, char x);
char popChar(NodoChar*& p);
void pushChar(NodoChar*& p, char v);
void ingresarLetraEnPila(NodoChar*& pila, NodoChar*& pilaEliminados, char c);
char eliminarPrimerNodoChar(NodoChar*& lista);

/*
//ejercicio 3
NodoPaciente* insertarOrdenadoPaciente(NodoPaciente*& p, Turno v);
void encolarPaciente(NodoPaciente*& colaFte, NodoPaciente*& colaFin, Turno v);
Turno eliminarPrimerNodoPaciente(NodoPaciente*& p);

//ejercicio 4
void agregarNodo(Nodo*& p, int x);
int eliminarPrimerNodo(Nodo*& p);
Nodo* buscar(Nodo* p, int v);
void unirListasEliminandoNodos(Nodo*& listA, Nodo*& listB, Nodo*& listC);
void mostrar(Nodo* p);

//ejercicio 2
void agregarNodoCli(NodoCliente*& p, InfoCli*& x);
*/

int main()
{
	/*EJ 1 - 2 puntos*/
	/*Desarrollar un procedimiento que permita ingresar caracteres por teclado.
	* Si se ingresa una letra(A-Z) se inserta en la pila.
	* Si se ingresa un asterisco , se saca un elemento de la pila.
	* Imprimir la secuencia de caracteres que se sacaron de la pila.
	* El ingreso de caracteres termina cuando se ingresa un punto.
	* Nota: El valor ascii de la A es 65 y el de la Z es el 90.
	*/
	/*
    NodoChar* pila = NULL;
    NodoChar* listaEliminados = NULL;
    char c;
	cout << "Ingrese un caracter de la A a la Z, ingrese * si quiere eliminar un caracter ingresado. Ingrese . para finalizar el ingreso" << endl;
    cin >> c;
    while (c != '.') { //Itero mientras sea distinto de .
        ingresarLetraEnPila(pila, listaEliminados, c); //Acumulo el valor en la pila
        cout << "Ingrese un caracter, ingrese * para eliminar un caracter ingresado" << endl;
        cin >> c;
    }
	while (listaEliminados != NULL){ //Itero sobre la lista de eliminados mostrando cada nodo
        cout << eliminarPrimerNodoChar(listaEliminados) << endl;
    }
	*/
}

/*EJ 1*/
void agregarNodoChar(NodoChar*& p, char x)
{
	NodoChar* nuevoNodo = new NodoChar();
	nuevoNodo->info = x;
	nuevoNodo->sig = NULL;
	if (p == NULL)
	{
		p = nuevoNodo;
	}
	else
	{
		NodoChar* aux = p;
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nuevoNodo;
	}
}
char popChar(NodoChar*& p)
{
	char retorno = p->info;
	NodoChar* aux = p;
	p = aux->sig;
	delete aux;
	return retorno;
}
void pushChar(NodoChar*& p, char v)
{
	NodoChar* nuevo = new NodoChar();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}
void ingresarLetraEnPila(NodoChar*& pila, NodoChar*& lista, char caracter)
{
	if (caracter == '*'){ //Si es un asterisco, saco el nodo de la pila y lo pongo en la lista
		agregarNodoChar(lista, popChar(pila));
	}
	if (caracter >= 65 && caracter <= 90){ //Si es una letra, la agrego a la pila
		pushChar(pila, caracter);
	}
}
char eliminarPrimerNodoChar(NodoChar*& lista)
{
	//Saco el primer nodo de la pila
	char valor = lista->info;
	NodoChar* aux = lista;
	lista = lista->sig;
	delete aux;
	return valor;
}