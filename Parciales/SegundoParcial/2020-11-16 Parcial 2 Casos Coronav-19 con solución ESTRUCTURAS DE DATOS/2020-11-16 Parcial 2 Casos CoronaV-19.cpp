/*
    Id.Programa: 2020-11-16 Parcial Casos CoronaV-19.cpp
    Autor......: Lic. Hugo Cuello
    Fecha......: noviembre-2020
    Comentario.: Cantidades de Hisopados, Infectados
                  Recuperados y Fallecidos por
                  CoronaV-19, en los paises.
                  Parcial 2 - 2020.
    Estructuras de datos:
        1. Vector con MAX_PAISES filas de registros con:
            nomPais
            cantHabit
        2. Matriz con MAX_PAISES filas (i) y 12 meses (j)
            de punteros a Lista de días.
        3. Lista de días un nodo por cada registro leido de
            ParteDiario.Dat, colgada del País y mes.
            El rInfo con:
            dia
            vCantCasos (H,I,R,F).
        Proceso:
        1. Se recorre Paises y se guarda el el vector el nomPais,
            y la cantHabit, opcion 1, insertando en orden por
            por nomPais, o bien al finalizar el archivo, ordenar
            por nomPais.
        2. Se recorre ParteDiario buscar con BusBinVec encontrado
            en la posicion i, usar este indice para la matriz en
            la fila y mes leido para la columna y generar un nodo
            colgado en esas coordenadas de la matriz, ordenado
            por dia.
        3. Proceder al listado con 3 ciclos:
            Ciclo exacto i representan c/u. de los paises.
            Ciclo exacto j representan c/u. de los meses.
            Ciclo indefinido mientras ListaDia distinto de NULL.
        OBSERVACIONES:
            La matriz debe ser inicializada en NULL.
            Al leer del archivo Paises se van contando los paises
            guardandolo en una variable cantPaises, en donde, cada
            registro leido es un Pais diferente de los otros, es
            decir, no hay paises repetidos en este archivo de Paises.
*/

#include <fstream>
#include <iomanip>
using namespace std;

#define HISOPADOS "Hisopados"
#define INFECTADOS "Infectados"
#define RECUPERADOS "Recuperados"
#define FALLECIDOS "Fallecidos"

enum eCasos {hisopados,infectados,recuperados,fallecidos};

typedef char str20[21];
typedef char str10[11];
typedef char *pChar;

const MAX_PAIS = 200,
       CANT_PAISES = 10;

typedef unsigned short tvEst[4];

struct tsPais {
    str20    nomPais;
    str10    continente;
    int      cantHabit;
};

struct tsParDia {
    str20            nomPais;
    unsigned short mes,
                     dia;
    tvEst            vEst;
};

typedef struct sNodo    *tLista;
typedef unsigned short  ushort;
typedef unsigned int    uint;

struct sInfo {
  ushort dia,
         vCantCasos[4];
};

struct sNodo {
  sInfo  rInfo;
  tLista sgte;
};

struct sPaisHab {
  str20 nomPais;
  uint  cantHab;
};

typedef sPaisHab tvPaises[MAX_PAIS];
typedef tLista tmPaisMes[MAX_PAIS][12];

void Abrir(ifstream &Paises,ifstream &ParteDiario) {
  Paises.open("Paises.Dat",ios::binary);
  ParteDiario.open("ParteDiario.Dat",ios::binary);
} // Abrir

void InicMat(tmPaisMes mPM) {
  for(ushort i = 0; i < MAX_PAIS; i++)
    for(ushort j = 0; j < 12; j++)
      mPM[i][j] = NULL;
} // InicMat

void InsertarEnOrden(tvPaises vE, sPaisHab elem, ushort card) {

  while (card > 0 && strcmp(elem.nomPais, vE[card - 1].nomPais) < 0) {
    vE[card] = vE[card - 1];
	card--;
  }
  vE[card] = elem;
} // InsertarEnOrden

void ProcPaises(ifstream &Pais, tvPaises vP, ushort &cPais) {
  tsPais   rPais;
  sPaisHab rInfoV;

  while (Pais.read((char *) &rPais,sizeof rPais)) {
    strcpy(rInfoV.nomPais,rPais.nomPais);
    rInfoV.cantHab = rPais.cantHabit;
    InsertarEnOrden(vP,rInfoV,cPais);
    cPais++;
  }
} // ProcPaises

