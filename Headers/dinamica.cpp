#include <iostream>
#include <string>
#include "dinamica.hpp"
using namespace std;

/*16 Clase 15/07*/
/*Listas*/
void agregarNodo(Nodo*& p, int x) {
    Nodo* nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (p == NULL) { // la lista p esta vacía 
        p = nuevo;
    }
    else {
        Nodo* aux = p; //Genero un nodo auxiliar basado en p
        //Itero hasta encontrar el ultimo nodo
        while (aux->sig != NULL) {
            //voy recorriendo la lista hasta llegar al final
            aux = aux->sig;
        }
        //Una vez que llego al ultimo nodo, le asigno un nuevo nodo al final de p
        aux->sig = nuevo;
    }
}
void mostrar(Nodo* p) {
    Nodo* aux = p; //Defino una lista, copia de p, para no perder p
    while (aux != NULL) { //Mientras no llego al final de lista..
        cout << aux->info << endl; //Muestro cada valor
        aux = aux->sig; //Avanzo
    }
}
void liberar(Nodo*& p) {
    Nodo* aux;
    while (p != NULL) {
        aux = p;
        p = p->sig;
        delete aux;
    }
}
Nodo* buscar(Nodo* p, int v) {
    Nodo* aux = p;
    //Itero mientras el valor pasado por referencia no es el buscado
    // y no es el final de la lista
    while (aux != NULL && aux->info != v) {
        aux = aux->sig;
    }
    // En el caso de que llegue al final de la lista, retorna null
    return aux;
}
void eliminar(Nodo*& p, int v) {
    Nodo* aux = p; //Creo un auxiliar basado en p
    Nodo* ant = NULL; //Creo el anterior
    //El mismo metodo de busqueda
    while (aux != NULL && aux->info != v) {
        ant = aux;
        aux = aux->sig;
    }
    // Si llegamos al final de la lista y no encontramos el valor ...
    if (ant == NULL) { //Estamos eliminando el primer nodo
        p = aux->sig;
    }
    else { // Estoy eliminando un nodo intermedio
        //aux = Nodo que quiero eliminar
        //ant = Nodo anterior del que quiero eliminar
        //ant->sig = Actualmente apunta al nodo  que quiero eliminar
        //aux->sig = Nodo siguiente al que quiero eliminar
        // El sig del anterior apunta al siguiente del que elimino
        ant->sig = aux->sig;
    }
    delete aux;
}
int eliminarPrimerNodo(Nodo*& p) {
    int retorno = p->info;
    Nodo* aux = p;
    p = p->sig;
    delete aux;
    return retorno;
}
Nodo* insertarOrdenado(Nodo*& p, int v) {
    // Inserta de forma ordenada de menor a mayor
    Nodo* nuevo = new Nodo();
    nuevo->info = v;
    nuevo->sig = NULL;
    Nodo* ant = NULL;
    Nodo* aux = p;
    while (aux != NULL && aux->info <= v) {
        ant = aux;
        aux = aux->sig;
    }
    if (ant == NULL) { //Estoy insertando al principio
        p = nuevo;
    }
    else {
        ant->sig = nuevo;
    }
    nuevo->sig = aux;
    return nuevo; //Devuelvo la direccion de memoria 
}
void ordenar(Nodo*& p) {
    Nodo* q = NULL;
    int valor;
    while (p != NULL) {
        valor = eliminarPrimerNodo(p);
        insertarOrdenado(q, valor);
    }
    p = q;
}
Nodo* buscaEInsertaOrdenado(Nodo*& p, int v, bool& enc) {
    Nodo* nodoBuscado = buscar(p, v);
    if (nodoBuscado != NULL) { // el nodo está en la lista
        enc = true;
    }
    else { // el nodo no está
        nodoBuscado = insertarOrdenado(p, v);
        enc = false;
    }
    return nodoBuscado;
}


/*17 Clase 22/7*/
/*Pilas*/
void push(Nodo*& p, int v) {
    Nodo* nuevo = new Nodo();
    nuevo->info = v; //Creo un nuevo nodo que apunta al valor nuevo
    nuevo->sig = p; //Defino como siguiente a p
    p = nuevo; //La pila ahora es, la pila recibida MAS el nodo con el valor V
}
int pop(Nodo*& p) {
    int retorno = p->info;
    Nodo* aux = p;
    p = aux->sig;
    delete aux; //Libera el espacio en memoria
    return retorno;
}

/*Colas*/
void encolar(Nodo*& cFte, Nodo*& cFin, int v) {
    Nodo* nuevo = new Nodo();
    nuevo->info = v;
    nuevo->sig = NULL;
    if (cFte == NULL) {
        cFte = nuevo; // Si cFte es NULL significa que la cola esta vacia, asi que solo asigno nuevo
    }
    else { //Si la cola tiene datos, agrego a la cola el nuevo nodo, apuntando el siguiente de cFin
        cFin->sig = nuevo;
    }
    cFin = nuevo;
}
int desencolar(Nodo*& cFte, Nodo*& cFin) {
    int retorno = cFte->info;
    Nodo* aux = cFte;
    cFte = aux->sig;
    if (cFte == NULL) { //En el caso de que "desencole" el ultimo nodo, tengo que vaiar cFin
        cFin = NULL;
    }
    delete aux; //Libera el espacio en memoria
    return retorno;
}

