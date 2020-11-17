#include <iostream>
#include "..\..\Headers\vectores.hpp"

struct articulo {
	int nroArt;
	char desc[50];
	float precio;
};

int main()
{
	//Ejemplo de posicionamiento en archivos
	/*
	FILE* archivo = fopen("listaDePrecios.dat","wb+");
	articulo reg;
	reg.nroArt = 1234;
	strcpy(reg.desc, "alfajor");
	reg.precio = 50.2;
	fwrite(&reg, sizeof(articulo), 1, archivo);

	reg.nroArt = 4567;
	strcpy(reg.desc, "turron");
	reg.precio = 20.5;
	fwrite(&reg, sizeof(articulo), 1, archivo);

	reg.nroArt = 6784;
	strcpy(reg.desc, "gomitas");
	reg.precio = 35;
	fwrite(&reg, sizeof(articulo), 1, archivo);

	reg.nroArt = 8976;
	strcpy(reg.desc, "gaseosa");
	reg.precio = 75.5;
	fwrite(&reg, sizeof(articulo), 1, archivo);

	reg.nroArt = 0;
	strcpy(reg.desc, "");
	reg.precio = 0.0;
	fwrite(&reg, sizeof(articulo), 1, archivo);

	//Posicionarnos en un lugar particular del archivo
	//Y movernos tantos bytes como pasemos en el segundo parametro
	//El sizeof puede ser negativo e ir para atras
	fseek(archivo, 1 * sizeof(articulo), SEEK_SET);
	//SEEK_SET -> Desde el principio del archivo, y le sumo la cantidad de bytes del registro
	//SEEK_CUR -> Desde la posicion donde estoy
	//SEEK_END -> Desde el final del archivo
	*/
}
