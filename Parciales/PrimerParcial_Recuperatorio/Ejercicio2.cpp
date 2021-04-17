#include <iostream>

using namespace std;

/**
 * Tenemos un archivo “apuestas.dat” (sin orden) que contiene las apuestas del Hipódromo de Palermo.
 * Cada apuesta está compuesta por un identificador de caballo, un identificador de apostador y el dinero apostado.
 * Cómo máximo son 20 caballos y 100 apostadores. Un apostador puede apostar por más de un caballo.

Informar:

El caballo con más dinero apostado.

El caballo que recibió más cantidad de apuestas.

El apostador que más dinero apostó.

El apostador que apostó a más caballos.

 */

struct Apuesta {
    int idCaballo;
    int idApostador;
    long dineroApostado;
}reg;

struct Caballo {
    int idCaballo;
    long dineroTotalRecaudado;
    int cantApuestasRecibidas;
};

struct Apostador {
    int idApostador;
    long dineroTotalApostado;
    int cantCaballosApostados;
};

//busca un caballo en el array en base a su clave primaria idCaballo
int buscar(Caballo *arr, int len, int idCaballo);

void agregar(Caballo *arr, int &len, Caballo dato);

//busca un apostador en el array en base a su clave primaria idApostador
int buscar(Apostador *arr, int len, int idApostador);

void agregar(Apostador *arr, int &len, Apostador dato);

int main() {

    Caballo arrCaballos[20];
    int lenCaballos = 0;

    Apostador arrApostador[100];
    int lenApostador = 0;

    FILE * apuestas = fopen("apuestas.dat", "rb");

    fread(&reg, sizeof(Apuesta), 1, apuestas);

    while (!feof(apuestas)) {

        //busco o inserto en array de caballos
        int posCaballo = -1;

        posCaballo = buscar(arrCaballos, lenCaballos, reg.idCaballo);

        if (posCaballo == -1) {
            //el dato no existe en array de caballos, agregando..
            Caballo dato;
            dato.idCaballo = reg.idCaballo;
            dato.dineroTotalRecaudado = reg.dineroApostado;
            dato.cantApuestasRecibidas = 1;
            agregar(arrCaballos, lenCaballos, dato);
        } else {
            //el caballo existe, agregando cantidad recaudada
            arrCaballos[posCaballo].dineroTotalRecaudado += reg.dineroApostado;
            arrCaballos[posCaballo].cantApuestasRecibidas++;
        }

        //busco o inserto en array de apostadores
        int posApostador = -1;

        posApostador = buscar(arrApostador, lenApostador, reg.idApostador);

        if (posApostador == -1) {
            //el dato no existe en el array de apostadores, agregando..
            Apostador dato;
            dato.idApostador = reg.idApostador;
            dato.dineroTotalApostado = reg.dineroApostado;
            dato.cantCaballosApostados = 1;
            agregar(arrApostador, lenApostador, dato);
        } else {
            //el apostador existe, agregando cantidad apostada
            arrApostador[posApostador].dineroTotalApostado += reg.dineroApostado;
            arrApostador[posApostador].cantCaballosApostados++;
        }

        fread(&reg, sizeof(Apuesta), 1, apuestas);
    }

    //cierro el stream
    fclose(apuestas);

    //analizo el vector de caballos
    int idCaballoMasApostado, idCaballoQueMasRecaudo;
    long cantMaxApostada = 0,cantMaxRecaudada = 0;

    for (int i = 0; i < lenCaballos; i++) {

        int idActual = arrCaballos[i].idCaballo;

        if (arrCaballos[i].cantApuestasRecibidas > cantMaxApostada) {
            idCaballoMasApostado = idActual;
        }

        if (arrCaballos[i].dineroTotalRecaudado > cantMaxRecaudada) {
            idCaballoQueMasRecaudo = idActual;
        }
    }

    Caballo caballoMasApostado = arrCaballos[idCaballoMasApostado];
    Caballo caballoQueMasRecaudo = arrCaballos[idCaballoQueMasRecaudo];

    cout << "El caballo que recibio mas apuestas fue el de id: " << caballoMasApostado.idCaballo;
    cout << " con un total de :" << caballoMasApostado.cantApuestasRecibidas << " apuestas" << endl;

    cout << "El caballo que mas dinero recaudo fue el de id: " << caballoQueMasRecaudo.idCaballo;
    cout << " con un total de :" << caballoQueMasRecaudo.dineroTotalRecaudado << " pesos recaudados" << endl;

    //analizo el vector de apostadores
    int idApostadorMaximoDinero, idApostadorMaximoCantidad;
    long cantMaxQueAposto = 0, cantMaxVecesApostadas = 0;

    for (int i = 0; i < lenApostador; i++) {

        int idActual = arrApostador[i].idApostador;

        if (arrApostador[i].dineroTotalApostado > cantMaxQueAposto) {
            idApostadorMaximoDinero = idActual;
        }

        if (arrApostador[i].cantCaballosApostados > cantMaxVecesApostadas) {
            idApostadorMaximoCantidad = idActual;
        }
    }

    Apostador apostadorQueMasApostoCantidad = arrApostador[idApostadorMaximoCantidad];
    Apostador apostadorQueMasDineroAposto = arrApostador[idApostadorMaximoDinero];

    cout << "El apostador que mas veces apposto fue el de id: " << apostadorQueMasApostoCantidad.idApostador;
    cout << " con un total de :" << apostadorQueMasApostoCantidad.cantCaballosApostados << " apuestas" << endl;

    cout << "El apostador que mas dinero aposto fue el de id: " << apostadorQueMasDineroAposto.idApostador;
    cout << " con un total de :" << apostadorQueMasDineroAposto.dineroTotalApostado << " pesos apostados" << endl;

    return 0;
}
