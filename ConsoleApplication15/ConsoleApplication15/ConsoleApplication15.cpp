#include <iostream>
#include "..\..\Headers\vectores.hpp"


int main()
{
	/*Ejercicio 1 - Apareo de archivos hacia vector*/
	/*LLeno el archivo dot*/
	/*
	FILE* cine = fopen("dot.dat", "wb+");
	pelicula reg;

	reg.idPeli = 1234;
	strcpy(reg.nombrePeli, "Toy Story 4");
	reg.cantEsp = 5700;
	fwrite(&reg, sizeof(pelicula), 1, cine);
	reg.idPeli = 4567;
	strcpy(reg.nombrePeli, "Saw 17");
	reg.cantEsp = 4800;
	fwrite(&reg, sizeof(pelicula), 1, cine);
	reg.idPeli = 7890;
	strcpy(reg.nombrePeli, "Destino Final 47");
	reg.cantEsp = 3500;
	fwrite(&reg, sizeof(pelicula), 1, cine);
	reg.idPeli = 6543;
	strcpy(reg.nombrePeli, "Titanic");
	reg.cantEsp = 10000;
	fwrite(&reg, sizeof(pelicula), 1, cine);

	rewind(cine);
	fread(&reg, sizeof(pelicula), 1, cine);
	while (!feof(cine)) {
		cout << reg.idPeli << endl;
		cout << reg.nombrePeli << endl;
		cout << reg.cantEsp << endl;
		cout << "_______________________________________" << endl;
		fread(&reg, sizeof(pelicula), 1, cine);
	}
	fclose(cine);
	*/
	/*LLeno el archivo unicenter*/
	/*
	FILE* cine = fopen("unicenter.dat", "wb+");
	pelicula reg;

	reg.idPeli = 1234;
	strcpy(reg.nombrePeli, "Toy Story 4");
	reg.cantEsp = 5000;
	fwrite(&reg, sizeof(pelicula), 1, cine);
	reg.idPeli = 4567;
	strcpy(reg.nombrePeli, "Saw 17");
	reg.cantEsp = 35000;
	fwrite(&reg, sizeof(pelicula), 1, cine);
	reg.idPeli = 9872;
	strcpy(reg.nombrePeli, "Rapidos y Furiosos 67");
	reg.cantEsp = 11000;
	fwrite(&reg, sizeof(pelicula), 1, cine);
	reg.idPeli = 6543;
	strcpy(reg.nombrePeli, "Titanic");
	reg.cantEsp = 8750;
	fwrite(&reg, sizeof(pelicula), 1, cine);

	rewind(cine);
	fread(&reg, sizeof(pelicula), 1, cine);
	while (!feof(cine)) {
		cout << reg.idPeli << endl;
		cout << reg.nombrePeli << endl;
		cout << reg.cantEsp << endl;
		cout << "_______________________________________" << endl;
		fread(&reg, sizeof(pelicula), 1, cine);
	}
	fclose(cine);
	*/
	/*Armo el vector, evaluo y muestro resultados*/
	/*
	FILE* uni = fopen("unicenter.dat","rb");
	FILE* dot = fopen("dot.dat","rb");
	FILE* finDeSemana = fopen("finDeSemana.dat","wb+");

	pelicula vec[20];
	int lenVec = 0;
	pelicula reg;
	//Guardo todas las peliculas de unicenter en el vector
	fread(&reg,sizeof(pelicula),1,uni);
	while(!feof(uni)){
		vec[lenVec] = reg;
		lenVec++;
		fread(&reg,sizeof(pelicula),1,uni);
	}

	//Guardo en el vector las peliculas del dot
	int pos;
	fread(&reg,sizeof(pelicula),1,dot);
	while(!feof(dot)){
		pos = busquedaSecuencial(vec, lenVec, reg.idPeli);
		//Si no existe la pelicula la agrego al vector
		if(pos == -1){
			vec[lenVec] = reg;
			lenVec++;
		}
		//Si la pelicula ya existe sumo la cantidad de espectadores
		else {
			vec[pos].cantEsp += reg.cantEsp;
		}
		fread(&reg,sizeof(pelicula),1,dot);
	}
	//Ordeno por burbuja
	burbuja(vec, lenVec);
	//Informo
	cout << "La pelicula menos vista fue " << vec[0].nombrePeli << " con " << vec[0].cantEsp << " espectadores" << endl;
	cout << "Las 3 peliculas mas vistas fueron: " << endl;
	for(int i = lenVec-1; i > lenVec-4; i--) {
		cout << "- " << vec[i].nombrePeli << " con " << vec[i].cantEsp << endl;
	}
	// Armo el struct de peliculas del fin de semana, con los datos del vector ordenado
	peliculaFDS regFDS;
	for(int i = lenVec-1; i >= 0; i--) {
		strcpy(regFDS.nombrePeli,vec[i].nombrePeli);
		regFDS.cantEsp = vec[i].cantEsp;
		fwrite(&regFDS,sizeof(peliculaFDS),1,finDeSemana);
	}
	//Imprimo fin de semana
	rewind(finDeSemana);
	fread(&regFDS,sizeof(peliculaFDS),1,finDeSemana);
	while(!feof(finDeSemana)){
		cout << regFDS.nombrePeli << endl;
		cout << regFDS.cantEsp << endl;
		cout << "___________________" << endl;
		fread(&regFDS,sizeof(peliculaFDS),1,finDeSemana);
	}
	fclose(uni);
	fclose(dot);
	fclose(finDeSemana);
	*/
}
