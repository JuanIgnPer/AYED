
#include <string>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/*16 Clase 15/07*/
struct Nodo {
	int info;
	Nodo* sig;
};
/*17 Clase 22/07*/
struct NodoInv {
	char info;
	NodoInv* sig;
};
/*18 Clase 26/08*/
struct NodoEst {
	string info;
	NodoEst* sig;
};
struct est {
	int legajo;
	char nya[50];
	int curso;
};
struct NodoEstudiante {
	est info;
	NodoEstudiante* sig;
};
/*22 Clase 23/9*/
struct planta {
	int piso;
	int suben;
	int bajan;
};
struct NodoAscensor {
	planta info;
	NodoAscensor* arriba;
	NodoAscensor* abajo;
};
struct pisoEliminado {
	int piso;
	int diffEntreSubenYBajan;
};
/*23 Clase 30/9*/
struct Nota {
	int nota;
	Nota* sig;
};
struct infoestudiante {
	int id;
	Nota* notas[4];
};
struct Estudiante {
	infoestudiante infoEst;
	Estudiante* sigEst;
};
struct infocurso {
	int id;
	int promocionados;
	int regularizados;
	int recursantes;
	Estudiante* listaEstudiantes;
};
struct Curso {
	infocurso infoCur;
	Curso* sigCur;
};
struct novedad {
	int idCurso;
	int idEstudiante;
	int nroEvaluacion;
	int nota;
};
/*24 Clase 7/10*/
struct venta {
	int nroCliente;
	char articulo[50];
	int cant;
	float precioUnitario;
};
struct infoArt {
	char articulo[50];
	int cantidad;
	float precioUnitario;
};
struct Articulo {
	infoArt info;
	Articulo* sig;
};
struct infoCliente {
	int nroCliente;
	float dineroGastado;
	Articulo* articulosComprados;
};
struct Cliente {
	infoCliente info;
	Cliente* sig;
};
/*24 Clase 7/10 - EJ2*/
struct ingreso {
	int nroSocio;
	int nroSucursal;
	int estadia;
};
struct infoSocio {
	int nroSocio;
	int cantVisitas;
	int estadiaTotal;
};
struct Socio {
	infoSocio info;
	Socio* sig;
};
struct infoSuc {
	int nroSucusal;
	int cantPersonasDistintas;
	int cantVisitas;
	Socio* listaSocios;
};
struct Sucursal {
	infoSuc info;
	Sucursal* sig;
};
/*26 Clase 28/10*/
/*EJ 1*/
struct Arbol {
	Arbol* izq;
	int info;
	Arbol* der;
};
/*EJ 2*/
struct huella {
	int dni;
	char apeNom[50];
	int dedo;
	int tipo;
	int subtipo;
};
struct Dedo {
	int nroDedo;
	Dedo* sig;
};
struct infoSospe {
	int dni;
	char apeNom[50];
	Dedo* dedos;
};
struct Sospechoso {
	infoSospe info;
	Sospechoso* sig;
};

/*27 Clase 4/11*/
/*Ej 1*/
struct infoConver {
	int idConversacion;
	string nombre;
	bool vistaPrevia;
	bool notificar;
};
struct Conversacion {
	infoConver info;
	Conversacion* sgte;
};
struct contacto {
	int idUsuario;
	string nombreContacto;
	bool bloqueado;
};
/*Ej 2*/
struct candidato {
	string nombre;
	int lista;
};
struct resultado {
	candidato cand;
	float pos;
};

#ifndef dinamica
#define dinamica
/*16 Clase 15/07*/

//Listas

