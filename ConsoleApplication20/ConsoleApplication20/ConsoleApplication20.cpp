#include <iostream>
#include "..\..\Headers\dinamica.hpp"

int main()
{
    cout << "Pilas" << endl;

    /*
    Realizar una función que reciba un array de char con una secuencia de 
    paréntesis y llaves, y devuelva si está balanceada o no. Por ejemplo:
    a. Entrada: “[()]{}{[()()]()}”
        Salida: true
    b. Entrada: “[(])”
        Salida: false
    */
    cout << "----------------------------" << endl;
    cout << "Ejercicio 1" << endl;
    /*
    //char vec[16] = { '[','(',')',']','{','}','{','[','(',')','(',')',']','(',')','}' };
    //int len = 16;
    char vec[4] = {'[','(',']',')'};
    int len = 4;
    if(estaBalanceado(vec,len)){
        cout << "Esta balanceado" << endl;
    } else {
        cout << "No esta balanceado" << endl;
    }
    */
    


    /*Realizar una función que reciba un array de char con una expresión en notación
    polaca inversa, y devuelva el resultado.
    Por ejemplo: La expresión algebraica 5+((1+2)*4)-3 se traduce a la notación
        polaca inversa como 5 1 2 + 4 * + 3 - y se evalúa de izquierda a derecha según
        se muestra en la siguiente tabla:
    */
    cout << "----------------------------" << endl;
    cout << "Ejercicio 2" << endl;
    /*
    char vec[9] = { '5', '1', '2', '+', '4', '*' , '+' , '3', '-' };
    int len = 9;
    cout << calculoPolacaInversa(vec, len);
    */

    /*Ingresar una secuencia de caracteres, que termine con -1 e imprimirla en orden
    inverso.
    a. Imitar el funcionamiento de la pila utilizando un array.
    b. Imitar el funcionamiento de la pila utilizando dos colas.
    
    Redefinir PUSH y POP.*/
    cout << "----------------------------" << endl;
    cout << "Ejercicio 3" << endl;
    /*char vecPila[50];
    int len = 0;

    pushUsandoArray(vecPila, len, 'c');
    pushUsandoArray(vecPila, len, 'a');
    pushUsandoArray(vecPila, len, 'd');
    pushUsandoArray(vecPila, len, 'h');

    cout << popUsandoArray(vecPila, len) << endl;
    cout << popUsandoArray(vecPila, len) << endl;
    cout << popUsandoArray(vecPila, len) << endl;
    cout << popUsandoArray(vecPila, len) << endl;
    cout << len << endl;
    */
    /*
    Nodo* cfte = NULL;
    Nodo* cfin = NULL;

    pushUsandoCola(cfte, cfin, 'c');
    pushUsandoCola(cfte, cfin, 'a');
    pushUsandoCola(cfte, cfin, 'd');
    pushUsandoCola(cfte, cfin, 'h');

    cout << popUsandoCola(cfte, cfin) << endl;
    cout << popUsandoCola(cfte, cfin) << endl;
    cout << popUsandoCola(cfte, cfin) << endl;
    cout << popUsandoCola(cfte, cfin) << endl;
    cout << cfte << endl;
    cout << cfin << endl;
    */
}