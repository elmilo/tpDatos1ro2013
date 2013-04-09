#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "common.h"

using namespace std;

class parser{

/*
 * Puntero de lectura
 * */
ifstream ficheroEntrada;
    
vector<palabraPos> vecpalabraPos;

/*
 * 
 * */
void filtrarPalabrasyPosicionEntrada(int maxNodos);

public:

/*
 * Constructores
 * */
    parser(string ficheroTxt);

void listado(int cantidad);

void abrirArchivo(string archivotxt);

void devolverGapsEntrepalabras (string entrada);

};

#endif