/*Agrega un nodo al final de la lista, o al principio si esta vacia
*/
void agregarNodo(Nodo*& p, int x);
/*La función mostrar recorre la lista p y muestra por pantalla el valor que contienen cada
uno de sus nodos.*/
void mostrar(Nodo* p);
/*La función liberar recorre la lista p liberando la memoria que ocupan cada uno de sus
nodos.*/
void liberar(Nodo*& p);
/*La función buscar permite determinar si alguno de los nodos de la lista p contiene el
valor v.
Retorna un puntero al nodo que contiene dicho valor o NULL si ninguno de los nodos
lo contiene.*/
Nodo* buscar(Nodo* p, int v);
/*La función eliminar permite eliminar de la lista p al nodo que contiene el valor v.
*/
void eliminar(Nodo*& p, int v);
/*La función eliminarPrimerNodo elimina el primer nodo de la lista y retorna el valor que
este contenía.*/
int eliminarPrimerNodo(Nodo*& p);
/*La función insertarOrdenado permite insertar el valor v respetando el ctriterio de
ordenamiento de la lista p; se presume que la lista está ordenada o vacía.Retorna la
dirección de memoria del nodo insertado.*/
Nodo* insertarOrdenado(Nodo*& p, int v);
/*La función ordenar ordena la lista direccionada por p.La estrategia consiste en
eliminar uno a uno los nodos de la lista e insertarlos en orden en una lista nueva;
finalmente hacer que p apunte a la nueva lista.*/
void ordenar(Nodo*& p);
/*La función buscaEInsertaOrdenado busca el valor v en la lista p.Si no lo encuentra
entonces lo inserta respetando el criterio de ordenamiento.Retorna un puntero al
nodo encontrado o insertado y asigna el valor true o false al parámetro enc según
corresponda.*/
Nodo* buscaEInsertaOrdenado(Nodo*& p, int v, bool& enc);

/*17 Clase 22/7*/

/*Pilas*/
void push(Nodo*& p, int v);
int pop(Nodo*& p);
/*Colas*/
void encolar(Nodo*& cFte, Nodo*& cFIN, int v);
int desencolar(Nodo*& cFte, Nodo*& cFin);

/*Ejercicio 1 - Pilas*/
void eliminarLosDosPrimerosNodos(Nodo*& pila, int x);
/*Ejercicio 2 - Pilas*/
void colocarEnTercerLugar(Nodo*& pila, int x, char& exitoso);
/*Ejercicio 3 - Pilas*/
void colocarEnPosicionYLugar(Nodo*& pila, int x,int y, char& exitoso);
/*Ejercicio 4 - Pilas*/
void reemplazarXporY(Nodo*& pila, int x, int y);
/*Ejercicio 5 - Pilas*/
bool inversa(NodoInv*& colaFte, NodoInv*& colaFin);
void encolarInv(NodoInv*& cFte, NodoInv*& cFIN, int v);
int desencolarInv(NodoInv*& cFte, NodoInv*& cFin);
/*Ejercicio 6 - Pilas*/
void imprimirApellidosOrdenInverso();
/*Ejercicio 7 - Pilas*/
void ordenarPila(Nodo*& pila);


/*Ejercicio 1 - Colas*/
void encolarEstudiante(NodoEstudiante*& cFte, NodoEstudiante*& cFin, est v);
est desencolarEstudiante(NodoEstudiante*& cFte, NodoEstudiante*& cFin);
char eliminarNodos(NodoEstudiante*& cfte, NodoEstudiante*& cfin, int cantNodosAEliminar);
/*Ejercicio 2 - Colas*/
void agregarNodoEstudiante(NodoEstudiante*& p, est x);
int contarNodos(NodoEstudiante*& cfte, NodoEstudiante*& cfin);
/*Ejercicio 3 - Colas*/
void unirColas(NodoEstudiante*& cfteA, NodoEstudiante*& cfinA, NodoEstudiante*& cfteB, NodoEstudiante*& cfinB, NodoEstudiante*& cfteC, NodoEstudiante*& cfinC);
/*Ejercicio 4 - Colas*/
void pushEstudiante(NodoEstudiante*& p, est v);
est popEstudiante(NodoEstudiante*& p);
void imprimirCola(NodoEstudiante*& cfte, NodoEstudiante*& cfin);
/*Ejercicio 5 - Colas*/
void apareo(NodoEstudiante*& cfteA, NodoEstudiante*& cfinA, NodoEstudiante*& cfteB, NodoEstudiante*& cfinB, NodoEstudiante*& cfteC, NodoEstudiante*& cfinC);

