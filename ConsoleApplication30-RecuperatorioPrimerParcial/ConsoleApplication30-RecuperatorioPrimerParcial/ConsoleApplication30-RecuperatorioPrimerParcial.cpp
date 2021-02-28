#include "..\..\Headers\dinamica.hpp"
#include "..\..\Headers\vectores.hpp"
#include <iostream>


//Ejercicio 1
/*
struct estudio {
    char hospital[20];
    char obraSocial[20];
    int codEstudio;
    char descripcion[20];
    int precio;
};
struct cuenta {
    char hospital[20];
    char obraSocial[20];
    int totalAPagar;
};
*/

//Ejercicio 2
/*Comentario:
lenC se debería pasar por parámetro.

Se pedía hacer un apareo.

buscarPersona(arrA, lenA, arrA[i])  --> Buscas un elemento en el mismo array?? Nunca va a dar -1*/
/*
struct persona {
    int DNI;
    string mail;
    int telefono;
    string nomYApe;
    string fechaDeNacimiento;
};
void agregarPersona(persona arr[], int n, int& len, persona v);
void apareoPersona(persona arrA[], int lenA, persona arrB[], int lenB, persona arrC[], int& lenC);
void mostrarPersona(persona arr[], int len);
*/

//Ejercicio 4
/*
struct Apuesta {
    int idCaballo;
    int idApostador;
    int dineroApostado;
};
struct Caballo {
    int idCaballo;
    int dineroTotalRecaudado;
    int cantApuestasRecibidas;
};
struct Apostador {
    int idApostador;
    int dineroTotalApostado;
    int cantCaballosApostados;
};

//Busca a un caballo por idCaballo en un array de tipo Caballo
int buscarCaballo(Caballo arr[], int len, int idCaballo);
//Agrega a un caballo a un array de tipo Caballo
void agregarCaballo(Caballo arr[], int& len, Caballo dato);

//Busca a un apostador por idApostador en un array de tipo Apostador
int buscarApostador(Apostador arr[], int len, int idApostador);
//Agrega a un apostador a un array de tipo Apostador
void agregarApostador(Apostador arr[], int& len, Apostador dato);

int buscarCaballo(Caballo arr[], int len, int v) {
    int i = 0;
    int pos = -1;
    while (i < len && arr[i].idCaballo != v) {
        i++;
    }
    if (i < len) {
        pos = i;
    }
    return pos;
}
void agregarCaballo(Caballo arr[], int& len, Caballo v) {
    if (len < 100) {
        arr[len] = v;
        len++;
    }
    else {
        cout << "El vector está lleno :( " << endl;
    }
}

int buscarApostador(Apostador arr[], int len, int v) {
    int i = 0;
    int pos = -1;
    while (i < len && arr[i].idApostador != v) {
        i++;
    }
    if (i < len) {
        pos = i;
    }
    return pos;
}
void agregarApostador(Apostador arr[], int& len, Apostador v) {
    if (len < 100) {
        arr[len] = v;
        len++;
    }
    else {
        cout << "El vector está lleno :( " << endl;
    }
}
*/

//Ejercicio 5
/*
bool elAnioEsBiciesto(int anio);
*/

