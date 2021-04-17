#include <iostream>
using namespace std;

/*Ejercicio 1*/
struct venta {
    int codArticulo;
    char descripcion[50];
    int cantVendida;
    float precioUni;
};
/*Crear un archivo con el tipo de dato*/
void crearArchivoSucursal();
venta crearVenta(int codArticulo, string descripcion, int cantVendida, float precioUni);
template <typename T>
void write(FILE* f, T v);
void burbuja1(venta vec[], int len);
int busquedaSecuencial1(venta vec[], int len, int valorBuscado);
/*Ejercicio 2*/
struct nota {
	int nroDeLegajo;
	char nombreDeMateria[30];
	char codDeCurso[5];
	float nota;
};
struct aprobado {
	int nroDeLegajo;
	char nombreDeMateria[30];
	char codDeCurso[5];
};
/*Ejercicio 3*/
int diaDeSemana(int dia, int mes, int anio);
/*Ejercicio 4*/
int busquedaSecuencial4(int vec[], int len, int valorBuscado);
void agregar(int arr[], int n, int& len, int v);
void llenarVector(int vecA[], int vecB[], int lenA, int lenB, int vecC[], int& lenC);
int main()
{
	/*Ejercicio 1*/
	/*LLenado de archivos*/
	crearArchivoSucursal();
	/*Apareo de archivos*/
	/*
	FILE * suc1 = fopen("suc1.dat", "rb+");
	FILE * suc2 = fopen("suc2.dat", "rb+");
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
	*/

	/*Ejercicio 2*/
	/*Creado de archivo notas*/
	/*
	FILE * notas = fopen("notas.dat", "wb+");
	nota reg;
	//LLeno archivo notas
	//El nombre de materia aparece solo 1 vez por estudiante.
	//El archivo se encuentra ordenado por legajo
	reg.nroDeLegajo= 123;
	strcpy(reg.nombreDeMateria, "algoritmos");
	strcpy(reg.codDeCurso, "1151");
	reg.nota = 5;
	fwrite(&reg, sizeof(nota), 1, notas);
	reg.nroDeLegajo = 123;
	strcpy(reg.nombreDeMateria, "quimica");
	strcpy(reg.codDeCurso, "1152");
	reg.nota = 8;
	fwrite(&reg, sizeof(nota), 1, notas);

	reg.nroDeLegajo = 321;
	strcpy(reg.nombreDeMateria, "fisica");
	strcpy(reg.codDeCurso, "2254");
	reg.nota = 9.5;
	fwrite(&reg, sizeof(nota), 1, notas);
	reg.nroDeLegajo = 321;
	strcpy(reg.nombreDeMateria, "analisis");
	strcpy(reg.codDeCurso, "2256");
	reg.nota = 8.5;
	fwrite(&reg, sizeof(nota), 1, notas);

	rewind(notas);
	fread(&reg, sizeof(nota), 1, notas);
	while (!feof(notas)) {
		cout << reg.nroDeLegajo << endl;
		cout << reg.nombreDeMateria << endl;
		cout << reg.codDeCurso << endl;
		cout << reg.nota << endl;
		cout << "__________________" << endl;
		fread(&reg, sizeof(nota), 1, notas);
	}
	fclose(notas);
	cout << "**********************************************" << endl;
	*/
	/*Ejecucion de programa*/
	/*
	FILE * notas = fopen("notas.dat", "rb+");
	nota reg;
	FILE* aprobados = fopen("aprobados.dat", "wb+");
	aprobado alumno;
	int lenVecAprobados = 0;
	
	float promedioDeEstudiante;
	float promedioMasAlto = 0;
	float promedioMasBajo = 999999999.5;
	int legajoDePromedioMasAlto = 0;
	int legajoDePromedioMasBajo = 0;

	fread(&reg, sizeof(nota), 1, notas);
	while (!feof(notas)) {
		int legajoAnterior = reg.nroDeLegajo;
		float sumaDeNotas = 0;
		int cantidadDeNotas = 0;

		while (!feof(notas) && reg.nroDeLegajo == legajoAnterior) {
			sumaDeNotas += reg.nota;
			cantidadDeNotas++;
			if (reg.nota > 6) {
				alumno.nroDeLegajo = reg.nroDeLegajo;
				strcpy(alumno.codDeCurso, reg.codDeCurso);
				strcpy(alumno.nombreDeMateria, reg.nombreDeMateria);
				fwrite(&alumno, sizeof(aprobado), 1, aprobados);
			}
			fread(&reg, sizeof(nota), 1, notas);
		}
		promedioDeEstudiante = sumaDeNotas / cantidadDeNotas;
		cout << "El promedio del estudiante " << legajoAnterior << " es de " << promedioDeEstudiante << endl;
		cout << "-------------------------------------------------------" << endl;

		if (promedioDeEstudiante > promedioMasAlto) {
			promedioMasAlto = promedioDeEstudiante;
			legajoDePromedioMasAlto = legajoAnterior;
		}
		if (promedioDeEstudiante < promedioMasBajo) {
			promedioMasBajo = promedioDeEstudiante;
			legajoDePromedioMasBajo = legajoAnterior;
		}
	}
	cout << "________________________________________________________" << endl;
	cout << "El promedio del estudiante " << legajoDePromedioMasBajo << " es el mas bajo con  " << promedioMasBajo << endl;
	cout << "El promedio del estudiante " << legajoDePromedioMasAlto << " es el mas alto con  " << promedioMasAlto << endl;
	fclose(notas);
	cout << "_______________________Informe de aprobados_________________________________" << endl;
	rewind(aprobados);
	fread(&alumno, sizeof(aprobado), 1, aprobados);
	while (!feof(aprobados)) {
		cout << alumno.nroDeLegajo << endl;
		cout << alumno.nombreDeMateria << endl;
		cout << alumno.codDeCurso << endl;
		cout << "__________________" << endl;
		fread(&alumno, sizeof(aprobado), 1, aprobados);
	}
	fclose(aprobados);
	*/

	/*Ejercicio 3*/
	/*
	int dia;
	int mes;
	int anio;
	int res = -1;
	cout << "Ingrese dia: ";
	cin >> dia;
	cout << "Ingrese mes: ";
	cin >> mes;
	cout << "Ingrese anio: ";
	cin >> anio;

	res = diaDeSemana(dia, mes, anio);

	switch (res)
	{
	case 0:
		cout << "El dia fue domingo" << endl;
		break;
	case 1:
		cout << "El dia fue lunes" << endl;
		break;
	case 2:
		cout << "El dia fue martes" << endl;
		break;
	case 3:
		cout << "El dia fue miercoles" << endl;
		break;
	case 4:
		cout << "El dia fue jueves" << endl;
		break;
	case 5:
		cout << "El dia fue viernes" << endl;
		break;
	case 6:
		cout << "El dia fue sabado" << endl;
		break;
	default:
		cout << "Error de calculo" << endl;
		break;
	}
	*/

	/*Ejercicio 4*/
	/*Crear un procedimiento que dados dos vectores A y B(10 elementos como máximo cada uno), llene un vector C con la unión(sin repetidos) de los vectores A y B.*/
	/*int vecA[10] = { 1,2,3}; 
	int vecB[10] = { 6,7,8,9,10,11,12,13,14 };
	int vecC[20];
	int lenA = 3;
	int lenB = 10;
	int lenC = 0;
	llenarVector(vecA, vecB, lenA, lenB, vecC, lenC);
	for (int i = 0; i < lenC - 1; i++) {
		cout << vecC[i] << endl;
	}*/
}

