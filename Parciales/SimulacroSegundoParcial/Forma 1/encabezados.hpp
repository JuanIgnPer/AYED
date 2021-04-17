#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


struct Nodo
{
	int info;
	Nodo* sig;
};

struct NodoChar
{
	char info;
	NodoChar* sig;
};

struct Turno
{
	int hora;
	char nombre[50];
};

struct NodoPaciente
{
	Turno info;
	NodoPaciente* sig;
};


struct Ventas
{
	int nroCliente;
	int idArt;
	int cantComprada;
	float PrecioUni;
};

struct InfoArtComprado
{
	int ArtComprados;
	int cantComprada;
	float precioUnitario;
};

struct ArtComprado
{
	InfoArtComprado info;
	ArtComprado* sig;
};

struct InfoCli
{
	int nroCli;
	float dineroGastado = 0;
	ArtComprado* listaArt;
};

struct NodoCliente
{
	InfoCli info;
	NodoCliente* sig;
};


#ifndef vectores
#define vectores

//ejercicio 1
void agregarNodoChar(NodoChar*& p, char x);

int popChar(NodoChar*& p);

void pushChar(NodoChar*& p, char v);

void ingresarLetraEnPila(NodoChar*& pila, NodoChar*& pilaEliminados, char c);

char eliminarPrimerNodoChar(NodoChar*& lista);

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

#endif