/*Ejercicio 1 - Pilas*/
void eliminarLosDosPrimerosNodos(Nodo*& pila, int x) {
    for (int i = 0; i < 2; i++)
    {
        pop(pila);
    }
    push(pila, x);
    while (pila != NULL)
    {
        cout << pop(pila) << endl;
    }
}
/*Ejercicio 2 - Pilas*/
void colocarEnTercerLugar(Nodo*& pila, int x, char& exitoso) {
    Nodo* pilaAux = NULL;
    int i = 0;
    while (pila != NULL && i < 2) {
        push(pilaAux, pop(pila));
        i++;
    }
    if (i == 2) {
        exitoso = 'S';
        push(pila, x); //Si fue exitoso agrego el valor x
    }
    else {
        exitoso = 'N';
    }
    while (pilaAux != NULL) {
        push(pila, pop(pilaAux));
    }//Vuelvo a armar la pila    
}
/*Ejercicio 3 - Pilas*/
void colocarEnPosicionYLugar(Nodo*& pila, int x, int y, char& exitoso) {
    Nodo* pilaAux = NULL;
    int i = 0;
    while (pila != NULL && i < (y - 1)) {
        push(pilaAux, pop(pila));
        i++;
    }
    if (i == (y-1)) {
        exitoso = 'S';
        push(pila, x); //Si fue exitoso agrego el valor x
    }
    else {
        exitoso = 'N';
    }
    while (pilaAux != NULL) {
        push(pila, pop(pilaAux));
    }//Vuelvo a armar la pila    
}
/*Ejercicio 4 - Pilas*/
void reemplazarXporY(Nodo*& pila, int x, int y) {
    Nodo* pilaAux = NULL;
    int valor;
    while (pila != NULL) {
        valor = pop(pila);
        if (valor == x) {
            valor = y;
        }
        push(pilaAux, valor);
    }
    while (pilaAux != NULL) {
        push(pila, pop(pilaAux));
    }
}
/*Ejercicio 5 - Pilas*/
void encolarInv(NodoInv*& cFte, NodoInv*& cFin, int v) {
    NodoInv* nuevo = new NodoInv();
    nuevo->info = v;
    nuevo->sig = NULL;
    if (cFte == NULL) {
        cFte = nuevo; // Si cFte es NULL significa que la cola esta vacia, asi que solo asigno nuevo
    }
    else { //Si la cola tiene datos, agrego a la cola el nuevo nodo, apuntando el siguiente de cFin
        cFin->sig = nuevo;
    }
    cFin = nuevo;
}
int desencolarInv(NodoInv*& cFte, NodoInv*& cFin) {
    int retorno = cFte->info;
    NodoInv* aux = cFte;
    cFte = aux->sig;
    if (cFte == NULL) { //En el caso de que "desencole" el ultimo nodo, tengo que vaiar cFin
        cFin = NULL;
    }
    delete aux; //Libera el espacio en memoria
    return retorno;
}
void pushInv(NodoInv*& p, int v) {
    NodoInv* nuevo = new NodoInv();
    nuevo->info = v; //Creo un nuevo nodo que apunta al valor nuevo
    nuevo->sig = p; //Defino como siguiente a p
    p = nuevo; //La pila ahora es, la pila recibida MAS el nodo con el valor V
}
int popInv(NodoInv*& p) {
    int retorno = p->info;
    NodoInv* aux = p;
    p = aux->sig;
    delete aux; //Libera el espacio en memoria
    return retorno;
}
bool inversa(NodoInv*& colaFte, NodoInv*& colaFin) {
    bool retorno = true;
    NodoInv* pila = NULL;
    while (colaFte->info != '.') {
        pushInv(pila, desencolarInv(colaFte, colaFin)); //Armo una pila con lo que saque de la cola
    }
    desencolarInv(colaFte, colaFin); //Saco el punto
    while (colaFte != NULL) {
        //Si los caracteres son diferentes, significa que no son inversos
        if (desencolarInv(colaFte, colaFin) != popInv(pila)) {
            retorno = false;
            break;
        }
    }
    return retorno;
}
/*Ejercicio 6 - Pilas*/
void pushEst(NodoEst*& p, string v) {
    NodoEst* nuevo = new NodoEst();
    nuevo->info = v; //Creo un nuevo nodo que apunta al valor nuevo
    nuevo->sig = p; //Defino como siguiente a p
    p = nuevo; //La pila ahora es, la pila recibida MAS el nodo con el valor V
}
string popEst(NodoEst*& p) {
    string retorno = p->info;
    NodoEst* aux = p;
    p = aux->sig;
    delete aux; //Libera el espacio en memoria
    return retorno;
}
void imprimirApellidosOrdenInverso() {
    NodoEst* pila = NULL;
    string apellido;
    cout << "Ingresar Apellido. Terminar con X" << endl;
    cin >> apellido;
    while (apellido != "X") {
        pushEst(pila, apellido); //Ingreso los apellidos en una pila
        cout << "Ingresar Apellido. Terminar con X" << endl;
        cin >> apellido;
    }
    //Al ingresar x, muestro los nombres en orden inverso
    while (pila != NULL) {
        cout << popEst(pila) << endl;
    }
}
/*Ejercicio 7 - Pilas*/
void ordenarPila(Nodo*& pila) {
    Nodo* lista = NULL;
    //Creo una lista vacia
    while (pila != NULL) {
        //Tomo los datos de la pila y los inserto ordenados directamente en la lista
        insertarOrdenado(lista, pop(pila));
    }
    while (lista != NULL) {
        //Saco los datos de la lista e inserto directamente en la pila (ya ordenados)
        push(pila, eliminarPrimerNodo(lista));
    }
}


