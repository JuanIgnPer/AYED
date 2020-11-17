#include <iostream>
#include "..\..\Headers\dinamica.hpp"

int main()
{
    cout << "Listas" << endl;

    /*
    Dada una lista, desarrollar una función que devuelva la cantidad de nodos que tiene. */
    cout << "----------------------------" << endl;
    cout << "Ejercicio 1" << endl;
    /*NodoEstudiante* lista = NULL;
    est datos;
    datos.legajo = 4451;
    strcpy(datos.nya, "pepe");
    datos.curso = 1053;
    agregarNodoEstudiante(lista, datos);

    datos.legajo = 153444;
    strcpy(datos.nya, "ale");
    datos.curso = 1051;
    agregarNodoEstudiante(lista, datos);

    datos.legajo = 654;
    strcpy(datos.nya, "vir");
    datos.curso = 1043;
    agregarNodoEstudiante(lista, datos);

    datos.legajo = 123444;
    strcpy(datos.nya, "facu");
    datos.curso = 1034;
    agregarNodoEstudiante(lista, datos);

    datos.legajo = 0;
    strcpy(datos.nya, "");
    datos.curso = 0;

    cout << "La lista tiene " << contarNodosLista(lista) << " nodos" << endl;
    while (lista != NULL) {
        cout << lista->info.legajo << endl;
        cout << lista->info.nya << endl;
        cout << lista->info.curso << endl;
        lista = lista->sig;
    }
    */

    /*Dadas dos listas LISTA y LISTB, desarrollar un procedimiento que genere una
    única lista LISTC a partir de ellas. (Primero los nodos de LISTA y luego los de
    LISTB).*/
    cout << "----------------------------" << endl;
    cout << "Ejercicio 2" << endl;
    /*
    NodoEstudiante* listaA = NULL;
    NodoEstudiante* listaB = NULL;
    NodoEstudiante* listaC = NULL;

    est datos;
    datos.legajo = 4451;
    strcpy(datos.nya, "pepe");
    datos.curso = 1053;
    agregarNodoEstudiante(listaA, datos);

    datos.legajo = 153444;
    strcpy(datos.nya, "ale");
    datos.curso = 1051;
    agregarNodoEstudiante(listaA, datos);

    datos.legajo = 654;
    strcpy(datos.nya, "vir");
    datos.curso = 1043;
    agregarNodoEstudiante(listaB, datos);

    datos.legajo = 123444;
    strcpy(datos.nya, "facu");
    datos.curso = 1034;
    agregarNodoEstudiante(listaB, datos);

    datos.legajo = 0;
    strcpy(datos.nya, "");
    datos.curso = 0;

    unirListasNoEliminandoNodos(listaA, listaB, listaC);
    //Posicion en memoria de cada lista
    //Si eliminamos el nodo, la direccion es 0
    cout << listaA << endl;
    cout << listaB << endl;
    cout << listaC << endl;

    while (listaC != NULL) {
        cout << listaC->info.legajo << endl;
        cout << listaC->info.nya << endl;
        cout << listaC->info.curso << endl;
        listaC = listaC->sig;
    }
    */


    /*Dada una LISTA, imprimirla en orden natural si tiene más de 100 nodos, caso
    contrario imprimirla en orden inverso.*/
    cout << "----------------------------" << endl;
    cout << "Ejercicio 3" << endl;
    /*
    NodoEstudiante* lista = NULL;
    est datos;
    datos.legajo = 4451;
    strcpy(datos.nya, "pepe");
    datos.curso = 1053;
    agregarNodoEstudiante(lista,datos);

    datos.legajo = 153444;
    strcpy(datos.nya, "ale");
    datos.curso = 1051;
    agregarNodoEstudiante(lista,datos);

    datos.legajo = 654;
    strcpy(datos.nya, "vir");
    datos.curso = 1043;
    agregarNodoEstudiante(lista,datos);

    datos.legajo = 123444;
    strcpy(datos.nya, "facu");
    datos.curso = 1034;
    agregarNodoEstudiante(lista,datos);

    for(int i=0; i< 100; i++){
        datos.legajo = i;
        strcpy(datos.nya, "pepe");
        datos.curso = 1053;
        agregarNodoEstudiante(lista,datos);
    }

    datos.legajo = 0;
    strcpy(datos.nya,"");
    datos.curso = 0;

    imprimirLista(lista);
    */

    /*Dadas dos listas LISTA y LISTB, desarrollar un procedimiento que genere otra
    lista LISTC por apareo del campo LEGAJO del registro (define orden creciente
    en ambas).
    Nota: LISTA y LISTB dejan de ser útiles después del apareo.*/
    cout << "----------------------------" << endl;
    cout << "Ejercicio 4" << endl;
    /*
    NodoEstudiante* listaA = NULL;
    NodoEstudiante* listaB = NULL;
    NodoEstudiante* listaC = NULL;

    est datos;
    datos.legajo = 4451;
    strcpy(datos.nya, "pepe");
    datos.curso = 1053;
    agregarNodoEstudiante(listaA, datos);

    datos.legajo = 153444;
    strcpy(datos.nya, "ale");
    datos.curso = 1051;
    agregarNodoEstudiante(listaA, datos);

    datos.legajo = 654;
    strcpy(datos.nya, "vir");
    datos.curso = 1043;
    agregarNodoEstudiante(listaB, datos);

    datos.legajo = 123444;
    strcpy(datos.nya, "facu");
    datos.curso = 1034;
    agregarNodoEstudiante(listaB, datos);

    apareoListasSinEliminarNodo(listaA, listaB, listaC);

    while (listaC != NULL) {
        cout << listaC->info.legajo << endl;
        cout << listaC->info.nya << endl;
        cout << listaC->info.curso << endl;
        listaC = listaC->sig;
    }
    */

    /*Dado un archivo de registros de estudiantes (ARCHA). Se debe desarrollar el
    programa que genere un archivo ARCHL igual al anterior pero ordenado por
    número de legajo.*/
    cout << "----------------------------" << endl;
    cout << "Ejercicio 5" << endl;
    //Archivo con X registros -> vector
    //Archivos con registros desconocidos-> listas 
    //Pilas y colas NO SE RECORREN

    //Creo archivo desordenado
    /*
    FILE* archa = fopen("archa.dat", "wb+");

    est datos;
    datos.legajo = 153444;
    strcpy(datos.nya, "pepe");
    datos.curso = 1053;
    fwrite(&datos, sizeof(est), 1, archa);

    datos.legajo = 4451;
    strcpy(datos.nya, "ale");
    datos.curso = 1051;
    fwrite(&datos, sizeof(est), 1, archa);

    datos.legajo = 123444;
    strcpy(datos.nya, "vir");
    datos.curso = 1043;
    fwrite(&datos, sizeof(est), 1, archa);

    datos.legajo = 654;
    strcpy(datos.nya, "facu");
    datos.curso = 1034;
    fwrite(&datos, sizeof(est), 1, archa);

    rewind(archa);
    fread(&datos, sizeof(est), 1, archa);
    while (!feof(archa)) {
        cout << datos.legajo << endl;
        cout << datos.nya << endl;
        cout << datos.curso << endl;
        fread(&datos, sizeof(est), 1, archa);
    }

    fclose(archa);
       */

    //Leo el archivo generado
    /*FILE* archa = fopen("archa.dat", "rb");
    est reg;
    NodoEstudiante* lista = NULL;
    //Guardo todos los datos del archivo en una lista
    fread(&reg, sizeof(est), 1, archa);
    while (!feof(archa)) {
        insertarOrdenadoEstudiante(lista, reg);
        fread(&reg, sizeof(est), 1, archa);
    }
    fclose(archa);

    //Abro el archivo nuevo, y escribo en orden desde la lista
    FILE* archl = fopen("archl.dat", "ab+");
    NodoEstudiante* aux = lista;
    while (aux != NULL) {
        fwrite(&aux->info, sizeof(est), 1, archl);
        aux = aux->sig;
    }

    //Muestro los estudiantes por pantalla
    rewind(archl);
    fread(&reg, sizeof(est), 1, archl);
    while (!feof(archl)) {
        cout << reg.legajo << endl;
        cout << reg.nya << endl;
        cout << reg.curso << endl;
        fread(&reg, sizeof(est), 1, archl);
    }

    fclose(archl);
    */
}
