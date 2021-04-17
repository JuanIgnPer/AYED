
#include <string>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/*7_Clase 13/05*/
/*Ejercicio 1*/
//struct pais {
//	string nombre;
//	int velocidadMax;
//	int velocidadMin;
//};
/*Ejercicio 2*/
//struct nota {
//	int codigo;
//	int cantidadAlumnos;
//};
/*Ejercicio 3*/
//struct producto {
//	int codigo;
//	string nombre;
//	float precio;
//	int stock;
//};
/*Ejercicio 4*/
//struct estudiante {
//	int legajo;
//	string nombre;
//	float nota;
//};


/*8_Clase20/05*/
/*Ejercicio 2*/
//struct estudianteAED {
//	int legajo;
//	string apellido;
//	float promedio;
//};
/*Ejercicio 3*/
//struct estudiantePA {
//	int legajo;
//	string nya;
//	string materia;
//	float notaFinal;
//};


/*9_Clase27/05*/
/*Ejercicio 1 - Corte de control con arreglos*/
//struct sucursal {
//	int sucursal;
//	int dia;
//	float dineroRecaudado;
//};
/*Ejercicio 2 - Apareo con archivos*/
//struct claustro {
//	int legajo;
//	char nombre[50];
//};
//struct claustroConsolidado {
//	claustro claustro;
//	char descripcionClaustro[50];
//};
/*Ejercicio 1 - Corte de control con archivos*/
//struct venta {
//	int codArt;
//	int cantVendida;
//	float precioUnitario;
//};
/*Ejercicio 2 - Corte de control con archivos*/
//struct notaEstudiante {
//	int legajo;
//	char materia[50];
//	float nota;
//};


/*11_Clase10/06*/
/*Ejercicio 1 - Apareo de archivos*/
//struct articulo {
//	int nroArt;
//	char descripcion[50];
//	int cantidad;
//};
/*Ejercicio 2 - Apareo de archivos*/
//struct articuloDeposito {
//	articulo art;
//	char deposito[25];
//};


/*14_Clase01/07*/
/*Ejercicio 1 - Apareo de vectores hacia Archivo*/
//struct estudiante {
//	int legajo;
//	char nombre[50];
//	char mail[100];
//};
//struct estudianteListado {
//	estudiante est;
//	char curso[20];
//};
/*Ejercicio 2 - Corte de control de archivo*/
//struct venta {
//	int nroCli;
//	char artComprado[50];
//	int cantComprada;
//	float precioUni;
//};
/*Ejercicio 3 - Combinado*/
//struct listaDePrecios {
//	int codigoArt;
//	float precioUnitario;
//};
//struct stock {
//	int nroArt;
//	int cantUnidades;
//	int posListaDePrecios;
//};
//struct cabecera {
//	int idFactura;
//	int fecha;
//	int nroCliente;
//	float totalFactura;
//};
//struct detalle {
//	int idFactura;
//	int nroArticulo;
//	int cant;
//	float precioUnitario;
//	float totalArticulo;
//};

/*16_Clase15/07*/
/*Ejercicio 1*/
//struct pelicula {
//	int idPeli;
//	char nombrePeli[50];
//	int cantEsp;
//};
//struct peliculaFDS {
//	char nombrePeli[50];
//	int cantEsp;
//};

#ifndef vectores
#define vectores
//n -> cantidad de elementos totales que puede almacenar el vector
//len -> cantidad de elementos reales que hay en el vector
//En los parciales se pueden usar estos metodos cambiando el tipo de dato que esperan
//Generales -> Revisar

/*
Llena el vector con "0" desde la primer posicion hasta la pasada por parametro - 1
*/
void inicializar(int vec[], int n);
/*
Primera iteracion -> vector vacío -> len = 0
 llamo a agregar -> inserto valor en pos O  -> len = 1
 Segunda iteración -> len = 1
 llamo a agregar -> inserto valor en pos 1 -> len = 2
 Agrego un valor en el vector, solamente si el vector tiene espacio
 Que tenga espacio significa que es menor el len a n*/
