#include <iostream>
#include <string.h>
using namespace std;


int factorial(int numero);
int potencia(int base, int exp);
int fibonacci(int n);
int divisionNatural(int dividendo, int divisor);
void insercion(int vec[], int len);
void seleccion(int vec[], int len);
int busquedaBinaria(int vec[], int len, int valorBuscado);


struct articulo {
	int nroArt;
	char desc[50];
	float precio;
};

//Tipo de dato del vector
struct estudiante {
	int legajo;
	char nombre[50];
	char mail[100];
};

//Tipo de dato del archivo consolidado
struct estudianteListado {
	estudiante est;
	char curso[20];
};

struct venta {
	int nroCli;
	char artComprado[50];
	int cantComprada;
	float precioUni;
};

struct listaDePrecios {
	int codigoArt;
	float precioUnitario;
};

struct stock {
	int nroArt;
	int cantUnidades;
	int posListaDePrecios;
};

struct cabecera {
	int idFactura;
	int fecha;
	int nroCliente;
	float totalFactura;
};

struct detalle {
	int idFactura;
	int nroArticulo;
	int cant;
	float precioUnitario;
	float totalArticulo;
};

struct pelicula {
	int idPeli;
	char nombrePeli[50];
	int cantEsp;
};

struct peliculaFDS {
	char nombrePeli[50];
	int cantEsp;
};

struct Nodo {
    int info;
    Nodo* sig;
};

struct NodoInv {
    char info;
    NodoInv* sig;
};


int busquedaSecuencial(pelicula vec[], int len, int valorBuscado);
void imprimirCabeceras(FILE * cabeceraArch, cabecera regCabecera);
void imprimirDetalles(FILE * detalleArch, detalle regDetalle);
void burbuja(pelicula vec[], int len);
void agregarNodo(Nodo* &p, int x);
void mostrar (Nodo* p);
void liberar(Nodo* &p);
Nodo* buscar(Nodo* p, int v);
void eliminar(Nodo*&p, int v);
int eliminarPrimerNodo(Nodo*&p);
Nodo* insertarOrdenado(Nodo*&p, int v);
void ordenar(Nodo*& p);
Nodo* buscaEInsertaOrdenado(Nodo* &p, int v, bool & enc);
void push(NodoInv*& p, char v);
int pop(NodoInv*& p);
void encolar(NodoInv* & cFte, NodoInv* & cFin, char v);
int desencolar(NodoInv* &cFte, NodoInv* & cFin);
//void eliminarLosDosPrimeros(Nodo* &pila, int x);
//void colocarEnTercerLugar(Nodo* &pila , int x, char& exitoso);
//void colocarEnPosicionYLugar(Nodo* &pila , int x, int y, char& exitoso);
//void reemplazarXporY(Nodo* &pila , int x, int y);
bool inversa(NodoInv* &colaFte, NodoInv* &colaFin);

