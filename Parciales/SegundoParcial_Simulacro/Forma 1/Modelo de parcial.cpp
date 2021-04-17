#include <iostream>
#include "encabezados.hpp"
using namespace std;

int main()
{
    //ejercicio 1 modelo de parcial
    /*
    NodoChar* pila = NULL;
    NodoChar* listaEliminados = NULL;
    char c;

    cout << "Ingrese un caracter de la A a la Z, ingrese * si quiere eliminar un caracter ingresado. Ingrese . para finalizar el ingreso" << endl;
    cin >> c;

    while (c != '.')
    {
        ingresarLetraEnPila(pila, listaEliminados, c);
        cout << "Ingrese un caracter, ingrese * para eliminar un caracter ingresado" << endl;
        cin >> c;
    }

    while (listaEliminados != NULL)
    {
        cout << eliminarPrimerNodoChar(listaEliminados) << endl;
    }
    

    //ejercicio 3 modelo de parcial
    FILE* fTurnosOct31 = fopen("turnos20201031.dat", "rb");
    Turno reg;

    NodoPaciente* lista = NULL;
    fread(&reg, sizeof(Turno), 1, fTurnosOct31);
    while (!feof(fTurnosOct31))
    {
        insertarOrdenadoPaciente(lista, reg);
        fread(&reg, sizeof(Turno), 1, fTurnosOct31);
    }
    fclose(fTurnosOct31);

    NodoPaciente* cFte = NULL;
    NodoPaciente* cFin = NULL;

    while (lista != NULL)
    {
        encolarPaciente(cFte, cFin, eliminarPrimerNodoPaciente(lista));
    }
    
    
    //ejercicio 4 modelo de parcial
    Nodo* listA = NULL;
    Nodo* listB = NULL;
    Nodo* listC = NULL;

    agregarNodo(listA, 2);
    agregarNodo(listA, 3);
    agregarNodo(listA, 4);
    agregarNodo(listB, 5);
    agregarNodo(listB, 3);
    agregarNodo(listB, 7);

    unirListasEliminandoNodos(listA, listB, listC);

    mostrar(listC);
    */

    //ejercicio 2
    FILE* fVentas = fopen("ventas.dat", "rb+");
    Ventas reg;

    NodoCliente* lista = NULL;

    InfoCli* clientInfo = NULL;

    fread(&reg, sizeof(Ventas), 1, fVentas);
    while (!feof(fVentas))
    {
        clientInfo->nroCli = reg.nroCliente;
        clientInfo->dineroGastado += reg.cantComprada * reg.PrecioUni;
        agregarNodoCli(lista, clientInfo);
        fread(&reg, sizeof(Ventas), 1, fVentas);
    }
    fclose(fVentas);

}