/*Ejercicio 1 - Listas*/
//Recorre una lista y devuelve la cantidad de nodos que tiene
int contarNodosLista(NodoEstudiante* lista);
/*Ejercicio 2 - Listas*/
void unirListasEliminandoNodos(NodoEstudiante*& listaA, NodoEstudiante*& listaB, NodoEstudiante*& listaC);
void unirListasNoEliminandoNodos(NodoEstudiante* listaA, NodoEstudiante* listaB, NodoEstudiante*& listaC);
/*Ejercicio 3 - Listas*/
//Dada una lista de estudiantes, muestra los datos de cada uno
void mostrarEstudiante(NodoEstudiante* p);
//Imprime los datos de una lista en orden natural si tiene mas de 100 nodos, si no en orden inverso
void imprimirLista(NodoEstudiante* lista);
/*Ejercicio 4 - Listas*/
void apareoListas(NodoEstudiante*& listaA, NodoEstudiante*& listaB, NodoEstudiante*& listaC);
void apareoListasSinEliminarNodo(NodoEstudiante* listaA, NodoEstudiante* listaB, NodoEstudiante*& listaC);
/*Ejercicio 5 - Listas*/
NodoEstudiante* insertarOrdenadoEstudiante(NodoEstudiante*& p, est v);


/*Ejercicio 1 - Pilas*/
/*Tecnicamente un char es un int...*/
void pushChar(Nodo*& p, char v);
char popChar(Nodo*& p);
/*Recibe un vector de chars y su len, devuelve si esta "balanceado" en terminos de '{[('*/
bool estaBalanceado(char vec[], int len);
/*Ejercicio 2 - Pilas*/
int calculoPolacaInversa(char vec[], int len);
/*Ejercicio 3 - Pilas*/
//Imito el comportamiento de una pila usando un array
void pushUsandoArray(char vecPila[], int& len, char valor);
//Imito el comportamiento de una pila usando un array 
char popUsandoArray(char vecPila[], int& len);
//Imito el comportamiento de una pila usando una cola
char popUsandoCola(Nodo*& colafte, Nodo*& colafin);
//Imito el comportamiento de una pila usando una cola
void pushUsandoCola(Nodo*& colafte, Nodo*& colafin, char valor);

/*Ejercicio 1 - Colas*/
void encolarUsandoLista(Nodo*& lista, int v);
int desencolarUsandoLista(Nodo*& lista);
/*Ejercicio 2 - Colas*/
void encolarUsandoArray(int vec[], int &len, int v);
int desencolarUsandoArray(int vec[], int &len);
/*Ejercicio 3 - Colas*/
void encolarUsandoPila(Nodo* &pila, int v);
int desencolarUsandoPila(Nodo* &pila);

/*Listas Doblemente Enlazadas - Final 1*/ 
//Inserta unNuevoPiso arriba de unPisoActual, calcula cuantos pisos separan a unNuevoPiso del piso mas bajo, mas alto y de la planta baja. Retorna distancia a la planta baja(0), el resto por referencia
int insertarPisoArribaDelActualYMedir(NodoAscensor* &unNuevoPiso, NodoAscensor* &unPisoActual, int &distanciaPlantaMasAlta, int &distanciaPlantaMasBaja);
//Dado un piso, retorna por referencia la distancia al piso mas alto y la distancia al piso mas bajo.
void medirDistanciaAPisosExtremos(NodoAscensor* unPiso, int& distanciaPlantaBaja, int& distanciaPlantaAlta);


/*22 Clase 23/9*/
/*Listas Doblemente Enlazadas - Final 2*/
//Agrega un nodo en una lista enlazada en la parte mas "arriba" de la lista
void agregarNodoListaDoble(NodoAscensor* &lista, planta v);
int eliminarLosPisosPrimosArribaDe(NodoAscensor* &unPisoActual, FILE* arch);
int esPrimo(int numero);
//Elimina el piso pasado por parametro, enlazando con sus nodos arriba y abajo
void eliminarPiso(NodoAscensor*& unPiso);


