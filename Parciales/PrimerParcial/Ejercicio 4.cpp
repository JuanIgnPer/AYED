#include <iostream>
using namespace std;

struct pelicula {
	int idPeli;
	char nombrePeli[50];
	int cantEsp;
};
struct peliculaTop {
	char nombrePeli[50];
	int cantEsp;
};

void burbuja(pelicula vec[], int len);
int busquedaSecuencial(pelicula vec[], int len, int valorBuscado);

int main()
{

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

	reg.idPeli = 4568;
	strcpy(reg.nombrePeli, "Saw 18");
	reg.cantEsp = 350;
	fwrite(&reg, sizeof(pelicula), 1, cine);

	reg.idPeli = 4569;
	strcpy(reg.nombrePeli, "Saw 19");
	reg.cantEsp = 350;
	fwrite(&reg, sizeof(pelicula), 1, cine);

	reg.idPeli = 4570;
	strcpy(reg.nombrePeli, "Saw 21");
	reg.cantEsp = 350;
	fwrite(&reg, sizeof(pelicula), 1, cine);

	reg.idPeli = 9872;
	strcpy(reg.nombrePeli, "Rapidos y Furiosos 67");
	reg.cantEsp = 11000;
	fwrite(&reg, sizeof(pelicula), 1, cine);

	reg.idPeli = 9874;
	strcpy(reg.nombrePeli, "Rapidos y Furiosos 85");
	reg.cantEsp = 1100;
	fwrite(&reg, sizeof(pelicula), 1, cine);

	reg.idPeli = 6543;
	strcpy(reg.nombrePeli, "Titanic");
	reg.cantEsp = 8750;
	fwrite(&reg, sizeof(pelicula), 1, cine);

	reg.idPeli = 6544;
	strcpy(reg.nombrePeli, "Titanic 2");
	reg.cantEsp = 8750;
	fwrite(&reg, sizeof(pelicula), 1, cine);

	reg.idPeli = 6545;
	strcpy(reg.nombrePeli, "Titanic 3");
	reg.cantEsp = 8750;
	fwrite(&reg, sizeof(pelicula), 1, cine);

	reg.idPeli = 6546;
	strcpy(reg.nombrePeli, "Titanic 4");
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

	FILE* uni = fopen("unicenter.dat", "rb");
	FILE* dot = fopen("dot.dat", "rb");
	FILE* topDiez = fopen("top10.dat", "wb+");
	int cantidadRecaudadaUnicenter = 0;
	int cantidadRecaudadaDot = 0;

	pelicula vec[100];
	int lenVec = 0;
	int pos;
	pelicula reg;
	//Guardo todas las peliculas de unicenter en el vector
	fread(&reg, sizeof(pelicula), 1, uni);
	while (!feof(uni)) {
		vec[lenVec] = reg;
		lenVec++;
		cantidadRecaudadaUnicenter += reg.cantEsp * 350;
		fread(&reg, sizeof(pelicula), 1, uni);
	}
	//Guardo en el vector las peliculas del dot que no sean repetidas
	fread(&reg, sizeof(pelicula), 1, dot);
	while (!feof(dot)) {
		pos = busquedaSecuencial(vec, lenVec, reg.idPeli);
		//Si no existe la pelicula la agrego al vector
		if (pos == -1) {
			vec[lenVec] = reg;
			lenVec++;
		}
		//Si la pelicula ya existe sumo la cantidad de espectadores
		else {
			vec[pos].cantEsp += reg.cantEsp;
		}
		cantidadRecaudadaDot += reg.cantEsp * 350;
		fread(&reg, sizeof(pelicula), 1, dot);
	}
	burbuja(vec, lenVec); //Ordeno de forma ascendente

	cout << "*****************************" << endl;

	if (cantidadRecaudadaDot > cantidadRecaudadaUnicenter) {
		cout << "El cine que mas recaudo fue el Dot con un total de $" << cantidadRecaudadaDot << endl;
	}
	else {
		cout << "El cine que mas recaudo fue el Unicenter con un total de $" << cantidadRecaudadaUnicenter << endl;
	}

	cout << "*****************************" << endl;
	// Armo el struct de peliculas top, con los datos del vector ordenado en forma ascendente
	peliculaTop regTop;
	for (int i = lenVec - 10; i < lenVec; i++) {
		strcpy(regTop.nombrePeli, vec[i].nombrePeli);
		regTop.cantEsp = vec[i].cantEsp;
		fwrite(&regTop, sizeof(peliculaTop), 1, topDiez);
	}
	//Imprimo peliculas top
	rewind(topDiez);
	fread(&regTop, sizeof(peliculaTop), 1, topDiez);
	while (!feof(topDiez)) {
		cout << regTop.nombrePeli << endl;
		cout << regTop.cantEsp << endl;
		cout << "_______________________" << endl;
		fread(&regTop, sizeof(peliculaTop), 1, topDiez);
	}
	fclose(uni);
	fclose(dot);
	fclose(topDiez);

}
int busquedaSecuencial(pelicula vec[], int len, int valorBuscado) {
    int pos = -1;
    int i = 0;
    while (i < len && vec[i].idPeli != valorBuscado) {
        i++;
    }
    if (vec[i].idPeli == valorBuscado) {
        pos = i;
    }
    return pos;
}
void burbuja(pelicula vec[], int len) {
    pelicula temp;
    bool huboIntercambio = true;
    for (int i = 0; i < len && huboIntercambio; i++) {
        huboIntercambio = false;
        for (int j = 0; j < len - 1; j++) {
            if (vec[j].cantEsp > vec[j + 1].cantEsp) {
                huboIntercambio = true;
                temp = vec[j + 1];
                vec[j + 1] = vec[j];
                vec[j] = temp;
            }
        }
    }
}