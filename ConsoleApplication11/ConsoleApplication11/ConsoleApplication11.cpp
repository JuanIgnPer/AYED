#include "..\..\Headers\vectores.hpp"

int main()
{
    /*Ejercicio 1 - Apareo de archivos*/
    /*Llenado de archivos*/
    /*
    articulo reg;
    //Deposito 1
    FILE* dep1 = fopen("deposito1.dat", "wb+");
    reg.nroArt = 1236;
    strcpy(reg.descripcion, "martillo");
    reg.cantidad = 100;
    fwrite(&reg, sizeof(articulo), 1, dep1);
    reg.nroArt = 6789;
    strcpy(reg.descripcion, "tornillo");
    reg.cantidad = 2000;
    fwrite(&reg, sizeof(articulo), 1, dep1);
    rewind(dep1);
    cout << "____________________" << endl;
    cout << "_____Deposito 1_____" << endl;
    cout << "____________________" << endl;
    fread(&reg, sizeof(articulo), 1, dep1);
    while (!feof(dep1)) {
        cout << "Nro Art " << reg.nroArt << endl;
        cout << "Descripcion " << reg.descripcion << endl;
        cout << "Cantidad " << reg.cantidad << endl;
        cout << "______________________________" << endl;
        fread(&reg, sizeof(articulo), 1, dep1);
    }
    fclose(dep1);

    //Deposito2
    FILE* dep2 = fopen("deposito2.dat", "wb+");
    reg.nroArt = 1100;
    strcpy(reg.descripcion, "pinza");
    reg.cantidad = 18;
    fwrite(&reg, sizeof(articulo), 1, dep2);
    reg.nroArt = 7900;
    strcpy(reg.descripcion, "pegamento");
    reg.cantidad = 500;
    fwrite(&reg, sizeof(articulo), 1, dep2);
    cout << "____________________" << endl;
    cout << "_____Deposito 2_____" << endl;
    cout << "____________________" << endl;
    rewind(dep2);
    fread(&reg, sizeof(articulo), 1, dep2);
    while (!feof(dep2)) {
        cout << "Nro Art " << reg.nroArt << endl;
        cout << "Descripcion " << reg.descripcion << endl;
        cout << "Cantidad " << reg.cantidad << endl;
        cout << "______________________________" << endl;
        fread(&reg, sizeof(articulo), 1, dep2);
    }
    fclose(dep2);
    */
    /*Apareo de archivos*/
    /*
    FILE* dep1 = fopen("deposito1.dat", "rb");
    FILE* dep2 = fopen("deposito2.dat", "rb");
    FILE* stock = fopen("stock.dat", "wb+"); //Abro el archivo consolidado
    articulo reg1; //Defino el reg1 para el dep1
    articulo reg2; //Defino el reg1 para el dep2
    fread(&reg1, sizeof(articulo), 1, dep1); //Leo los dos primeros articulos de los dep
    fread(&reg2, sizeof(articulo), 1, dep2);
    while (!feof(dep1) && !feof(dep2)) {
        if (reg1.nroArt < reg2.nroArt) {
            fwrite(&reg1, sizeof(articulo), 1, stock);
            fread(&reg1, sizeof(articulo), 1, dep1);
        }
        else {
            fwrite(&reg2, sizeof(articulo), 1, stock);
            fread(&reg2, sizeof(articulo), 1, dep2);
        }
    }
    while (!feof(dep1)) {
        fwrite(&reg1, sizeof(articulo), 1, stock);
        fread(&reg1, sizeof(articulo), 1, dep1);
    }
    while (!feof(dep2)) {
        fwrite(&reg2, sizeof(articulo), 1, stock);
        fread(&reg2, sizeof(articulo), 1, dep2);
    }
    //Ciero ambos archivos de deposito
    fclose(dep1);
    fclose(dep2);
    rewind(stock);
    articulo regStock;
    fread(&regStock, sizeof(articulo), 1, stock);
    while (!feof(stock)) {
        cout << "Nro Art " << regStock.nroArt << endl;
        cout << "Descripcion " << regStock.descripcion << endl;
        cout << "Cantidad " << regStock.cantidad << endl;
        cout << "______________________________" << endl;
        fread(&regStock, sizeof(articulo), 1, stock);
    }
    fclose(stock);
    */

    /*Ejercicio 2 - Apareo de archivos*/
    /*Llenado de archivos*/
    /*
    articulo reg;
    //Deposito 1
    FILE* dep1 = fopen("deposito1.dat", "wb+");
    reg.nroArt = 1236;
    strcpy(reg.descripcion, "martillo");
    reg.cantidad = 100;
    fwrite(&reg, sizeof(articulo), 1, dep1);
    reg.nroArt = 6789;
    strcpy(reg.descripcion, "tornillo");
    reg.cantidad = 2000;
    fwrite(&reg, sizeof(articulo), 1, dep1);
    rewind(dep1);
    cout << "____________________" << endl;
    cout << "_____Deposito 1_____" << endl;
    cout << "____________________" << endl;
    fread(&reg, sizeof(articulo), 1, dep1);
    while (!feof(dep1)) {
        cout << "Nro Art " << reg.nroArt << endl;
        cout << "Descripcion " << reg.descripcion << endl;
        cout << "Cantidad " << reg.cantidad << endl;
        cout << "______________________________" << endl;
        fread(&reg, sizeof(articulo), 1, dep1);
    }
    fclose(dep1);

    //Deposito2
    FILE* dep2 = fopen("deposito2.dat", "wb+");
    reg.nroArt = 1100;
    strcpy(reg.descripcion, "pinza");
    reg.cantidad = 18;
    fwrite(&reg, sizeof(articulo), 1, dep2);
    reg.nroArt = 7900;
    strcpy(reg.descripcion, "pegamento");
    reg.cantidad = 500;
    fwrite(&reg, sizeof(articulo), 1, dep2);
    cout << "____________________" << endl;
    cout << "_____Deposito 2_____" << endl;
    cout << "____________________" << endl;
    rewind(dep2);
    fread(&reg, sizeof(articulo), 1, dep2);
    while (!feof(dep2)) {
        cout << "Nro Art " << reg.nroArt << endl;
        cout << "Descripcion " << reg.descripcion << endl;
        cout << "Cantidad " << reg.cantidad << endl;
        cout << "______________________________" << endl;
        fread(&reg, sizeof(articulo), 1, dep2);
    }
    fclose(dep2);
    */
    /*Apareo de archivos*/
    /*
    dep1 = fopen("deposito1.dat", "rb");
    dep2 = fopen("deposito2.dat", "rb");
    FILE* stock = fopen("stock.dat", "wb+"); //Abro el archivo consolidado
    articulo reg1; //Defino el reg1 para el dep1
    articulo reg2; //Defino el reg1 para el dep2
    articuloDeposito regArtDeposito; //Defino el articuloDesposito para ambos depositos
    fread(&reg1, sizeof(articulo), 1, dep1); //Leo los dos primeros articulos de los dep
    fread(&reg2, sizeof(articulo), 1, dep2);
    while (!feof(dep1) && !feof(dep2)) {
        if (reg1.nroArt < reg2.nroArt) {
            regArtDeposito.art = reg1; //Armo el artDeposito, tomando el articulo que esta siendo procesado en este momento
            strcpy(regArtDeposito.deposito, "Dep 1");//Le asigno el Dep correspondiente
            fwrite(&regArtDeposito, sizeof(articuloDeposito), 1, stock);
            fread(&reg1, sizeof(articulo), 1, dep1);
        }
        else {
            regArtDeposito.art = reg2;
            strcpy(regArtDeposito.deposito, "Dep 2");
            fwrite(&regArtDeposito, sizeof(articuloDeposito), 1, stock);
            fread(&reg2, sizeof(articulo), 1, dep2);
        }
    }
    while (!feof(dep1)) {
        regArtDeposito.art = reg1;
        strcpy(regArtDeposito.deposito, "Dep 1");
        fwrite(&regArtDeposito, sizeof(articuloDeposito), 1, stock);
        fread(&reg1, sizeof(articulo), 1, dep1);
    }
    while (!feof(dep2)) {
        regArtDeposito.art = reg2;
        strcpy(regArtDeposito.deposito, "Dep 2");
        fwrite(&regArtDeposito, sizeof(articuloDeposito), 1, stock);
        fread(&reg2, sizeof(articulo), 1, dep2);
    }
    //Ciero ambos archivos de deposito
    fclose(dep1);
    fclose(dep2);
    //Leo el consolidado
    rewind(stock);
    articuloDeposito regStock;
    fread(&regStock, sizeof(articuloDeposito), 1, stock);
    while (!feof(stock)) {
        cout << "Nro Art " << regStock.art.nroArt << endl;
        cout << "Descripcion " << regStock.art.descripcion << endl;
        cout << "Cantidad " << regStock.art.cantidad << endl;
        cout << "Deposito " << regStock.deposito << endl;
        cout << "______________________________" << endl;
        fread(&regStock, sizeof(articuloDeposito), 1, stock);
    }
    fclose(stock);
    */
}