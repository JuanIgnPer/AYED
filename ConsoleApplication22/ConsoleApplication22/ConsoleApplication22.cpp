#include <iostream>
#include "..\..\Headers\dinamica.hpp"

int main()
{
	//Final 1
    /*
    NodoAscensor* ascensor = NULL;
    planta info;

    info.piso = -3;
    info.suben = 23;
    info.bajan = 3;
    agregarNodoListaDoble(ascensor, info);

    info.piso = -1;
    info.suben = 25;
    info.bajan = 5;
    agregarNodoListaDoble(ascensor, info);

    info.piso = 0;
    info.suben = 7;
    info.bajan = 30;
    agregarNodoListaDoble(ascensor, info);

    info.piso = 2;
    info.suben = 9;
    info.bajan = 5;
    agregarNodoListaDoble(ascensor, info);

    info.piso = 4;
    info.suben = 1;
    info.bajan = 15;
    agregarNodoListaDoble(ascensor, info);

	//Los siguientes dos bloques de codigo necesitan este auxiliar, se ejecutan de a uno por ejecucion
    //NodoAscensor* aux = ascensor;

    //Recorro hasta el final, para mostrar el contenido de la lista
    //while (aux != NULL) {
    //    cout << aux->info.piso<< endl;
    //    aux = aux->arriba;
    //}

    //Recorro hasta el ultimo nodo(arriba) y luego bajo
    //while (aux->arriba != NULL) {
    //    aux = aux->arriba;
    //}
    //while (aux != NULL) {
    //    cout << aux->info.piso << endl;
    //    aux = aux->abajo;
    //}

	//La lista actualmente tiene un solo "piso" cuyo valor es -3
    NodoAscensor* pisoActual = ascensor;
    //Recorro desde los pisos negativos, hasta el 0
    //Me posicion en el piso anterior al que voy a insertar
    while (pisoActual != NULL && pisoActual->info.piso != 2) {
        pisoActual = pisoActual->arriba;
    }
    
    //Deberia mostrar 0
    //cout << pisoActual->info.piso << endl;

	//Creo el nuevoPiso que voy a insertar en la lista
    NodoAscensor* unNuevoPiso = new NodoAscensor();
    unNuevoPiso->info.piso = 3;
    unNuevoPiso->info.suben = 1;
    unNuevoPiso->info.bajan = 1;
    unNuevoPiso->arriba = NULL;
    unNuevoPiso->abajo = NULL;

    int distanciaPlantaBaja = 0;
    int distanciaPlantaMasBaja = 0;
    int distanciaPlantaMasAlta = 0;

	distanciaPlantaBaja = insertarPisoArribaDelActualYMedir(unNuevoPiso, pisoActual, distanciaPlantaMasAlta, distanciaPlantaMasBaja);

    cout << "La distancia a la planta baja es " << distanciaPlantaBaja << endl;
    cout << "La distancia a la planta mas baja es " << distanciaPlantaMasBaja << endl;
    cout << "La distancia a la planta mas alta es " << distanciaPlantaMasAlta << endl;
	/*Al momento de ejecutar hay una diferencia de 1 piso en masBaja y MasAlta.
	Esto se debe a que la profesora en su codigo tiene esta linea:
	cout << auxAbajo->info.piso << endl; 
	en el metodo que cuenta las distancias, al hacer esto se avanza 1 y se pierde la referencia al puntero.
	Haciendo que salga del while 1 nodo antes de lo esperado.
	*/

 
	//Final 2
	/* 
	NodoAscensor* ascensor = NULL;
	planta info;

	info.piso = -3;
	info.suben = 23;
	info.bajan = 3;
	agregarNodoListaDoble(ascensor, info);

	info.piso = -1;
	info.suben = 25;
	info.bajan = 5;
	agregarNodoListaDoble(ascensor, info);

	info.piso = 0;
	info.suben = 7;
	info.bajan = 30;
	agregarNodoListaDoble(ascensor, info);

	info.piso = 1;
	info.suben = 9;
	info.bajan = 5;
	agregarNodoListaDoble(ascensor, info);

	info.piso = 2;
	info.suben = 1;
	info.bajan = 15;
	agregarNodoListaDoble(ascensor, info);

	info.piso = 3;
	info.suben = 34;
	info.bajan = 7;
	agregarNodoListaDoble(ascensor, info);

	info.piso = 4;
	info.suben = 20;
	info.bajan = 9;
	agregarNodoListaDoble(ascensor, info);

	info.piso = 5;
	info.suben = 9;
	info.bajan = 2;
	agregarNodoListaDoble(ascensor, info);

	FILE* archivo = fopen("pisosPrimos.dat", "wb+");
	pisoEliminado reg;
	int cantPisosEliminados;
	
	NodoAscensor* pisoActual = ascensor;
	//Me posiciono en el piso anterior al que voy a empezar a eliminar si es primo
	while (pisoActual != NULL && pisoActual->info.piso != 1) {
		pisoActual = pisoActual->arriba;
	}

	cantPisosEliminados = eliminarLosPisosPrimosArribaDe(pisoActual, archivo);
	cout << "La cantidad de pisos eliminados fue " << cantPisosEliminados << endl;

	rewind(archivo);
	fread(&reg, sizeof(pisoEliminado), 1, archivo);
	while (!feof(archivo)) {
		cout << reg.piso << endl;
		cout << reg.diffEntreSubenYBajan << endl;
		cout << "----------------------" << endl;
		fread(&reg, sizeof(pisoEliminado), 1, archivo);
	}
	fclose(archivo);

	cout << "---------------------" << endl;

	while (pisoActual->arriba != NULL) {
		pisoActual = pisoActual->arriba;
	}
	while (pisoActual != NULL) {
		cout << pisoActual->info.piso << endl;
		pisoActual = pisoActual->abajo;
	}
	*/
}