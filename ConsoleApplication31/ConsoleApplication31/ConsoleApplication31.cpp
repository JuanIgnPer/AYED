#include "..\..\Headers\dinamica.hpp"
#include "..\..\Headers\vectores.hpp"
#include <iostream>

//InfoSublista
struct infoPeli {
    int codPeli;
    char nomPeli[50];
    int cantEntradas;
};
//Sublista
struct pelicula {
    infoPeli info;
    pelicula * sig;
};
//InfoLista
struct infoCine {
    int codCine;
    int cantEntradasVendidas;
    pelicula* peliculas;
};
//Lista
struct cine {
    infoCine info;
    cine* sig;
};
//Datos del archivo
struct datos {
    int codCine;
    int codPeli;
    char nomPeli[50];
    char fecha[20];
    int cantEntradasVendidas;
};

cine* buscarCine(cine* p, int v);
void agregarPeli(pelicula*& p, infoPeli x);
void agregarCine(cine*& p, infoCine x);
pelicula* buscarPeli(pelicula* p, int v);

void llenarArchivo();

//Recuperatorio 
int main()
{
    //
    llenarArchivo();

    FILE* archivoCine = fopen("cineOctubre2020.dat", "rb+");
    datos reg;
    cine* listaDeCines = NULL;

    //Voy leyendo el archivo y guardando los datos en la lista
    fread(&reg, sizeof(datos), 1, archivoCine);
    while (!feof(archivoCine)) {
        //Busco el cine en la lista
        cine* aux = buscarCine(listaDeCines, reg.codCine);

        if (aux == NULL) { //El cine no esta en la lista
            infoCine nuevoCine;
            nuevoCine.codCine = reg.codCine;
            nuevoCine.cantEntradasVendidas = reg.cantEntradasVendidas;
            //Al ser un nuevo cine, armo la sublista de peliculas y la pelicula
            pelicula* subListaPeliculas = NULL;
            infoPeli nuevaPeli;
            nuevaPeli.codPeli = reg.codPeli;
            nuevaPeli.cantEntradas = reg.cantEntradasVendidas;
            strcpy(nuevaPeli.nomPeli, reg.nomPeli);
            agregarPeli(subListaPeliculas, nuevaPeli);
            //Guardo la subLista de peliculas
            nuevoCine.peliculas = subListaPeliculas;
            //Agrego el nuevo cine a la lista de cines
            agregarCine(listaDeCines, nuevoCine);
        }
        else { //El cine si esta en la lista
            //Tengo que agregar los datos de la pelicula al cine
            //Busco si existe la pelicula en el cine
            pelicula* auxPeli = buscarPeli(aux->info.peliculas, reg.codPeli);
            
            if (auxPeli == NULL) { //La peli no esta en la sublista
                //Agrego la peli a la sublista
                infoPeli nuevaPeli;
                nuevaPeli.cantEntradas = reg.cantEntradasVendidas;
                nuevaPeli.codPeli = reg.codPeli;
                strcpy(nuevaPeli.nomPeli, reg.nomPeli);
                agregarPeli(aux->info.peliculas, nuevaPeli);
            }
            else { //La peli ya existia en la sublista
                //Actualizo la cantidad de entradas vendidas
                auxPeli->info.cantEntradas += reg.cantEntradasVendidas;
            }
            aux->info.cantEntradasVendidas += reg.cantEntradasVendidas;
        }

        fread(&reg, sizeof(datos), 1, archivoCine);
    }
    fclose(archivoCine);


    //Itero sobre la lista de cines
    cine* auxListaCine = listaDeCines;
    int cineMasVentas = 0;
    int cantMaxEntradas = 0;
    int cineMenosVentas = 0;
    int cantMinEntradas = 999999;
    int peliQueMasVendio = 0;
    int peliQueMenosVendio = 0;
    //Cine que vendio mas entradas -> cual fue la peli con menos entradas
    //Cine que vendio menos entradas -> cual fue la peli con mas entradas
    
    while (auxListaCine != NULL) {
        //Busco cine con mas ventas
        if (auxListaCine->info.cantEntradasVendidas > cantMaxEntradas) {
            cantMaxEntradas = auxListaCine->info.cantEntradasVendidas;
            cineMasVentas = auxListaCine->info.codCine;
            //Buscar peli con menos ventas

            pelicula* auxSubListaCine = auxListaCine->info.peliculas;
            while (auxSubListaCine != NULL) {
                if (auxSubListaCine->info.cantEntradas < cantMinEntradas) {
                    cantMinEntradas = auxSubListaCine->info.cantEntradas;
                    peliQueMenosVendio = auxSubListaCine->info.codPeli;
                }
                auxSubListaCine = auxSubListaCine->sig;
            }
        }
        //Busco cine con menos ventas
        if (auxListaCine->info.cantEntradasVendidas < cantMinEntradas) {
            cantMinEntradas = auxListaCine->info.cantEntradasVendidas;
            cineMenosVentas = auxListaCine->info.codCine;
            //Busco peli con mas ventas

            pelicula* auxSubListaCine = auxListaCine->info.peliculas;
            while (auxSubListaCine != NULL) {
                if (auxSubListaCine->info.cantEntradas > cantMaxEntradas) {
                    cantMaxEntradas = auxSubListaCine->info.cantEntradas;
                    peliQueMasVendio = auxSubListaCine->info.codPeli;
                }
                auxSubListaCine = auxSubListaCine->sig;
            }
        }
        auxListaCine = auxListaCine->sig;
    }

    cout << "El cine que mas entradas vendio es: " << cineMasVentas;
    cout << "  La peli que menos entradas vendio en ese cine es " << peliQueMenosVendio << endl;
    cout << "El cine que menos entradas vendio es: " << cineMenosVentas;
    cout << "  La peli que mas entradas vendio en ese cine es " << peliQueMasVendio << endl;
}

