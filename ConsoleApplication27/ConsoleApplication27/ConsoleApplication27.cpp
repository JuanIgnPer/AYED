#include "..\..\Headers\dinamica.hpp"
#include <iostream>
#include <string>

int main()
{
    /*EJ 1*/
    /*
    Conversacion* conversaciones = NULL;
    contacto vecContactos[200]{ {3462, "Pepito", false}, {7893, "Pirulito", true} };
    int len = 2;
    
    infoConver info;
    info.idConversacion = 8953;
    info.nombre = "Gym";
    info.notificar = true;
    info.vistaPrevia = true;
    agregarConversacion(conversaciones, info);

    info.idConversacion = 8990;
    info.nombre = "Yoga";
    info.notificar = true;
    info.vistaPrevia = false;
    agregarConversacion(conversaciones, info);

    info.idConversacion = 8991;
    info.nombre = "Memes";
    info.notificar = false;
    info.vistaPrevia = false;
    agregarConversacion(conversaciones, info);

    info.idConversacion = 9875;
    info.nombre = "";
    info.notificar = true;
    info.vistaPrevia = true;
    agregarConversacion(conversaciones, info);

    info.idConversacion = 9876;
    info.nombre = "";
    info.notificar = true;
    info.vistaPrevia = false;
    agregarConversacion(conversaciones, info);

    cout << "Grupal con vista previa" << endl;
    notificarMensajeRecibido(conversaciones, vecContactos, len, 8953, 3462 , "Nos vemos a las 9");
    cout << "Particular bloqueado" << endl;
    notificarMensajeRecibido(conversaciones, vecContactos, len, 8953, 7893 , "Nos vemos a las 9");
    cout << "Particular no agendado" << endl;
    notificarMensajeRecibido(conversaciones, vecContactos, len, 8953, 541199256535, "Nos vemos a las 9");
    cout << "Grupal sin vista previa" << endl;
    notificarMensajeRecibido(conversaciones, vecContactos, len, 8990, 3462 , "Nos vemos a las 9");
    */

    /*EJ 2*/
    /*
    //Array de docentes - {"nroListaPersona", nroLista} - ordenados de mayor a menor por cantida de votos
    candidato vecCand[15] = {
        {"1A",1},{"1B",1},{"1C",1},{"1D",1},{"1E",1}, //Lista 1
        {"2A",2},{"2B",2},{"2C",2},{"2D",2},{"2E",2}, //Lista 2
        {"3A",3},{"3B",3},{"3C",3},{"3D",3},{"3E",3}, //Lista 3
    };
    int lenCand = 15;

    resultado vecRes[5];
    int lenRes = 0;

    generarListaConsejerosDocentes(vecCand, lenCand, vecRes, lenRes);

    for (int i = 0; i < lenRes; i++){
        cout << "Posicion: " << vecRes[i].pos << endl;
        cout << "Lista: " << vecRes[i].cand.lista << endl;
        cout << "Nombre: " << vecRes[i].cand.nombre << endl;
        cout << "-------------------------------" << endl;
    }
    */
    //Terminado
}