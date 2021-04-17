#include "funciones.h"

/**
 * (3 puntos) Se tiene un archivo “ventas.dat” que contiene los siguientes datos: número de cliente, artículo comprado, cantidad comprada y precio unitario.
 * Con estos datos llenar una lista que debe contener número de cliente y dinero gastado.
 * A su vez cada nodo de esa lista, va a poseer una sublista de los artículos comprados, junto con su cantidad comprada y precio unitario.
 * Nota: El precio unitario para cada artículo no varía. Si el artículo se repite por cada cliente debe incrementarse su cantidad vendida.
 *
    Informar:

    Cuál es el cliente que menos dinero gastó.
    Cuál es el cliente que más unidades totales de productos compró.
    Este ejercicio debe resolverse sí o sí en forma manuscrita. Colocar el DNI en la hoja de la resolución y sacarle una foto.
 */

struct Venta {
    int nroCliente;
    int codArticulo;
    int cantComprada;
    int precioUnitario;
} reg;

struct Articulo {
    int codArticulo;
    int cantComprada;
    int precioUnitario;
};

struct NodoArticulo {
    Articulo articulo;
    NodoArticulo* sig;
};

struct Cliente {
    int nroCliente;
    long dineroGastado;
    NodoArticulo* articulosComprados;
};

struct NodoCliente {
    Cliente cliente;
    NodoCliente* sig;
};

/**
 * FUNCIONES OBLIGATORIAS (PARA LA VERSION MANUSCRITA)
 */

void agregarNodo(NodoCliente* &lista, Cliente cliente);
void agregarNodo(NodoArticulo* &lista, Articulo articulo);

//busca la lista de clientes en base al numero del cliente, retorna el nodo o NULL si no encontro nada
NodoCliente* buscar(NodoCliente* lista, int nroCliente);

//busca la lista de articulos en base al codigo de articulo, retorna el nodo o NULL si no encontro nada
NodoArticulo* buscar(NodoArticulo* lista, int codArticulo);

/**
 * FUNCIONES COMPLEMENTARIAS (IMPLEMENTACION NO REQUERIDA/POSIBLE DURANTE EXAMEN)
 */

void cargarArchivo();


int main() {
//    cargarArchivo();

    FILE* ventas = fopen("ventas.dat", "rb");
    NodoCliente* lista = NULL;
    fread(&reg, sizeof(Venta), 1, ventas);

    while(!feof(ventas)) {
        int nroCliente = reg.nroCliente;
        NodoCliente* aux = buscar(lista, nroCliente);
        if (aux == NULL) {
            //el cliente no existe, inserto desde 0 todo
            Cliente cliente;
            cliente.nroCliente = nroCliente;
            cliente.dineroGastado = reg.cantComprada * reg.precioUnitario;

            //cargo el articulo y su lista de articulos desde 0 tambien
            NodoArticulo* articulos = NULL;
            Articulo articulo;
            articulo.codArticulo = reg.codArticulo;
            articulo.precioUnitario = reg.precioUnitario;
            articulo.cantComprada = reg.cantComprada;
            agregarNodo(articulos, articulo);
            cliente.articulosComprados = articulos;

            agregarNodo(lista, cliente);
        } else {
            //el cliente existe y tengo el nodo
            aux->cliente.dineroGastado += reg.cantComprada * reg.precioUnitario;
            NodoArticulo* auxArt = buscar(aux->cliente.articulosComprados, reg.codArticulo);

            if (auxArt == NULL) {
                //el articulo no existe, agrego un nodo nuevo
                Articulo articulo;
                articulo.codArticulo = reg.codArticulo;
                articulo.precioUnitario = reg.precioUnitario;
                articulo.cantComprada = reg.cantComprada;
                agregarNodo(aux->cliente.articulosComprados, articulo);

            } else {
                //el articulo existe, modifico el nodo actual
                auxArt->articulo.cantComprada += reg.cantComprada;
            }
        }

        fread(&reg, sizeof(Venta), 1, ventas);
    }
    //finalizado el while de lectura, tengo una lista cargada con todos los clientes, y cada cliente tiene ademas una lista con sus productos.

    //punto A: cual es el cliente que menos gasto? es tan simple como iterar la lista manteniendo un minimo global (simple)

    int minimoGastado = 9999999;
    NodoCliente* menorGastador = NULL;
    NodoCliente* auxIterador = lista;

    //punto B: recorrer cada sublista de cada cliente y mantener un un contador maximo por cada cliente (mid) se puede mergear al otro ciclo

    int cantMaxDeArticulosComprados = 0;
    NodoCliente* mayorCompradorPorCantidad = NULL;

    while (auxIterador != NULL) {
        int dineroGastado = lista->cliente.dineroGastado;
        if (dineroGastado < minimoGastado) {
            minimoGastado = dineroGastado;
            menorGastador = auxIterador;
        }
        int cantArticulosComprados = 0;
        NodoArticulo* articuloIterador = auxIterador->cliente.articulosComprados;
        while (articuloIterador != NULL) {
            cantArticulosComprados += articuloIterador->articulo.cantComprada;
            articuloIterador = articuloIterador->sig;
        }
        if (cantArticulosComprados > cantMaxDeArticulosComprados) {
            cantMaxDeArticulosComprados = cantArticulosComprados;
            mayorCompradorPorCantidad = auxIterador;
        }
        auxIterador = auxIterador->sig;
    }

    cout << "el cliente que menos gasto fue el de id: " << menorGastador->cliente.nroCliente << " con una suma de: " << minimoGastado << endl;
    cout << "el cliente que mas articulos compro (por cantidad) fue: " << mayorCompradorPorCantidad->cliente.nroCliente << " con una cantidad de: " << cantMaxDeArticulosComprados << endl;

    return 0;
}