/*23 Clase 30/9*/
void agregarNota(Nota*& p, int x);
Estudiante* buscaEInsertaEstudiante(Estudiante*& p, infoestudiante v, bool& enc);
Estudiante* buscarEstudiante(Estudiante* p, infoestudiante v);
Estudiante* agregarEstudiante(Estudiante*& p, infoestudiante x);
Curso* buscaEInsertaCurso(Curso*& p, infocurso v, bool& enc);
//Recorro la lista de cursos y retorno el nodo que estoy buscando
Curso* buscarCurso(Curso* p, infocurso v);
//Agrega el curso a la lista 
Curso* agregarCurso(Curso*& p, infocurso x);
//Agrega la nota En el curso->estudiante->notas->nota correspondiente
void agregarNota(Curso*& listaCursos, int idCurso, int idEstudiante, int nroEvaluacion, int nota);
//Se le pasa un archivo, y una lista de cursos. Lee el archivo y carga las novedades en la lista de cursos
void procesarNovedades(FILE* novedades, Curso*& listaCursos);
//Arma la lista de notas de cada estudiante, para pasarselas a getEstado()
void calcularEstadisticas(Curso* listaCursos);
//notas tiene la ultima nota de c/evaluacion - Retorna  el estado del estudiante basado en las notas
int getEstado(int notas[], int len);

/*24 Clase 07/10*/
Articulo* buscarArticulo(Articulo* p, infoArt v);
Articulo* agregarArticulo(Articulo*& p, infoArt x);
Articulo* buscaEInsertaArticulo(Articulo*& p, infoArt v, bool& enc);
//Busca un cliente en una lista, si lo encuentra retorna el nodo, si no lo encuentra retorna NULL.
Cliente* buscarCliente(Cliente* p, infoCliente v);
//Inserta el cliente en la lista pasada por parametro.
Cliente* agregarCliente(Cliente*& p, infoCliente x);
//Busca si existe el cliente en la lista, si existe lo inserta. En ambos casos retorna el nodo.
Cliente* buscaEInsertaCliente(Cliente*& p, infoCliente v, bool& enc);

Socio* buscarSocio(Socio* p, infoSocio v);
Socio* agregarSocio(Socio*& p, infoSocio x);
Socio* buscaEInsertaSocio(Socio*& p, infoSocio v, bool& enc);
Sucursal* buscarSucursal(Sucursal* p, infoSuc v);
Sucursal* agregarSucursal(Sucursal*& p, infoSuc x);
Sucursal* buscaEInsertaSucursal(Sucursal*& p, infoSuc v, bool& enc);

/*26 Clase 28/10*/
/*EJ 1*/
void insertarNodoEnArbol(Arbol*& raiz, int valor);
void preOrden(Arbol*& raiz);
void inOrden(Arbol*& raiz);
void postOrden(Arbol*& raiz);
/*EJ 2*/
void emitirSospechosos(Sospechoso* matSospe[4][9], int tipo, int subtipo);
//Carga una matriz con los datos de un archivo 
void cargarMatrizSospechosos(Sospechoso* matSospe[4][9], FILE* arch);
void agregarDedo(Dedo*& lista, int x);
Sospechoso* insertarSospechosoOrdenado(Sospechoso*& p, infoSospe v);
Sospechoso* buscarEInsertaSospechoso(Sospechoso*& lista, infoSospe v, bool& enc);
//Busca un sospechoso dentro de una lista, utilizando el dni
Sospechoso* buscarSospechoso(Sospechoso* lista, infoSospe v);

/*27 Clase 4/11*/
/*EJ 1*/
void emitirNotificacion(string titulo, string descripcion);
string numeroTelefonicoDelUsuario(int idEmisor);
string vistaPreviaMensaje(string mensaje);
void agregarConversacion(Conversacion*& lista, infoConver x);
//Busca una conversacion por idConversacion, en una lista
Conversacion* buscarConversacion(Conversacion* p, int v);
//Busca un contacto por idContacto, en un vector
int buscarContacto(contacto arr[], int len, int v);
void notificarMensajeRecibido(Conversacion* lista, contacto vec[], int len, int idConversacion, int idUsuarioEmisor, string mensaje);
/*EJ 2*/
static float votos1 = 50;
static float votos2 = 35;
static float votos3 = 15;
//Genera un array de electos en base a un array de candidatos
void generarListaConsejerosDocentes(candidato vecCandidatos[], int lenCan, resultado vecResultado[], int& lenRes);
void ordenarVector(resultado vecAuxiliar[], int lenAux);
#endif