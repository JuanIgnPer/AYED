#include <iostream>

/**
 * (3 puntos) Un supermercado tiene 4 cajas con sus respectivas colas C1, C2, C3 y C4.
 * Las colas se encuentran implementadas en un vector: la posición 0 contiene el puntero a la cola 1, etc.
 * Cada changuito (nodo), contiene el identificador de cliente, la cantidad de artículos totales, el dinero a abonar, el medio de pago y si requieren de envío a domicilio (si o no).

La caja 1 se cierra y se debe dividir los changuitos de la siguiente manera (lo que ocurra primero):

- A la caja 2 deben ir aquellos que tienen menos de 15 artículos.

- A la caja 3 deben ir aquellos que pagan con tarjeta de crédito.

- A la caja 4 aquellos que requieran de envío a domicilio.
 En este caso también se debe persistir en un archivo “domicilio.dat” el identificador de cliente y la cantidad de artículos totales.
 */

struct RegistroDomicilio {
    int idCliente;
    int cantArticulosTotales;
};

struct Compra {
    int idCliente;
    int cantArticulosTotales;
    long dineroAAbonar;
    char medioDePago[2];
    bool requiereEnvio;
};

struct Changuito {
    Compra compra;
    Changuito* sig;
};

struct Cola {
    Changuito* cfte;
    Changuito* cfin;
};

//MEDIOS DE PAGO:

//EF : EFECTIVO
//TC : TARJETA DE CREDITO
//TD : TARJETA DE DEBITO

void administrarCierreCaja1(Cola colas[4]);

void encolar (Changuito* &colaFrente, Changuito* &colaFin, Compra compra);

Compra desencolar(Changuito* &colaFrente, Changuito* &colaFin);

void administrarCierreCaja1(Cola colas[4]) {

    FILE* entregasDomicilio = fopen("domicilio.dat", "wb");

    Cola cola1 = colas[0];
    Cola cola2 = colas[1];
    Cola cola3 = colas[2];
    Cola cola4 = colas[3];

    while (cola1.cfte != NULL) {
        Compra compra = desencolar(cola1.cfte, cola1.cfin);

        if (compra.cantArticulosTotales < 15) {
            encolar(cola2.cfte, cola2.cfin, compra);
            continue;
        }

        if (compra.medioDePago == "TC") {
            encolar(cola3.cfte, cola3.cfin, compra);
            continue;
        }

        if (compra.requiereEnvio) {
            encolar(cola4.cfte, cola4.cfin, compra);
            RegistroDomicilio registroDomicilio;
            registroDomicilio.idCliente = compra.idCliente;
            registroDomicilio.cantArticulosTotales = compra.cantArticulosTotales;
            fwrite(&registroDomicilio, sizeof(RegistroDomicilio), 1, entregasDomicilio);
            continue;
        }
    }
    fclose(entregasDomicilio);
}
