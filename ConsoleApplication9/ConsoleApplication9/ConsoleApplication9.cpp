#include "..\..\Headers\vectores.hpp"
using namespace std;

int main()
{
    /*Ejercicio 1 - Corte de control con arreglos*/
    /*
    //30 días(Abril) * Cantidad de Sucursales
    //Suponemos que tiene 3 sucursales
    sucursal vecSuc[90] = {
        {1,1,1000.50},
        {1,2,1500},
        {1,3,800.2},
        {2,1,600},
        {2,2,767.3},
        {2,3,875},
        {3,1,469},
        {3,2,800.7},
        {3,3,2700}
    };
    int lenVecSuc = 9;
    int pos = 0;
    int sucursalAnterior;
    float dineroRecaudadoXSucursalEnElMes;
    float maxDineroSucursal;
    int diaMaxDineroSucursal;
    float minRecaudacionEnElMes = 999999999999999999999999999.0;
    int NroSucursalminRecaudacionEnElMes = -1;
    //While que itera sobre todas las sucursales
    while(pos < lenVecSuc) {
      //Vacio todas las variables generales
      sucursalAnterior = vecSuc[pos].sucursal;
      dineroRecaudadoXSucursalEnElMes = 0;
      maxDineroSucursal = -1;
      diaMaxDineroSucursal = -1;
      //Itero sobre la misma sucursal, sumando todo el dinero recaudado al pasar los dias
      while(pos < lenVecSuc && sucursalAnterior == vecSuc[pos].sucursal) {
        dineroRecaudadoXSucursalEnElMes += vecSuc[pos].dineroRecaudado;
        if(vecSuc[pos].dineroRecaudado > maxDineroSucursal) {
          maxDineroSucursal = vecSuc[pos].dineroRecaudado;
          diaMaxDineroSucursal = vecSuc[pos].dia;
        }
        pos++;
      }
      cout << "La sucursal nro " << sucursalAnterior <<  " recaudo " << dineroRecaudadoXSucursalEnElMes << endl;
      cout << "El día que más dinero recaudó fue " << diaMaxDineroSucursal << " de Abril " << " con $ " <<  maxDineroSucursal << endl;
      if(dineroRecaudadoXSucursalEnElMes < minRecaudacionEnElMes){
        minRecaudacionEnElMes = dineroRecaudadoXSucursalEnElMes;
        NroSucursalminRecaudacionEnElMes = sucursalAnterior;
      }
    }
    cout << "La sucursal nro " << NroSucursalminRecaudacionEnElMes << "  fue la que menos recaudó con un total de $" << minRecaudacionEnElMes << endl;
    */

    /*Ejercicio 2 - Apareo con archivos*/
    /*Creacion y llenado de archivos*/
    /*
    claustro reg;
    //fopen("nombreDelArchivo.dat","tipoDeApertura")
    //"wb" -> Para escribir  //"rb" -> Para leer //Y si yo quiero leer y escribir "rb+" o "wb+""
    
    //Estudiante
    FILE* archivo_est = fopen("estudiante.dat", "wb+");
    strcpy(reg.nombre,"Natalia");
    reg.legajo = 7892;
    //(registro por referencia, sizeof tipo de registro, cantidadDeElementosAEscribir, puntero-archivo)
    fwrite(&reg, sizeof(claustro), 1, archivo_est);
    strcpy(reg.nombre, "Lucas");
    reg.legajo = 1234;
    fwrite(&reg,sizeof(claustro),1, archivo_est);
    //Una vez que escribo, para leer tengo que volver al princpio del archivo
    rewind(archivo_est); //Vuelvo al principio
    //ESTRATEGIA DE LECTURA, SIEMPRE IGUAL!!!!!!!!!!!!
    fread(&reg,sizeof(claustro),1, archivo_est);//En reg voy a tener los datos que acabo de leer
    while(!feof(archivo_est)) {
      //PROCESAR LO QUE SEA QUE TENGA QUE PROCESAR
       cout << "Nombre: " << reg.nombre << endl;
       cout << "Legajo: " << reg.legajo  << endl;
       lineaSeparatoria();
      //VUELVO A LEER PARA AVANZAR
      fread(&reg,sizeof(claustro),1, archivo_est);
    }
    fclose(archivo_est);
    //Docente
    FILE* archivo_doc = fopen("docente.dat", "wb+");
    strcpy(reg.nombre, "Karina");
    reg.legajo = 5678;
    fwrite(&reg, sizeof(claustro), 1, archivo_doc);
    strcpy(reg.nombre, "Santiago");
    reg.legajo = 2345;
    fwrite(&reg, sizeof(claustro), 1, archivo_doc);
    rewind(archivo_doc);
    fread(&reg, sizeof(claustro), 1, archivo_doc);
    while (!feof(archivo_doc)) {
        cout << "Nombre: " << reg.nombre << endl;
        cout << "Legajo: " << reg.legajo << endl;
        lineaSeparatoria();
        fread(&reg, sizeof(claustro), 1, archivo_doc);
    }
    fclose(archivo_doc);
    //Graduado
    FILE* archivo_gra = fopen("graduado.dat", "wb+");
    strcpy(reg.nombre, "Valeria");
    reg.legajo = 9000;
    fwrite(&reg, sizeof(claustro), 1, archivo_gra);
    strcpy(reg.nombre, "Juan");
    reg.legajo = 8769;
    fwrite(&reg, sizeof(claustro), 1, archivo_gra);
    rewind(archivo_gra);
    fread(&reg, sizeof(claustro), 1, archivo_gra);
    while (!feof(archivo_gra)) {
        cout << "Nombre: " << reg.nombre << endl;
        cout << "Legajo: " << reg.legajo << endl;
        lineaSeparatoria();
        fread(&reg, sizeof(claustro), 1, archivo_gra);
    }
    fclose(archivo_gra);
    //No docente
    FILE* archivo_nod = fopen("nodocente.dat", "wb+");
    strcpy(reg.nombre, "Ayelen");
    reg.legajo = 5900;
    fwrite(&reg, sizeof(claustro), 1, archivo_nod);
    strcpy(reg.nombre, "Sebastian");
    reg.legajo = 1111;
    fwrite(&reg, sizeof(claustro), 1, archivo_nod);
    rewind(archivo_nod);
    fread(&reg, sizeof(claustro), 1, archivo_nod);
    while (!feof(archivo_nod)) {
        cout << "Nombre: " << reg.nombre << endl;
        cout << "Legajo: " << reg.legajo << endl;
        lineaSeparatoria();
        fread(&reg, sizeof(claustro), 1, archivo_nod);
    }
    fclose(archivo_nod);
    //Leo archivos->Inserto ordenado en el vec correspondiente
    claustroConsolidado regConsolidado;
    //Estudiante
    FILE* archivoEst = fopen("estudiante.dat", "rb");
    claustroConsolidado vecEstudiante[10];
    int lenVecEstudiante = 0;
    fread(&reg, sizeof(claustro), 1, archivoEst);
    while (!feof(archivoEst)) {
        regConsolidado.claustro = reg;
        strcpy(regConsolidado.descripcionClaustro, "Estudiante");
        insertarOrdenadoClaustro(vecEstudiante, lenVecEstudiante, regConsolidado);
        fread(&reg, sizeof(claustro), 1, archivoEst);
    }
    fclose(archivoEst);
    //Graduado
    FILE* archivoGra = fopen("graduado.dat", "rb");
    claustroConsolidado vecGraduado[10];
    int lenVecGraduado = 0;
    fread(&reg, sizeof(claustro), 1, archivoGra);
    while (!feof(archivoGra)) {
        regConsolidado.claustro = reg;
        strcpy(regConsolidado.descripcionClaustro, "Graduado");
        insertarOrdenadoClaustro(vecGraduado, lenVecGraduado, regConsolidado);
        fread(&reg, sizeof(claustro), 1, archivoGra);
    }
    fclose(archivoGra);
    //Docente
    FILE* archivoDoc = fopen("docente.dat", "rb");
    claustroConsolidado vecDocente[10];
    int lenVecDoc = 0;
    fread(&reg, sizeof(claustro), 1, archivoDoc);
    while (!feof(archivoDoc)) {
        regConsolidado.claustro = reg;
        strcpy(regConsolidado.descripcionClaustro, "Docente");
        insertarOrdenadoClaustro(vecDocente, lenVecDoc, regConsolidado);
        fread(&reg, sizeof(claustro), 1, archivoDoc);
    }
    fclose(archivoDoc);
    //NoDocente
    FILE* archivoNoDoc = fopen("nodocente.dat", "rb");
    claustroConsolidado vecNoDocente[10];
    int lenVecNoDoc = 0;
    fread(&reg, sizeof(claustro), 1, archivoNoDoc);
    while (!feof(archivoNoDoc)) {
        regConsolidado.claustro = reg;
        strcpy(regConsolidado.descripcionClaustro, "No Docente");
        insertarOrdenadoClaustro(vecNoDocente, lenVecNoDoc, regConsolidado);
        fread(&reg, sizeof(claustro), 1, archivoNoDoc);
    }
    fclose(archivoNoDoc);
    */
    /*Apareo los archivos, usando vectores*/
    /*
    //Junto de a 2 vectores, y despues junto de nuevo el resultado y escribo en un archivo
    FILE * archivoConsolidado = fopen("consolidado.dat","wb+");
    //Junto estudiantes con graduados haciendo un apareo de arreglos
    claustroConsolidado vectorConsolidadoEstGra[20];
    int lenConEstGra = 0;
    int posEst = 0;
    int posGra = 0;
    while(posEst < lenVecEstudiante && posGra < lenVecGraduado) {
        if(vecEstudiante[posEst].claustro.legajo < vecGraduado[posGra].claustro.legajo) {
            vectorConsolidadoEstGra[lenConEstGra] = vecEstudiante[posEst];
            posEst++;
        } else {
            vectorConsolidadoEstGra[lenConEstGra] = vecGraduado[posGra];
            posGra++;
        }
        lenConEstGra++;
    }
    while(posEst < lenVecEstudiante){
        vectorConsolidadoEstGra[lenConEstGra] = vecEstudiante[posEst];
        posEst++;
        lenConEstGra++;
    }
    while(posGra < lenVecGraduado){
        vectorConsolidadoEstGra[lenConEstGra] = vecGraduado[posGra];
        posGra++;
        lenConEstGra++;
    }
    //Junto docentes con noDocentes haciendo un apareo de arreglos
    claustroConsolidado vectorConsolidadoDocNoDoc[20];
    int lenConDocNoDoc = 0;
    int posNoDoc = 0;
    int posDoc = 0;
    while(posDoc < lenVecDoc && posNoDoc < lenVecNoDoc) {
          if(vecDocente[posDoc].claustro.legajo < vecNoDocente[posNoDoc].claustro.legajo) {
              vectorConsolidadoDocNoDoc[lenConDocNoDoc] = vecDocente[posDoc];
              posDoc++;
          } else {
              vectorConsolidadoDocNoDoc[lenConDocNoDoc] = vecNoDocente[posNoDoc];
              posNoDoc++;
          }
          lenConDocNoDoc++;
    }
    while(posDoc < lenVecDoc) {
        vectorConsolidadoDocNoDoc[lenConDocNoDoc] = vecDocente[posDoc];
        posDoc++;
        lenConDocNoDoc++;
    }
    while(posNoDoc < lenVecNoDoc) {
        vectorConsolidadoDocNoDoc[lenConDocNoDoc] = vecNoDocente[posNoDoc];
        posNoDoc++;
        lenConDocNoDoc++;
    }
    //Junto estudiantesYGraduados con docentesYnoDocentes haciendo un apareo de arreglos
    int posEstGra = 0;
    int posDocNoDoc = 0;
    while( posEstGra < lenConEstGra && posDocNoDoc < lenConDocNoDoc) {
        if(vectorConsolidadoEstGra[posEstGra].claustro.legajo < vectorConsolidadoDocNoDoc[posDocNoDoc].claustro.legajo) {
            fwrite(&vectorConsolidadoEstGra[posEstGra],sizeof(claustroConsolidado),1,archivoConsolidado);
            posEstGra++;
        } else {
            fwrite(&vectorConsolidadoDocNoDoc[posDocNoDoc],sizeof(claustroConsolidado),1,archivoConsolidado);
            posDocNoDoc++;
        }
    }
    while(posEstGra < lenConEstGra){
        fwrite(&vectorConsolidadoEstGra[posEstGra],sizeof(claustroConsolidado),1,archivoConsolidado);
        posEstGra++;
    }
    while(posDocNoDoc < lenConDocNoDoc) {
        fwrite(&vectorConsolidadoDocNoDoc[posDocNoDoc],sizeof(claustroConsolidado),1,archivoConsolidado);
        posDocNoDoc++;
    }
    //Vuelvo al principio y muestro todos los datos ordenados
    rewind(archivoConsolidado);
    claustroConsolidado regLectura;
    fread(&regLectura,sizeof(claustroConsolidado),1,archivoConsolidado);
    while(!feof(archivoConsolidado)) {
      cout << "Legajo:" << regLectura.claustro.legajo << endl;
      cout << "Nombre:" << regLectura.claustro.nombre << endl;
      cout << "Claustro: " << regLectura.descripcionClaustro << endl;
      lineaSeparatoria();
      fread(&regLectura,sizeof(claustroConsolidado),1,archivoConsolidado);
    }
    fclose(archivoConsolidado);
    */

    /*Ejercicio 1 - Corte de control con archivos*/
    /*
    FILE * ventas = fopen("ventas052018.dat","rb");
    venta reg;
    int codArtAnterior;
    float ventasFacturadasEnElMes = 0.0;
    int cantVendidaXArticulo;
    int maxCantArticulo = -1;
    int codArtMaxVendido;
    fread(&reg,sizeof(venta),1,ventas);
    while(!feof(ventas)) { //Itero sobre todo el archivo ( ventas )
      codArtAnterior = reg.codArt;
      cantVendidaXArticulo = 0;
      while(!feof(ventas) && codArtAnterior == reg.codArt) { //Mientras sea el mismo cod articulo
        ventasFacturadasEnElMes += reg.cantVendida * reg.precioUnitario; //Acumulo el total facturado en el mes
        cantVendidaXArticulo += reg.cantVendida; //Acumulo la cantidad vendida del articulo
        fread(&reg,sizeof(venta),1,ventas);//Avanzo
      }
      if(cantVendidaXArticulo > maxCantArticulo) {//Si esta cantidad es mayor a la anterior cambio el maximo
          maxCantArticulo = cantVendidaXArticulo;
          codArtMaxVendido = codArtAnterior;
      }
      cout << "Se vendieron " << cantVendidaXArticulo << " unidades del artículo " << codArtAnterior << endl;
    }
    cout << "Durante el mes de Mayo 2018 se facturaron $ " << ventasFacturadasEnElMes << endl;
    cout << "El artículo más vendido fue " << codArtMaxVendido << " con " << maxCantArticulo << " unidades" << endl;
    fclose(ventas);
    */

    /*Ejercicio 2 - Corte de control con archivos*/
    /*
    FILE* nota = fopen("notas.dat", "rb");
    notaEstudiante reg;
    int legajoAnterior;
    int cantidadNotasTotales = 0;
    float sumaNotasTotales = 0.0;
    int cantNotasPorEst;
    float sumaNotasPorEstudiante;
    float notaMasAltaXEstudiante;
    char materiaNotaMasAlta[50];
    fread(&reg, sizeof(notaEstudiante), 1, nota);
    while (!feof(nota)) {
        legajoAnterior = reg.legajo;
        cantNotasPorEst = 0;
        sumaNotasPorEstudiante = 0.0;
        notaMasAltaXEstudiante = -1;
        strcpy(materiaNotaMasAlta, "");
        while (!feof(nota) && legajoAnterior == reg.legajo) {
            cantNotasPorEst++;
            sumaNotasPorEstudiante += reg.nota;
            if (reg.nota > notaMasAltaXEstudiante) {
                notaMasAltaXEstudiante = reg.nota;
                strcpy(materiaNotaMasAlta, reg.materia);
            }
            fread(&reg, sizeof(notaEstudiante), 1, nota);
        }
        cantidadNotasTotales += cantNotasPorEst;
        sumaNotasTotales += sumaNotasPorEstudiante;
        cout << "El promedio para el estudiante con legajo " << legajoAnterior << " es " << sumaNotasPorEstudiante / cantNotasPorEst << endl;
        lineaSeparatoria();
        cout << "La nota más alta del estudiante con legajo " << legajoAnterior << " es " << notaMasAltaXEstudiante << " en la materia " << materiaNotaMasAlta << endl;
        lineaSeparatoria();
    }
    cout << "La cantidad de notas procesadas es " << cantidadNotasTotales << endl;
    cout << "El promedio total de los estudiantes es: " << sumaNotasTotales / cantidadNotasTotales << endl;
    fclose(nota);
    */
}