int main(int argc, char** argv) {

	//Listas 22/7	
	/*
	Nodo* lista = NULL;
	agregarNodo(lista,0);
	agregarNodo(lista,10);
	agregarNodo(lista,11);
    agregarNodo(lista,20);
    agregarNodo(lista,50);
    agregarNodo(lista,4);
    agregarNodo(lista,1);
    agregarNodo(lista,100);
    agregarNodo(lista,2);
	Nodo* buscado;
	buscado = buscar(lista,4);
	
	if(buscado != NULL) {
		eliminar(lista,4);
	} else {
		cout << "El valor no se encuentra" << endl;
	}
	cout<< "El nro. del primer nodo es " << eliminarPrimerNodo(lista) << endl;
	
	ordenar(lista);
	bool encontrado;
	Nodo * nodoBuscado = buscaEInsertaOrdenado(lista, 20, encontrado);
	cout << nodoBuscado->info << endl;
	if(encontrado) {
		 cout << "El nodo ya existia" << endl;
	} else {
		cout << "El nodo fue insertado" << endl;
	}
	
	mostrar(lista);
	liberar(lista);
	*/
	
/*	Nodo * pila = NULL;
	push(pila,90);
	push(pila,100);
	push(pila,1);
	push(pila,5);
	push(pila,20);
	push(pila,50);
	
	while(pila != NULL) {
		cout << pop(pila) << endl;
	}*/
	
/*	Nodo* colaFrente = NULL;
	Nodo* colaFin = NULL;
	encolar(colaFrente, colaFin,4);
	encolar(colaFrente, colaFin,10);
	encolar(colaFrente, colaFin,50);
	encolar(colaFrente, colaFin,100);
	encolar(colaFrente, colaFin,1);
	
	while(colaFrente != NULL) {
		cout << desencolar(colaFrente, colaFin) << endl;
	}
	
*/

	//Pilas - Ejercicio 1
	/*Nodo * pila = NULL;
	push(pila,90);
	push(pila,100);
	push(pila,1);
	
	int x;
	cout << "Ingrese el valor X" << endl;
	cin >> x; 
	
	eliminarLosDosPrimeros(pila, x);
	
	while(pila != NULL){
		cout << pop(pila) << endl;
	}	
	*/
	
	/*
	//Pilas - Ejercicio 2
	Nodo * pila = NULL;
	push(pila,90);

	
	int x;
	cout << "Ingrese el valor X" << endl;
	cin >> x; 
	
	char exitoso;
	colocarEnTercerLugar(pila,x,exitoso);
	
	if(exitoso == 'S') {
		cout << "Se pudo realizar el req" << endl;
	} else {
		cout << "No se pudo realizar el req" << endl;
	}
	
	while(pila != NULL){
		cout << pop(pila) << endl;
	}
	*/

	/*	
	//Pilas - Ejericio 3
	Nodo * pila = NULL;
	push(pila,90);
	push(pila,100);
	push(pila,4);
	push(pila,1);
		
	int x;
	cout << "Ingrese el valor X" << endl;
	cin >> x; 
	
	int y;
	cout << "Para reemplazar en la posicion Y" << endl;
	cin >> y;
	
	char exitoso;
	colocarEnPosicionYLugar(pila , x, y,exitoso);
	
	if(exitoso == 'S') {
		cout << "Se pudo realizar el req" << endl;
	} else {
		cout << "No se pudo realizar el req" << endl;
	}
	
	while(pila != NULL){
		cout << pop(pila) << endl;
	}
	*/
	
	/*
	//Pilas - Ejercicio 4
	Nodo * pila = NULL;
	push(pila,1);
	push(pila,100);
	push(pila,4);
	push(pila,1);
	push(pila,1);
	push(pila,200);
		
	int x;
	cout << "Ingrese el valor X" << endl;
	cin >> x; 
	
	int y;
	cout << "Para reemplazar por valor Y" << endl;
	cin >> y;
	
	reemplazarXporY(pila , x, y); 
	
	while(pila != NULL){
		cout << pop(pila) << endl;
	}
	*/
	
	//Pilas - Ejercicio 5
	NodoInv* colaFte = NULL;
	NodoInv* colaFin = NULL;
	
	char c;
	cout << "Ingrese el caracter" << endl;
	cin >> c;
	
	while (c != '0') {
		encolar(colaFte,colaFin,c);
		cout << "Ingrese el caracter" << endl;
		cin >> c;
	}
	
	bool esInversa = inversa(colaFte,colaFin);
	
	if(esInversa){
		cout << "Los caracteres son inversos" << endl;
	} else {
		cout << "Los caracteres no son inversos" << endl;
	}
	
}

bool inversa(NodoInv* &colaFte, NodoInv* &colaFin) {
	bool retorno = true;
	NodoInv* pila = NULL;
	while(colaFte->info != '.') {
		push(pila, desencolar(colaFte,colaFin));
	} 
	desencolar(colaFte, colaFin);
	
	while(colaFte != NULL) {
		if(desencolar(colaFte, colaFin) != pop(pila)){
			retorno = false;
			break;
		}
	}
	
	return retorno;
}

