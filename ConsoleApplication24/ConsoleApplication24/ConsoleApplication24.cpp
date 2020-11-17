#include "..\..\Headers\dinamica.hpp"
#include <iostream>

int main()
{
	//EJ1
	/*
	* Se tiene un archivo “ventas.dat” que contiene los siguientes datos:
		número de cliente, artículo comprado, cantidad comprada y precio
		unitario. Con estos datos llenar una lista que debe contener número de
		cliente y dinero gastado. A su vez cada nodo de esa lista va a poseer
		una sublista de los artículos comprados, junto con su cantidad
		comprada y precio unitario. Nota: El precio unitario para cada artículo
		no varía. Si el artículo se repite por cada cliente debe incrementarse su
		cantidad vendida.
		Luego, mostrar un listado con la siguiente estructura:
		Número de Cliente: $dineroGastado por el cliente
		Detalle:
		● Artículo cantidadDeUnidades precioUnitario total
		Total de Dinero Recaudado: $dineroGastadoPorTodosLosClientes
	*/
	//Genero archivo
	/*
	FILE* archivoVenta = fopen("ventas.dat", "rb+");
	venta reg;
	reg.nroCliente = 15;
	strcpy(reg.articulo, "coca");
	reg.cant = 2;
	reg.precioUnitario = 150.75;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 15;
	strcpy(reg.articulo, "alfajor");
	reg.cant = 2;
	reg.precioUnitario = 65.2;

	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 5;
	strcpy(reg.articulo, "turron");
	reg.cant = 25;
	reg.precioUnitario = 18.6;

	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 5;
	strcpy(reg.articulo, "pepas");
	reg.cant = 5;
	reg.precioUnitario = 78;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 10;
	strcpy(reg.articulo, "pepas");
	reg.cant = 2;
	reg.precioUnitario = 78;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 15;
	strcpy(reg.articulo, "pepas");
	reg.cant = 1;
	reg.precioUnitario = 78;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 10;
	strcpy(reg.articulo, "papas");
	reg.cant = 25;
	reg.precioUnitario = 200;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 10;
	strcpy(reg.articulo, "coca");
	reg.cant = 5;
	reg.precioUnitario = 150.75;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 10;
	strcpy(reg.articulo, "pepas");
	reg.cant = 18;
	reg.precioUnitario = 78;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 5;
	strcpy(reg.articulo, "alfajor");
	reg.cant = 10;
	reg.precioUnitario = 65.2;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 10;
	strcpy(reg.articulo, "turron");
	reg.cant = 12;
	reg.precioUnitario = 18.6;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 5;
	strcpy(reg.articulo, "coca");
	reg.cant = 21;
	reg.precioUnitario = 150.75;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 15;
	strcpy(reg.articulo, "turron");
	reg.cant = 5;
	reg.precioUnitario = 18.6;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 5;
	strcpy(reg.articulo, "alfajor");
	reg.cant = 12;
	reg.precioUnitario = 65.2;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	reg.nroCliente = 15;
	strcpy(reg.articulo, "alfajor");
	reg.cant = 1;
	reg.precioUnitario = 65.2;
	fwrite(&reg, sizeof(venta), 1, archivoVenta);

	rewind(archivoVenta);
	fread(&reg, sizeof(venta), 1, archivoVenta);
	while (!feof(archivoVenta)) {
		cout << reg.nroCliente << endl;
		cout << reg.articulo << endl;
		cout << reg.cant << endl;
		cout << reg.precioUnitario << endl;
		cout << "---------------------" << endl;
		fread(&reg, sizeof(venta), 1, archivoVenta);
	}
	fclose(archivoVenta);
	*/
	//Resuelvo el ejercicio
	/*
	FILE* archivoVenta = fopen("ventas.dat", "rb");
	venta reg;
	Cliente* listaClientes = NULL;
	bool enc;
	infoCliente infoC;
	Cliente* clienteBuscado;
	infoArt infoA;
	Articulo* articuloBuscado;

	//Leo el archivo y acumulo los datos
	fread(&reg, sizeof(venta), 1, archivoVenta);
	while (!feof(archivoVenta)) {
		//Defino el infocliente para el cliente
		infoC.nroCliente = reg.nroCliente;
		infoC.dineroGastado = 0;
		infoC.articulosComprados = NULL;

		clienteBuscado = buscaEInsertaCliente(listaClientes, infoC, enc);

		//Defino el infoArt para el articulo, y lo busco
		strcpy(infoA.articulo, reg.articulo);
		infoA.cantidad = reg.cant;
		infoA.precioUnitario = reg.precioUnitario;
		//Busco el articulo que lei del archivo, en la lista de articulos comprados del cliente
		articuloBuscado = buscaEInsertaArticulo(clienteBuscado->info.articulosComprados, infoA, enc);

		if (enc) { //Si ase encontro un nuevo articulo(ya estaba insertado el articulo), se actualiza la cantidad 
			articuloBuscado->info.cantidad += reg.cant;
		} 
		//Actualizo el dinero gastado del cliente
		clienteBuscado->info.dineroGastado += reg.cant * reg.precioUnitario;
		fread(&reg, sizeof(venta), 1, archivoVenta);
	}
	fclose(archivoVenta);

	float dineroGastadoPorTodosLosClientes = 0;
	Cliente* clienteAux = listaClientes;
	while (clienteAux != NULL) {
		cout << "-----------------------------------------------------------" << endl;
		cout << "El cliente " << clienteAux->info.nroCliente << " gasto $ " << clienteAux->info.dineroGastado << endl;
		cout << "Detalle: " << endl;
		Articulo* articuloAux = clienteAux->info.articulosComprados;
		//Recorro la lista de articulos comprados de cada cliente;
		while (articuloAux != NULL) {
			cout << articuloAux->info.articulo << " - " 
				 << articuloAux->info.cantidad << " - " 
				 << articuloAux->info.precioUnitario << " - " 
				 << articuloAux->info.cantidad * articuloAux->info.precioUnitario 
				 << endl;
			articuloAux = articuloAux->sig;
		}
		dineroGastadoPorTodosLosClientes += clienteAux->info.dineroGastado;
		clienteAux = clienteAux->sig;
	}

	cout << "Total de Dinero Recaudado: " << dineroGastadoPorTodosLosClientes << endl;
	*/

	//EJ2
	/*
	* Se tiene un archivo “ingresos.dat” que contiene datos de los ingresos a los gimnasios de la
		cadena “Fitness” para el mes de septiembre. En el archivo se encuentran: nro. de socio, nro. de
		sucursal y estadía (en minutos).
		Con estos datos llenar una lista que debe contener nro. de sucursal, cantidad de personas
		distintas que la visitaron en el mes y la cantidad total de visitas. A su vez cada nodo de esa lista
		va a poseer una sublista con los socios que la visitaron, junto con su estadía total y cantidad de
		veces que visitaron la sucursal en el mes.
		Informar cuál fue el socio que más estadía tuvo en una misma sucursal e imprimir el siguiente
		listado:
		Septiembre
		Nro. de Sucursal: XXXX Cantidad de Visitas: XXXXXX Cantidad de Personas Distintas: XXXXXX
	*/
	//Genero archivo
	/*
	FILE * archivoIngreso = fopen("ingreso.dat","wb+");
	ingreso reg;

	reg.nroSucursal = 3;
	reg.nroSocio = 1000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 1000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 7000;
	reg.estadia = 120;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);
	
	reg.nroSucursal = 3;
	reg.nroSocio = 7000;
	reg.estadia = 120;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSocio = 8000;
	reg.estadia = 40;
	reg.nroSucursal = 5;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 1000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 1000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 1000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 8000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 8000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 8000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 8000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 1000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 7000;
	reg.estadia = 120;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 5000;
	reg.estadia = 90;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 5000;
	reg.estadia = 90;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 8000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 8000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 7000;
	reg.estadia = 120;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 1000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 5000;
	reg.estadia = 90;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 1000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 8000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 8000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 9000;
	reg.estadia = 20;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 7000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 5000;
	reg.estadia = 90;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 9000;
	reg.estadia = 20;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 5000;
	reg.estadia = 90;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 7000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 8000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 8000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 5000;
	reg.estadia = 90;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 1000;
	reg.estadia = 20;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 1000;
	reg.estadia = 20;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 9000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 5000;
	reg.estadia = 90;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 3;
	reg.nroSocio = 5000;
	reg.estadia = 90;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 7000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 7000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 8000;
	reg.estadia = 40;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 9000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSucursal = 5;
	reg.nroSocio = 9000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	reg.nroSocio = 9000;
	reg.estadia = 60;
	fwrite(&reg,sizeof(ingreso),1,archivoIngreso);

	rewind(archivoIngreso);
	fread(&reg,sizeof(ingreso),1,archivoIngreso);
	while(!feof(archivoIngreso)) {
		cout << reg.nroSucursal << endl;
		cout << reg.nroSocio << endl;
		cout << reg.estadia << endl;
		cout << "---------------------" << endl;
		fread(&reg,sizeof(ingreso),1,archivoIngreso);
	}
	fclose(archivoIngreso);
	*/
	//Resuelvo el ejercicio
	/*
	FILE* archIngreso = fopen("ingreso.dat", "rb");
	ingreso reg;
	Sucursal* listaSucursales = NULL;
	Sucursal* sucursalBuscada;
	Socio* socioBuscado;
	bool encSuc;
	bool encSoc;
	infoSuc infoS;
	infoSocio infoSoc;

	fread(&reg, sizeof(ingreso), 1, archIngreso);
	while (!feof(archIngreso)) {

		infoS.nroSucusal = reg.nroSucursal;
		infoS.cantPersonasDistintas = 0;
		infoS.cantVisitas = 0;
		infoS.listaSocios = NULL;
		sucursalBuscada = buscaEInsertaSucursal(listaSucursales, infoS, encSuc);

		infoSoc.nroSocio = reg.nroSocio;
		infoSoc.cantVisitas = 1;
		infoSoc.estadiaTotal = reg.estadia;
		socioBuscado = buscaEInsertaSocio(sucursalBuscada->info.listaSocios, infoSoc, encSoc);

		if (encSoc) {
			socioBuscado->info.cantVisitas++;
			socioBuscado->info.estadiaTotal += reg.estadia;
		}
		else {
			sucursalBuscada->info.cantPersonasDistintas++;
		}
		sucursalBuscada->info.cantVisitas++;

		fread(&reg, sizeof(ingreso), 1, archIngreso);
	}
	fclose(archIngreso);

	Sucursal* auxSuc = listaSucursales;
	int maxEstadia = 0;
	int maxSocio = 0;
	int maxSucursal = 0;

	//Itero por todas las sucursales
	cout << "Septiembre" << endl;
	while (auxSuc != NULL) {
		cout << "Nro de Suc: " << auxSuc->info.nroSucusal << endl 
			 << "Cantidad de Visitas: " << auxSuc->info.cantVisitas << endl 
			 << "Cantidad de Personas Distintas: " << auxSuc->info.cantPersonasDistintas << endl;

		Socio* auxSoc = auxSuc->info.listaSocios;
		//Itero por la lista de socios de cada sucursal
		while (auxSoc != NULL) {
			if (auxSoc->info.estadiaTotal > maxEstadia) {
				maxEstadia = auxSoc->info.estadiaTotal;
				maxSocio = auxSoc->info.nroSocio;
				maxSucursal = auxSuc->info.nroSucusal;
			}
			auxSoc = auxSoc->sig;
		}
		auxSuc = auxSuc->sig;
	}
	cout << "El socio de mas estadia en septiembre fue: " << maxSocio << " con " <<
	maxEstadia << " minutos, en la sucursal " << maxSucursal << endl;
	*/
}
