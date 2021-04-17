#include <iostream>

using namespace std;

/**
 * Desarrolle un procedimiento que muestre, dado un mes (MM), cuál es la estación (Primavera-Verano-Otoño-Invierno) del año.
 */

//1 = Otoño
//2 = Invierno
//3 = Primavera
//4 = Verano

int estaciones[12] = {1,1,1,2,2,2,3,3,3,4,4,4};

void mostrarEstacion(int mes) {

    int estacion = estaciones[mes - 1];

    switch (estacion) {
        case 1:
            std::cout << "es Otoño" << endl;
            break;

        case 2:
            std::cout << "es Invierno" << endl;
            break;

        case 3:
            std::cout << "es Primavera" << endl;
            break;

        case 4:
            std::cout << "es Verano" << endl;
            break;
    }

}