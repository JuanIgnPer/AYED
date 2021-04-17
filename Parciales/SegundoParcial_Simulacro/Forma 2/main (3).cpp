#include <iostream>

#include "funciones.h"

/**
 * Simulacro 2do Parcial
 */

/*
 * (2 puntos) Crear un procedimiento que dadas dos listas A y B, llene una lista C con la unión (sin repetidos) de las listas A y B.
 *
 * Comentario: es funcionalmente equivalente al "Apareo" de vectores, pero con memoria dinamica.
 */
void mergeLists(Nodo* listaA, Nodo* listaB, Nodo* &listaC);

int main() {

    Nodo* listaA = NULL;
    Nodo* listaB = NULL;
    Nodo* listaC = NULL;

    agregarNodo(listaA, 10);
    agregarNodo(listaA, 15);
    agregarNodo(listaA, 13);

    agregarNodo(listaB, 13);
    agregarNodo(listaB, 27);
    agregarNodo(listaB, 3);

    mergeLists(listaA, listaB, listaC);

    mostrar(listaC);

    return 0;
}

void mergeLists(Nodo* listaA, Nodo* listaB, Nodo* &listaC) {

    while (listaA != NULL) {
        int v = listaA->value;
        bool enc;
        buscaEinsertaOrdenado(listaC,v, enc);
        listaA = listaA->sig;
    }

    while (listaB != NULL) {
        int v = listaB->value;
        bool enc;
        buscaEinsertaOrdenado(listaC, v, enc);
        listaB = listaB->sig;
    }
}
