#include <iostream>
#include <cstring>

using namespace std;

/**
 * (3 puntos) Se tiene un archivo “cineOctubre2020.dat” que contiene los siguientes datos:
 * código de cine,
 * código de la película,
 * nombre de la película,
 * fecha y
 * cantidad de entradas vendidas.
 *
 * Con estos datos llenar una lista que contenga código de cine y entradas totales vendidas del cine en el mes de Octubre.
 * A su vez cada nodo de esa lista, va a poseer una sublista de películas, junto con su cantidad de entradas vendidas en dicho mes.

Luego, mostrar un listado con la siguiente estructura:

Código de cine: entradas totales vendidas

Detalle:

Nombre de la película – entradas vendidas

e informar cuál fue el cine que más entradas vendió en el mes.
 */

//este es el registro con el que leo el archivo
struct ReporteVentas {
    int codCine;
    int codPelicula;
    char nombrePelicula[50];
    char fecha[6];
    int cantEntradasVendidas;
} reg;

struct Pelicula {
    int codPelicula;
    char nombrePelicula[50];
    int cantEntradasVendidas;
};

struct NodoPeliculas {
    Pelicula pelicula;
    NodoPeliculas* sig;
};

struct Cine {
    int codCine;
    int cantEntradasVendidas;
    NodoPeliculas* peliculas;
};

struct NodoCine {
    Cine cine;
    NodoCine* sig;
};

//simple busqueda en base al Cine.codCine
NodoCine* buscar(NodoCine *lista, int codCine);

//busqueda en base a Pelicula.codPelicula
NodoPeliculas* buscar(NodoPeliculas *lista, int codPelicula);

//agrega un nodo con un objeto de tipo peliculas a la lista de tipo NodoPeliculas
void agregarNodo(NodoPeliculas* &lista, Pelicula pelicula);

//agrega un nodo con un objeto de tipo cine a la lista de tipo NodoCine
void agregarNodo(NodoCine* &lista, Cine cine);

int main() {

    NodoCine *listaCines = NULL;

    FILE* reportesDeVentas = fopen("cineOctubre2020.dat", "rb");

    fread(&reg, sizeof(ReporteVentas), 1, reportesDeVentas);

    while (!feof(reportesDeVentas)) {
        int codCine = reg.codCine;
        NodoCine *busqueda = buscar(listaCines, codCine);

        if (busqueda == NULL) {
            //no existe un cine cargado en la lista, lo creo todo desde 0
            Cine cine;
            cine.codCine = codCine;
            cine.cantEntradasVendidas = reg.cantEntradasVendidas;

            NodoPeliculas* listaPeliculas = NULL;
            Pelicula pelicula;
            pelicula.codPelicula = reg.codPelicula;
            strcpy(pelicula.nombrePelicula, reg.nombrePelicula);
            pelicula.cantEntradasVendidas = reg.cantEntradasVendidas;
            agregarNodo(listaPeliculas, pelicula);
            cine.peliculas = listaPeliculas;

            agregarNodo(listaCines, cine);
        } else {
            //el elemento existe (y tengo el nodo)
            busqueda->cine.cantEntradasVendidas += reg.cantEntradasVendidas;
            NodoPeliculas* busquedaPeliculas = buscar(busquedaPeliculas, reg.codPelicula);

            if (busquedaPeliculas == NULL) {
                //la pelicula no esta cargada en la lista de este cine, la creo y agrego
                Pelicula pelicula;
                pelicula.codPelicula = reg.codPelicula;
                strcpy(pelicula.nombrePelicula, reg.nombrePelicula);
                pelicula.cantEntradasVendidas = reg.cantEntradasVendidas;
                agregarNodo(busqueda->cine.peliculas, pelicula);

            } else {
                //la pelicula esta cargada en la lista (y tengo el nodo)
                busquedaPeliculas->pelicula.cantEntradasVendidas += reg.cantEntradasVendidas;
            }
        }

        fread(&reg, sizeof(ReporteVentas), 1, reportesDeVentas);
    }

    //una vez finalizada la lectura del archivo, poseo una lista de cines, cada uno con su sublista de peliculas

    int cantMaxDeVentas = 0;
    NodoCine* punteroCineConMasVentas = NULL;

    //utilizo un auxiliar para recorrer la lista
    NodoCine* auxListaCines = listaCines;
    while (auxListaCines != NULL) {

        //imprimo el codigo de cine junto a las entradas totales que vendio
        int cantEntradasVendidas = auxListaCines->cine.cantEntradasVendidas;
        cout << auxListaCines->cine.codCine << " : " << cantEntradasVendidas << endl;

        //aprovecho e intento ver si este es el cine con mas ventas
        if (cantEntradasVendidas > cantMaxDeVentas) {
            cantMaxDeVentas = cantEntradasVendidas;
            punteroCineConMasVentas = auxListaCines;
        }

        NodoPeliculas* auxListaPeliculas = auxListaCines->cine.peliculas;
        cout << "Detalle: " << endl;
        while (auxListaPeliculas != NULL) {

            //imprimo el nombre de la pelicula junto a la cantidad de entradas totales que vendio
            cout << auxListaPeliculas->pelicula.nombrePelicula << " : " << auxListaPeliculas->pelicula.cantEntradasVendidas << endl;
            auxListaPeliculas = auxListaPeliculas->sig;
        }

        auxListaCines = auxListaCines->sig;
    }

    Cine cineConMasVentas = punteroCineConMasVentas->cine;
    cout << "el cine con mas ventas fue el de codigo: " << cineConMasVentas.codCine << " con una cant. de ventas: " << cineConMasVentas.cantEntradasVendidas << endl;

    return 0;
}
