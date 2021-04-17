#include <iostream>

using namespace std;

/**
 * Desarrolle una función que determine si un año (AAAA) que se pasa por parámetro es bisiesto.
 * Realizar el programa principal que invoca a esta función luego de pedirle al usuario que ingrese un año.
 * En el programa principal imprimir “El año AAAA es bisiesto”o  “El año AAAA no es bisiesto” según corresponda.
 * Un año es bisiesto si es divisible entre cuatro y no es divisible entre 100 o es divisible entre 400.
 */

//uso year por que no le gusta la enie al IDE
bool esBisiesto(int year);

int main() {

    int year;
    cout << "Ingrese un año en el formato AAAA: ";
    cin >> year;

    bool val = esBisiesto(year);

    cout << "el año " << year;

    if (val) {
        cout << " es bisiesto" << endl;
    } else {
        cout << " no es bisiesto" << endl;
    }

    return 0;
}

bool esBisiesto(int year) {
    return (year % 4 == 0 && year % 100 != 0);
}