/*
void reemplazarXporY(Nodo* &pila , int x, int y) {
	Nodo * pilaAux = NULL;
	int valor;
	while(pila != NULL){
		valor = pop(pila);
		if(valor == x){
			valor = y;
		}
		push(pilaAux,valor);
	}
	
	while(pilaAux != NULL) {
		push(pila,pop(pilaAux));
	}
	
}

void colocarEnPosicionYLugar(Nodo* &pila , int x, int y, char& exitoso){
	Nodo * pilaAux = NULL;
	int i = 0;
	while(pila != NULL && i < (y-1)) {
		push(pilaAux,pop(pila));
		i++;
	}
	
	if(i == (y-1)) {
		exitoso = 'S';
		push(pila,x);
	} else {
		exitoso = 'N';
	}
	
	while(pilaAux != NULL){
		push(pila,pop(pilaAux));
	}
}

void colocarEnTercerLugar(Nodo* &pila , int x, char& exitoso){
	Nodo * pilaAux = NULL;
	int i = 0;
	while(pila != NULL && i < 2) {
		push(pilaAux,pop(pila));
		i++;
	}
	
	if(i == 2) {
		exitoso = 'S';
		push(pila,x);
	} else {
		exitoso = 'N';
	}
	
	while(pilaAux != NULL){
		push(pila,pop(pilaAux));
	}
	
}

void eliminarLosDosPrimeros(Nodo* &pila, int x) {

	for(int i = 0; i < 2; i++){
		pop(pila);
	}
	
	push(pila, x);
}
*/

int desencolar(NodoInv* &cFte, NodoInv* & cFin){
	int retorno = cFte->info;
	NodoInv* aux =  cFte;
	cFte = aux->sig;
	if(cFte == NULL) {
		cFin = NULL;
	}
	delete aux;
	return retorno;
}

void encolar(NodoInv* & cFte, NodoInv* & cFin, char v){
	NodoInv * nuevo = new NodoInv();
	nuevo->info = v;
	nuevo->sig = NULL;
	if(cFte == NULL) {
		cFte = nuevo;
	} else {
		cFin->sig = nuevo;	
	}
	cFin = nuevo;
}

int pop(NodoInv*& p) {
	int retorno = p->info;
	NodoInv* aux = p;
	p = aux->sig;
	delete aux;
	return retorno;
}

void push(NodoInv*& p, char v){
	NodoInv* nuevo = new NodoInv();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}

Nodo* buscaEInsertaOrdenado(Nodo* &p, int v, bool & enc) {
	Nodo * nodoBuscado = buscar(p,v);
	if(nodoBuscado != NULL) { // el nodo está en la lista
		enc = true;
	} else { // el nodo no está
		nodoBuscado = insertarOrdenado(p,v);
		enc = false;
	}
	
	return nodoBuscado;
}

void ordenar(Nodo*& p) {
	Nodo* q = NULL;
	int valor;
	
	while(p != NULL) {
		valor = eliminarPrimerNodo(p);
		insertarOrdenado(q, valor);	
	}
	
	p = q;
}

Nodo* insertarOrdenado(Nodo*&p, int v){
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	Nodo* ant = NULL;
	Nodo* aux = p;
	
	while(aux!=NULL && aux->info <= v) {
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL){ //Estoy insertando al principio
		p= nuevo;		
	} else {
		ant->sig = nuevo;
	}
	nuevo->sig = aux;
	
	return nuevo;
}

int eliminarPrimerNodo(Nodo*&p) {
	int retorno = p->info;
	Nodo* aux = p;
	p = p->sig;
	delete aux;
	return retorno;
}