/*Ejercicio 1 - Colas*/
void encolarEstudiante(NodoEstudiante*& cFte, NodoEstudiante*& cFin, est v) {
    NodoEstudiante* nuevo = new NodoEstudiante();
    nuevo->info = v;
    nuevo->sig = NULL;
    if (cFte == NULL) {
        cFte = nuevo; // Si cFte es NULL significa que la cola esta vacia, asi que solo asigno nuevo
    }
    else { //Si la cola tiene datos, agrego a la cola el nuevo nodo, apuntando el siguiente de cFin
        cFin->sig = nuevo;
    }
    cFin = nuevo;
}
est desencolarEstudiante(NodoEstudiante*& cFte, NodoEstudiante*& cFin) {
    est retorno = cFte->info;
    NodoEstudiante* aux = cFte;
    cFte = aux->sig;
    if (cFte == NULL) { //En el caso de que "desencole" el ultimo nodo, tengo que vaiar cFin
        cFin = NULL;
    }
    delete aux; //Libera el espacio en memoria
    return retorno;
}
char eliminarNodos(NodoEstudiante*& cfte, NodoEstudiante*& cfin, int cantNodosAEliminar) {
     //Cuando no hay nada ambos apuntan a NULL
    int contador = 0;
    char resultado;

    while (cfte != NULL && contador < cantNodosAEliminar) {
        desencolarEstudiante(cfte, cfin);
        contador++;
    }
    if (contador == cantNodosAEliminar) {
        resultado = 'S';
    }
    else {
        resultado = 'N';
    }
    return resultado;
}
/*Ejercicio 2 - Colas*/
void agregarNodoEstudiante(NodoEstudiante*& p, est x) {
    NodoEstudiante* nuevo = new NodoEstudiante();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (p == NULL) { // la lista p esta vacía 
        p = nuevo;
    }
    else {
        NodoEstudiante* aux = p; //Genero un nodo auxiliar basado en p
        //Itero hasta encontrar el ultimo nodo
        while (aux->sig != NULL) {
            //voy recorriendo la lista hasta llegar al final
            aux = aux->sig;
        }
        //Una vez que llego al ultimo nodo, le asigno un nuevo nodo al final de p
        aux->sig = nuevo;
    }
}
est eliminarPrimerNodoEstudiante(NodoEstudiante*& p) {
    est retorno = p->info;
    NodoEstudiante* aux = p;
    p = p->sig;
    delete aux;
    return retorno;
}
int contarNodos(NodoEstudiante*& cfte, NodoEstudiante*& cfin) {
    //La estrategia consiste en pasar toda la cola a una lista,
    //contar la cantidad de nodos que tiene la pila
    // y luego volver a insertar en la cola los datos de la lista
    int contador = 0;
    NodoEstudiante* lista = NULL;

    while (cfte != NULL) {
        agregarNodoEstudiante(lista, desencolarEstudiante(cfte, cfin));
        contador++;
    }
    while (lista != NULL) {
        encolarEstudiante(cfte, cfin, eliminarPrimerNodoEstudiante(lista));
    }
    return contador;
}
/*Ejercicio 3 - Colas*/
void unirColas(NodoEstudiante*& cfteA, NodoEstudiante*& cfinA, NodoEstudiante*& cfteB, NodoEstudiante*& cfinB, NodoEstudiante*& cfteC, NodoEstudiante*& cfinC) {

    while (cfinA != NULL) {
        encolarEstudiante(cfteC, cfinC, desencolarEstudiante(cfteA, cfinA));
    }
    while (cfinB != NULL) {
        encolarEstudiante(cfteC, cfinC, desencolarEstudiante(cfteB, cfinB));
    }
}
/*Ejercicio 4 - Colas*/
void pushEstudiante(NodoEstudiante*& p, est v) {
    NodoEstudiante* nuevo = new NodoEstudiante();
    nuevo->info = v; //Creo un nuevo nodo que apunta al valor nuevo
    nuevo->sig = p; //Defino como siguiente a p
    p = nuevo; //La pila ahora es, la pila recibida MAS el nodo con el valor V
}
est popEstudiante(NodoEstudiante*& p) {
    est retorno = p->info;
    NodoEstudiante* aux = p;
    p = aux->sig;
    delete aux; //Libera el espacio en memoria
    return retorno;
}
void imprimirCola(NodoEstudiante*& cfte, NodoEstudiante*& cfin) {
    int cantNodos = contarNodos(cfte, cfin);
    est aux;

    if (cantNodos > 100) {
        while (cfte != NULL) {
            aux = desencolarEstudiante(cfte, cfin);
            cout << aux.legajo << endl;
            cout << aux.nya << endl;
            cout << aux.curso << endl;
        }
    }
    else {
        NodoEstudiante* pila = NULL;
        while (cfte != NULL) {
            pushEstudiante(pila, desencolarEstudiante(cfte, cfin));
        }

        while (pila != NULL) {
            aux = popEstudiante(pila);
            cout << aux.legajo << endl;
            cout << aux.nya << endl;
            cout << aux.curso << endl;
        }
    }
}
/*Ejercicio 5 - Colas*/
void apareo(NodoEstudiante*& cfteA, NodoEstudiante*& cfinA, NodoEstudiante*& cfteB, NodoEstudiante*& cfinB, NodoEstudiante*& cfteC, NodoEstudiante*& cfinC) {
    while (cfteA != NULL && cfteB != NULL) {
        if (cfteA->info.legajo < cfteB->info.legajo) {
            encolarEstudiante(cfteC, cfinC, desencolarEstudiante(cfteA, cfinA));
        }
        else {
            encolarEstudiante(cfteC, cfinC, desencolarEstudiante(cfteB, cfinB));
        }
    }
    while (cfteA != NULL) {
        encolarEstudiante(cfteC, cfinC, desencolarEstudiante(cfteA, cfinA));
    }
    while (cfteB != NULL) {
        encolarEstudiante(cfteC, cfinC, desencolarEstudiante(cfteB, cfinB));
    }
}

/*Ejercicio 1 - Listas*/
int contarNodosLista(NodoEstudiante* lista) {
    int contador = 0;
    while (lista != NULL) {
        lista = lista->sig;
        contador++;
    }
    return contador;
}
/*Ejercicio 2 - Listas*/
void unirListasEliminandoNodos(NodoEstudiante*& listaA, NodoEstudiante*& listaB, NodoEstudiante*& listaC) {
    while (listaA != NULL) {
        agregarNodoEstudiante(listaC, eliminarPrimerNodoEstudiante(listaA));
    }
    while (listaB != NULL) {
        agregarNodoEstudiante(listaC, eliminarPrimerNodoEstudiante(listaB));
    }
}
void unirListasNoEliminandoNodos(NodoEstudiante* listaA, NodoEstudiante* listaB, NodoEstudiante*& listaC) {
    NodoEstudiante* auxA = listaA;
    NodoEstudiante* auxB = listaB;

    while (auxA != NULL) {
        agregarNodoEstudiante(listaC, auxA->info);
        auxA = auxA->sig;
    }
    while (auxB != NULL) {
        agregarNodoEstudiante(listaC, auxB->info);
        auxB = auxB->sig;
    }
}
/*Ejercicio 3 - Listas*/
void mostrarEstudiante(NodoEstudiante* p) {
    NodoEstudiante* aux = p; //Defino una lista, copia de p, para no perder p
    while (aux != NULL) { //Mientras no llego al final de lista..
        cout << aux->info.legajo << endl;
        cout << aux->info.nya << endl;
        cout << aux->info.curso << endl;//Muestro cada valor
        aux = aux->sig; //Avanzo
    }
}
void imprimirLista(NodoEstudiante* lista) {
    int cantNodos = contarNodosLista(lista);

    if (cantNodos > 100) {
        //Muestro todos los estudiantes en orden natural
        mostrarEstudiante(lista);
    }
    else {
        NodoEstudiante* pila = NULL;
        NodoEstudiante* aux = lista;
        //Recorro la lista
        while (aux != NULL) {
            //Pongo todos los estudiantes en la pila
            pushEstudiante(pila, aux->info);
            aux = aux->sig;
        }
        est datosDelNodo;
        //Recorro la pila 
        while (pila != NULL) {
            //Muestro los datos
            cout << "--------------" << endl;
            datosDelNodo = popEstudiante(pila);
            cout << datosDelNodo.legajo << endl;
            cout << datosDelNodo.nya << endl;
            cout << datosDelNodo.curso << endl;
        }
    }
}
/*Ejercicio 4 - Listas*/
void apareoListas(NodoEstudiante*& listaA, NodoEstudiante*& listaB, NodoEstudiante*& listaC) {
    while (listaA != NULL && listaB != NULL) {
        if (listaA->info.legajo < listaB->info.legajo) {
            agregarNodoEstudiante(listaC, eliminarPrimerNodoEstudiante(listaA));
        }
        else {
            agregarNodoEstudiante(listaC, eliminarPrimerNodoEstudiante(listaB));
        }
    }
    while (listaA != NULL) {
        agregarNodoEstudiante(listaC, eliminarPrimerNodoEstudiante(listaA));
    }
    while (listaB != NULL) {
        agregarNodoEstudiante(listaC, eliminarPrimerNodoEstudiante(listaB));
    }
}
void apareoListasSinEliminarNodo(NodoEstudiante* listaA, NodoEstudiante* listaB, NodoEstudiante*& listaC) {
    NodoEstudiante* auxA = listaA;
    NodoEstudiante* auxB = listaB;

    while (auxA != NULL && auxB != NULL) {
        if (auxA->info.legajo < auxB->info.legajo) {
            agregarNodoEstudiante(listaC, auxA->info);
            auxA = auxA->sig;
        }
        else {
            agregarNodoEstudiante(listaC, auxB->info);
            auxB = auxB->sig;
        }
    }
    while (auxA != NULL) {
        agregarNodoEstudiante(listaC, auxA->info);
        auxA = auxA->sig;
    }
    while (auxB != NULL) {
        agregarNodoEstudiante(listaC, auxB->info);
        auxB = auxB->sig;
    }
}
/*Ejercicio 5 - Listas*/
NodoEstudiante* insertarOrdenadoEstudiante(NodoEstudiante*& p, est v) {
    NodoEstudiante* nuevo = new NodoEstudiante();
    nuevo->info = v;
    nuevo->sig = NULL;
    NodoEstudiante* ant = NULL;
    NodoEstudiante* aux = p;

    while (aux != NULL && aux->info.legajo <= v.legajo) {
        ant = aux;
        aux = aux->sig;
    }
    if (ant == NULL) { //Estoy insertando al principio
        p = nuevo;
    }
    else {
        ant->sig = nuevo;
    }
    nuevo->sig = aux;
    return nuevo;
}

