#include <iostream>
#include <string.h>
#include <stdio.h>
#include "encabezados.hpp"
using namespace std;

//ejercicio 1
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

int popChar(NodoChar*& p)
{
	int retorno = p->info;
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
	if (caracter == '*')
	{
		agregarNodoChar(lista, popChar(pila));
	}
	if (caracter >= 65 && caracter <= 90)
	{
		pushChar(pila, caracter);
	}
}

char eliminarPrimerNodoChar(NodoChar*& lista)
{
	char valor = lista->info;
	NodoChar* aux = lista;
	lista = lista->sig;
	delete aux;
	return valor;
}


//ejercicio 3
NodoPaciente* insertarOrdenadoPaciente(NodoPaciente*& p, Turno v)
{
	NodoPaciente* nuevo = new NodoPaciente();
	nuevo->info = v;
	nuevo->sig = NULL;
	NodoPaciente* aux = p;
	NodoPaciente* ant = NULL;

	while (aux != NULL && aux->info.hora <= v.hora)
	{
		ant = aux;
		aux = aux->sig;
	}

	if (ant == NULL)
	{
		p = nuevo;
	}
	else
	{
		ant->sig = nuevo;
	}
	nuevo->sig = aux;

	return nuevo;
}

void encolarPaciente(NodoPaciente*& colaFte, NodoPaciente*& colaFin, Turno v)
{
	NodoPaciente* nuevo = new NodoPaciente();
	nuevo->info = v;
	nuevo->sig = NULL;
	if (colaFte == NULL)
	{
		colaFte = nuevo;
	}
	else
	{
		colaFin->sig = nuevo;
	}
	colaFin = nuevo;
}

Turno eliminarPrimerNodoPaciente(NodoPaciente*& p)
{
	Turno valor = p->info;
	NodoPaciente* aux = p;
	p = p->sig;
	delete aux;
	return valor;
}


//ejercicio 4
void agregarNodo(Nodo*& p, int x)
{
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->info = x;
	nuevoNodo->sig = NULL;
	if (p == NULL)
	{
		p = nuevoNodo;
	}
	else
	{
		Nodo* aux = p;
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nuevoNodo;
	}
}

int eliminarPrimerNodo(Nodo*& p)
{
	int valor = p->info;
	Nodo* aux = p;
	p = p->sig;
	delete aux;
	return valor;
}

Nodo* buscar(Nodo* p, int v)
{
	Nodo* aux = p;
	while (aux->info != v && aux->sig != NULL)
	{
		aux = aux->sig;
	}

	if (aux->info == v)
	{
		return aux;
	}
	else
	{
		return NULL;
	}
}

void unirListasEliminandoNodos(Nodo*& listA, Nodo*& listB, Nodo*& listC) //sin repetidos
{
	while (listA != NULL)
	{
		agregarNodo(listC, eliminarPrimerNodo(listA));
	}

	Nodo* encontrado;
	while (listB != NULL)
	{
		encontrado = buscar(listC, listB->info);
		if (encontrado == NULL)
		{
			agregarNodo(listC, eliminarPrimerNodo(listB));
		}
		else
		{
			eliminarPrimerNodo(listB);
		}
	}
}

void mostrar(Nodo* p)
{
	Nodo* aux = p;
	while (aux != NULL)
	{
		cout << aux->info << endl;
		aux = aux->sig;
	}
}


//ejercicio 2
void agregarNodoCli(NodoCliente*& p, InfoCli*& x)
{
	NodoCliente* nuevoNodo = new NodoCliente();
	nuevoNodo->info = x;
	nuevoNodo->sig = NULL;
	if (p == NULL)
	{
		p = nuevoNodo;
	}
	else
	{
		NodoCliente* aux = p;
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nuevoNodo;
	}
}