
#include "..\..\Headers\dinamica.hpp"
#include <iostream>

/*Ejercicio 1*/
//Archivo
struct datos {
    int nroDeCurso;
    int legajo;
    float promedio;
};
//InfoSublista
struct infoEstudiante {
    int nroLegajo;
    float nroPromedio;    
};
//Sublista
struct Estudiante {
    infoEstudiante info;
    Estudiante* sig;
};
//InfoLista
struct infoCurso {
    int numeroDeCurso;
    int cantAprobados;
    int cantPromocionados;
    int cantRecursantes;
    Estudiante* estudiantes;
};
//Lista
struct Curso {
    infoCurso info;
    Curso* sig;
};
Curso* buscarCurso(Curso* lista, int v) {
    Curso* aux = lista;
    while (aux != NULL && aux->info.numeroDeCurso != v) {
        aux = aux->sig;
    }
    return aux;
}
//Agrega un infoEstudiante a una lista de estudiantes
void agregarEstudiante(Estudiante*& p, infoEstudiante x) {
    Estudiante* nuevo = new Estudiante();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (p == NULL) { // la lista p esta vacía 
        p = nuevo;
    }
    else {
        Estudiante* aux = p; //Genero un nodo auxiliar basado en p
        //Itero hasta encontrar el ultimo nodo
        while (aux->sig != NULL) {
            //voy recorriendo la lista hasta llegar al final
            aux = aux->sig;
        }
        //Una vez que llego al ultimo nodo, le asigno un nuevo nodo al final de p
        aux->sig = nuevo;
    }
}
void agregarCurso(Curso*& p, infoCurso x) {
    Curso* nuevo = new Curso();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (p == NULL) { // la lista p esta vacía
        p = nuevo;
    }
    else {
        Curso* aux = p;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

/*Ejercicio 2*/
struct infoTurno {
    int hora;
    char nombrePaciente[30];
};
struct NodoTurnos {
    infoTurno info;
    NodoTurnos* sig;
};
struct infoUnion {
    int hora;
    char nombrePaciente[30];
    char consultorioOrigen[30];
};
struct NodoUnion {
    infoUnion info;
    NodoUnion* sig;
};
void encolarTurno(NodoTurnos*& cFte, NodoTurnos*& cFin, infoTurno v);
infoTurno desencolarTurno(NodoTurnos*& cFte, NodoTurnos*& cFin);
void encolarUnion(NodoUnion*& cFte, NodoUnion*& cFin, infoTurno v, char consultorioOrigen[]);
infoUnion desencolarUnion(NodoUnion*& cFte, NodoUnion*& cFin);
void unirColas(NodoTurnos*& cfteA, NodoTurnos*& cfinA, NodoTurnos*& cfteB, NodoTurnos*& cfinB, NodoUnion*& cfteC, NodoUnion*& cfinC);

/*Ejercicio 3*/
void pushUsandoLista(Nodo*& p, int v);
int popUsandoLista(Nodo*& p);
/*Ejercicio 4*/
void interseccionDeListas(Nodo*& listaA, Nodo*& listaB, Nodo*& listaC);

int main()
{
    /*Ejercicio 1*/
    /*(3 puntos - 0/3) 
    Se tiene un archivo “promediosAED.dat” que contiene los siguientes datos: número de curso, legajo y promedio. 
    Con estos datos llenar una lista que contiene:
    número de curso, 
    cantidad de estudiantes aprobados, 
    cantidad de estudiantes promocionados 
    y cantidad de estudiantes recursantes. 
    A su vez cada nodo de esa lista, va a poseer una sublista de los legajos de los estudiantes, junto con su promedio.

        Nota: El archivo no está ordenado. Los estudiantes no se repiten por curso.
        Imprimir por pantalla para cada curso:
        Número de curso: XXXXXXX
        Promocionados: XXXXXX
        Aprobados: XXXXXX
        Recursantes: XXXXXX
        Detalle:
        Legajo Promedio
        ……….....

        Este ejercicio debe resolverse sí o sí en forma manuscrita. Colocar el DNI en la hoja de la resolución y sacarle una foto.
    */
    /**/
    FILE* archivoPromedio = fopen("promediosAED.dat", "wb+");
    datos reg;
    Curso* listaDeCursos = NULL;
    //Voy leyendo el archivo y guardando los datos en la lista
    fread(&reg, sizeof(datos), 1, archivoPromedio);
    while (!feof(archivoPromedio)) {
        //Busco el curso en la lista
        Curso* aux = buscarCurso(listaDeCursos, reg.nroDeCurso);
        if (aux == NULL) { //El curso no esta en la lista
            infoCurso nuevoCurso;
            if (reg.promedio >= 6) {
                nuevoCurso.cantAprobados++;
                if (reg.promedio >= 8) {
                    nuevoCurso.cantPromocionados++;
                }
            }
            else {
                nuevoCurso.cantRecursantes++;
            }
            //Al ser un nuevo curso, armo la sublista de estudiantes y el estudiante
            Estudiante* subListaEstudiante = NULL;
            infoEstudiante nuevoEstudiante;
            nuevoEstudiante.nroLegajo = reg.legajo;
            nuevoEstudiante.nroPromedio = reg.promedio;
            agregarEstudiante(subListaEstudiante, nuevoEstudiante);
            //Guardo la sublista de estudiantes
            nuevoCurso.estudiantes = subListaEstudiante;
            //Agrego el nuevo curso a la lista de cursos
            agregarCurso(listaDeCursos, nuevoCurso);
        }
        else { //El curso si esta en la lista
            if (reg.promedio >= 6) {
                aux->info.cantAprobados++;
                if (reg.promedio >= 8) {
                    aux->info.cantPromocionados++;
                }
            }
            else {
                aux->info.cantRecursantes++;
            }
            //Armo el estudiante a insertar en el curso
            infoEstudiante nuevoEstudiante;
            nuevoEstudiante.nroLegajo = reg.legajo;
            nuevoEstudiante.nroPromedio = reg.promedio;
            agregarEstudiante(aux->info.estudiantes, nuevoEstudiante);
        }
        fread(&reg, sizeof(datos), 1, archivoPromedio);
    }
    fclose(archivoPromedio);

    //Itero sobre la lista de cursos
    Curso* auxLista = listaDeCursos;
    while (auxLista != NULL) {
        cout << "Numero de curso: " << auxLista->info.numeroDeCurso << endl;
        cout << "Promocionados: " << auxLista->info.cantPromocionados << endl;
        cout << "Aprobados: " << auxLista->info.cantAprobados << endl;
        cout << "Recursantes: " << auxLista->info.cantRecursantes << endl;
        cout << "Detalle: " << endl;
        //Itero sobre la lista de estudiantes de cada curso
        Estudiante* auxSubLista = auxLista->info.estudiantes;
        while (auxSubLista != NULL) {
            cout << "Legajo: " << auxSubLista->info.nroLegajo << endl;
            cout << "Promedio: " << auxSubLista->info.nroPromedio << endl;
            auxSubLista = auxSubLista->sig;
        }
        auxLista = auxLista->sig;
    }
    
   
    /*Ejercicio 2*/
    /*(3 puntos - 2.50/3) 
    Un centro de salud cuenta con dos consultorios donde atienden dos médicos clínicos. 
    En el día de hoy, uno de los médicos se encuentra de vacaciones. 
    Dadas dos colas C1 y C2 (una por cada consultorio) con los turnos del día, 
    desarrollar un procedimiento que genere una cola única (CU) ordenada por la hora del turno que será utilizada para llamar a los pacientes. 
    Del turno sabemos, la hora (integer) y el nombre del paciente. 
    Agregar el consultorio de origen (“Consultorio 1”,”Consultorio 2”) en el registro de la nueva cola. 
    Además, se debe persistir la información de la CU en un archivo denominado “turnos20201110.dat”.

    Nota: C1 y C2 dejan de ser útiles después del apareo.*/
    /*Comentario:
    Ojo que si desencolas la CU, no la tenés más. Tendrías que haber persistido al ritmo que encolabas en la CU.

    while (CUfte != NULL) {
    auxU = desencolarUnion(CUfte, CUfin);
    fwrite(&auxU, sizeof(infoUnion), 1, archivoConsultorio);
    ----------------------
    Podria haber puesto el fwrite en la misma funcion de UnirColas. Y ahi hacer todo junto.
    }*/
    /*
    //Creo dos colas
    NodoTurnos* C1fin = NULL;
    NodoTurnos* C1fte = NULL;
    NodoTurnos* C2fin = NULL;
    NodoTurnos* C2fte = NULL;

    NodoUnion* CUfin = NULL;
    NodoUnion* CUfte = NULL;
    infoTurno aux;
    //Guardo turnos de prueba en consultorio 1
    aux.hora = 4;
    strcpy(aux.nombrePaciente, "Pepito");
    encolarTurno(C1fte, C1fin, aux);
    aux.hora = 6;
    strcpy(aux.nombrePaciente, "Pirulito");
    encolarTurno(C1fte, C1fin, aux);
    aux.hora = 8;
    strcpy(aux.nombrePaciente, "Pablito");
    encolarTurno(C1fte, C1fin, aux);

    //Guardo turnos de prueba en consultorio 2
    aux.hora = 1;
    strcpy(aux.nombrePaciente, "Juan");
    encolarTurno(C2fte, C2fin, aux);
    aux.hora = 2;
    strcpy(aux.nombrePaciente, "Jorge");
    encolarTurno(C2fte, C2fin, aux);
    aux.hora = 3;
    strcpy(aux.nombrePaciente, "Jose");
    encolarTurno(C2fte, C2fin, aux);

    //Muestro el contenido de la cola 1
    cout << "Cola 1" << endl;
    while (C1fte != NULL) {
        aux = desencolarTurno(C1fte, C1fin);
        cout << aux.hora << endl;
        cout << aux.nombrePaciente << endl;
        cout << "-----------" << endl;
    }
    //Muestro el contenido de la cola 1
    cout << "Cola 2" << endl;
    while (C2fte != NULL) {
        aux = desencolarTurno(C2fte, C2fin);
        cout << aux.hora << endl;
        cout << aux.nombrePaciente << endl;
        cout << "-----------" << endl;
    }

    unirColas(C1fte, C1fin, C2fte, C2fin, CUfte, CUfin);
    infoUnion auxU;
    //Muestro el contenido de la Union

    cout << "Cola U" << endl;
    while (CUfte != NULL) {
        auxU = desencolarUnion(CUfte, CUfin);
        cout << auxU.hora << endl;
        cout << auxU.nombrePaciente << endl;
        cout << auxU.consultorioOrigen << endl;
        cout << "-----------" << endl;
    }

    FILE* archivoConsultorio = fopen("turnos20201110.dat", "wb+");
    //Voy desencolando los nodos de la cola y los esribo en el archivo
    while (CUfte != NULL) {
        auxU = desencolarUnion(CUfte, CUfin);
        fwrite(&auxU, sizeof(infoUnion), 1, archivoConsultorio);
    }
    //Leo el archivo
    rewind(archivoConsultorio);
    fread(&auxU, sizeof(infoUnion), 1, archivoConsultorio);
    while (!feof(archivoConsultorio)) {
        cout << auxU.hora << endl;
        cout << auxU.nombrePaciente << endl;
        cout << auxU.consultorioOrigen << endl;
        cout << "-----------" << endl;
        fread(&auxU, sizeof(infoUnion), 1, archivoConsultorio);
    }
    fclose(archivoConsultorio);
    */

    /*Ejercicio 3*/
    /*(2 puntos - 2/2) 
    Redefinir el procedimiento PUSH y la función POP, imitando el funcionamiento de la pila con una lista.*/
    /*
    Nodo* lista = new Nodo();

    pushUsandoLista(lista, 1);
    pushUsandoLista(lista, 2);
    pushUsandoLista(lista, 3);
    pushUsandoLista(lista, 4);

    cout << popUsandoLista(lista)<< endl;
    cout << popUsandoLista(lista)<< endl;
    cout << popUsandoLista(lista)<< endl;
    cout << popUsandoLista(lista)<< endl;
    */

    /*Ejercicio 4*/
    /*(2 puntos - 2/2) Desarrollar un procedimiento que dadas dos listas A y B, llene una lista C con la intersección de las dos listas A y B. 
    La lista C será utilizada en el programa principal que invoca este procedimiento, como así también las listas A y B.*/
    /*
    Nodo* listaA = NULL;
    Nodo* listaB = NULL;
    Nodo* listaC = NULL;

    agregarNodo(listaA,1);
    agregarNodo(listaA,2);
    agregarNodo(listaA,3);
    agregarNodo(listaB,2);
    agregarNodo(listaB,3);
    agregarNodo(listaB,4);

    interseccionDeListas(listaA, listaB, listaC);

    cout << "Lista A: " << endl;
    mostrar(listaA);
    cout << "---------" << endl;
    cout << "Lista B: " << endl;
    mostrar(listaB);
    cout << "---------" << endl;
    cout << "Lista C: " << endl;
    mostrar(listaC);
    */
}


/*Ejercicio 2*/
void encolarTurno(NodoTurnos*& cFte, NodoTurnos*& cFin, infoTurno v) {
    NodoTurnos* nuevo = new NodoTurnos();
    nuevo->info = v;
    nuevo->sig = NULL;
    if (cFte == NULL) {
        cFte = nuevo;
    }
    else {
        cFin->sig = nuevo;
    }
    cFin = nuevo;
}
infoTurno desencolarTurno(NodoTurnos*& cFte, NodoTurnos*& cFin) {
    infoTurno retorno = cFte->info;
    NodoTurnos* aux = cFte;
    cFte = aux->sig;
    if (cFte == NULL) {
        cFin = NULL;
    }
    delete aux;
    return retorno;
}
void encolarUnion(NodoUnion*& cFte, NodoUnion*& cFin, infoTurno v, char consultorioOrigen[]) {
    NodoUnion* nuevo = new NodoUnion();
    nuevo->info.hora = v.hora;
    strcpy(nuevo->info.nombrePaciente, v.nombrePaciente);
    strcpy(nuevo->info.consultorioOrigen , consultorioOrigen);
    nuevo->sig = NULL;
    if (cFte == NULL) {
        cFte = nuevo;
    }
    else {
        cFin->sig = nuevo;
    }
    cFin = nuevo;
}
infoUnion desencolarUnion(NodoUnion*& cFte, NodoUnion*& cFin) {
    infoUnion retorno = cFte->info;
    NodoUnion* aux = cFte;
    cFte = aux->sig;
    if (cFte == NULL) { //En el caso de que "desencole" el ultimo nodo, tengo que vaiar cFin
        cFin = NULL;
    }
    delete aux; //Libera el espacio en memoria
    return retorno;
}
void unirColas(NodoTurnos*& cfteA, NodoTurnos*& cfinA, NodoTurnos*& cfteB, NodoTurnos*& cfinB, NodoUnion*& cfteC, NodoUnion*& cfinC) {
    char consultorio1[] = "Consultorio 1";
    char consultorio2[] = "Consultorio 2";

    while (cfteA != NULL && cfteB != NULL) {
        if (cfteA->info.hora < cfteB->info.hora) {
            encolarUnion(cfteC, cfinC, desencolarTurno(cfteA, cfinA), consultorio1);
        }
        else {
            encolarUnion(cfteC, cfinC, desencolarTurno(cfteB, cfinB), consultorio2);
        }
    }
    while (cfteA != NULL) {
        encolarUnion(cfteC, cfinC, desencolarTurno(cfteA, cfinA), consultorio1);
    }
    while (cfteB != NULL) {
        encolarUnion(cfteC, cfinC, desencolarTurno(cfteB, cfinB), consultorio2);
    }
}

/*Ejercicio 3*/
void pushUsandoLista(Nodo*& lista, int v) {
    Nodo* nuevaLista = new Nodo();
    nuevaLista->info = v; //Guardo el valor a guardar en el primer nodo
    //Armo una lista auxiliar para no perder la referencia
    Nodo* aux = lista;
    while (aux != NULL) {
        //Guardo los valores de la lista original
        agregarNodo(nuevaLista, eliminarPrimerNodo(aux));
    }
    lista = nuevaLista;
}
int popUsandoLista(Nodo*& p) {
    return eliminarPrimerNodo(p);
}

/*Ejercicio 4*/
void interseccionDeListas(Nodo*& listaA, Nodo*& listaB, Nodo*& listaC){
    Nodo* nodoBuscado = NULL;
    Nodo* listaAaux = listaA;
    Nodo* listaBaux = listaB;

    while (listaAaux != NULL) {
        nodoBuscado = buscar(listaBaux, listaAaux->info); 
        //Si retorna NULL significa que no se encontro el valor
        if (nodoBuscado != NULL) {
            //Si no es NULL, entonces significa que el valor de A si esta en B
            //Inserto el valor en C
            //cout << "encontre un valor" << endl;
            agregarNodo(listaC,nodoBuscado->info);
        }
        listaAaux = listaAaux->sig;
    }
}