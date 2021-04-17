#include <iostream>
using namespace std;

struct venta {
	char sucursal[10];
	int codArticulo;
	char descripcion[50];
	int cantVendida;
	float precioUni;
};
struct artVendidos {
	int codArticulo;
	int cantVendida;
};

int busquedaSecuencial(artVendidos vec[], int len, int valorBuscado);

int main()
{
	FILE* articulos = fopen("articulos.dat", "rb+");
	venta reg;
	artVendidos artVendidosVec[1000];
	int lenVecArt = 0;
	int montoMinRecaudado = 0;
	string sucursalQueMenosRecaudo;
	int pos;
	//Recorro la primer sucursal, acumulo los articulos y aparte el monto total recaudado
	fread(&reg, sizeof(venta), 1, articulos);
	while (!feof(articulos)) {
		string sucAnterior = reg.sucursal;
		int montoRecaudadoSuc = 0;
		while (!feof(articulos) && sucAnterior == reg.sucursal){
			pos = busquedaSecuencial(artVendidosVec, lenVecArt, reg.codArticulo);
			if (pos == -1) { // si no lo encuentra, lo guarda en el vector}
				artVendidos  artVec;
				artVec.codArticulo = reg.codArticulo;
				artVec.cantVendida = reg.cantVendida;
				artVendidosVec[lenVecArt] = artVec;
				lenVecArt++;
			}
			else {// si ya lo encuentra suma la cantidad vendida
				artVendidosVec[pos].cantVendida += reg.cantVendida;
			}
			montoRecaudadoSuc+= reg.cantVendida * reg.precioUni;
			fread(&reg, sizeof(venta), 1, articulos);
		}
		cout << "La sucursal recaudo " << montoRecaudadoSuc << endl;
		if (montoRecaudadoSuc < montoMinRecaudado) {
			montoMinRecaudado = montoRecaudadoSuc;
			sucursalQueMenosRecaudo = reg.sucursal;
		}
	}
	fclose(articulos);
	//Escribo todo lo que tenia guardado en el vector, en el archivo
	artVendidos artVec;
	FILE* articulosVendidos = fopen("articulosVendidos.dat", "wb+");
	for (int i = 0; i < lenVecArt; i++) {
		artVec = artVendidosVec[i];
		fwrite(&artVec, sizeof(artVendidos), 1, articulosVendidos);
	}
	fclose(articulosVendidos);




	venta vec[100];//Armo un vector con 100 ventas, 50 ventas maximo por cada archivo
	int lenVec = 0;
	int montoRecaudadoSuc1 = 0;
	int montoRecaudadoSuc2 = 0;
	venta reg;
	//Recorro la primer sucursal, acumulo los articulos y aparte el monto total recaudado
	fread(&reg, sizeof(venta), 1, suc1);
	while (!feof(suc1)) {
		vec[lenVec] = reg;
		lenVec++;
		montoRecaudadoSuc1 += reg.cantVendida * reg.precioUni;
		fread(&reg, sizeof(venta), 1, suc1);
	}
	int pos;
	fread(&reg, sizeof(venta), 1, suc2);
	while (!feof(suc2)) {
		montoRecaudadoSuc2 += reg.cantVendida * reg.precioUni;
		pos = busquedaSecuencial1(vec, lenVec, reg.codArticulo); //Busco en que posicion esta el ID del reg que le envio
		if (pos == -1) { // si no lo encuentra, lo guarda en el vector
			vec[lenVec] = reg;
			lenVec++;
		}
		else {// si ya lo encuentra suma la cantidad vendida
			vec[pos].cantVendida += reg.cantVendida;
		}
		fread(&reg, sizeof(venta), 1, suc2);
	}
	burbuja1(vec, lenVec);// ordena el vector 
	cout << "Las 3 articulos mas vendidos fueron: " << endl;
	for (int i = lenVec - 1; i > lenVec - 4; i--) {
		cout << "- " << vec[i].descripcion << " con " << vec[i].cantVendida << " unidades vendidas." << endl;
	}
	if (montoRecaudadoSuc1 > montoRecaudadoSuc2) {
		cout << "La sucursal que mas vendio fue la Sucursal " << "1, recaudando $" << montoRecaudadoSuc1 << endl;
	}
	else if (montoRecaudadoSuc1 < montoRecaudadoSuc2) {
		cout << "La sucursal que mas vendio fue la Sucursal " << "2, recaudando $" << montoRecaudadoSuc2 << endl;
	}
	else {
		cout << "Ambas sucursales recaudaron lo mismo $ " << montoRecaudadoSuc1;
	}
	//Ciero ambos archivos de deposito
	fclose(suc1);
	fclose(suc2);

}

int busquedaSecuencial(venta vec[], int len, int valorBuscado) {
	int pos = -1;
	int i = 0;
	while (i < len && vec[i].codArticulo != valorBuscado) {
		i++;
	}
	if (vec[i].codArticulo == valorBuscado) {
		pos = i;
	}
	return pos;
}