void eliminar(Nodo*&p, int v) {
	Nodo* aux = p;
	Nodo* ant = NULL;
	while(aux!= NULL && aux->info != v){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { //Estamos eliminando el primer nodo
		p = aux->sig;
	} else {
		ant->sig = aux->sig;
	}
	
	delete aux;
}

Nodo* buscar(Nodo* p, int v) {
	Nodo* aux = p;
	while(aux!= NULL && aux->info != v){
		aux = aux->sig;
	}
	return aux;
}

void liberar(Nodo*&p){
	Nodo* aux;
	while(p!=NULL) {
		aux = p;
		p=p->sig;
		delete aux;
	}
}

void mostrar (Nodo* p) {
	Nodo* aux = p;
	while(aux != NULL) {
		cout << aux->info << endl;
		aux = aux->sig;
	}
}

void agregarNodo(Nodo* & p, int x) {
	Nodo* nuevo = new Nodo();
	nuevo->info = x;
	nuevo->sig = NULL;
	if(p==NULL) { // la lista p esta vacía
		p = nuevo;
	} else {
		Nodo* aux = p;
		while(aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
	
}

void imprimirCabeceras(FILE * cabeceraArch, cabecera regCabecera) {
	rewind(cabeceraArch);
	
	cout << "Cabeceras de las Facturas" << endl;
	
	fread(&regCabecera,sizeof(cabecera),1,cabeceraArch);
	while(!feof(cabeceraArch)) {
		cout << regCabecera.idFactura << endl;
		cout << regCabecera.fecha << endl;
		cout << regCabecera.nroCliente << endl;
		cout << regCabecera.totalFactura << endl;
		cout << "______________________________" << endl;
		fread(&regCabecera,sizeof(cabecera),1,cabeceraArch);
	}
}

void imprimirDetalles(FILE * detalleArch, detalle regDetalle){
	rewind(detalleArch);
	
	cout << "Detalle de las Facturas" << endl;
	
	fread(&regDetalle,sizeof(detalle),1,detalleArch);
	while(!feof(detalleArch)) {
		cout << regDetalle.idFactura << endl;
        cout << regDetalle.nroArticulo << endl;
        cout << regDetalle.cant << endl;
        cout << regDetalle.precioUnitario << endl;
        cout << regDetalle.totalArticulo << endl;
		cout << "______________________________" << endl;
		fread(&regDetalle,sizeof(detalle),1,detalleArch);
	}
}

int busquedaBinaria(int vec[], int len, int valorBuscado){
	int pos = -1;
	int primero = 0; 
	int ultimo = len-1;
	int medio = (primero + ultimo) / 2;
	
	while(primero <= ultimo) {
		
		if(vec[medio] == valorBuscado) {
			pos = medio;
			break;
		} else if (vec[medio] < valorBuscado) {
			primero = medio + 1;
		} else {
			ultimo = medio - 1;
		}
		
		if(vec[primero] == valorBuscado) {
			pos = primero;
			break;
		}
		
		if(vec[ultimo] == valorBuscado){
			pos = ultimo;
			break;
		}
		
		medio = (primero + ultimo) / 2;
	}
	
	return pos;
}

int busquedaSecuencial(pelicula vec[], int len, int valorBuscado){
	int pos = -1;
	
	int i = 0;
	while(i<len && vec[i].idPeli != valorBuscado) {
		i++;
	}
	
	if(vec[i].idPeli == valorBuscado) {
		pos = i;
	}
	
	return pos;
}

int factorial(int numero) {
	int resultado;
	
	if(numero == 0) {
		resultado = 1;
	} else {
		resultado = numero  * factorial(numero - 1);
	}
	
	return resultado;
}

int potencia(int base, int exp){
	int resultado;
	
	if(exp == 0) {
		resultado = 1;
	} else {
		resultado = base * potencia(base, exp-1);
	}
	
	return resultado;
}

int fibonacci(int n) {
	int resultado;
	
	if(n == 0 || n == 1) {
		resultado = n;	
	} else {
		resultado = fibonacci(n-2) + fibonacci(n-1);
	}
	
	return resultado;
}

int divisionNatural(int dividendo, int divisor) {
	int resultado;
	
	if(dividendo == divisor) {
		resultado = 1;
	} else if (divisor > dividendo) {
		resultado = 0;
	} else {
		resultado = 1 + divisionNatural(dividendo-divisor,divisor);
	}
	
	return resultado;
}

void burbuja(pelicula vec[], int len) {
	pelicula temp;
	bool huboIntercambio = true;
	
	for(int i = 0; i < len && huboIntercambio; i++) {
		
		huboIntercambio = false;
		for(int j=0; j < len-1; j ++) {
			if(vec[j].cantEsp > vec[j+1].cantEsp) {
				huboIntercambio = true;
				temp = vec[j+1];
				vec[j+1] = vec[j];
				vec[j] = temp;
			}
		}
		
	}
	
}

void insercion(int vec[], int len) {
	
	int elementoAInsertar, j; 
	
	for(int i = 1; i < len; i++) {
		
		elementoAInsertar = vec[i];	
		j = i - 1;
		
		while(j >= 0 && vec[j] > elementoAInsertar) {
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] = 	elementoAInsertar;	
	}
}

void seleccion(int vec[], int len) {
	int indiceQueTieneElValorMinimo, temp;
	for(int i=0; i < len-1; i++){
		indiceQueTieneElValorMinimo = i;
		for(int j = i+1; j < len; j++) {
			if(vec[j] < vec[indiceQueTieneElValorMinimo]) {
				indiceQueTieneElValorMinimo = j;
			}
		}
		
		temp = vec[indiceQueTieneElValorMinimo];
		vec[indiceQueTieneElValorMinimo] = vec[i];
		vec[i] = temp;
	}
}
