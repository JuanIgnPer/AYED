#include <iostream>
#include <string>
#include "vectores.hpp"
using namespace std;

void inicializar(int vec[], int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = 0;
    }
}
void agregar(int arr[], int n, int& len, int v) {
    if (len < n) {
        arr[len] = v;
        len++;
    }
    else {
        cout << "El vector está lleno :( " << endl;
    }
}
void mostrar(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
}
int buscar(int arr[], int len, int v) {
    int i = 0;
    int pos = -1;
    while (i < len && arr[i] != v) {
        i++;
    }
    if (i < len) {
        pos = i;
    }
    return pos;
}
void eliminar(int arr[], int& len, int pos) {
    for (int i = pos; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }
    len--;
    arr[len] = 0;
}
void insertar(int arr[], int& len, int v, int pos) {
    for (int i = len - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = v;
    len++;
}
int insertarOrdenado(int arr[], int& len, int v) {
    int i = 0;
    while (i < len && arr[i] <= v) {
        i++;
    }
    insertar(arr, len, v, i);
    return i;
}
int buscaEInserta(int arr[], int& len, int v, bool& enc) {
    int pos = buscar(arr, len, v);
    if (pos == -1) {
        enc = false;
        pos = insertarOrdenado(arr, len, v);
    }
    else {
        enc = true;
    }
    return pos;
}
int buscarMinimo(int vec[], int len) {
    int min = 999999999;
    for (int i = 0; i < len; i++) {
        if (vec[i] < min) {
            min = vec[i];
        }
    }
    return min;
}
void lineaSeparatoria() {
    cout << endl;
    cout << "_____________________________" << endl;
    cout << endl;
}

/*7_Clase 13/05*/
/*Ejercicio 1*/
//int buscarMaximaVelocidad(pais vec[], int len, int& pos) {
//    int max = -1;
//    for (int i = 0; i < len; i++) {
//        if (vec[i].velocidadMax > max) {
//            max = vec[i].velocidadMax;
//            pos = i;
//        }
//    }
//    return max;
//}
//int buscarMinimaVelocidad(pais vec[], int len, int& pos) {
//    int min = 99999999;
//    for (int i = 0; i < len; i++) {
//        if (vec[i].velocidadMin < min) {
//            min = vec[i].velocidadMin;
//            pos = i;
//        }
//    }
//    return min;
//}
//float sacarPromedioVelocidadMaxima(pais vec[], int len) {
//    float suma = 0;
//    for (int i = 0; i < len; i++) {
//        suma += vec[i].velocidadMax;
//    }
//    return suma / len;
//}
/*Ejercicio 2*/
//int buscarMaxInscriptos(nota vec[], int len) {
//    int max = -1;
//    int materia = -1;
//    for (int i = 0; i < len; i++) {
//        if (vec[i].cantidadAlumnos > max) {
//            max = vec[i].cantidadAlumnos;
//            materia = vec[i].codigo;
//        }
//    }
//    return materia;
//}
//int buscarMinInscriptos(nota vec[], int len) {
//    int min = 99999999;
//    int materia = -1;
//    for (int i = 0; i < len; i++) {
//        if (vec[i].cantidadAlumnos < min) {
//            min = vec[i].cantidadAlumnos;
//            materia = vec[i].codigo;
//        }
//    }
//    return materia;
//}
//float sacarPromedioInscriptos(nota vec[], int len) {
//    float suma = 0;
//    for (int i = 0; i < len; i++) {
//        suma += vec[i].cantidadAlumnos;
//    }
//    return suma / len;
//}
/*Ejercicio 3*/
//void imprimirMenu() {
//    cout << "Ingrese 1 para dar de alta un producto" << endl;
//    cout << "Ingrese 2 para buscar un producto" << endl;
//    cout << "Ingrese 3 para modificar el stock de un producto" << endl;
//    cout << "Ingrese 4 para modificar el precio de un producto" << endl;
//    cout << "Ingrese 0 para salir" << endl;
//};
//void agregarProducto(producto arr[], int n, int& len, producto productoAGuardar) {
//    if (len < n) { // Si la cantidad de elementos actuales es menor a la cantidad maxima permitida..
//        arr[len] = productoAGuardar; //Guardo en la cantidad actual el producto (el arr arranca en 0)
//        len++; //Aumento una posicion
//    }
//    else {
//        cout << "El vector está lleno :( " << endl;
//    }
//}
//void mostrarProducto(producto arr[], int len) {
//    for (int i = 0; i < len; i++) {
//        cout << "Código: " << arr[i].codigo << endl;
//        cout << "Nombre: " << arr[i].nombre << endl;
//        cout << "Precio: " << arr[i].precio << endl;
//        cout << "Stock: " << arr[i].stock << endl;
//        lineaSeparatoria();
//    }
//}
//int buscarProducto(producto arr[], int len, string nombre) {
//    int i = 0;
//    int pos = -1;
//    while (i < len && arr[i].nombre != nombre) {
//        i++;
//    }
//    if (i < len) {
//        pos = i;
//    }
//    return pos;
//}
/*Ejercicio 4*/
//void imprimirMenuNotas() {
//    cout << "Ingrese 1 para buscar un alumno" << endl;
//    cout << "Ingrese 2 para modificar la nota de un alumno" << endl;
//    cout << "Ingrese 3 para mostrar el promedio de todas las notas" << endl;
//    cout << "Ingrese 4 para mostrar el estudiante que mejor nota se ha sacado" << endl;
//    cout << "Ingrese 5 para mostrar el estudiante que menor nota se ha sacado" << endl;
//    cout << "Ingrese 0 para salir" << endl;
//}
//int buscarEstudiante(estudiante arr[], int len, int legajo) {
//    int i = 0;
//    int pos = -1;
//    while (i < len && arr[i].legajo != legajo) {
//        i++;
//    }
//    if (i < len) {
//        pos = i;
//    }
//    return pos;
//}
//void mostrarEstudiante(estudiante est) {
//    cout << "Legajo: " << est.legajo << endl;
//    cout << "Nombre: " << est.nombre << endl;
//    cout << "Nota: " << est.nota << endl;
//}
//float promedioEstudiantes(estudiante arr[], int len) {
//    float promedio;
//    float suma = 0;
//    for (int i = 0; i < len; i++) {
//        suma += arr[i].nota;
//    }
//    promedio = suma / len;
//    return promedio;
//}
//int buscarMejorNota(estudiante vec[], int len) {
//    //Voy a devolver la posición del estudiante
//    float max = -1;
//    int pos = 0;
//    for (int i = 0; i < len; i++) {
//        if (vec[i].nota > max) {
//            max = vec[i].nota;
//            pos = i;
//        }
//    }
//    return pos;
//}
//int buscarMenorNota(estudiante vec[], int len) {
//    //Voy a devolver la posición del estudiante
//    float min = 101;
//    int pos;
//    for (int i = 0; i < len; i++) {
//        if (vec[i].nota < min) {
//            min = vec[i].nota;
//            pos = i;
//        }
//    }
//    return pos;
//}


/*8_Clase 20/05*/
/*Ejercicio 2*/
//void agregarEstudianteAED(estudianteAED arr[], int n, int& len, estudianteAED v) {
//    if (len < n) {
//        arr[len] = v;
//        len++;
//    }
//    else {
//        cout << "El vector está lleno :( " << endl;
//    }
//}
//void mostrarEstudianteAED(estudianteAED arr[], int len) {
//    for (int i = 0; i < len; i++) {
//        cout << "Legajo: " << arr[i].legajo << endl;
//        cout << "Apellido: " << arr[i].apellido << endl;
//        cout << "Promedio: " << arr[i].promedio << endl;
//        lineaSeparatoria();
//    }
//}


/*9_Clase 27/05*/
/*Ejercicio 2 - Apareo con archivos*/
//void insertarClaustro(claustroConsolidado arr[], int& len, claustroConsolidado v, int pos) {
//    for (int i = len - 1; i >= pos; i--) {
//        arr[i + 1] = arr[i];
//    }
//    arr[pos] = v;
//    len++;
//}
//int insertarOrdenadoClaustro(claustroConsolidado arr[], int& len, claustroConsolidado v) {
//    int i = 0;
//    while (i < len && arr[i].claustro.legajo <= v.claustro.legajo) {
//        i++;
//    }
//    insertarClaustro(arr, len, v, i);
//    return i;
//}


/*10_Clase03/06*/
/*Recursividad*/
//int factorial(int numero) {
//    int resultado;
//
//    if (numero == 0) {
//        resultado = 1;
//    }
//    else {
//        resultado = numero * factorial(numero - 1);
//    }
//    return resultado;
//}
//int potencia(int base, int exp) {
//    int resultado;
//    if (exp == 0) {
//        resultado = 1;
//    }
//    else {
//        resultado = base * potencia(base, exp - 1);
//    }
//    return resultado;
//}
//int fibonacci(int n) {
//    int resultado;
//    if (n == 0 || n == 1) {
//        resultado = n;
//    }
//    else {
//        resultado = fibonacci(n - 2) + fibonacci(n - 1);
//    }
//    return resultado;
//}
//int divisionNatural(int dividendo, int divisor) {
//    int resultado;
//    if (divisor > dividendo) {
//        resultado = 0;
//    }
//    else if (divisor == dividendo) {
//        resultado = 1;
//    }
//    else {
//        resultado = 1 + divisionNatural((dividendo - divisor), divisor);
//    }
//    return resultado;
//}


/*12_Clase17/06*/
//void burbuja(int vec[], int len) {
//    //Ordena unvector de de menor a mayor
//    int temp;
//    bool huboIntercambio = true;
//    //Tiene que ser menor a len, para que el j+1 no tome una posicion inexistente
//    // Mientras haya un intercambio sigue iterando
//    for (int i = 0; i < len && huboIntercambio; i++) {
//        huboIntercambio = false;
//        for (int j = 0; j < len - 1; j++) {
//            // Si es mayor intercambia valores
//            if (vec[j] > vec[j + 1]) {
//                huboIntercambio = true;
//                temp = vec[j + 1];
//                vec[j + 1] = vec[j];
//                vec[j] = temp;
//            }
//        }
//    }
//}
//void insercion(int vec[], int len) {
//    int elementoAInsertar, j;
//    for (int i = 1; i < len; i++) {
//        elementoAInsertar = vec[i];
//        j = i - 1;
//        while (j >= 0 && vec[j] > elementoAInsertar) {
//            vec[j + 1] = vec[j];
//            j--;
//        }
//        vec[j + 1] = elementoAInsertar;
//    }
//}
//void seleccion(int vec[], int len) {
//    int indiceQueTieneElValorMinimo, temp;
//    for (int i = 0; i < len - 1; i++) {
//        indiceQueTieneElValorMinimo = i;
//        for (int j = i + 1; j < len; j++) {
//            if (vec[j] < vec[indiceQueTieneElValorMinimo]) {
//                indiceQueTieneElValorMinimo = j;
//            }
//        }
//        temp = vec[indiceQueTieneElValorMinimo];
//        vec[indiceQueTieneElValorMinimo] = vec[i];
//        vec[i] = temp;
//    }
//}

/*13_Clase24/06*/
////No hace falta que el vector este ordenado
//int busquedaSecuencial(int vec[], int len, int valorBuscado) {
//    int pos = -1;
//    int i = 0;
//    while (i < len && vec[i] != valorBuscado) {
//        i++;
//    }
//    if (vec[i] == valorBuscado) {
//        pos = i;
//    }
//    return pos;
//}
//int busquedaBinaria(int vec[], int len, int valorBuscado) {
//    /*Pos queda en el medio de la busqueda
//      El vector no deberia tener vlores repetidos*/
//    int pos = -1;
//    int primero = 0;
//    int ultimo = len - 1;
//    int medio = (primero + ultimo) / 2;
//    while (primero <= ultimo) {
//        if (vec[medio] == valorBuscado) {
//            pos = medio;
//            break;
//        }
//        else if (vec[medio] < valorBuscado) {
//            primero = medio + 1;
//        }
//        else {
//            ultimo = medio - 1;
//        }
//        if (vec[primero] == valorBuscado) {
//            pos = primero;
//            break;
//        }
//        if (vec[ultimo] == valorBuscado) {
//            pos = ultimo;
//            break;
//        }
//        medio = (primero + ultimo) / 2;
//    }
//    return pos;
//} 

/*14_Clase01/07*/
/*Ejercicio 3 - Combinado*/
//int busquedaSecuencial(stock vec[], int len, int valorBuscado) {
//    int pos = -1;
//    int i = 0;
//    while (i < len && vec[i].nroArt != valorBuscado) {
//        i++;
//    }
//    if (vec[i].nroArt == valorBuscado) {
//        pos = i;
//    }
//    return pos;
//}
//void imprimirCabeceras(FILE* cabeceraArch, cabecera regCabecera) {
//    rewind(cabeceraArch);
//    cout << "Cabeceras de las Facturas" << endl;
//    fread(&regCabecera, sizeof(cabecera), 1, cabeceraArch);
//    while (!feof(cabeceraArch)) {
//        cout << regCabecera.idFactura << endl;
//        cout << regCabecera.fecha << endl;
//        cout << regCabecera.nroCliente << endl;
//        cout << regCabecera.totalFactura << endl;
//        cout << "______________________________" << endl;
//        fread(&regCabecera, sizeof(cabecera), 1, cabeceraArch);
//    }
//}
//void imprimirDetalles(FILE* detalleArch, detalle regDetalle) {
//    rewind(detalleArch);
//    cout << "Detalle de las Facturas" << endl;
//    fread(&regDetalle, sizeof(detalle), 1, detalleArch);
//    while (!feof(detalleArch)) {
//        cout << regDetalle.idFactura << endl;
//        cout << regDetalle.nroArticulo << endl;
//        cout << regDetalle.cant << endl;
//        cout << regDetalle.precioUnitario << endl;
//        cout << regDetalle.totalArticulo << endl;
//        cout << "______________________________" << endl;
//        fread(&regDetalle, sizeof(detalle), 1, detalleArch);
//    }
//}

/*16_Clase15/07*/
//int busquedaSecuencial(pelicula vec[], int len, int valorBuscado) {
//    int pos = -1;
//    int i = 0;
//    while (i < len && vec[i].idPeli != valorBuscado) {
//        i++;
//    }
//    if (vec[i].idPeli == valorBuscado) {
//        pos = i;
//    }
//    return pos;
//}
//void burbuja(pelicula vec[], int len) {
//    pelicula temp;
//    bool huboIntercambio = true;
//    for (int i = 0; i < len && huboIntercambio; i++) {
//        huboIntercambio = false;
//        for (int j = 0; j < len - 1; j++) {
//            if (vec[j].cantEsp > vec[j + 1].cantEsp) {
//                huboIntercambio = true;
//                temp = vec[j + 1];
//                vec[j + 1] = vec[j];
//                vec[j] = temp;
//            }
//        }
//    }
//}