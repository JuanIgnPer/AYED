#include <iostream>
#include "..\..\Headers\dinamica.hpp"

int main()
{
    cout << "Colas" << endl;
    /* 1. Imitar el funcionamiento de una cola utilizando una lista enlazada.*/
    cout << "----------------------------" << endl;
    cout << "Ejercicio 1" << endl;
    Nodo* lista = NULL;
    encolarUsandoLista(lista, 12);
    encolarUsandoLista(lista, 6);
    encolarUsandoLista(lista, 34);
    encolarUsandoLista(lista, 78);
    encolarUsandoLista(lista, 129);
    encolarUsandoLista(lista, 2);

    desencolarUsandoLista(lista);
    desencolarUsandoLista(lista);

    Nodo* aux = lista;
    while (aux != NULL) {
        cout << aux->info << endl;
        aux = aux->sig;
    }
    /*
    */

    
    /*2. Imitar el funcionamiento de una cola utilizando un array.*/
    cout << "----------------------------" << endl;
    cout << "Ejercicio 2" << endl;
    /*
    int vec[10];
    int len = 0;
    encolarUsandoArray(vec, len, 12);
    encolarUsandoArray(vec, len, 6);
    encolarUsandoArray(vec, len, 34);
    encolarUsandoArray(vec, len, 78);
    encolarUsandoArray(vec, len, 129);
    encolarUsandoArray(vec, len, 2);
    
    desencolarUsandoArray(vec, len);
    desencolarUsandoArray(vec, len);
    desencolarUsandoArray(vec, len);

    cout << len << endl;

    for (int i = 0; i < len; i++) {
        cout << vec[i] << endl;
    }
    */

    /*3. Imitar el funcionamiento de una cola utilizando dos pilas.*/
    cout << "----------------------------" << endl;
    cout << "Ejercicio 3" << endl;
    /*
    Nodo* pila = NULL;

    encolarUsandoPila(pila, 12);
    encolarUsandoPila(pila, 6);
    encolarUsandoPila(pila, 34);
    encolarUsandoPila(pila, 78);
    encolarUsandoPila(pila, 129);
    encolarUsandoPila(pila, 2);

    desencolarUsandoPila(pila);
    desencolarUsandoPila(pila);

    while (pila != NULL) {
        cout << pop(pila) << endl;
    }
    */


    /*Listas doblemente enlazadas*/
    /*
    * Ademas de tener un nodo que apunta al siguiente tiene uno que apunta hacia atras
    * El Info esta compuesto por el valor + otro puntero, hacia atras
    */

    /*Final Ascensores 1 - Se resuelve en la clase 22*/
    /*
    NodoAscensor* ascensor;
    NodoAscensor* unNuevoPiso = new NodoAscensor();
    unNuevoPiso->info.piso = 2;
    unNuevoPiso->info.suben = 4;
    unNuevoPiso->info.bajan = 0;
    unNuevoPiso->arriba = NULL;
    unNuevoPiso->abajo = NULL;

    int distanciaPisoMasBajo = 0;
    int distanciaPisoMasAlto = 0;
    int distanciaPlantaBaja = 0;

    distanciaPlantaBaja = insertarPisoArribaDelActualYMedir(unNuevoPiso, unPisoActual, distanciaPisoMasAlto, distanciaPisoMasBajo);

    cout << "La distancia a la planta baja es " << distanciaPlantaBaja << endl;
    cout << "La distancia a la planta mas alta es " << distanciaPisoMasAlto << endl;
    cout << "La distancia a la planta mas bajo es " << distanciaPisoMasBajo << endl;
    */
}