/*Ejercicio 1*/
void crearArchivoSucursal() {
	FILE* suc1 = fopen("suc1.dat", "wb+");
	FILE* suc2 = fopen("suc2.dat", "wb+");
	venta reg;
	//LLeno archivo 1
	write<venta>(suc1, crearVenta(123, "1_remaches", 10, 50));
	write<venta>(suc1, crearVenta(456, "1_bulones", 10, 50));
	write<venta>(suc1, crearVenta(789, "1_reten", 10, 50));
	rewind(suc1);
	fread(&reg, sizeof(venta), 1, suc1);
	while (!feof(suc1)) {
		cout << reg.codArticulo << endl;
		cout << reg.descripcion << endl;
		cout << reg.cantVendida << endl;
		cout << reg.precioUni << endl;
		cout << "__________________" << endl;
		fread(&reg, sizeof(venta), 1, suc1);
	}
	fclose(suc1);
	cout << "**********************************************" << endl;
	//Lleno archivo 2
	write<venta>(suc2, crearVenta(321, "2_clavo", 20, 5));
	write<venta>(suc2, crearVenta(654, "2_tarugo", 20, 5));
	write<venta>(suc2, crearVenta(987, "2_tornillo",10, 50));
	rewind(suc2);
	fread(&reg, sizeof(venta), 1, suc2);
	while (!feof(suc2)) {
		cout << reg.codArticulo << endl;
		cout << reg.descripcion << endl;
		cout << reg.cantVendida << endl;
		cout << reg.precioUni << endl;
		cout << "__________________" << endl;
		fread(&reg, sizeof(venta), 1, suc2);
	}
	fclose(suc2);
}
template <typename T>
void write(FILE* f, T v) {
	fwrite(&v, sizeof(T), 1, f);
}
venta crearVenta(int codArticulo, string descripcion, int cantVendida, float precioUni) {
	venta reg;
	reg.codArticulo= codArticulo;
	strcpy(reg.descripcion, descripcion.c_str());
	reg.cantVendida = cantVendida;
	reg.precioUni = precioUni;
	return reg;
}
int busquedaSecuencial1(venta vec[], int len, int valorBuscado) {
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
void burbuja1(venta vec[], int len) {
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
/*Ejercicio 3*/
int diaDeSemana(int dia, int mes, int anio) {
	int vecRegular[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };
	int vecBisiesto[12] = { 0,3,4,0,2,5,0,3,6,1,4,6 };
	int X;

	if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0)
	{
		X = vecBisiesto[mes - 1];
	}
	else
	{
		X = vecRegular[mes - 1];
	}

	return (((anio - 1) % 7) + ((((anio - 1) / 4) - ((3 * ((anio - 1) / 100) + 1) / 4)) % 7) + X + dia % 7) % 7;
}
/*Ejercicio 4*/
int busquedaSecuencial4(int vec[], int len, int valorBuscado) {
	int pos = -1;
	int i = 0;
	while (i < len && vec[i] != valorBuscado) {
		i++;
	}
	if (vec[i] == valorBuscado) {
		pos = i;
	}
	return pos;
}
void agregar4(float arr[], int n, int& len, float v) {
	if (len < n) {
		arr[len] = v;
		len++;
	}
	else {
		cout << "El vector está lleno :( " << endl;
	}
}
void llenarVector(int vecA[], int vecB[], int lenA, int lenB, int vecC[], int& lenC) {
	int posA = 0;
	int posB = 0;
	int posC = 0;
	int pos;
	while (posA < lenA) {
		agregar(vecC, 20, lenC, vecA[posA]);
		posA++;
	}
	while (posB < lenB) {
		pos = busquedaSecuencial4(vecC, lenC, vecB[posB]); //Busco en que posicion esta el ID del reg que le envio
		if (pos == -1) { // si no lo encuentra, lo guarda en el vector
			agregar(vecC, 20, lenC, vecB[posB]);
		}
		posB++;
	}
}