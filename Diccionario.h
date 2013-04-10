#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "common.h"
#include "PosicionesPorDocumento.cpp"


/**
 * Tipos personalizados: 
*          - un mapa con docIDs (se puede cambiar en common.h) y clase lista de posiciones
*          - un mapa con strings de palabras y el anterior.
 * */
typedef map<tipoDocID, PosicionesPorDocumento> mapa1;

typedef map<string, mapa1> mapaDelDiccionario;


class Diccionario{

mapaDelDiccionario diccionario;


public:

/**
 * Trata de insertar una palabra si corresponde, si no actualiza la lista
 * */
void insertar(palabraPos termino, tipoDocID unDoc);

/**
 * TEMPORAL
 * */
void mostrar();
    
};

#endif