/*Pilas*/
/*Ejercicio 1 - Pilas*/
void pushChar(Nodo*& p, char v) {
    Nodo* nuevo = new Nodo();
    nuevo->info = v; //Creo un nuevo nodo que apunta al valor nuevo
    nuevo->sig = p; //Defino como siguiente a p
    p = nuevo; //La pila ahora es, la pila recibida MAS el nodo con el valor V
}
char popChar(Nodo*& p) {
    int retorno = p->info;
    Nodo* aux = p;
    p = aux->sig;
    delete aux; //Libera el espacio en memoria
    return retorno;
}
bool estaBalanceado(char vec[], int len) {
    bool resultado = true;
    Nodo* pila = NULL;
    //Recorro el vector de chars
    for (int i = 0; i < len; i++) {
        switch (vec[i]) {
        //En el caso de que sea un "abrir"
        case '(':
        case '{':
        case '[':
            //Lo guardo en la pila
            pushChar(pila, vec[i]);
            break;
        //En el caso de que sea un cerrar..
        //Lo comparo con el ultimo valor guardado en la pila
        case ')':
            if (popChar(pila) != '(') {
                resultado = false;
                break;
            }
            break;
        case '}':
            if (popChar(pila) != '{') {
                resultado = false;
                break;
            }
            break;
        case ']':
            if (popChar(pila) != '[') {
                resultado = false;
                break;
            }
            break;
        }
    }
    return resultado;
}
/*Ejercicio 2 - Pilas*/
int calculoPolacaInversa(char vec[], int len) {
    Nodo* pila = NULL;
    int op1;
    int op2;

    for (int i = 0; i < len; i++) {
        switch (vec[i]) {
        case '+':
            op1 = pop(pila);
            op2 = pop(pila);
            push(pila, op1 + op2);
            break;
        case '*':
            op1 = pop(pila);
            op2 = pop(pila);
            push(pila, op1 * op2);
            break;
        case '-':
            op1 = pop(pila);
            op2 = pop(pila);
            push(pila, op2 - op1);
            break;
        default:
            // El - '0' es una forma de castear a int
            push(pila, vec[i] - '0');
            break;
        }
    }
    return pop(pila);
}
/*Ejercicio 3 - Pilas*/
void pushUsandoArray(char vecPila[], int& len, char valor) {
    for (int i = len - 1; i >= 0; i--) { //Voy al ultimo valor del array
        vecPila[i + 1] = vecPila[i];
    }
    vecPila[0] = valor;
    len++;
}
char popUsandoArray(char vecPila[], int& len) {
    char ret = vecPila[0];
    for (int i = 0; i < len; i++) {
        vecPila[i] = vecPila[i + 1];
    }
    len--;
    return ret;
}
char popUsandoCola(Nodo*& colafte, Nodo*& colafin) {
    return desencolar(colafte, colafin);
}
void pushUsandoCola(Nodo*& colafte, Nodo*& colafin, char valor) {
    Nodo* colafteAux = NULL;
    Nodo* colafinAux = NULL;
    encolar(colafteAux, colafinAux, valor);

    while (colafte != NULL) {
        encolar(colafteAux, colafinAux, desencolar(colafte, colafin));
    }

    colafte = colafteAux;
    colafin = colafinAux;
}


