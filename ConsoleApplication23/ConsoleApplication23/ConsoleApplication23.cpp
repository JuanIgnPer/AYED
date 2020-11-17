#include <iostream>
#include "..\..\Headers\dinamica.hpp"

int main()
{
	//Final Evaluaciones
	//Creación Archivo
	/*
	FILE * novedades = fopen("novedades.dat","wb+");
	novedad reg;
	reg.idCurso = 1053;
	reg.idEstudiante = 456;
	reg.nroEvaluacion = 1;
	reg.nota = 8;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 456;
	reg.nroEvaluacion = 2;
	reg.nota = 5;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 456;
	reg.nroEvaluacion = 2;
	reg.nota = 6;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 457;
	reg.nroEvaluacion = 3;
	reg.nota = 2;
	fwrite(&reg, sizeof(novedad),1, novedades);


	reg.idCurso = 1053;
	reg.idEstudiante = 457;
	reg.nroEvaluacion = 3;
	reg.nota = 7;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 457;
	reg.nroEvaluacion = 1;
	reg.nota = 6;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 456;
	reg.nroEvaluacion = 3;
	reg.nota = 6;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 456;
	reg.nroEvaluacion = 3;
	reg.nota = 4;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 458;
	reg.nroEvaluacion = 2;
	reg.nota = 4;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 458;
	reg.nroEvaluacion = 2;
	reg.nota = 5;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 458;
	reg.nroEvaluacion = 2;
	reg.nota = 3;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 457;
	reg.nroEvaluacion = 1;
	reg.nota = 8;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 456;
	reg.nroEvaluacion = 4;
	reg.nota = 7;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 457;
	reg.nroEvaluacion = 2;
	reg.nota = 6;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 457;
	reg.nroEvaluacion = 4;
	reg.nota = 8;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 458;
	reg.nroEvaluacion = 1;
	reg.nota = 2;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 580;
	reg.nroEvaluacion = 1;
	reg.nota = 10;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 458;
	reg.nroEvaluacion = 1;
	reg.nota = 2;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 581;
	reg.nroEvaluacion = 1;
	reg.nota = 2;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 581;
	reg.nroEvaluacion = 1;
	reg.nota = 7;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 458;
	reg.nroEvaluacion = 3;
	reg.nota = 1;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 580;
	reg.nroEvaluacion = 2;
	reg.nota = 6;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 580;
	reg.nroEvaluacion = 2;
	reg.nota = 9;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 581;
	reg.nroEvaluacion = 2;
	reg.nota = 2;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 581;
	reg.nroEvaluacion = 2;
	reg.nota = 5;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 581;
	reg.nroEvaluacion = 2;
	reg.nota = 7;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1053;
	reg.idEstudiante = 458;
	reg.nroEvaluacion = 4;
	reg.nota = 2;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 580;
	reg.nroEvaluacion = 3;
	reg.nota = 8;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 581;
	reg.nroEvaluacion = 3;
	reg.nota = 6;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 582;
	reg.nroEvaluacion = 3;
	reg.nota = 6;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 581;
	reg.nroEvaluacion = 4;
	reg.nota = 8;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 580;
	reg.nroEvaluacion = 4;
	reg.nota = 9;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 582;
	reg.nroEvaluacion = 4;
	reg.nota = 6;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 582;
	reg.nroEvaluacion = 1;
	reg.nota = 5;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 582;
	reg.nroEvaluacion = 2;
	reg.nota = 5;
	fwrite(&reg, sizeof(novedad),1, novedades);

	reg.idCurso = 1050;
	reg.idEstudiante = 582;
	reg.nroEvaluacion = 2;
	reg.nota = 2;
	fwrite(&reg, sizeof(novedad),1, novedades);

	rewind(novedades);
	fread(&reg,sizeof(novedad),1, novedades);
	while(!feof(novedades)){
		cout << reg.idCurso << endl;
		cout << reg.idEstudiante << endl;
		cout << reg.nroEvaluacion << endl;
		cout << reg.nota << endl;
		cout << "-------------------------------------" << endl;
		fread(&reg,sizeof(novedad),1, novedades);
	}

	fclose(novedades);
	*/

	//Desarrollo del Final
	/*
	Curso* listaCursos = NULL; //Es importante definir como NULL
	FILE* novedades = fopen("novedades.dat", "rb");

	procesarNovedades(novedades, listaCursos);
	*/

	//Nos sirve para chequear que la estructura esté bien cargada
	/*
	Curso* auxCurso = listaCursos;

	//Itero sobre todo el curso
	while(auxCurso != NULL){
		cout << "---------------------------------" << endl;
		cout << "Curso nro " << auxCurso->infoCur.id << endl;
		Estudiante* auxEst = auxCurso->infoCur.listaEstudiantes;
		//Itero sobre la lista de estudiantes del curso
		while(auxEst != NULL){
			cout << "_______________________________" << endl;

			cout << "Estudiante nro " << auxEst->infoEst.id << endl;

			cout << endl << "Notas de la 1era Evaluacion ";
			Nota* aux1erEvaluacion = auxEst->infoEst.notas[0];
			//Itero sobre todas las notas de la primer evaluacion
			while(aux1erEvaluacion != NULL) {
				cout << aux1erEvaluacion->nota << " ";
				aux1erEvaluacion = aux1erEvaluacion->sig;
			}

			cout << endl << "Notas de la 2da Evaluacion  " ;
			Nota* aux2daEvaluacion = auxEst->infoEst.notas[1];
			while(aux2daEvaluacion != NULL) {
				cout << aux2daEvaluacion->nota << " ";
				aux2daEvaluacion = aux2daEvaluacion->sig;
			}

			cout << endl << "Notas de la 3era Evaluacion ";
			Nota* aux3eraEvaluacion = auxEst->infoEst.notas[2];
			while(aux3eraEvaluacion != NULL) {
				cout << aux3eraEvaluacion->nota << " ";
				aux3eraEvaluacion = aux3eraEvaluacion->sig;
			}

			cout << endl << "Notas de la 4ta Evaluacion  ";
			Nota* aux4taEvaluacion = auxEst->infoEst.notas[3];
			while(aux4taEvaluacion != NULL) {
				cout << aux4taEvaluacion->nota << " ";
				aux4taEvaluacion = aux4taEvaluacion->sig;
			}
			cout << endl;
			auxEst = auxEst->sigEst;
		}
		auxCurso = auxCurso->sigCur;
	}
	*/

	/*
	calcularEstadisticas(listaCursos);

	//Quiero imprimir las estadisticas por curso
	Curso* auxCurso = listaCursos;
	while (auxCurso != NULL) {
		cout << "Curso nro " << auxCurso->infoCur.id << endl;
		cout << "Promocionados " << auxCurso->infoCur.promocionados << endl;
		cout << "Regularizados " << auxCurso->infoCur.regularizados << endl;
		cout << "Recursantes " << auxCurso->infoCur.recursantes << endl;
		cout << "--------------------" << endl;
		auxCurso = auxCurso->sigCur;
	}


	fclose(novedades);
	*/
}