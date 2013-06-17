#ifndef TOKENIZER_H_INCLUDED
#define TOKENIZER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <search.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Tokenizer{

public:

public:
Tokenizer(std::string direccionArchivo);

void normalizar (string unaFrase);

bool tengaTerminos();

string siguienteTermino();

unsigned siguientePosicion();


private:

    static const char* delim;
    list<string> posiciones;
    unsigned cantidad;
    const char* direccion;

void agregarEnContenedor(char *palabra);
bool esAlfaNum (string entrada);

/**
 * Codigo C
 * */
int separarTokens();

};

#endif
