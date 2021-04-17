#include <iostream>
using namespace std;

/*
Desarrolle una función que dado un mes (1 a 12) y un año (AAAA) que se pasan por parámetro devuelva la cantidad de días que tiene ese mes.
Recordar que un año puede ser bisiesto. Un año es bisiesto si es divisible entre cuatro y no es divisible entre 100 o es divisible entre 400.
*/
int cantidadDeDiasDelMes(int mes, int anio);

int main()
{
	int diasDeFebrero = cantidadDeDiasDelMes(2, 2020);
	cout << diasDeFebrero << endl;

}
int cantidadDeDiasDelMes(int mes, int anio) {
	switch (mes)
	{
	case  1:
	case  3:
	case  5:
	case  7:
	case  8:
	case 10:
	case 12: return 31;
		break;
	case  4:
	case  6:
	case  9:
	case 11: return 30;
		break;
	case  2:
		//Si el anio es biciesto febrero tiene 29 dias
		if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0)
			return 29;
		else
			return 28;
		break;
	default:
		cout << "Mes Invalido" << endl;
		break;
	}
}
