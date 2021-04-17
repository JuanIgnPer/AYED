#include <iostream>
using namespace std;

bool esUnAnioDeOlimpiada(int anio);

int main()
{
	bool prueba;

	prueba = esUnAnioDeOlimpiada(2004);

	if (prueba == true) {
		cout << "Es un anio de olimpiada" << endl;
	}
	else {
		cout << "No es un anio de olimpiada" << endl;
	}
}

bool esUnAnioDeOlimpiada(int anio) {
	bool esAnioDeOlimpiada = false;

	if (anio % 4 == 0) {
		esAnioDeOlimpiada = true;
	}

	return esAnioDeOlimpiada;
}