/**
 * IMPLEMENTACIONES PURA Y EXCLUSIVAMENTE OPCIONALES DURANTE EL EXAMEN
 */

void agregarNodo(NodoCliente* &lista, Cliente cliente) {
    NodoCliente* nuevo = new NodoCliente();
    nuevo->cliente = cliente;
    nuevo->sig = NULL;

    if(lista == NULL) {
        //la lista p esta vacia
        lista = nuevo;
    } else {
        //tengo que recorrer hasta el ultimo valor
        NodoCliente* aux = lista;
        while(aux-> sig != NULL) {
            aux = aux->sig;
        }
        //finalmente, agrego el nuevo nodo al ultimo lugar
        aux->sig = nuevo;
    }
}

void agregarNodo(NodoArticulo* &lista, Articulo articulo) {
    NodoArticulo* nuevo = new NodoArticulo();
    nuevo->articulo = articulo;
    nuevo->sig = NULL;

    if(lista == NULL) {
        //la lista p esta vacia
        lista = nuevo;
    } else {
        //tengo que recorrer hasta el ultimo valor
        NodoArticulo* aux = lista;
        while(aux-> sig != NULL) {
            aux = aux->sig;
        }
        //finalmente, agrego el nuevo nodo al ultimo lugar
        aux->sig = nuevo;
    }
}

NodoCliente* buscar(NodoCliente* lista, int nroCliente) {
    NodoCliente* aux = lista;
    while (aux != NULL && aux->cliente.nroCliente != nroCliente) {
        aux = aux->sig;
    }
    return aux;
}

NodoArticulo* buscar(NodoArticulo* lista, int codArticulo) {
    NodoArticulo* aux = lista;
    while (aux != NULL && aux->articulo.codArticulo != codArticulo) {
        aux = aux->sig;
    }
    return aux;
}

void cargarArchivo() {
    FILE* ventas = fopen("ventas.dat", "wb");

    Venta v1_100_1;
    v1_100_1.codArticulo = 1;
    v1_100_1.precioUnitario = 50;
    v1_100_1.cantComprada = 3;
    v1_100_1.nroCliente = 100;

    fwrite(&v1_100_1, sizeof(Venta), 1, ventas);

    Venta v1_100_2;
    v1_100_2.codArticulo = 1;
    v1_100_2.precioUnitario = 50;
    v1_100_2.cantComprada = 2;
    v1_100_2.nroCliente = 100;

    fwrite(&v1_100_2, sizeof(Venta), 1, ventas);

    Venta v2_100_1;
    v2_100_1.codArticulo = 2;
    v2_100_1.precioUnitario = 45;
    v2_100_1.cantComprada = 5;
    v2_100_1.nroCliente = 100;

    fwrite(&v2_100_1, sizeof(Venta), 1, ventas);

    Venta v2_110_1;
    v2_110_1.codArticulo = 2;
    v2_110_1.precioUnitario = 45;
    v2_110_1.cantComprada = 3;
    v2_110_1.nroCliente = 110;

    fwrite(&v2_110_1, sizeof(Venta), 1, ventas);

    Venta v3_110_1;
    v3_110_1.codArticulo = 3;
    v3_110_1.precioUnitario = 75;
    v3_110_1.cantComprada = 10;
    v3_110_1.nroCliente = 110;

    fwrite(&v3_110_1, sizeof(Venta), 1, ventas);

    fclose(ventas);
}