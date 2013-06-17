#ifndef NORMALIZADOR_H_INCLUDED
#define NORMALIZADOR_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>


using namespace std;

class Normalizador{
public:

Normalizador (std::string unaFrase);

unsigned cantidad();

string unTermino (unsigned posicion);


private:
    static const char* delim;

    vector<string> posiciones;
    void agregarEnContenedor(char *palabra);
    bool esAlfaNum (string entrada);

};


#endif

