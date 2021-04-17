#include <iostream>
using namespace std;

struct venta {
	int codArticulo;
	char descripcion[50];
	int cantVendida;
	float precioUni;
};

void burbuja(venta vec[], int len);
int busquedaSecuencial(venta vec[], int len, int valorBuscado);
int main()
{
	FILE* suc1 = fopen("suc1.dat", "rb+");
	FILE* suc2 = fopen("suc2.dat", "rb+");
	venta vec[50];
	int lenVec = 0;
	int montoRecaudadoSuc1 = 0;
	int montoRecaudadoSuc2 = 0;
	venta reg;
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
		pos = busquedaSecuencial(vec, lenVec, reg.codArticulo);
		if (pos == -1) {
			vec[lenVec] = reg;
			lenVec++;
		}
		else {
			vec[pos].cantVendida += reg.cantVendida;
		}
		fread(&reg, sizeof(venta), 1, suc2);
	}
	burbuja(vec, lenVec);
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
void burbuja(venta vec[], int len) {
	venta temp;
	bool huboIntercambio = true;
	for (int i = 0; i < len && huboIntercambio; i++) {
		huboIntercambio = false;
		for (int j = 0; j < len - 1; j++) {
			if (vec[j].cantVendida > vec[j + 1].cantVendida) {
				huboIntercambio = true;
				temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
			}
		}
	}
}