cine* buscarCine(cine* p, int v) {
    cine* aux = p;
    while (aux != NULL && aux->info.codCine != v) {
        aux = aux->sig;
    }
    return aux;
}
void agregarPeli(pelicula*& p, infoPeli x) {
    pelicula* nuevo = new pelicula();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (p == NULL) {
        p = nuevo;
    }
    else {
        pelicula* aux = p;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}
void agregarCine(cine*& p, infoCine x) {
    cine* nuevo = new cine();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (p == NULL) {
        p = nuevo;
    }
    else {
        cine* aux = p;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}
pelicula* buscarPeli(pelicula* p, int v) {
    pelicula* aux = p;
    while (aux != NULL && aux->info.codPeli != v) {
        aux = aux->sig;
    }
    return aux;
}

void llenarArchivo() {
    //LLeno el archivo con apuestas
    FILE* cine = fopen("cineOctubre2020.dat", "wb+");
    datos reg;

    reg.codCine = 1;
    reg.codPeli = 23;
    strcpy(reg.nomPeli, "IT 2 ");
    strcpy(reg.fecha, "15/09/2018");
    reg.cantEntradasVendidas = 100;
    fwrite(&reg, sizeof(datos), 1, cine);

    reg.codCine = 1;
    reg.codPeli = 23;
    strcpy(reg.nomPeli, "IT 2 ");
    strcpy(reg.fecha, "15/09/2018");
    reg.cantEntradasVendidas = 200;
    fwrite(&reg, sizeof(datos), 1, cine);

    rewind(cine);
    fread(&reg, sizeof(datos), 1, cine);
    while (!feof(cine)) {
        cout << reg.codCine << endl;
        cout << reg.codPeli << endl;
        cout << reg.nomPeli << endl;
        cout << reg.fecha << endl;
        cout << reg.cantEntradasVendidas << endl;
        cout << "_______________________________________" << endl;
        fread(&reg, sizeof(datos), 1, cine);
    }
    fclose(cine);
}