#include <iostream> 
#include <stdio.h> 
#include <string.h> 

using namespace std;

struct Registro {
    int legajo;
    char materia[20];
    char curso[10];
    float nota;
};

struct Promedios {
    int legajo;
    float promedio;
};

struct Alumno {
    int legajo;
    char materia[20];
    char curso[10];
};

template <typename T>
T read(FILE* f);

template <typename T>
void write(FILE* f, T v);

template <typename T>
int agregar(T v[], int& len, T x);

void crearArchivoNotas();
Registro crearRegistro(int legajo, string materia, string curso, float nota);
void mostrarLista(Promedios lista[], int len);
int calcularPromedioMax(Promedios lista[], int len);
int calcularPromedioMin(Promedios lista[], int len);
void procesarAprobados(Alumno lista[], int len);
void guardarAprobados(Alumno lista[], int len);
void leerAprobados(); // para pruebas 

int main()
{
    Promedios lista[10];
    int len = 0;

    Alumno aprobados[10];
    int lenA = 0;

    crearArchivoNotas();

    FILE* f1 = fopen("../notas.DAT", "r+b");
    Registro r = read<Registro>(f1); //leo el primer registro 

    while (!feof(f1)) {
        int sum = 0;
        float ac = 0;

        int legAnterior = r.legajo; // porque esta ordenado por legajo 
        lista[len].legajo = r.legajo;

        while (!feof(f1) && legAnterior == r.legajo) { // control 
            ac = ac + r.nota;
            sum++;

            if (r.nota >= 6) {
                Alumno x;
                x.legajo = r.legajo;
                strcpy(x.materia, r.materia);
                strcpy(x.curso, r.curso);
                agregar<Alumno>(aprobados, lenA, x);
            }

            r = read<Registro>(f1);
        }
        lista[len].promedio = ac / sum;
        len++;
    }

    fclose(f1);

    mostrarLista(lista, len);

    int pMax = calcularPromedioMax(lista, len);
    int pMin = calcularPromedioMin(lista, len);

    cout << "el mejor promedio es: " << lista[pMax].legajo << endl;
    cout << "el peor promedio es: " << lista[pMin].legajo << endl;

    cout << "________________________________________________________" << endl;

    procesarAprobados(aprobados, lenA);
    guardarAprobados(aprobados, lenA);
    //leerAprobados(); // para pruebas 

    return 0;
}

void crearArchivoNotas() {

    FILE* f1 = fopen("../notas.DAT", "w+b");

    write<Registro>(f1, crearRegistro(10, "analisis", "z101", 8.5));
    write<Registro>(f1, crearRegistro(10, "algebra", "z103", 5));
    write<Registro>(f1, crearRegistro(10, "fisica", "z105", 6));

    write<Registro>(f1, crearRegistro(20, "analisis", "z102", 8.5));
    write<Registro>(f1, crearRegistro(20, "quimica", "z108", 5));

    write<Registro>(f1, crearRegistro(40, "fisica", "z105", 9.2));
    write<Registro>(f1, crearRegistro(40, "analisis", "z101", 8.4));
    write<Registro>(f1, crearRegistro(40, "quimica", "z108", 4));

    write<Registro>(f1, crearRegistro(60, "fisica", "z105", 10));
    write<Registro>(f1, crearRegistro(60, "algebra", "z103", 7.4));

    fclose(f1);
}

Registro crearRegistro(int legajo, string materia, string curso, float nota) {
    Registro p;
    p.legajo = legajo;
    strcpy(p.materia, materia.c_str());
    strcpy(p.curso, curso.c_str());
    p.nota = nota;
    return p;
}

void mostrarLista(Promedios lista[], int len) {
    for (int i = 0; i < len; i++) {
        cout << lista[i].legajo << " - " << lista[i].promedio << endl;
    }
}

int calcularPromedioMax(Promedios lista[], int len) {
    int nMax = 0;
    int pos;
    for (int i = 0; i < len; i++) {
        if (nMax < lista[i].promedio) {
            nMax = lista[i].promedio;
            pos = i;
        }
    }
    return pos;
}

int calcularPromedioMin(Promedios lista[], int len) {
    int nMin = 99;
    int pos;
    for (int i = 0; i < len; i++) {
        if (nMin > lista[i].promedio) {
            nMin = lista[i].promedio;
            pos = i;
        }
    }
    return pos;
}


void procesarAprobados(Alumno lista[], int len) {
    int i = 0;
    while (i < len) {

        int legAnterior = lista[i].legajo; // porque esta ordenado por legajo 
        cout << lista[i].legajo;

        while ((i < len) && legAnterior == lista[i].legajo) { // control 
            cout << " : " << lista[i].materia;
            i++;
        }
        cout << endl;
    }
}


void guardarAprobados(Alumno lista[], int len) {
    FILE* f1 = fopen("../aprobados.DAT", "w+b");
    for (int i = 0; i < len; i++) {
        write<Alumno>(f1, lista[i]);
    }

    fclose(f1);
}

void leerAprobados() {
    FILE* f1 = fopen("../aprobados.DAT", "r+b");
    Alumno a = read<Alumno>(f1);
    while (!feof(f1)) {

        cout << a.legajo << " - " << a.materia << " - " << a.curso << endl;
        a = read<Alumno>(f1);
    }
    fclose(f1);

}

template <typename T>
int agregar(T v[], int& len, T x) {
    v[len] = x;
    len++;

    return len - 1;
}

template <typename T>
T read(FILE* f) {
    T buff;
    fread(&buff, sizeof(T), 1, f);
    return buff;
}

template <typename T>
void write(FILE* f, T v) {
    fwrite(&v, sizeof(T), 1, f);
}