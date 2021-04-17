#include <iostream>
using namespace std;

/*
 Crear un procedimiento que dados dos vectores A y B (10 elementos como máximo cada uno),
 llene un vector C que contenga todos los elementos del vector A que no se encuentren en el vector B.
 Los vectores están conformados por un registro de “persona” con los siguientes datos: DNI, nombre y apellido, fecha de nacimiento (DDMMAAAA).
 El vector C será utilizado en el programa principal.*/
struct persona {
	int dni;
	char nombreYApellido[50];
	char fechaDeNacimiento[50];
};

void mostrar(persona arr[], int len);
int buscar(persona arr[], int len, persona v);
void agregar(persona arr[], int n, int& len, persona v);
void unirVectores(persona vecA[], persona vecB[], int lenA, int lenB, persona vecC[], int& lenC);

int main()
{
	persona vecA[10] = { {41825252 , "Fulano Gutierrez", "14021995"}, {13679842, "Pedro Picapiedra", "20101950"}, {24561879, "Jhonny Bravo", "04051980"} };
	persona vecB[10] = { {41825252 , "Fulano Gutierrez", "14021995"},  {123456789 , "Guido Alvarez", "24021999"}, {24561879, "Jhonny Bravo", "04051980"} };
	persona vecC[20] = {}; //Solo deberia contener a Pedro Picapiedra
	int lenA = 5;
	int lenB = 4;
	int lenC = 0;
	int n = 20;
	unirVectores(vecA, vecB, lenA, lenB, vecC, lenC);
	mostrar(vecC, lenC);
}

void mostrar(persona arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "DNI " << arr[i].dni << endl;
		cout << "Nombre y Apellido " << arr[i].nombreYApellido << endl;
		cout << "Fecha de nacimiento " << arr[i].fechaDeNacimiento << endl;
	}
}
int buscar(persona arr[], int len, persona v) {
	int i = 0;
	int pos = -1;
	while (i < len && arr[i].dni != v.dni) {
		i++;
	}
	if (i < len) {
		pos = i;
	}
	return pos;
}
void agregar(persona arr[], int n, int& len, persona v) {
	if (len < n) {
		arr[len] = v;
		len++;
	}
	else {
		cout << "El vector esta lleno" << endl;
	}
}
void unirVectores(persona vecA[], persona vecB[], int lenA, int lenB, persona vecC[], int& lenC) {
	int i = 0;
	int j = 0;
	int pos = -1;
	//Itero sobre el vec A, evaluando cada uno de sus elementos contra el vector B
	while (i < lenA) {
		pos = buscar(vecB, lenB, vecA[i]); //Busco el elemento de A en B
		if (pos == -1) { //Si el elemento de A no esta en B lo agrego a C
			agregar(vecC, 20, lenC, vecA[i]);
		}
		i++;
	}
}