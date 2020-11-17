#include <iostream>
#include "..\..\Headers\vectores.hpp"
using namespace std;

int main()
{
    /*Apareo de arreglos*/
    //8_Clase 20/5
    /*Ejercicio 1*/
    /*
    int vecA[5] = { 3,7,9,14,20 }; //Ambos vectores deben estar ordenados
    int vecB[6] = { 2,5,10,11,25,30 };
    int vecC[11]; //Suma de ambos vectores, ordenado.
    int lenA = 5; //Cantidad maxima de elementos en el vector A
    int lenB = 6; //Cantidad maxima de elementos en el vector B
    int lenC = 0; //Cantidad maxima de elementos en el vector C Al comenzar el programa..
    int posA = 0;
    int posB = 0;
    int posC = 0;
    //Mientras que no se termine de recorrer uno de los dos vectores, itera
    while (posA < lenA && posB < lenB) {
        //Inserto el menor valor de ambos vectores
        if (vecA[posA] < vecB[posB]) {
            agregar(vecC, 11, lenC, vecA[posA]);
            posA++;
        }
        else {
            agregar(vecC, 11, lenC, vecB[posB]);
            posB++;
        }
        //Una vez que agrego un elemento a C, tengo que aumentar la pos del vector de donde tome el valor
    }//Cuando termino el while, hay dos escenarios: 
    //Todavia quedan elementos de A
    while (posA < lenA) {
        agregar(vecC, 11, lenC, vecA[posA]);
        posA++;
    }
    //O todavia quedan elementos del vector B
    while (posB < lenB) {
        agregar(vecC, 11, lenC, vecB[posB]);
        posB++;
    }
    //En ambos escenarios tengo que poner todos los valores restantes del vector
    mostrar(vecC, lenC);
    */
    /*Ejercicio 2*/
    /*
    estudianteAED curso1[10] = { {1234,"Perez",8},{3456,"Lopez",7.5} };
    estudianteAED curso2[10] = { {2453,"Rodriguez",10},{2500,"Alvarez",9.5}, {5674,"Gonzales",6.5} };
    estudianteAED cursoConsolidado[20];
    int lenC1 = 2;
    int lenC2 = 3;
    int lenCo = 0;
    int posC1 = 0;
    int posC2 = 0;
    //Ordeno los estudiantes por nro de legajo
    while (posC1 < lenC1 && posC2 < lenC2) {
        if (curso1[posC1].legajo < curso2[posC2].legajo) {
            agregarEstudianteAED(cursoConsolidado, 20, lenCo, curso1[posC1]);
            posC1++;
        }
        else {
            agregarEstudianteAED(cursoConsolidado, 20, lenCo, curso2[posC2]);
            posC2++;
        }
    }
    while (posC1 < lenC1) {
        agregarEstudianteAED(cursoConsolidado, 20, lenCo, curso1[posC1]);
        posC1++;
    }
    while (posC2 < lenC2) {
        agregarEstudianteAED(cursoConsolidado, 20, lenCo, curso2[posC2]);
        posC2++;
    }
    mostrarEstudianteAED(cursoConsolidado, lenCo);
    */
    /*Corte de control en arreglos*/
    /*Ejercicio 1*/
    /*
     estudiantePA vecPA[8000] ={
        {123,"Perez","Discreta",6},
        {123,"Perez","Analisis",7.5},
        {123,"Perez","AED",8},
        {100,"Lopez","Algebra",9},
        {100,"Lopez", "AED",10},
        {100, "Lopez","Arq",8.5},
        {540,"Rodriguez","IngYSoc",9.5},
        {540,"Rodriguez","Quimica",7}
     };
     int lenPA = 8;
     int posPA = 0;
     float promedioPorEstudiante;
     float sumaNotasPorEstudiante;
     int cantNotasPorEstudiante;
     // Inicializar todas las variables que me sirvan para el procesamiento global de los datos. Por ejemplo: Mejor Promedio 
     float maxPromedio = 0;
     int legajoMaxPromedio;
     while(posPA < lenPA) {
       // Inicializar todas las variables que me sirvan para el procesamiento de cada lote de datos. Por ejemplo: Promedio de cada estudiante
       int legajoAnterior = vecPA[posPA].legajo;
       promedioPorEstudiante = 0;
       sumaNotasPorEstudiante = 0;
       cantNotasPorEstudiante = 0;
       //Proceso cada lote de datos (misma clave)
       //Mientras sea el mismo legajo y el vector tenga elementos
       while(vecPA[posPA].legajo == legajoAnterior && posPA < lenPA) {
         sumaNotasPorEstudiante += vecPA[posPA].notaFinal;
         cantNotasPorEstudiante ++;
         posPA++;
       }
       // Voy a informar (mostrar por pantalla) todo lo relacionado a el procesamiento de cada lote de datos. Por ejemplo: Promedio de cada estudiante
       promedioPorEstudiante = sumaNotasPorEstudiante/cantNotasPorEstudiante;
       cout << "El promedio del estudiante nroLegajo: " << legajoAnterior << endl; 
       cout << promedioPorEstudiante << endl;
       lineaSeparatoria();
       //proceso los datos globales. Por ejemplo: Mejor Promedio
       if(promedioPorEstudiante > maxPromedio) {
         maxPromedio = promedioPorEstudiante;
         legajoMaxPromedio = legajoAnterior;
       }
     }
     //Voy a informar (mostrar por pantalla) todo lo relacionado a el procesamiento global de los datos. Por ejemplo: Mejor Promedio
     cout << "El mejor promedio es: " << maxPromedio << " y pertenece a: " << legajoMaxPromedio << endl;
     */
}