#include <iostream>
#include "..\..\Headers\vectores.hpp"

int main()
{
	/*Ejercicio 1 - Apareo de vectores hacia Archivo*/
	/*
	estudiante vecK1051[20] = {{123,"lucas","l@gmail.com"},{567,"josefina","j@gmail.com"},{987,"luciana","luli@gmail.com"}};
	estudiante vecK1052[20] = {{345,"martin","m@gmail.com"},{789,"lucrecia","lu@gmail.com"}};
	int lenK1051 = 3;
	int lenK1052 = 2;
	int posK1051 = 0;
	int posK1052 = 0;
	FILE * listadoConsolidado = fopen("estudiantes.dat","wb+");
	estudianteListado reg;
	// Escribo en el archivo listadoConsolidado, los datos de los vectores
	while(posK1051 < lenK1051 && posK1052 < lenK1052) {
		if(vecK1051[posK1051].legajo < vecK1052[posK1052].legajo ) {
			reg.est = vecK1051[posK1051];
			strcpy(reg.curso,"K1051");
			posK1051++;
		} else {
			reg.est = vecK1052[posK1052];
			strcpy(reg.curso,"K1052");
			posK1052++;
		}
		fwrite(&reg,sizeof(estudianteListado),1, listadoConsolidado);
	}
	while(posK1051 < lenK1051) {
			reg.est = vecK1051[posK1051];
			strcpy(reg.curso,"K1051");
			posK1051++;
			fwrite(&reg,sizeof(estudianteListado),1, listadoConsolidado);
	}
	while(posK1052 < lenK1052) {
			reg.est = vecK1052[posK1052];
			strcpy(reg.curso,"K1052");
			posK1052++;
			fwrite(&reg,sizeof(estudianteListado),1, listadoConsolidado);
	}
	rewind(listadoConsolidado);
	fread(&reg,sizeof(estudianteListado), 1, listadoConsolidado);
	while(!feof(listadoConsolidado)){
		cout << reg.est.legajo << endl;
		cout << reg.est.nombre << endl;
		cout << reg.est.mail << endl;
		cout << reg.curso << endl;
		cout << "___________________" << endl;
		fread(&reg,sizeof(estudianteListado), 1, listadoConsolidado);
	}
	fclose(listadoConsolidado);
	*/


	/*Ejercicio 2 - Corte de control de archivo*/
	//LLeno el archivo ventas con data
	/*
	FILE* ventas = fopen("ventas.dat", "wb+");
	venta reg;
	//Cliente 1
	reg.nroCli = 123;
	strcpy(reg.artComprado, "alfajor");
	reg.cantComprada = 12;
	reg.precioUni = 50.3;
	fwrite(&reg, sizeof(venta), 1, ventas);
	reg.nroCli = 123;
	strcpy(reg.artComprado, "turron");
	reg.cantComprada = 18;
	reg.precioUni = 20;
	fwrite(&reg, sizeof(venta), 1, ventas);
	reg.nroCli = 123;
	strcpy(reg.artComprado, "mermelada");
	reg.cantComprada = 2;
	reg.precioUni = 175.70;
	fwrite(&reg, sizeof(venta), 1, ventas);

	//Cliente 2
	reg.nroCli = 345;
	strcpy(reg.artComprado, "alfajor");
	reg.cantComprada = 10;
	reg.precioUni = 50;
	fwrite(&reg, sizeof(venta), 1, ventas);
	reg.nroCli = 345;
	strcpy(reg.artComprado, "turron");
	reg.cantComprada = 5;
	reg.precioUni = 20.5;
	fwrite(&reg, sizeof(venta), 1, ventas);
	reg.nroCli = 345;
	strcpy(reg.artComprado, "gomitas");
	reg.cantComprada = 25;
	reg.precioUni = 80.9;
	fwrite(&reg, sizeof(venta), 1, ventas);

	//Cliente 3
	reg.nroCli = 290;
	strcpy(reg.artComprado, "gaseosa");
	reg.cantComprada = 12;
	reg.precioUni = 175;
	fwrite(&reg, sizeof(venta), 1, ventas);
	reg.nroCli = 290;
	strcpy(reg.artComprado, "alfajor de arroz");
	reg.cantComprada = 6;
	reg.precioUni = 67.8;
	fwrite(&reg, sizeof(venta), 1, ventas);
	reg.nroCli = 290;
	strcpy(reg.artComprado, "gomitas");
	reg.cantComprada = 1;
	reg.precioUni = 80;
	fwrite(&reg, sizeof(venta), 1, ventas);

	//Cliente 4
	reg.nroCli = 568;
	strcpy(reg.artComprado, "alfajor caro");
	reg.cantComprada = 1;
	reg.precioUni = 150;
	fwrite(&reg, sizeof(venta), 1, ventas);
	
	//Lectura
	rewind(ventas);
	fread(&reg, sizeof(venta), 1, ventas);
	while (!feof(ventas)) {
		cout << reg.nroCli << endl;
		cout << reg.artComprado << endl;
		cout << reg.cantComprada << endl;
		cout << reg.precioUni << endl;
		cout << "__________________" << endl;
		fread(&reg, sizeof(venta), 1, ventas);
	}
	fclose(ventas);
	*/
	//Hago corte de control
	/*
	FILE* ventas = fopen("ventas.dat", "rb");
	venta reg;
	int nroCliAnterior;
	float cliMaxDineroGastado = -1;
	int nroCliMaxDineroGastado;
	float sumaDineroGastadoXCliente;
	int cliMinArtComprados = 999999999999;
	int nroCliMinArtComprados;
	int sumaCantArticulosXCliente;
	int cantArtMaxCompradoXCliente;
	char artMaxCompradoXCliente[50];
	fread(&reg, sizeof(venta), 1, ventas);
	while (!feof(ventas)) {
		nroCliAnterior = reg.nroCli;
		sumaDineroGastadoXCliente = 0.0;
		sumaCantArticulosXCliente = 0;
		cantArtMaxCompradoXCliente = 0;
		while (!feof(ventas) && nroCliAnterior == reg.nroCli) {
			sumaDineroGastadoXCliente += reg.cantComprada * reg.precioUni;
			sumaCantArticulosXCliente += reg.cantComprada;
			if (reg.cantComprada > cantArtMaxCompradoXCliente) {
				cantArtMaxCompradoXCliente = reg.cantComprada;
				strcpy(artMaxCompradoXCliente, reg.artComprado);
			}
			fread(&reg, sizeof(venta), 1, ventas);
		}
		cout << "El cliente " << nroCliAnterior << " gasto $" << sumaDineroGastadoXCliente << endl;
		cout << "El articulo mas comprado fue " << artMaxCompradoXCliente << " con " << cantArtMaxCompradoXCliente << " unidades" << endl;
		cout << "_____________________________________________________" << endl;
		if (sumaDineroGastadoXCliente > cliMaxDineroGastado) {
			cliMaxDineroGastado = sumaDineroGastadoXCliente;
			nroCliMaxDineroGastado = nroCliAnterior;
		}
		if (sumaCantArticulosXCliente < cliMinArtComprados) {
			cliMinArtComprados = sumaCantArticulosXCliente;
			nroCliMinArtComprados = nroCliAnterior;
		}
	}
	cout << "______________________________________________" << endl;
	cout << "El cliente que mas dinero gasto es " << nroCliMaxDineroGastado << " con $" << cliMaxDineroGastado << endl;
	cout << "El cliente que menos articulos compro es " << nroCliMinArtComprados << " con " << cliMinArtComprados << " articulos" << endl;
	fclose(ventas);
	*/


	/*Ejercicio 3 - Combinado*/
	/*Creo y lleno proximoIdentificador*/
	/*
	FILE* proximoIdentificador = fopen("proximoIdentificador.dat", "wb+");
	int reg = 1;
	fwrite(&reg, sizeof(int), 1, proximoIdentificador);
	rewind(proximoIdentificador);
	fread(&reg, sizeof(int), 1, proximoIdentificador);
	while (!feof(proximoIdentificador)) {
	    cout << reg << endl;
	    fread(&reg, sizeof(int), 1, proximoIdentificador);
	}
	fclose(proximoIdentificador);
	*/
	/*Creo y lleno lista de precios*/
	/*
	FILE * listaArch = fopen("listaDePrecios.dat", "wb+");
	listaDePrecios reg;
	reg.codigoArt = 123;
	reg.precioUnitario = 50.5;
	fwrite(&reg, sizeof(listaDePrecios), 1, listaArch);
	reg.codigoArt = 234;
	reg.precioUnitario = 25.2;
	fwrite(&reg, sizeof(listaDePrecios), 1, listaArch);
	reg.codigoArt = 345;
	reg.precioUnitario = 75;
	fwrite(&reg, sizeof(listaDePrecios), 1, listaArch);
	reg.codigoArt = 478;
	reg.precioUnitario = 12.75;
	fwrite(&reg, sizeof(listaDePrecios), 1, listaArch);
	reg.codigoArt = 567;
	reg.precioUnitario = 37.8;
	fwrite(&reg, sizeof(listaDePrecios), 1, listaArch);
	
	rewind(listaArch);
	fread(&reg, sizeof(listaDePrecios), 1, listaArch);
	while (!feof(listaArch)) {
	    cout << reg.codigoArt << endl;
	    cout << reg.precioUnitario << endl;
	    cout << "_________________________________"<< endl;
	    fread(&reg, sizeof(listaDePrecios), 1, listaArch);
	}
	fclose(listaArch); 
	*/
	/*Ejecuto el programa*/
	/*
	stock vecStock[100] = { {478,34,4},{123,78,1},{234,100,2},{345,300,3},{567,46,5} };
	int lenStock = 5;
	FILE* listaArch = fopen("listaDePrecios.dat", "rb"); //Una lista de articulos para todo el programa
	FILE* proximoIdentificador = fopen("proximoIdentificador.dat", "rb+");
	//  Abro los archivos para agregar al final y no pisar los registros que
	//  ya tengo guardados
	FILE* cabeceraArch = fopen("cabecera.dat", "ab+"); //Una cabecera por factura
	FILE* detalleArch = fopen("detalle.dat", "ab+"); //Varios detalles por factura

	detalle regDetalle;
	cabecera regCabecera;
	listaDePrecios regListaPrecios;

	int terminarIngresoDeFacturas;
	int terminarIngresoDeArticulos;
	int proxId;
	int posArtEnStock;

	cout << "Bienvenido" << endl;
	cout << "Para terminar con el ingreso de facturas, presione 0." << endl;
	cin >> terminarIngresoDeFacturas;
	//While para cargar todas las facutas
	while (terminarIngresoDeFacturas != 0) {
		//Guardo los datos que me pide la cabecera
		cout << "Ingrese el nro de cliente" << endl;
		cin >> regCabecera.nroCliente;
		cout << "Ingrese la fecha" << endl;
		cin >> regCabecera.fecha;

		//Acumulo el ID de la factura obteniendolo del archivo proximoIdentificador
		fread(&proxId, sizeof(int), 1, proximoIdentificador);
		cout << "El id es" << proxId << endl;
		regCabecera.idFactura = proxId;

		regCabecera.totalFactura = 0;
		cout << "Para terminar con el ingreso de articulos, presione 0." << endl;
		cin >> terminarIngresoDeArticulos;
		while (terminarIngresoDeArticulos != 0) {
			// Acumulo los datos de la factura
			regDetalle.idFactura = regCabecera.idFactura;
			cout << "Ingrese el articulo" << endl;
			cin >> regDetalle.nroArticulo;
			cout << "Ingrese la cantidad" << endl;
			cin >> regDetalle.cant;
			// Busco el nro articulo en el stock
			posArtEnStock = busquedaSecuencial(vecStock, lenStock, regDetalle.nroArticulo);
			if (posArtEnStock == -1) {
				cout << "Articulo no existente" << endl;
			}
			else {
				//La cantidad en el stock es mayor o igual a la cantidad que quiero facturar?
				if (vecStock[posArtEnStock].cantUnidades >= regDetalle.cant) {
					//Si hay suficiente lo resto del stock
					vecStock[posArtEnStock].cantUnidades -= regDetalle.cant;
					//Voy a buscar el precio en la lista de precios, posicionandome en el archivo
					fseek(listaArch, (vecStock[posArtEnStock].posListaDePrecios - 1) * sizeof(listaDePrecios), SEEK_SET);
					fread(&regListaPrecios, sizeof(listaDePrecios), 1, listaArch);
					// Calulo el total y guardo los datos en el detalle y la cabecera
					regDetalle.precioUnitario = regListaPrecios.precioUnitario;
					regDetalle.totalArticulo = regDetalle.precioUnitario * regDetalle.cant;
					regCabecera.totalFactura += regDetalle.totalArticulo;
					// Escribo el detalle en el archivo de detalles
					fwrite(&regDetalle, sizeof(detalle), 1, detalleArch);
				}
				else {
					cout << "No hay cantidad suficiente, solo quedan " << vecStock[posArtEnStock].cantUnidades << " unidades." << endl;
				}
			}
			cout << "Para terminar con el ingreso de articulos, presione 0." << endl;
			cin >> terminarIngresoDeArticulos;
		}
		//Escribo la cabecera en el archivo, al finalizar la carga de todos los datos
		fwrite(&regCabecera, sizeof(cabecera), 1, cabeceraArch);

		//Escribo el id de la proxima factura en el archivo
		rewind(proximoIdentificador);
		proxId = regCabecera.idFactura + 1;
		fwrite(&proxId, sizeof(int), 1, proximoIdentificador);
		rewind(proximoIdentificador);

		cout << "Para terminar con el ingreso de facturas, presione 0." << endl;
		cin >> terminarIngresoDeFacturas;
	}
	imprimirCabeceras(cabeceraArch, regCabecera);
	imprimirDetalles(detalleArch, regDetalle);
	fclose(listaArch);
	fclose(proximoIdentificador);
	fclose(cabeceraArch);
	fclose(detalleArch);
	*/
	
	//fseek(listaDePrecios, (posLista - 1) * sizeof(lista), SEEK_SET);
	//posLista que sale del vector
}
