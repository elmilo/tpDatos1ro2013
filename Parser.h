#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include "common.h"

using namespace std;

class Parser{

/*
 * Puntero de lectura
 * */
ifstream ficheroEntrada;
    
vector<palabraPos> vecpalabraPos;

public:
/*
 * 
 * */
void filtrarPalabrasyPosicionEntrada(int maxNodos);



/*
 * Constructores
 * */
Parser(string ficheroTxt);

void listado(int cantidad);

void abrirArchivo(string archivotxt);

void devolverGapsEntrepalabras (string entrada);

palabraPos unNodo(unsigned int posicion);
};

#endif
