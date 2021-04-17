#include "funciones.h"

/*
 * Simulacro 2do Parcial
 */

/**
 *
 * (2 puntos)Desarrollar un procedimiento que permita ingresar caracteres por teclado.
 *
 * Si se ingresa una letra (A-Z) se inserta en la pila. Si se ingresa un asterisco se saca un elemento de la pila.
 * Imprimir la secuencia de caracteres que se sacaron de la pila. El ingreso de caracteres termina cuando se ingresa un punto.
 *
 * Nota: El valor ascii de la A es 65 y el de la Z es 90.
 */

void insertAndPrint();
void insertAndPrint2();

int main() {

    insertAndPrint2();

    return 0;
}

//implementacion que imprime a medida que se remueven caracteres
void insertAndPrint() {

    NodoString* pila = NULL;

    char input;
    cout << "Ingrese un caracter: " << endl;
    cin >> input;

    char *eof = ".";
    while (input != *eof) {
        int ascii = (int)input;

        char *removechar = "*";
        if (input == *removechar) {
            if (pila == NULL)
                break;
            char v = pop(pila);
            cout << "caracter impreso: " << v << endl;

        //verificar por ASCII si el valor es una letra
        } else if (ascii >= 65 && ascii <= 90) {
            push(pila, input);
        }

        cout << "Ingrese un caracter: " << endl;
        cin >> input;
    }
}

//implementacion que guarda los caracteres en una lista y los imprime al final
void insertAndPrint2() {

    NodoString* pila = NULL;
    NodoString* lista = NULL;

    char input;
    cout << "Ingrese un caracter: " << endl;
    cin >> input;

    char *eof = ".";
    while (input != *eof) {
        int ascii = (int)input;

        char *removechar = "*";
        if (input == *removechar) {
            if (pila == NULL)
                break;
            char v = pop(pila);
            agregarNodo(lista, v);

            //verificar por ASCII si el valor es una letra
        } else if (ascii >= 65 && ascii <= 90) {
            push(pila, input);
        }

        cout << "Ingrese un caracter: " << endl;
        cin >> input;
    }

    mostrar(lista);
}
