#include "..\..\Headers\dinamica.hpp"
#include <iostream>

int main()
{
    /*EJ 1 - Arboles*/
    /*
    Arbol* raiz = NULL;
    insertarNodoEnArbol(raiz, 15);
    insertarNodoEnArbol(raiz, 6);
    insertarNodoEnArbol(raiz, 20);
    insertarNodoEnArbol(raiz, 3);
    insertarNodoEnArbol(raiz, 9);
    insertarNodoEnArbol(raiz, 18);
    insertarNodoEnArbol(raiz, 24);
    insertarNodoEnArbol(raiz, 1);
    insertarNodoEnArbol(raiz, 4);
    insertarNodoEnArbol(raiz, 7);
    insertarNodoEnArbol(raiz, 12);
    insertarNodoEnArbol(raiz, 17);
    insertarNodoEnArbol(raiz, 12);


    cout << "PreOrden" << endl;
    preOrden(raiz);
    cout << "----------------" << endl;
    cout << "InOrden" << endl;
    inOrden(raiz);
    cout << "----------------" << endl;
    cout << "PostOrden" << endl;
    postOrden(raiz);
    */

    /*EJ 2*/
    //Vacio la matriz
    Sospechoso* matSospe[4][9];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            matSospe[i][j] = NULL;
        }
    }
    //Genero archivo, lo lleno con los datos de "huella"
    /*
    FILE* arch = fopen("huellas.dat", "wb+");
    huella reg;

    strcpy(reg.apeNom, "Pepito");
    reg.dni = 36789567;
    reg.dedo = 5;
    reg.tipo = 1;
    reg.subtipo = 1;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Pepito");
    reg.dni = 36789567;
    reg.dedo = 6;
    reg.tipo = 1;
    reg.subtipo = 7;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Pepito");
    reg.dni = 36789567;
    reg.dedo = 8;
    reg.tipo = 2;
    reg.subtipo = 7;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Pepito");
    reg.dni = 36789567;
    reg.dedo = 10;
    reg.tipo = 3;
    reg.subtipo = 3;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Pepito");
    reg.dni = 36789567;
    reg.dedo = 1;
    reg.tipo = 3;
    reg.subtipo = 3;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Pepito");
    reg.dni = 36789567;
    reg.dedo = 2;
    reg.tipo = 4;
    reg.subtipo = 6;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Natalia");
    reg.dni = 35358428;
    reg.dedo = 6;
    reg.tipo = 1;
    reg.subtipo = 7;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Natalia");
    reg.dni = 35358428;
    reg.dedo = 8;
    reg.tipo = 3;
    reg.subtipo = 3;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Natalia");
    reg.dni = 35358428;
    reg.dedo = 10;
    reg.tipo = 4;
    reg.subtipo = 9;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Natalia");
    reg.dni = 35358428;
    reg.dedo = 2;
    reg.tipo = 2;
    reg.subtipo = 7;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Natalia");
    reg.dni = 35358428;
    reg.dedo = 7;
    reg.tipo = 2;
    reg.subtipo = 9;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Lucas");
    reg.dni = 33789567;
    reg.dedo = 1;
    reg.tipo = 1;
    reg.subtipo = 7;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Lucas");
    reg.dni = 33789567;
    reg.dedo = 2;
    reg.tipo = 4;
    reg.subtipo = 6;
    fwrite(&reg, sizeof(huella), 1, arch);
       
    strcpy(reg.apeNom, "Lucas");
    reg.dni = 33789567;
    reg.dedo = 4;
    reg.tipo = 3;
    reg.subtipo = 3;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Lucas");
    reg.dni = 33789567;
    reg.dedo = 6;
    reg.tipo = 2;
    reg.subtipo = 3;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Lucas");
    reg.dni = 33789567;
    reg.dedo = 9;
    reg.tipo = 1;
    reg.subtipo = 1;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Karina");
    reg.dni = 40789278;
    reg.dedo = 6;
    reg.tipo = 3;
    reg.subtipo = 6;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Karina");
    reg.dni = 40789278;
    reg.dedo = 8;
    reg.tipo = 2;
    reg.subtipo = 5;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Karina");
    reg.dni = 40789278;
    reg.dedo = 10;
    reg.tipo = 4;
    reg.subtipo = 3;
    fwrite(&reg, sizeof(huella), 1, arch);

    strcpy(reg.apeNom, "Karina");
    reg.dni = 40789278;
    reg.dedo = 1;
    reg.tipo = 1;
    reg.subtipo = 7;
    fwrite(&reg, sizeof(huella), 1, arch);   

    fclose(arch);
    */

    //Resuelvo - Solo inserta el primer dedo al momento de agregar, esperar a que lo resolvamos en clase
    FILE * arch = fopen("huellas.dat", "rb+");
    cargarMatrizSospechosos(matSospe, arch);
    emitirSospechosos(matSospe, 1, 7);

    fclose(arch);
    
}