/*Ejercicio 1 - Colas*/
void encolarUsandoLista(Nodo*& lista, int v) {
    agregarNodo(lista, v);
}
int desencolarUsandoLista(Nodo*& lista) {
    return eliminarPrimerNodo(lista);
}
/*Ejercicio 2 - Colas*/
void encolarUsandoArray(int vec[], int& len, int v) {
    vec[len] = v;
    len++;
}
int desencolarUsandoArray(int vec[], int &len) {
    int resultado = vec[0];

    for (int i = 0; i < len; i++) {
        vec[i] = vec[i + 1];
    }

    len--;
    return resultado;
}
/*Ejercicio 3 - Colas*/
void encolarUsandoPila(Nodo*& pila, int v) {
    Nodo* pilaAux = NULL;

    while (pila != NULL) {
        push(pilaAux, pop(pila));
    }
    push(pilaAux, v);
 
    while (pilaAux != NULL) {
        push(pila, pop(pilaAux));
    }
}
int desencolarUsandoPila(Nodo*& pila) {
    return pop(pila);
}
/*Listas Doblemente Enlazadas*/
int insertarPisoArribaDelActualYMedir(NodoAscensor*& unNuevoPiso, NodoAscensor*& unPisoActual, int& distanciaPlantaMasAlta, int& distanciaPlantaMasBaja) {
    //Primero apuntamos los punteros del NuevoPiso(arriba y abajo) a sus correspondientes nodos
    unNuevoPiso->arriba = unPisoActual->arriba; //Arriba va a ser igual a lo que este arriba del actual
    unNuevoPiso->abajo = unPisoActual;//Abajo va a apuntar al piso actual 
    //Pusimos el nuevo piso entre medio de unPisoActual y arriba

   
    //Ahora hay que apuntar los otros dos punteros restantes

    //unPisoActual->arriba = NodoAscensor* arriba->abajo
    unPisoActual->arriba->abajo = unNuevoPiso;
    //Es la otra parte de unNuevoPiso->arriba 

    unPisoActual->arriba = unNuevoPiso;
    //Es la otra parte de unNuevoPiso->abajo

    medirDistanciaAPisosExtremos(unNuevoPiso, distanciaPlantaMasBaja, distanciaPlantaMasAlta);
    int distanciaPlantaBaja = 0;

    NodoAscensor* aux = unNuevoPiso;
    // Voy subiendo o bajando pisos, hasta que llego al ultimo y apunto a null
    while (aux != NULL && aux->info.piso != 0) {
        distanciaPlantaBaja++;
        if (aux->info.piso < 0) {
            aux = aux->arriba; 
        }
        else {
            aux = aux->abajo;
        }
    }

    return distanciaPlantaBaja;
}
void medirDistanciaAPisosExtremos(NodoAscensor* unPiso, int& distanciaPlantaBaja, int& distanciaPlantaAlta) {
    distanciaPlantaBaja = 0;
    distanciaPlantaAlta = 0;
    //Voy hacia abajo y cuento cuantos pisos tengo
    NodoAscensor* auxAbajo = unPiso;
    while (auxAbajo != NULL) {
        distanciaPlantaBaja++;
        auxAbajo = auxAbajo->abajo;
    }
    //Voy hacia arriba y cuento cuantos pisos tengo
    NodoAscensor* auxArriba = unPiso;
    while (auxArriba != NULL) {
        distanciaPlantaAlta++;
        auxArriba = auxArriba->arriba;
    }

}


/*22 Clase 23/9*/
void agregarNodoListaDoble(NodoAscensor*& lista, planta v){
    NodoAscensor* nuevo = new NodoAscensor();
    nuevo->info = v;
    nuevo->arriba = NULL;
    nuevo->abajo = NULL;
    if (lista == NULL) { // la lista p esta vacía 
        lista = nuevo;
    }
    else {
        NodoAscensor* aux = lista; //Genero un nodo auxiliar basado en p
        //Itero hasta encontrar el ultimo nodo
        while (aux->arriba != NULL) {
            //voy recorriendo la lista hasta llegar al final(arriba)
            aux = aux->arriba;
        }
        //Una vez que llego al ultimo nodo, hago la doble asignacion
        aux->arriba = nuevo;
        nuevo->abajo = aux;
        //Hay que apuntar a un Nodo
    }
}
int esPrimo(int numero) {
    bool resultado = true;
    for (int i = 2; i < numero; i++)
    {
        //Evaluo si es divisible
        if (numero % i == 0) {
            resultado = false;
            break;
        }
    }
    return resultado;
}
void eliminarPiso(NodoAscensor*& unPiso) {
    if (unPiso->abajo != NULL) {
        unPiso->abajo->arriba = unPiso->arriba;
    }
    if (unPiso->arriba != NULL) {
        unPiso->arriba->abajo = unPiso->abajo;
    }
    //Si descomento esta linea, no compila
    //delete(unPiso); 
}
int eliminarLosPisosPrimosArribaDe(NodoAscensor*& unPisoActual, FILE* arch) {
    int cantPisosEliminados = 0;
    pisoEliminado reg;

    NodoAscensor* aux = unPisoActual;
    //Voy un piso arriba y valido que no sea null
    aux = aux->arriba;
    while (aux != NULL) {
        if (esPrimo(aux->info.piso)) {
            //Guardo los datos del piso que voy a eliminar
            reg.piso = aux->info.piso;
            reg.diffEntreSubenYBajan = aux->info.suben - aux->info.bajan;
            //Escribo los datos en el archivo 
            fwrite(&reg, sizeof(pisoEliminado), 1, arch);
            eliminarPiso(aux);
            cantPisosEliminados++;
        }
        aux = aux->arriba;
    }

    return cantPisosEliminados;
}