int main()
{
    //Ejercicio 1
    /* (3 puntos - 3/3) 
    Se tiene un archivo “estudios.dat” (1000 registros como máximo) que contiene los siguientes datos: 
    hospital, obra social, código de estudio, descripción y precio. El archivo se encuentra ordenado por hospital y por obra social. 
    Se pide informar cuánto dinero debe pagar cada hospital a cada obra social y grabarlo en el archivo “cuentasApagar.dat”. 
    El archivo debe contener los siguientes datos: hospital, obra social y dinero total a pagar.
    Este ejercicio debe resolverse sí o sí en forma manuscrita. Colocar el DNI en la hoja de la resolución y sacarle una foto.*/
    /*


    ////LLeno el archivo con apuestas
    //FILE* estudios = fopen("estudios.dat", "wb+");
    //estudio reg;

    //strcpy(reg.hospital, "hospital 2 ");
    //strcpy(reg.obraSocial, "  swiss ");
    //reg.codEstudio = 1;
    //strcpy(reg.descripcion, "  asdsadadas ");
    //reg.precio = 1;    
    //fwrite(&reg, sizeof(estudio), 1, estudios);

    //strcpy(reg.hospital, "hospital 2 ");
    //strcpy(reg.obraSocial, "  swiss ");
    //reg.codEstudio = 1;
    //strcpy(reg.descripcion, "  asdsadadas ");
    //reg.precio = 1;
    //fwrite(&reg, sizeof(estudio), 1, estudios);
    //
    //strcpy(reg.hospital, "hospital 3 ");
    //strcpy(reg.obraSocial, "  swiss ");
    //reg.codEstudio = 1;
    //strcpy(reg.descripcion, "  asdsadadas ");
    //reg.precio = 1;
    //fwrite(&reg, sizeof(estudio), 1, estudios);

    //strcpy(reg.hospital, "hospital 3 ");
    //strcpy(reg.obraSocial, "  swiss ");
    //reg.codEstudio = 1;
    //strcpy(reg.descripcion, "  asdsadadas ");
    //reg.precio = 1;
    //fwrite(&reg, sizeof(estudio), 1, estudios);

    //strcpy(reg.hospital, "hospital 3 ");
    //strcpy(reg.obraSocial, "  accord ");
    //reg.codEstudio = 1;
    //strcpy(reg.descripcion, "  asdsadadas ");
    //reg.precio = 1;
    //fwrite(&reg, sizeof(estudio), 1, estudios);

    //rewind(estudios);
    //fread(&reg, sizeof(estudio), 1, estudios);
    //while (!feof(estudios)) {
    //    cout << reg.hospital << endl;
    //    cout << reg.obraSocial << endl;
    //    cout << reg.precio << endl;
    //    cout << "_______________________________________" << endl;
    //    fread(&reg, sizeof(estudio), 1, estudios);
    //}
    //fclose(estudios);


    FILE* estudios = fopen("estudios.dat", "rb+");
    estudio reg;

    FILE* cuentas = fopen("cuentasAPagar.dat", "wb+");
    cuenta cuentaAPagar;

    int dineroTotalAPagar;
    fread(&reg, sizeof(estudio), 1, estudios);
    while (!feof(estudios)) {
        estudio estudioAnterior = reg;
        dineroTotalAPagar = 0;

        //Guardo el nombre del hospital y la OS
        strcpy(cuentaAPagar.hospital, estudioAnterior.hospital);
        strcpy(cuentaAPagar.obraSocial, estudioAnterior.obraSocial);
        //Mientras siga leyendo datos del mismo hospital y misma OOSS
        while (!feof(estudios) && strcmp(reg.hospital, estudioAnterior.hospital) == 0 && strcmp(reg.obraSocial, estudioAnterior.obraSocial) == 0) {
            dineroTotalAPagar += reg.precio; //Acumulo lo adeudado por OOSS
            fread(&reg, sizeof(estudio), 1, estudios);
        }
        //Guardo el total a pagar y escribo en el archivo
        cuentaAPagar.totalAPagar = dineroTotalAPagar;
        fwrite(&cuentaAPagar, sizeof(cuenta), 1, cuentas);
        cout << "El hospital " << cuentaAPagar.hospital << " debe pagar " << cuentaAPagar.totalAPagar << " a la OS" << cuentaAPagar.obraSocial << endl;
    }
    fclose(estudios);
    fclose(cuentas);
    */

    //Ejercicio 2
    /*(2 puntos - 0.50/2) Arreglado
    Crear un procedimiento que dados dos vectores A y B (10 elementos como máximo cada uno), llene un vector C con el apareo de ambos vectores.
    Los vectores están conformados por un registro de “persona” con los siguientes datos: DNI, mail, teléfono, nombre y apellido, fecha de nacimiento (DDMMAAAA).
    Además, se encuentran ordenados por DNI. El vector C será utilizado en el programa principal.*/
    /*
    persona arrA[10] = { {1234,"mail@mail.com", 11446535, "Fula Nito","25/04/95"},{9999,"mail@mail.com", 11446535, "Fula Nito2","25/04/95"} };
    persona arrB[10] = { {4444,"mail@mail.com", 11446535, "Fula Nito3","25/04/95"},{5555,"mail@mail.com", 11446535, "Fula Nito4","25/04/95"} };
    persona arrC[20];
    int lenA = 2;
    int lenB = 2;
    int lenC = 0;

    apareoPersona(arrA, lenA, arrB, lenB, arrC, lenC);
    mostrarPersona(arrC, lenC);
    */

    //Ejercicio 4
    /*(3 puntos - 2.50/3)
    Tenemos un archivo “apuestas.dat” (sin orden) que contiene las apuestas del Hipódromo de Palermo. 
    Cada apuesta está compuesta por un identificador de caballo, un identificador de apostador y el dinero apostado. 
    Cómo máximo son 20 caballos y 100 apostadores. 
    Un apostador puede apostar por más de un caballo.*/
    /*
    ////LLeno el archivo con apuestas
    //FILE* apuestas = fopen("apuestas.dat", "wb+");
    //Apuesta reg;

    //reg.idCaballo = 1; //Caballo con mas apuestas
    //reg.idApostador = 11;
    //reg.dineroApostado = 100;
    //fwrite(&reg, sizeof(Caballo), 1, apuestas);

    //reg.idCaballo = 2;
    //reg.idApostador = 11;
    //reg.dineroApostado = 100;
    //fwrite(&reg, sizeof(Caballo), 1, apuestas);

    //reg.idCaballo = 3;
    //reg.idApostador = 11; //Apostador que aposto mas variado
    //reg.dineroApostado = 100;
    //fwrite(&reg, sizeof(Caballo), 1, apuestas);

    //reg.idCaballo = 4;
    //reg.idApostador = 11;
    //reg.dineroApostado = 100;
    //fwrite(&reg, sizeof(Caballo), 1, apuestas);

    //reg.idCaballo = 1;//Caballo que mas apuestas tuvo
    //reg.idApostador = 21; //Apostador que aposto mas cantidad de dinero
    //reg.dineroApostado = 1500;
    //fwrite(&reg, sizeof(Caballo), 1, apuestas);

    //reg.idCaballo = 2;//Caballo que mas recaudo
    //reg.idApostador = 21; //Apostador que aposto mas cantidad de dinero
    //reg.dineroApostado = 1500;
    //fwrite(&reg, sizeof(Caballo), 1, apuestas);

    //rewind(apuestas);
    //fread(&reg, sizeof(Caballo), 1, apuestas);
    //while (!feof(apuestas)) {
    //    cout << reg.idCaballo << endl;
    //    cout << reg.idApostador << endl;
    //    cout << reg.dineroApostado << endl;
    //    cout << "_______________________________________" << endl;
    //    fread(&reg, sizeof(Caballo), 1, apuestas);
    //}
    //fclose(apuestas);
    

    
    //Defino array de caballos
    Caballo arrCaballos[20];
    int lenCaballos = 0;

    Apostador arrApostador[100];
    int lenApostador = 0;

    //Leo el archivo
    FILE* apuestas = fopen("apuestas.dat", "rb");
    Apuesta reg;

    //Itero sobre el archivo
    fread(&reg, sizeof(Apuesta), 1, apuestas);
    while (!feof(apuestas)) {

        //Guardo datos del caballo en el array
        int posCaballo = buscarCaballo(arrCaballos, lenCaballos, reg.idCaballo);
        if (posCaballo == -1) {
            //El caballo no existe, lo agrego
            Caballo dato;
            dato.idCaballo = reg.idCaballo;
            dato.dineroTotalRecaudado = reg.dineroApostado;
            dato.cantApuestasRecibidas = 1;
            agregarCaballo(arrCaballos, lenCaballos, dato);
        }
        else {
            //El caballo existe, guardo datos
            arrCaballos[posCaballo].dineroTotalRecaudado += reg.dineroApostado;
            arrCaballos[posCaballo].cantApuestasRecibidas++;
        }

        //Guardo datos del apostador en el array
        int posApostador = buscarApostador(arrApostador, lenApostador, reg.idApostador);
        if (posApostador == -1) {
            //El apostador no existe, lo agrego
            Apostador dato;
            dato.idApostador = reg.idApostador;
            dato.dineroTotalApostado = reg.dineroApostado;
            dato.cantCaballosApostados = 1;
            agregarApostador(arrApostador, lenApostador, dato);
        }
        else {
            //El apostador existe, guardo datos
            arrApostador[posApostador].dineroTotalApostado += reg.dineroApostado;
            arrApostador[posApostador].cantCaballosApostados++;
        }
        //Leo para avanzar en el archivo
        fread(&reg, sizeof(Apuesta), 1, apuestas);
    }
    fclose(apuestas);
    


    int idCaballoConMasApuestas = 0;
    int idCaballoQueMasRecaudo = 0;
    int cantMaxApostada = 0;
    int cantMaxRecaudada = 0;

    //Itero sobre el vector de caballos
    for (int i = 0; i < lenCaballos; i++) {
        //Busco el caballo que tuvo mas apuestas
        if (arrCaballos[i].cantApuestasRecibidas > cantMaxApostada) {
            idCaballoConMasApuestas = arrCaballos[i].idCaballo;
            cantMaxApostada = arrCaballos[i].cantApuestasRecibidas; //Me olvide de poner esto en la resolucion del examen
        }
        //Busco el caballo que mas recaudo
        if (arrCaballos[i].dineroTotalRecaudado > cantMaxRecaudada) {
            idCaballoQueMasRecaudo = arrCaballos[i].idCaballo;
            cantMaxRecaudada = arrCaballos[i].dineroTotalRecaudado;//Me olvide de poner esto en la resolucion del examen
        }
    }

    cout << "Id del caballo con mas cantidad de apuestas: " << idCaballoConMasApuestas << endl;
    cout << "Id del caballo con mas dinero apostado: " << idCaballoQueMasRecaudo << endl;

    
    int idApostadorMaximoDinero = 0;
    int idApostadorMaximoCantidad = 0;
    int cantMaxQueAposto = 0;
    int cantMaxVecesApostadas = 0;
    //Itero sobre el vector de apostadores
    for (int i = 0; i < lenApostador; i++) {
        //Busco el apostador que haya apostado mas dinero
        if (arrApostador[i].dineroTotalApostado > cantMaxQueAposto) {
            idApostadorMaximoDinero = arrApostador[i].idApostador;
            cantMaxQueAposto = arrApostador[i].dineroTotalApostado;
        }
        //Busco el apostador que mas veces aposto
        if (arrApostador[i].cantCaballosApostados > cantMaxVecesApostadas) {
            idApostadorMaximoCantidad = arrApostador[i].idApostador;
            cantMaxVecesApostadas = arrApostador[i].cantCaballosApostados;
        }
    }

    cout << "Id del apostador que aposto a mas caballos: " << idApostadorMaximoCantidad << endl;
    cout << "Id del apostador que mas dinero aposto: " << idApostadorMaximoDinero << endl;
    */

    //Ejercicio 5
    /*(1 punto - 1/1) 
    Desarrolle una función que determine si un año (AAAA) que se pasa por parámetro es bisiesto. 
    Realizar el programa principal que invoca a esta función luego de pedirle al usuario que ingrese un año. 
    En el programa principal imprimir “El año AAAA es bisiesto”o  “El año AAAA no es bisiesto” según corresponda. 
    Un año es bisiesto si es divisible entre cuatro y no es divisible entre 100 o es divisible entre 400.*/
    /*
    int anio;
    cout << "Ingrese un anio para determinar si es biciesto o no " << endl;
    cin >> anio;
    bool resultado = elAnioEsBiciesto(anio);

    if (resultado) {
        cout << "El año " << anio << " es biciesto" << endl;
    }
    else {
        cout << "El año " << anio << " no es biciesto" << endl;
    }
    */
}