void agregar(int arr[], int n, int& len, int v);
/*
Muestro cada elemento de un array y/o atributos de cada struct
*/
void mostrar(int arr[], int len);
/*
Busca la posicion de un elemento pasado como argumento, o -1 si no lo encuentra
*/
int buscar(int arr[], int len, int v);
/* 
Elimina un valor que esta en una posicion pasada por parametro
El valor se elimina cuando asigno un nuevo valor, en este caso el siguiente en el vector
El actual es igual al siguiente => {6,7,8} eliminar(1) => {6,8,8}-{6,8,0} 
*/
void eliminar(int arr[], int& len, int pos);
/*
El siguiente es igual al actual, yendo de mayor a menor
Luego asigno el valor a la posicion que quedo libre
*/
void insertar(int arr[], int& len, int v, int pos);
/*
Busco el valor que sea menor dentro del vector, 
llamo a insertar e inserta en esa posicion
*/
int insertarOrdenado(int arr[], int& len, int v);
/*
Si no encuentra el valor en el vector, lo inserta ordenado
*/
int buscaEInserta(int arr[], int& len, int v, bool& enc);
/*
Busca el valor minimo en un vector
*/
int buscarMinimo(int vec[], int len);
void lineaSeparatoria();


/*7_Clase 13/05*/
/*Ejercicio 1*/
//int buscarMaximaVelocidad(pais vec[], int len, int& pos);
//int buscarMinimaVelocidad(pais vec[], int len, int& pos);
//float sacarPromedioVelocidadMaxima(pais vec[], int len);
/*Ejercicio 2*/
//int buscarMaxInscriptos(nota vec[], int len);
//int buscarMinInscriptos(nota vec[], int len);
//float sacarPromedioInscriptos(nota vec[], int len);
/*Ejercicio 3*/
//void imprimirMenu();
//void agregarProducto(producto arr[], int n, int& len, producto productoAGuardar);
//void mostrarProducto(producto arr[], int len);
//int buscarProducto(producto arr[], int len, string nombre);
/*Ejercicio 4*/
//void imprimirMenuNotas();
//int buscarEstudiante(estudiante arr[], int len, int legajo);
//void mostrarEstudiante(estudiante est);
//float promedioEstudiantes(estudiante arr[], int len);
//int buscarMejorNota(estudiante vec[], int len);
//int buscarMenorNota(estudiante vec[], int len);


/*8_Clase 20/05*/
/*Ejercicio 2*/
//void agregarEstudianteAED(estudianteAED arr[], int n, int& len, estudianteAED v);
//void mostrarEstudianteAED(estudianteAED arr[], int len);


/*9_Clase 27/5*/
/*Ejercicio 2 - Apareo con archivos*/
//void insertarClaustro(claustroConsolidado arr[], int& len, claustroConsolidado v, int pos);
//int insertarOrdenadoClaustro(claustroConsolidado arr[], int& len, claustroConsolidado v);


/*10_Clase03/06*/
/*Recursividad*/
//int factorial(int numero);
//int potencia(int base, int exp);
//int divisionNatural(int dividendo, int divisor);
//int fibonacci(int n);


/*12_Clase17/06*/
//void burbuja(int vec[], int len);
/*
El primer elemento se lo considera ordenado; es decir que se considera como un
vector de un solo elemento. Luego se van insertando los demás elementos en la
posición correcta, según sea mayor o menor.
*/
//void insercion(int vec[], int len);
/* 
Se debe encontrar el mínimo elemento del vector y ponerlo al principio. 
En el viejo lugar del mínimo elemento, se coloca el elemento desplazado. 
El algoritmo mantiene dos subvectores, uno ordenado y otro desordenado.
*/
//void seleccion(int vec[], int len);

/*13_Clase24/06*/
//int busquedaSecuencial(int vec[], int len, int valorBuscado);
//int busquedaBinaria(int vec[], int len, int valorBuscado);

/*14_Clase01/07*/
/*Ejercicio 3 - Combinado*/
//void imprimirCabeceras(FILE* cabeceraArch, cabecera regCabecera);
//void imprimirDetalles(FILE* detalleArch, detalle regDetalle);
//int busquedaSecuencial(stock vec[], int len, int valorBuscado);

/*16_Clase15/07*/
//int busquedaSecuencial(pelicula vec[], int len, int valorBuscado);
//void burbuja(pelicula vec[], int len);
#endif