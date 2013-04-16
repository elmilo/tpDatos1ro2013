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
int posicionTexto;

public:
/*
 * 
 * */


void filtrarPalabrasyPosicionEntrada(int maxNodos);

palabraPos siguienteNodo();



/*
 * Constructores
 * */
Parser(string ficheroTxt);

void listado(int cantidad);


void abrirArchivo(string archivotxt);

void devolverGapsEntrepalabras (string entrada);

bool Parser::terminoArchivo ();

palabraPos unNodo(unsigned int posicion);
};

#endif
