
#include <iostream>
#include "..\..\Headers\vectores.hpp"
using namespace std;

int main()
{
    //Ejercicio 1
    /*
    pais velocidad[150] = {{"Argentina",120,60},{"Uruguay",190,70},{"Chile",150,50}};
    //Esta hardcodeado el len ( cantidad de elementos )
    int lenVelocidad = 3;
    int posMax = -1;
    int posMin = -1;
    int maxVelocidad = buscarMaximaVelocidad(velocidad,lenVelocidad,posMax);
    int minVelocidad = buscarMinimaVelocidad(velocidad,lenVelocidad,posMin);
    cout << "La máxima velocidad la tiene el país: " << velocidad[posMax].nombre << " y es " <<  maxVelocidad << endl;
    cout << "La mínima velocidad la tiene el país: " << velocidad[posMin].nombre << " y es " <<  minVelocidad << endl;
    float promedio = sacarPromedioVelocidadMaxima(velocidad,lenVelocidad);
    cout << "El pomedio de las velocidades máximas es: " << promedio << endl;
    */
    
    //Ejercicio 2
    /*
    nota vecNota[50] = {{2345,100},{8901,60},{1357,75}};
    int lenNotas = 3;
    int materiaMaxInscriptos = buscarMaxInscriptos(vecNota, lenNotas);
    int materiaMinInscriptos = buscarMinInscriptos(vecNota, lenNotas);
    float promedioInscriptos = sacarPromedioInscriptos(vecNota, lenNotas);
    cout << "La materia con mas inscriptos es: " << materiaMaxInscriptos << endl;
    cout << "La materia con menos inscriptos es: " << materiaMinInscriptos << endl;
    cout << "El promedio de inscriptos es: " << promedioInscriptos << endl;
    */

    //Ejercicio 3
    /*
    producto vecProducto[10] = {{123,"alfajor",50.5, 25},{567,"chicle",5,100},{472, "turron", 30.7, 50}};
    int lenProducto = 3;
    int opcion;
    int n = 10;
    string nombreABuscar;
    imprimirMenu();
    cin >> opcion;
    while(opcion > 0) {
        switch(opcion) {
          case 1: {
            producto productoAInsertar;
            cout << "Ingrese el código de Producto" << endl;
            cin >> productoAInsertar.codigo;
            cout << "Ingrese el nombre" << endl;
            cin >> productoAInsertar.nombre;
            cout << "Ingrese el precio" << endl;
            cin >> productoAInsertar.precio;
            cout << "Ingrese el stock" << endl;
            cin >> productoAInsertar.stock;
            agregarProducto(vecProducto, n, lenProducto, productoAInsertar);
            lineaSeparatoria();
            mostrarProducto(vecProducto,lenProducto);
            break;
            }
          case 2: {
              lineaSeparatoria();
              cout << "Ingrese el nombre del producto a buscar" << endl;
              cin >> nombreABuscar;
              int pos = buscarProducto(vecProducto, lenProducto, nombreABuscar);
              lineaSeparatoria();
              if(pos == -1) {
                  cout << "El producto no se encuentra cargado" << endl;
              } else {
                  cout << "Código: " << vecProducto[pos].codigo << endl;
                  cout << "Nombre: " << vecProducto[pos].nombre << endl;
                  cout << "Precio: " << vecProducto[pos].precio << endl;
                  cout << "Stock: " << vecProducto[pos].stock << endl;
              }
              lineaSeparatoria();
              break;
            }
          case 3: {
              lineaSeparatoria();
              cout << "Ingrese el nombre del producto a modificar el stock" << endl;
              cin >> nombreABuscar;
              int pos = buscarProducto(vecProducto, lenProducto, nombreABuscar);
              lineaSeparatoria();
              if(pos == -1) {
                  cout << "El producto no se encuentra cargado" << endl;
              } else {
                  cout << "El stock actual es " << vecProducto[pos].stock << endl;
                  cout << "Ingrese el nuevo stock " << endl;
                  cin >> vecProducto[pos].stock;
                  lineaSeparatoria();
                  cout << "Código: " << vecProducto[pos].codigo << endl;
                  cout << "Nombre: " << vecProducto[pos].nombre << endl;
                  cout << "Precio: " << vecProducto[pos].precio << endl;
                  cout << "Stock: " << vecProducto[pos].stock << endl;
              }
              lineaSeparatoria();
              break;
            }
          case 4: {
              lineaSeparatoria();
              cout << "Ingrese el nombre del producto a modificar el precio" << endl;
              cin >> nombreABuscar;
              int pos = buscarProducto(vecProducto, lenProducto, nombreABuscar);
              lineaSeparatoria();
              if(pos == -1) {
                  cout << "El producto no se encuentra cargado" << endl;
              } else {
                  cout << "El precio actual es " << vecProducto[pos].precio << endl;
                  cout << "Ingrese el nuevo precio " << endl;
                  cin >> vecProducto[pos].precio;
                  lineaSeparatoria();
                  cout << "Código: " << vecProducto[pos].codigo << endl;
                  cout << "Nombre: " << vecProducto[pos].nombre << endl;
                  cout << "Precio: " << vecProducto[pos].precio << endl;
                  cout << "Stock: " << vecProducto[pos].stock << endl;
              }
              lineaSeparatoria();
              break;
            }
          default: {
            cout << "Por favor ingrese una opción correcta" << endl;
            break;
          }
        }
        imprimirMenu();
        cin >> opcion;
    }
    */

    //Ejercicio 4
    /*
    estudiante vecEst[20] = { {123,"Pepito",6},{567,"Menganito",7.5},{479,"Fulanito",9.3} };
    int lenVecEst = 3;
    int opcion;
    int legajo;
    int pos;
    imprimirMenuNotas();
    cin >> opcion;
    while (opcion > 0) {
        switch (opcion) {
        case 1: { //Busqueda por legajo
            lineaSeparatoria();
            cout << "Ingrese el número de legajo que desea buscar" << endl;
            cin >> legajo;
            pos = buscarEstudiante(vecEst, lenVecEst, legajo);
            if (pos != -1) {
                mostrarEstudiante(vecEst[pos]);
            }
            else {
                cout << "Estudiante no encontrado" << endl;
            }
            break;
        }
        case 2: {
            lineaSeparatoria();
            cout << "Ingrese el número de legajo del estudiante que quiere modificar la nota" << endl;
            cin >> legajo;
            pos = buscarEstudiante(vecEst, lenVecEst, legajo);
            if (pos != -1) {
                cout << "El estudiante " << vecEst[pos].nombre << " tiene la nota " << vecEst[pos].nota << endl;
                cout << "Ingrese la nueva nota" << endl;
                cin >> vecEst[pos].nota;
                cout << "Los nuevos datos del estudiante son: " << endl;
                mostrarEstudiante(vecEst[pos]);
            }
            else {
                cout << "Estudiante no encontrado" << endl;
            }
            break;
        }
        case 3: {
            lineaSeparatoria();
            cout << "El promedio de los estudiantes es" << endl;
            cout << promedioEstudiantes(vecEst, lenVecEst) << endl;
            break;
        }
        case 4: {
            lineaSeparatoria();
            pos = buscarMejorNota(vecEst, lenVecEst);
            cout << "El estudiante que tiene la mejor nota es" << endl;
            mostrarEstudiante(vecEst[pos]);
            break;
        }
        case 5: {
            lineaSeparatoria();
            pos = buscarMenorNota(vecEst, lenVecEst);
            cout << "El estudiante que tiene la menor nota es" << endl;
            mostrarEstudiante(vecEst[pos]);
            break;
        }
        default:
            cout << "Ingrese una opción correcta" << endl;
            break;
        }
        lineaSeparatoria();
        imprimirMenuNotas();
        cin >> opcion;
    }
    */
}
