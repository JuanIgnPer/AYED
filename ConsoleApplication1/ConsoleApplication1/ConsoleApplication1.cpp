#include <iostream>
using namespace std;

int main()
{
    int n1 = 0, n2 = 0, opcion = 0, r = 0, ejercicio = 0, p1 = 0, p2 = 0, p3 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, salir = 0;
    while (salir != 2)
    {
        system("cls");
        cout << "Seleccione el ejercicio que desea ejecutar" << "\n" << "Ejercicio 1" << "\n" << "Ejercicio 2" << "\n" << "Ejercicio 3" << "\n" << "Ejercicio 4" << "\n" << "Ejercicio 5" << "\n" << "Ejercicio 6" << "\n" << "Ejercicio 7" << "\n";
        cin >> ejercicio;
        switch (ejercicio)
        {
        case 1:
        {
            cout << "Por favor ingrese un numero entero A" << "\n";
            cin >> n1;
            cout << "Por favor ingrese un numero entero B" << "\n";
            cin >> n2;
            cout << "Por favor seleccione una opcion:" << "\n" << "1-Suma" << "\n" << "2-Resta" << "\n" << "3-Multiplicacion" << "\n";
            cin >> opcion;
            if (opcion == 1)
                r = n1 + n2;
            if (opcion == 2)
                r = n1 - n2;
            if (opcion == 3)
                r = n1 * n2;
            if (r < 0){
                cout << "El resultado es negativo" << "\n" << endl;
            }
            else{
                cout << "El resultado es:" << r << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Por favor ingrese la nota del primer parcial" << "\n";
            cin >> p1;
            cout << "Por favor ingrese la nota del segundo parcial" << "\n";
            cin >> p2;
            cout << "Por favor ingrese la nota del tercer parcial" << "\n";
            cin >> p3;
            r = (p1 + p2 + p3) / 3;
            cout << "El promedio es:" << r << "\n" << endl;
            break;
        }
        case 3:
        {
            cout << "Se tiran los 5 dados al azar" << "\n";
            d1 = 1 + rand() % 6;
            d2 = 1 + rand() % 6;
            d3 = 1 + rand() % 6;
            d4 = 1 + rand() % 6;
            d5 = 1 + rand() % 6;
            if (d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5)
                cout << "Se formo generala!" << "\n";
            else
                cout << "No tuviste suerte los valores fueron:" << "\n" << "Dado 1 ->" << d1 << "\n" << "Dado 2 ->" << d2 << "\n" << "Dado 3 ->" << d3 << "\n" << "Dado 4 ->" << d4 << "\n" << "Dado 5 ->" << d5 << "\n" << endl;
            break;
        }
        case 4:
        {
            cout << "Ingrese un numero entero" << endl;
            cin >> n1;
            if (n1 % 2 == 0)
                cout << "El numero es PAR" << endl;
            else
                cout << "El numero es IMPAR" << endl;
            break;
        }
        case 5:
        {
            cout << "Ingrese un lado del triangulo" << "\n";
            cin >> p1;
            cout << "Ingrese otro lado del triangulo" << "\n";
            cin >> p2;
            cout << "Ingrese el ultimo lado del triangulo" << "\n";
            cin >> p3;
            if ((p1 == p2) && (p1 == p3) && (p2 == p3))
                cout << "El triangulo es equilatero" << endl;
            if ((p1 == p2 && p1 != p3) || (p1 == p3 && p1 != p2) || (p2 == p3 && p2 != p1) || (p2 == p1 && p2 != p3) || (p3 == p2 && p3 != p1) || (p3 == p1 && p3 != p2))
                cout << "El triangulo es isosceles" << endl;
            if ((p1 != p2) && (p1 != p3) && (p2 != p3))
                cout << "El triangulo es escaleno" << endl;
            break;
        }
        case 6:
        {
            cout << "Ingrese un valor entero" << endl;
            cin >> n1;
            r = n1 / 5;
            cout << "La quinta parte es: " << r << endl;
            r = n1 % 5;
            cout << "El resto es: " << r << endl;
            r = r / 7;
            cout << "La septima parte de la quinta parte es: " << r << endl;
            break;
        }
        case 7:
        {
            int mes = 0, anio = 0;
            cout << "Ingrese un mes:" << endl;
            cin >> mes;
            cout << "Ingrese un anio:" << endl;
            cin >> anio;
            switch (mes)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            {
                cout << "31 dias" << endl;
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11:
            {
                cout << "30 dias" << endl;
                break;
            }
            case 2:
            {
                if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
                    cout << "29 dias" << endl;
                else
                    cout << "28 dias" << endl;
                break;
            }
            default:
            {
                cout << "Ingreso un mes incorrecto" << endl;
            }
            }
            break;
        }
        default:
        {
            cout << "Ingreso una opcion incorrecta" << endl;
        }
        }
        cout << "Desea continuar con la seleccion de ejercicios?" << "\n" << "1-SI" << "\n" << "2-NO" << "\n";
        cin >> salir;
    }
}