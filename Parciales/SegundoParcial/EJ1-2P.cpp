#include <iostream>

using namespace std;

/**
 * (2 puntos) Desarrollar una función que reciba una palabra (vector de char) y verifique si es un palíndromo.
 * En la resolución se debe utilizar una pila.
 * Se debe desarrollar el programa principal que debe permitir ingresar palabras hasta que se ingrese un palíndromo.
 */

struct NodoString {
    char value;
    NodoString* sig;
};

bool esPalindromo(char palabra[], int len);

void push(NodoString* &p, char v);
char pop(NodoString* &p);

int main() {

    int len;
    bool palindromo;

    do {
        cout << "Ingrese el largo de la palabra que va a ingresar: " << endl;
        cin >> len;
        cout << "Ingrese una palabra: " << endl;
        char nuevaPalabra[len];
        cin >> nuevaPalabra;
        palindromo = esPalindromo(nuevaPalabra, len);

        if (palindromo) {
            cout << "la palabra ingresada es un palindromo" << endl;
        } else {
            cout << "la palabra ingresada NO es un palindromo, intente nuevamente.." << endl;
        }

    } while (!palindromo);

    return 0;
}

bool esPalindromo(char palabra[], int len) {
    NodoString *pila = NULL;

    for (int i = 0; i < len; i++) {
        //cargo la pila con los caracteres de la palabra
        push(pila, palabra[i]);
    }

    //una vez que la pila esta cargada, tengo que recorrer la mitad de la palabra original e ir comparando con los pop del stack
    for (int i = 0; i < len/2; i++) {
        char caracterOpuesto = pop(pila);
        if (palabra[i] != caracterOpuesto) {
            return false;
        }
    }
    return true;
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