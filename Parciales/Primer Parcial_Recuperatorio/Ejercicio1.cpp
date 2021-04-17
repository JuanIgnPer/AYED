struct Venta {
    int nroVenta;
    int idCliente;
    float monto;
    char fecha[8];
};

//la implementacion ejecuta una busqueda sequencial en base al campo venta.nroVenta
int buscar(Venta arr[], int len, int nroVenta);

//la implementacion inserta en el array de manera ordenada en base a la clave primaria venta.nroVenta
void insertarOrdenado(Venta arr[],int &len, Venta v);

void llenarVectorC(Venta ventasA[], int lenA, Venta ventasB[], int lenB, Venta ventasC[], int &lenC) {

    for (int i=0; i < lenB ; i++) {
        //por cada elemento de B, busco en el vector A
        int pos = -1;

        pos = buscar(ventasA, lenA, ventasB[i].nroVenta);

        if (pos == -1) {
            //el elemento no existe, insertando en el vector C
            insertarOrdenado(ventasC, lenC, ventasB[i]);

        } else {
            //el elemento existe en A, descarto el valor y salto hacia la proxima iteracion
            continue;
        }

    }
    
}