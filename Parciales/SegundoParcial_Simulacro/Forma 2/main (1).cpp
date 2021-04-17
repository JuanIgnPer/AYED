#include <cstdio>
#include <cstring>
#include "funciones.h"

/**
 * Simulacro 2do Parcial
 */

/**
 * (3 puntos) En el archivo “turnos20201031.dat” tenemos el listado de turnos de un consultorio para un día en particular.
 * De los turnos sabemos la hora (integer) y el nombre del paciente.
 * Ordenar la información contenida en el archivo por hora y colocarlo en una cola para que puedan ser llamados.
 */

struct Turno {
    int hora;
    char nya[50];
};

struct NodoTurno {
    Turno turno;
    NodoTurno* sig;
};

/**
 * FUNCIONES COMPLEMENTARIAS (IMPLEMENTACION NO REQUERIDA DURANTE EXAMEN)
 */

void llenarArchivo();
void agregarNodo(NodoTurno* &p, Turno turno);
void mostrar(NodoTurno* p);
Turno eliminarPrimerNodo(NodoTurno* &p);
NodoTurno* insertarOrdenado(NodoTurno* &p, Turno v);
void ordenar(NodoTurno* &p);
void encolar (NodoTurno* &colaFrente, NodoTurno* &colaFin, Turno v);

/**
 * FUNCIONES OBLIGATORIAS
 */

NodoTurno* leerArchivo();

int main() {

    NodoTurno* lista = leerArchivo();
    mostrar(lista);

    ordenar(lista);

    NodoTurno* cfte = NULL;
    NodoTurno* cfin = NULL;

    while (lista != NULL) {
        encolar(cfte,cfin, lista->turno);
        lista = lista->sig;
    }
    return 0;
}

//lee el archivo y llena una lista con la informacion (desordenada)
NodoTurno* leerArchivo() {
    NodoTurno* lista = NULL;

    FILE* turnos = fopen("turnos20201031.dat", "rb");
    Turno reg;

    fread(&reg, sizeof(Turno), 1, turnos);
    while (!feof(turnos)) {
        agregarNodo(lista, reg);
        fread(&reg, sizeof(Turno), 1, turnos);
    }
    fclose(turnos);
    return lista;
}

void llenarArchivo() {
    FILE* turnos = fopen("turnos20201031.dat", "wb");

    Turno turno;
    strcpy(turno.nya, "Ignacio Speicys");
    turno.hora = 8;
    fwrite(&turno, sizeof(Turno), 1, turnos);

    Turno turno2;
    strcpy(turno2.nya, "Santiago Illia");
    turno2.hora = 7;
    fwrite(&turno2, sizeof(Turno), 1, turnos);

    fclose(turnos);
}

void agregarNodo(NodoTurno* &p, Turno turno) {
    NodoTurno* nuevo = new NodoTurno();
    nuevo->turno = turno;
    nuevo->sig = NULL;

    if(p == NULL) {
        //la lista p esta vacia
        p = nuevo;
    } else {
        //tengo que recorrer hasta el ultimo valor
        NodoTurno* aux = p;
        while(aux-> sig != NULL) {
            aux = aux->sig;
        }
        //finalmente, agrego el nuevo nodo al ultimo lugar
        aux->sig = nuevo;
    }
}

void mostrar(NodoTurno* p) {
    cout << "mostrando lista.." << endl;
    NodoTurno* aux = p;
    while (aux != NULL) {
        cout << "------------------------------------------" << endl;
        cout << "nombre y apellido: " << aux->turno.nya << endl;
        cout << "hora: " <<  aux->turno.hora << endl;
        aux = aux->sig;
    }
}

Turno eliminarPrimerNodo(NodoTurno* &p) {
    cout << "eliminando primer nodo.." << endl;
    Turno result = p->turno;
    NodoTurno* aux = p;
    p = p->sig;
    delete aux;
    return result;
}

NodoTurno* insertarOrdenado(NodoTurno* &p, Turno v) {
    NodoTurno* nuevo = new NodoTurno();
    nuevo->turno = v;
    nuevo->sig = NULL;
    NodoTurno* prev = NULL;
    NodoTurno* aux = p;

    //criterio de orden custom aca
    while (aux != NULL && aux->turno.hora <= v.hora) {
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

void ordenar(NodoTurno* &p) {
    NodoTurno* q = NULL;
    Turno val;
    while (p != NULL) {
        val = eliminarPrimerNodo(p);
        insertarOrdenado(q, val);
    }
    p = q;
}

void encolar (NodoTurno* &colaFrente, NodoTurno* &colaFin, Turno v) {
    NodoTurno* nuevo = new NodoTurno();
    nuevo->turno = v;
    nuevo->sig = NULL;
    if (colaFrente == NULL) {
        colaFrente = nuevo;
    } else {
        colaFin->sig = nuevo;
    }
    colaFin = nuevo;
}