int BusBinVec(tvPaises vCI, str20 clv, ushort ult) {
  ushort pri = 0,
         med;

  while (pri <= ult) {
    med = (pri + ult) / 2;
	if (strcmp(vCI[med].nomPais, clv) == 0)
	  return med;
    else
	  if (strcmp(vCI[med].nomPais, clv) < 0)
		pri = med + 1;
      else
		ult = med - 1;
  }
  return -1;
} // BusBinVec

void InsertaInicio(tLista &Lista, sInfo valor) {
  tLista pNodo = new sNodo;

  pNodo->rInfo = valor;
  pNodo->sgte = Lista;
  Lista = pNodo;
} // InsertaInicio

void InsertaEnMedio(tLista &Lista, sInfo valor) {
  tLista pAct,
  pNodo = new sNodo;

  pNodo->rInfo = valor;
  pAct = Lista;
  while (pAct->sgte != NULL && valor.dia > pAct->sgte->rInfo.dia)
    pAct = pAct->sgte;
  pNodo->sgte = pAct->sgte;
  pAct->sgte = pNodo;
} // InsertaEnMedio

void InsertaNodo(tLista &Lista, sInfo valor) {
  if (!Lista || valor.dia < Lista->rInfo.dia)
    InsertaInicio(Lista,valor);
  else
    InsertaEnMedio(Lista,valor);
} // InsertaNodo

void ProcPteDia(ifstream &PteDia, tmPaisMes mPM,
                tvPaises vP, ushort cPais) {
  tsParDia  rParDia;
  ushort    posPais;
  tLista    pNodoDia,
            pDiaAnt;
  sInfo     rInfoD;

  while(PteDia.read((char *) &rParDia,sizeof rParDia)) {
    posPais = BusBinVec(vP,rParDia.nomPais,cPais);
    rInfoD.dia = rParDia.dia;
    for (short i = 0; i < 4; i++)
        rInfoD.vCantCasos[i] = rParDia.vEst[i];
    InsertaNodo(mPM[posPais][rParDia.mes-1],rInfoD);
  }
} // ProcPteDia

void SacarPrimerNodo(tLista &Lista, sInfo &valor) {
  tLista pElim = Lista;

  valor = Lista->rInfo;
  Lista = Lista->sgte;
  delete pElim;
} // SacarPrimerNodo

string replicate(char car, unsigned n) {
  string cad = "";

  for (unsigned i = 1; i <= n; i++)
    cad += car;
  return cad;
} // replicate

void Listado(tmPaisMes mPM, tvPaises vP, ushort cPais) {
  pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL","MAYO",
                       "JUNIO","JULIO","AGOSTO","SEPTIEMBRE",
                       "OCTUBRE","NOVIEMBRE","DICIEMBRE"
                         };
  sInfo rInfo;

  cout.precision(6);
  cout << fixed;
  freopen("ListadoPaisesMesesDias.Txt","w",stdout);
  cout << "Listado de Casos (H,I,R,F) ordenado por paises, meses y dias"
       << endl << endl;
  for(ushort i = 0; i < cPais; i++) {
    cout << replicate('-',70) << endl;
    cout << "Pais: " << vP[i].nomPais << ' '
         << " Cant. Habit.: " << vP[i].cantHab << endl;
    cout << replicate('-',70) << endl;
    for(ushort j = 0; j < 12; j++) {
        if(mPM[i][j])
          cout << "Mes: " << setw(2) << j+1 << ' '
                << setw(10) << mesCad[j+1]
                << "     Dia    Hisop.    Infec.    Recup.    Fallec."
                << endl;
          while(mPM[i][j]) {
            SacarPrimerNodo(mPM[i][j],rInfo);
            cout << replicate(' ',23)
                 << setw(2) << rInfo.dia << setw(5) << ' ';
            for(ushort k = 0; k < 4; k++)
                cout << setw(4) << rInfo.vCantCasos[k]
                     << setw(6) << ' ';
            cout << endl;
        }
    }
    cout << endl;
  }
  freopen("CON","w",stdout);
} // Listado

void Cerrar(ifstream &Pais, ifstream &PteDia) {
    Pais.close();
    PteDia.close();
}

main() {
    ifstream Paises;
    ifstream ParteDiario;
    tvPaises  vPaises;
    tmPaisMes mPaisMes;
    ushort    cantPaises = 0;

    Abrir(Paises,ParteDiario);
    InicMat(mPaisMes);
    ProcPaises(Paises,vPaises,cantPaises);
    ProcPteDia(ParteDiario,mPaisMes,vPaises,cantPaises);
    Listado(mPaisMes,vPaises,cantPaises);
    Cerrar(Paises,ParteDiario);
    return 0;
}