/*23 Clase 30/9*/
void agregarNota(Nota*& p, int x) {
    Nota* nuevo = new Nota();
    nuevo->nota = x;
    nuevo->sig = NULL;
    if (p == NULL) { // la lista p esta vacía
        p = nuevo;
    }
    else {
        Nota* aux = p;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}
Estudiante* buscaEInsertaEstudiante(Estudiante*& p, infoestudiante v, bool& enc) {
    Estudiante* nodoBuscado = buscarEstudiante(p, v);
    if (nodoBuscado != NULL) { // el nodo está en la lista
        enc = true;
    }
    else { // el nodo no está
        nodoBuscado = agregarEstudiante(p, v);
        enc = false;
    }

    return nodoBuscado;
}
Estudiante* buscarEstudiante(Estudiante* p, infoestudiante v) {
    Estudiante* aux = p;
    while (aux != NULL && aux->infoEst.id != v.id) {
        aux = aux->sigEst;
    }
    return aux;
}
Estudiante* agregarEstudiante(Estudiante*& p, infoestudiante x) {
    Estudiante* nuevo = new Estudiante();
    nuevo->infoEst = x;
    nuevo->sigEst = NULL;
    if (p == NULL) { // la lista p esta vacía
        p = nuevo;
    }
    else {
        Estudiante* aux = p;
        while (aux->sigEst != NULL) {
            aux = aux->sigEst;
        }
        aux->sigEst = nuevo;
    }

    return nuevo;
}
Curso* buscaEInsertaCurso(Curso*& p, infocurso v, bool& enc) {
    Curso* nodoBuscado = buscarCurso(p, v);
    if (nodoBuscado != NULL) { // el nodo está en la lista
        enc = true;
    }
    else { // el nodo no está, lo agrego a la lista
        nodoBuscado = agregarCurso(p, v);
        enc = false;
    }
    return nodoBuscado;
}
Curso* buscarCurso(Curso* p, infocurso v) {
    Curso* aux = p;
    while (aux != NULL && aux->infoCur.id != v.id) {
        aux = aux->sigCur;
    }
    return aux;
}
Curso* agregarCurso(Curso*& p, infocurso x) {
    Curso* nuevo = new Curso();
    nuevo->infoCur = x;
    nuevo->sigCur = NULL;
    if (p == NULL) { // la lista p esta vacía
        p = nuevo;
    }
    else {
        Curso* aux = p;
        while (aux->sigCur != NULL) {
            aux = aux->sigCur;
        }
        aux->sigCur = nuevo;
    }

    return nuevo;
}
void agregarNota(Curso*& listaCursos, int idCurso, int idEstudiante, int nroEvaluacion, int nota) {
    bool enc;
    //Defino la info del curso en base a los datos que recibo
    infocurso datosCur;
    datosCur.id = idCurso;
    datosCur.promocionados = 0;
    datosCur.recursantes = 0;
    datosCur.regularizados = 0;
    datosCur.listaEstudiantes = NULL;
    //Si el curso no esta, lo inserta. Si ya existia dentro de la lista devuelve el nodo.
    Curso* cursoDeInteres = buscaEInsertaCurso(listaCursos, datosCur, enc);

    infoestudiante datosEst;
    datosEst.id = idEstudiante;
    datosEst.notas[0] = NULL;
    datosEst.notas[1] = NULL;
    datosEst.notas[2] = NULL;
    datosEst.notas[3] = NULL;

    Estudiante* estudianteDeInteres = buscaEInsertaEstudiante(cursoDeInteres->infoCur.listaEstudiantes, datosEst, enc);
    //Una vez que tengo el curso y el esudiante de interes, hay que cargar la nota del estudiante
    agregarNota(estudianteDeInteres->infoEst.notas[nroEvaluacion - 1], nota);
}
void procesarNovedades(FILE* novedades, Curso*& listaCursos) {
    novedad reg;
    fread(&reg, sizeof(novedad), 1, novedades);
    //Lee el archivo de novedades y agrega cada novedad en la lista de cursos
    while (!feof(novedades)) {
        agregarNota(listaCursos, reg.idCurso, reg.idEstudiante, reg.nroEvaluacion, reg.nota);
        fread(&reg, sizeof(novedad), 1, novedades);
    }
}
void calcularEstadisticas(Curso* listaCursos) {
    int ultimasNotas[4];
    Curso* auxCurso = listaCursos;
    int len = 4;
    int estadoEstudiante;

    //Recorro todos los cursos
    while (auxCurso != NULL) {
        Estudiante* auxEst = auxCurso->infoCur.listaEstudiantes;
        //Recorro todos los estudiantes de cada curso
        while (auxEst != NULL) {
            //Busco la ultima nota de cada evaluacion
            /*Nota* aux1erEvaluacion = auxEst->infoEst.notas[0];
            while(aux1erEvaluacion->sig != NULL) {
                aux1erEvaluacion = aux1erEvaluacion->sig;
            }
            ultimasNotas[0] = aux1erEvaluacion->nota;

            Nota* aux2daEvaluacion = auxEst->infoEst.notas[1];
            while(aux2daEvaluacion->sig != NULL) {
                aux2daEvaluacion = aux2daEvaluacion->sig;
            }
            ultimasNotas[1] = aux2daEvaluacion->nota;

            Nota* aux3eraEvaluacion = auxEst->infoEst.notas[2];
            while(aux3eraEvaluacion->sig != NULL) {
                aux3eraEvaluacion = aux3eraEvaluacion->sig;
            }
            ultimasNotas[2] = aux3eraEvaluacion->nota;

            Nota* aux4taEvaluacion = auxEst->infoEst.notas[3];
            while(aux4taEvaluacion->sig != NULL) {
                aux4taEvaluacion = aux4taEvaluacion->sig;
            }
            ultimasNotas[3] = aux4taEvaluacion->nota;
            */

            //Otra forma más corta
            for (int i = 0; i < len; i++) {
                Nota* notaEvaluacion = auxEst->infoEst.notas[i];
                while (notaEvaluacion->sig != NULL) {
                    notaEvaluacion = notaEvaluacion->sig;
                }
                ultimasNotas[i] = notaEvaluacion->nota;
            }
            //Le paso la lista de notas
            estadoEstudiante = getEstado(ultimasNotas, len);
            //Actualizo la info del curso en base al resultado
            switch (estadoEstudiante) {
            case 1:
                auxCurso->infoCur.promocionados++;
                break;
            case 2:
                auxCurso->infoCur.regularizados++;
                break;
            case 3:
                auxCurso->infoCur.recursantes++;
                break;
            }
            //Avanzo al siguiente estudiante
            auxEst = auxEst->sigEst;
        }
        //Avanzo al siguiente Curso
        auxCurso = auxCurso->sigCur;
    }
}
int getEstado(int notas[], int len) {
    int estado;
    int promocion = 0;
    int recursa = 0;
    int regulariza = 0;

    for (int i = 0; i < len; i++) {
        if (notas[i] < 6) {
            recursa++;
        }
        else if (notas[i] >= 6 && notas[i] < 8) {
            regulariza++;
        }
        else {
            promocion++;
        }
    }

    if (promocion == 4) {
        estado = 1;
    }
    else if (recursa >= 1) {
        estado = 3;
    }
    else {
        estado = 2;
    }

    return estado;
}

/*24 Clase 07/10*/
Articulo* buscarArticulo(Articulo* p, infoArt v) {
    Articulo* aux = p;
    while (aux != NULL && strcmp(aux->info.articulo, v.articulo) != 0) {
        aux = aux->sig;
    }
    return aux;
}
Articulo* agregarArticulo(Articulo*& p, infoArt x) {
    Articulo* nuevo = new Articulo();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (p == NULL) { // la lista p esta vacía
        p = nuevo;
    }
    else {
        Articulo* aux = p;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

    return nuevo;
}
Articulo* buscaEInsertaArticulo(Articulo*& p, infoArt v, bool& enc) {
    Articulo* nodoBuscado = buscarArticulo(p, v);
    if (nodoBuscado != NULL) { // el nodo está en la lista
        enc = true;
    }
    else { // el nodo no está
        nodoBuscado = agregarArticulo(p, v);
        enc = false;
    }
    return nodoBuscado;
}
Cliente* buscarCliente(Cliente* p, infoCliente v) {
    Cliente* aux = p;
    while (aux != NULL && aux->info.nroCliente != v.nroCliente) {
        aux = aux->sig;
    }
    return aux;
}
Cliente* agregarCliente(Cliente*& p, infoCliente x) {
    Cliente* nuevo = new Cliente();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (p == NULL) { // la lista p esta vacía
        p = nuevo;
    }
    else {
        Cliente* aux = p;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    return nuevo;
}
Cliente* buscaEInsertaCliente(Cliente*& p, infoCliente v, bool& enc) {
    Cliente* nodoBuscado = buscarCliente(p, v);
    if (nodoBuscado != NULL) { // el nodo está en la lista
        enc = true;
    }
    else { // el nodo no está
        nodoBuscado = agregarCliente(p, v);
        enc = false;
    }
    return nodoBuscado;
}

Socio* buscarSocio(Socio* p, infoSocio v) {
    Socio* aux = p;
    while (aux != NULL && aux->info.nroSocio != v.nroSocio) {
        aux = aux->sig;
    }
    return aux;
}
Socio* agregarSocio(Socio*& p, infoSocio x) {
    Socio* nuevo = new Socio();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (p == NULL) { // la lista p esta vacía
        p = nuevo;
    }
    else {
        Socio* aux = p;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

    return nuevo;
}
Socio* buscaEInsertaSocio(Socio*& p, infoSocio v, bool& enc) {
    Socio* nodoBuscado = buscarSocio(p, v);
    if (nodoBuscado != NULL) { // el nodo está en la lista
        enc = true;
    }
    else { // el nodo no está
        nodoBuscado = agregarSocio(p, v);
        enc = false;
    }

    return nodoBuscado;
}
Sucursal* buscarSucursal(Sucursal* p, infoSuc v) {
    Sucursal* aux = p;
    while (aux != NULL && aux->info.nroSucusal != v.nroSucusal) {
        aux = aux->sig;
    }
    return aux;
}
Sucursal* agregarSucursal(Sucursal*& p, infoSuc x) {
    Sucursal* nuevo = new Sucursal();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (p == NULL) { // la lista p esta vacía
        p = nuevo;
    }
    else {
        Sucursal* aux = p;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    return nuevo;
}
Sucursal* buscaEInsertaSucursal(Sucursal*& p, infoSuc v, bool& enc) {
    Sucursal* nodoBuscado = buscarSucursal(p, v);
    if (nodoBuscado != NULL) { // el nodo está en la lista
        enc = true;
    }
    else { // el nodo no está
        nodoBuscado = agregarSucursal(p, v);
        enc = false;
    }
    return nodoBuscado;
}

/*26 Clase 28/10*/
/*EJ 1*/
void preOrden(Arbol*& raiz) {
    if (raiz == NULL) {
        return;
    }
    else {
        //Visito raiz
        cout << raiz->info << endl;
        //Recorro el subarbol izquierdo en pre-orden
        preOrden(raiz->izq);
        //Recorro el subarbol derecho en pre-orden
        preOrden(raiz->der);
    }
}
void inOrden(Arbol*& raiz) {
    if (raiz == NULL) {
        return;
    }
    else {
        //Recorro el subarbol izquierdo en in-orden
        inOrden(raiz->izq);
        //Visito raiz
        cout << raiz->info << endl;
        //Recorro el subarbol derecho en in-orden
        inOrden(raiz->der);
    }
}
void postOrden(Arbol*& raiz) {
    if (raiz == NULL) {
        return;
    }
    else {
        //Recorro el subarbol izquierdo en post-orden
        postOrden(raiz->izq);
        //Recorro el subarbol derecho en post-orden
        postOrden(raiz->der);
        //Visito raiz
        cout << raiz->info << endl;
    }
}
void insertarNodoEnArbol(Arbol*& raiz, int valor) {
    if (raiz == NULL) {
        Arbol* nuevo = new Arbol();
        nuevo->info = valor;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        raiz = nuevo;
    }
    else {
        if (valor > raiz->info) {
            insertarNodoEnArbol(raiz->der, valor);
        }
        else if (valor < raiz->info) {
            insertarNodoEnArbol(raiz->izq, valor);
        }
        else {
            cout << "Valor duplicado" << endl;
        }
    }
}
/*EJ 2*/
void emitirSospechosos(Sospechoso* matSospe[4][9], int tipo, int subtipo) {
    Sospechoso* listaSospe = matSospe[tipo - 1][subtipo - 1];
    int nroDedo;

    while (listaSospe != NULL) {
        cout << listaSospe->info.apeNom << endl;
        cout << listaSospe->info.dni << endl;
        Dedo* dedosAux = listaSospe->info.dedos;
        while (dedosAux != NULL) {
            nroDedo = dedosAux->nroDedo;

            switch (nroDedo) {
            case 1:
                cout << "pulgar mano derecha" << endl;
                break;
            case 2:
                cout << "indice mano derecha" << endl;
                break;
            case 3:
                cout << "medio mano derecha" << endl;
                break;
            case 4:
                cout << "anular mano derecha" << endl;
                break;
            case 5:
                cout << "menique mano derecha" << endl;
                break;
            case 6:
                cout << "pulgar mano izquierda" << endl;
                break;
            case 7:
                cout << "indice mano izquierda" << endl;
                break;
            case 8:
                cout << "medio mano izquierda" << endl;
                break;
            case 9:
                cout << "anular mano izquierda" << endl;
                break;
            case 10:
                cout << "menique mano izquierda" << endl;
                break;
            }
            dedosAux = dedosAux->sig;
        }
        listaSospe = listaSospe->sig;
    }

}
void cargarMatrizSospechosos(Sospechoso* matSospe[4][9], FILE* arch) {
    //Declaro variables
    huella reg;
    Sospechoso* sospeBuscado = NULL;
    bool enc;
    infoSospe infoS;
    //Voy leyendo el archivo e insertando en la matriz
    fread(&reg, sizeof(huella), 1, arch);
    while (!feof(arch)) {
        //Lleno el registro con los datos del archivo
        strcpy(infoS.apeNom, reg.apeNom);
        infoS.dni = reg.dni;
        infoS.dedos = NULL;
        //Inserta en la lista de sospechosos, al sospechoso
        sospeBuscado = buscarEInsertaSospechoso(matSospe[reg.tipo - 1][reg.subtipo - 1], infoS, enc);
        //Inserta el dedo, en la lista de dedos del sospechoso
        agregarDedo(sospeBuscado->info.dedos, reg.dedo);
        //Avanzo en el archivo
        fread(&reg, sizeof(huella), 1, arch);
    }
}
void agregarDedo(Dedo*& lista, int x) {
    Dedo* nuevo = new Dedo();
    nuevo->nroDedo = x;
    nuevo->sig = NULL;
    if (lista == NULL) { // la lista p esta vacía
        lista = nuevo;
    }
    else {
        Dedo* aux = lista;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}
Sospechoso* insertarSospechosoOrdenado(Sospechoso*& p, infoSospe v) {
    Sospechoso* nuevo = new Sospechoso();
    nuevo->info = v;
    nuevo->sig = NULL;
    Sospechoso* ant = NULL;
    Sospechoso* aux = p;

    while (aux != NULL && strcmp(aux->info.apeNom, v.apeNom) <= 0) {
        ant = aux;
        aux = aux->sig;
    }
    if (ant == NULL) { //Estoy insertando al principio
        p = nuevo;
    }
    else {
        ant->sig = nuevo;
    }
    nuevo->sig = aux;
    return nuevo;
}
Sospechoso* buscarEInsertaSospechoso(Sospechoso*& lista, infoSospe v, bool& enc) {
    Sospechoso* nodoBuscado = buscarSospechoso(lista, v);
    if (nodoBuscado != NULL) { // el nodo está en la lista
        enc = true;
    }
    else { // el nodo no está
        nodoBuscado = insertarSospechosoOrdenado(lista, v);
        enc = false;
    }

    return nodoBuscado;
}
Sospechoso* buscarSospechoso(Sospechoso* lista, infoSospe v) {
    Sospechoso* aux = lista;
    while (aux != NULL && aux->info.dni != v.dni) {
        aux = aux->sig;
    }
    return aux;
}

/*27 Clase 4/11*/
/*EJ 1*/
void emitirNotificacion(string titulo, string descripcion) {
    cout << "Titulo: " << titulo << endl;
    cout << "Descripcion: " << descripcion << endl;
}
string numeroTelefonicoDelUsuario(int idEmisor) {
    //return "+5491167567980";
    return to_string(idEmisor);
}
string vistaPreviaMensaje(string mensaje) {
    return mensaje;
}
void agregarConversacion(Conversacion*& lista, infoConver x) {
    Conversacion* nuevo = new Conversacion();
    nuevo->info = x;
    nuevo->sgte = NULL;
    if (lista == NULL) { // la lista p esta vacía
        lista = nuevo;
    }
    else {
        Conversacion* aux = lista;
        while (aux->sgte != NULL) {
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }
}
Conversacion* buscarConversacion(Conversacion* p, int v) {
    Conversacion* aux = p;
    //Itero mientras el valor pasado por referencia no es el buscado
    // y no es el final de la lista
    while (aux != NULL && aux->info.idConversacion != v) {
        aux = aux->sgte;
    }
    // En el caso de que llegue al final de la lista, retorna null
    return aux;
}
int buscarContacto(contacto arr[], int len, int v) {
    int i = 0;
    int pos = -1;
    while (i < len && arr[i].idUsuario != v) {
        i++;
    }
    if (i < len) {
        pos = i;
    }
    return pos;
}
void notificarMensajeRecibido(Conversacion* lista, contacto vec[], int len, int idConversacion, int idUsuarioEmisor, string mensaje) {
    //Cuando llega un mensaje hay que emitir una notificacion
    //Busca la conversacion, suponemos que siempre la encuentra 
    Conversacion* conversacionBuscada = buscarConversacion(lista, idConversacion);
    //Busca el numero entre los contactos
    int posContactoBuscado = buscarContacto(vec, len, idUsuarioEmisor);
    bool bloqueado;
    string nombreContacto;
    if (posContactoBuscado != -1) { // Si está en el vector de contactos
        bloqueado = vec[posContactoBuscado].bloqueado; //Chequear si esta bloqueado
        nombreContacto = vec[posContactoBuscado].nombreContacto;
    }
    else {// No está en el vector de contactos
        bloqueado = false;
        nombreContacto = numeroTelefonicoDelUsuario(idUsuarioEmisor);
    }

    string titulo;
    string descripcion;
    bool vistaPrevia = conversacionBuscada->info.vistaPrevia;
    //Validamos si se debe notificar o no
    //Se puede notificar
    if (!bloqueado && conversacionBuscada->info.notificar) {
        //Evaluo el tipo de conversacion
        if (conversacionBuscada->info.nombre != "") { //Conversacion grupal
            titulo = conversacionBuscada->info.nombre;
            if (vistaPrevia) { //Grupal con vista previa
                descripcion = nombreContacto + " : " + vistaPreviaMensaje(mensaje);
            }
            else {//Grupal sin vista previa
                descripcion = "Nuevo Mensaje de : " + nombreContacto;
            }
        }
        else { //Conversacion directa
            titulo = nombreContacto;
            if (vistaPrevia) { //Directa con vista previa
                descripcion = vistaPreviaMensaje(mensaje);
            }
            else {//Directa sin vista previa
                descripcion = "Nuevo Mensaje";
            }
        }
        emitirNotificacion(titulo, descripcion);
    }
    else {
        if (bloqueado) {
            cout << "Esta bloqueado" << endl;
        }
        if (!conversacionBuscada->info.notificar) {
            cout << "No notificar" << endl;
        }
    }
}
/*EJ 2*/
void generarListaConsejerosDocentes(candidato vecCandidatos[], int lenCan, resultado vecResultado[], int& lenRes) {
    float votos[3] = { votos1, votos2, votos3 }; //Votos totales por list
    float votosLista;
    int k = 0;//Cantidad total de postulados

    resultado vecAuxiliar[15]; //Acumulo los resultados de la votacion
    int lenAux = 15;
    //Recorro las listas
    for (int i = 0; i < 3; i++)
    {
        votosLista = votos[i]; // 50 - 35 - 15 - Cantidad de votos totales
        //Recorro los candidatos de cada lista
        for (int j = 0; j < 5; j++)
        {
            vecAuxiliar[k].cand = vecCandidatos[k];//Guardo el candidato
            vecAuxiliar[k].pos = votosLista / (j + 1); //Divido cantidad de votos totales, sobre la posicion (ordenado por cantidad)
            k++;
        }
    }
    ordenarVector(vecAuxiliar, lenAux); //Ordenar de mayor a menor

    for (int i = 0; i < 5; i++)
    {
        vecResultado[i].pos = (float)i + 1;
        vecResultado[i].cand = vecAuxiliar[i].cand;
        lenRes++;
    }
}
void ordenarVector(resultado vecAuxiliar[], int lenAux) {
    // Ordena un vector de menor a mayor
    resultado temp;
    bool huboIntercambio = true;
    // Tiene que ser menor a len, para que el j+1 no tome una posicion inexistente
    // Mientras haya un intercambio sigue iterando
    for (int i = 0; i < lenAux && huboIntercambio; i++) {
        huboIntercambio = false;
        for (int j = 0; j < lenAux - 1; j++) {
            // Si es menor intercambia valores
            if (vecAuxiliar[j].pos < vecAuxiliar[j + 1].pos) {
                huboIntercambio = true;
                temp = vecAuxiliar[j + 1];
                vecAuxiliar[j + 1] = vecAuxiliar[j];
                vecAuxiliar[j] = temp;
            }
        }
    }
}

/*28 Clase 11/11*/