//Ejercicio 2
/*
void apareoPersona(persona arrA[], int lenA, persona arrB[], int lenB, persona arrC[], int &lenC) {
    int posA = 0;
    int posB = 0;

    while (posA < lenA && posB < lenB) {
        if (arrA[posA].DNI < arrB[posB].DNI) {
            agregarPersona(arrC, 20, lenC, arrA[posA]);
            posA++;
        }
        else {
            agregarPersona(arrC, 20, lenC, arrB[posB]);
            posB++;
        }
    }
    while (posA < lenA) {
        agregarPersona(arrC, 20, lenC, arrA[posA]);
        posA++;
    }
    while (posB < lenB) {
        agregarPersona(arrC, 20, lenC, arrB[posB]);
        posB++;
    }
}
void agregarPersona(persona arr[], int n, int& len, persona v) {
    if (len < n) {
        arr[len] = v;
        len++;
    }
    else {
        cout << "El vector está lleno :( " << endl;
    }
}
void mostrarPersona(persona arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "DNI: " << arr[i].DNI << endl;
        cout << "Nombre y Apellido: " << arr[i].nomYApe << endl;
        lineaSeparatoria();
    }
}*/

//Ejercicio 3
/*(1 punto - 1/1) 
Desarrolle un procedimiento que muestre, dado un mes (MM), cuál es la estación (Primavera-Verano-Otoño-Invierno) del año.*/
/*
void calcularEstacion(int mes) {
    if (mes > 0 && mes < 4) {
        cout << "es Otoño" << endl;
    }
    else if(mes > 3 && mes < 7){
        cout << "es Invierno" << endl;
    }
    else if (mes > 6 && mes < 10) {
        cout << "es Primavera" << endl;
    }
    else if (mes > 9 && mes < 13) {
        cout << "es Verano" << endl;
    }
}
*/

//Ejercicio 5
/*
bool elAnioEsBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0);
}
*/