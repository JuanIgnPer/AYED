#include <iostream>

using namespace std;

struct Estudiante {
    int Legajo;
    char nombreYApellido[50];
    char fechaDeNacimiento[6];
};

struct NodoEstudiante {
    Estudiante estudiante;
    NodoEstudiante* sig;
};

struct EstudianteConCurso {
    Estudiante estudiante;
    int curso;
};

struct NodoEstudianteConCurso {
    EstudianteConCurso estudianteConCurso;
    NodoEstudianteConCurso* sig;
};

//agrega un nuevo nodo de tipo EstudianteConCurso (prototipo sin implementacion)
void agregarNodo(NodoEstudianteConCurso* &lista, EstudianteConCurso estudianteConCurso);

void llenarListaC3(NodoEstudiante* listaC1, NodoEstudiante* listaC2, NodoEstudianteConCurso* &listaC3) {

    //uso punteros auxiliares para recorrer las listas, por las dudas
    NodoEstudiante* auxC1 = listaC1;
    NodoEstudiante* auxC2 = listaC2;

    //realizo el apareo de las listas C1 y C2, agregando informacion extra por curso en la nueva estructura
    while(auxC1 != NULL && auxC2 != NULL) {
        EstudianteConCurso estudianteConCurso;
        if (auxC1->estudiante.Legajo < auxC2->estudiante.Legajo) {
            estudianteConCurso.estudiante = auxC1->estudiante;
            estudianteConCurso.curso = 1;
            agregarNodo(listaC3, estudianteConCurso);
            auxC1 = auxC1->sig;

        } else {
            estudianteConCurso.estudiante = auxC2->estudiante;
            estudianteConCurso.curso = 2;
            agregarNodo(listaC3, estudianteConCurso);
            auxC2 = auxC2->sig;
        }
    }

    while (auxC1 != NULL) {
        EstudianteConCurso estudianteConCurso;
        estudianteConCurso.estudiante = auxC1->estudiante;
        estudianteConCurso.curso = 1;
        agregarNodo(listaC3, estudianteConCurso);
        auxC1 = auxC1->sig;
    }

    while (auxC2 != NULL) {
        EstudianteConCurso estudianteConCurso;
        estudianteConCurso.estudiante = auxC2->estudiante;
        estudianteConCurso.curso = 2;
        agregarNodo(listaC3, estudianteConCurso);
        auxC2 = auxC2->sig;
    }

    cout << "Se realizo correctamente el apareo de las listas C1 y C2 hacia la lista C3" << endl;
}