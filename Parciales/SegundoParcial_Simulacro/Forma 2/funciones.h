//
// Created by user on 11/8/2020.
//

#include <iostream>
#include <string>

#ifndef NODOS_FUNCIONES_H

using namespace std;

struct Nodo {
    int value; //puede ser el tipo de dato que yo quiera (incluso otra lista)
    Nodo* sig; //esto lo convierte en una estructura autoreferenciada
};

struct NodoString {
    char value;
    NodoString* sig;
};

/**
 * Notaciones equivalentes:
 *  (*lista).value
 *  lista->value
 */

void agregarNodo(Nodo* &p, int x) {
    Nodo* nuevo = new Nodo();
    nuevo->value = x;
    nuevo->sig = NULL;

    if(p == NULL) {
        //la lista p esta vacia
        p = nuevo;
    } else {
        //tengo que recorrer hasta el ultimo valor
        Nodo* aux = p;
        while(aux-> sig != NULL) {
            aux = aux->sig;
        }
        //finalmente, agrego el nuevo nodo al ultimo lugar
        aux->sig = nuevo;
    }
}

void agregarNodo(NodoString* &p, char x) {
    NodoString* nuevo = new NodoString();
    nuevo->value = x;
    nuevo->sig = NULL;

    if(p == NULL) {
        //la lista p esta vacia
        p = nuevo;
    } else {
        //tengo que recorrer hasta el ultimo valor
        NodoString* aux = p;
        while(aux-> sig != NULL) {
            aux = aux->sig;
        }
        //finalmente, agrego el nuevo nodo al ultimo lugar
        aux->sig = nuevo;
    }
}

void mostrar(Nodo* p) {
    cout << "mostrando lista.." << endl;
    Nodo* aux = p;
    while (aux != NULL) {
        cout << aux->value << endl;
        aux = aux->sig;
    }
}

void mostrar(NodoString* p) {
    cout << "mostrando lista.." << endl;
    NodoString* aux = p;
    while (aux != NULL) {
        cout << aux->value << endl;
        aux = aux->sig;
    }
}

void liberar(Nodo* &p) {
    Nodo* aux = p;
    while (p != NULL) {
        aux = p;
        p = p->sig;
        delete aux;
    }
}

/**
 * retorna el Nodo que contiene el valor, o NULL en su defecto
 */
Nodo* buscar(Nodo* &p, int v) {
    Nodo* aux = p;
    while (aux != NULL && aux->value != v) {
        aux = aux->sig;
    }
    return aux;
}

/**
 * busca el nodo que contiene el valor v y lo elimina
 */
void eliminar(Nodo* &p, int v) {
    Nodo* aux = p;
    Nodo* prev = NULL;
    while (aux != NULL && aux->value != v) {
        prev = aux;
        aux = aux->sig;
    }

    if (prev == NULL) {
        //estamos eliminando el primer nodo
        p = aux->sig;
    } else {
        prev->sig = aux->sig;
    }

    delete aux;
}

int eliminarPrimerNodo(Nodo* &p) {
    cout << "eliminando primer nodo.." << endl;
    int result = p->value;
    Nodo* aux = p;
    p = p->sig;
    delete aux;
    return result;
}

Nodo* insertarOrdenado(Nodo* &p, int v) {
    Nodo* nuevo = new Nodo();
    nuevo->value = v;
    nuevo->sig = NULL;
    Nodo* prev = NULL;
    Nodo* aux = p;

    //recorro la lista previamente ordenada de forma creciente
    while (aux != NULL && aux->value <= v) {
        prev = aux;
        aux = aux->sig;
    }

    if (prev == NULL) {
        //estoy insertando al principio
        p = nuevo;
    } else {
        prev->sig = nuevo;
    }
    nuevo->sig = aux;
    return nuevo;
}

void ordenar(Nodo* &p) {
    Nodo* q = NULL;
    int val;
    while (p != NULL) {
        val = eliminarPrimerNodo(p);
        insertarOrdenado(q, val);
    }
    p = q;
}

Nodo* buscaEinsertaOrdenado(Nodo* &p, int v, bool &enc) {
    Nodo* buscado = buscar(p, v);

    if (buscado != NULL) {
        enc = true;
    } else {
        buscado = insertarOrdenado(p, v);
        enc = false;
    }
    return buscado;
}

/**
 * PILAS
 */

void push(Nodo* &p, int v) {
    Nodo* nuevo = new Nodo();
    nuevo->value = v;
    nuevo->sig = p;
    p = nuevo;
}

void push(NodoString* &p, char v) {
    NodoString* nuevo = new NodoString();
    nuevo->value = v;
    nuevo->sig = p;
    p = nuevo;
}

char pop(NodoString* &p) {
    char result = p->value;
    NodoString* aux = p;
    p = aux-> sig;
    delete aux;
    return result;
}

int pop(Nodo* &p) {
    int result = p->value;
    Nodo* aux = p;
    p = aux-> sig;
    delete aux;
    return result;
}

/**
 * COLAS
 */

void encolar (Nodo* &colaFrente, Nodo* &colaFin, int v) {
    Nodo* nuevo = new Nodo();
    nuevo->value = v;
    nuevo->sig = NULL;
    if (colaFrente == NULL) {
        colaFrente = nuevo;
    } else {
        colaFin->sig = nuevo;
    }
    colaFin = nuevo;
}

int desencolar(Nodo* &colaFrente, Nodo* &colaFin) {
    int result = colaFrente->value;
    Nodo* aux = colaFrente;
    colaFrente = aux->sig;
    if (colaFrente == NULL) {
        colaFin = NULL;
    }
    delete aux;
    return result;
}

#define NODOS_FUNCIONES_H

#endif //NODOS_FUNCIONES_H
