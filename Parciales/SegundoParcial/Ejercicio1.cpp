#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

//Ejercicio 1
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

int main()
{
    //Ejercicio 1

    ////LLeno el archivo 
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
}
