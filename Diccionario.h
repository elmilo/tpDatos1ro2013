#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "common.h"
//#include "Terminos.h"
#include "Termino.cpp"





class Diccionario{

typedef set<Terminos*> ConjuntoTerminos;
//typedef set<Terminos*>::const_iterator IteradorDiccionario;

    ConjuntoTerminos diccionario;


private:

bool Diccionario::buscarTermino(string unToken);

    
public:

/**
 * Trata de insertar una palabra si corresponde, si no actualiza la lista
 * */
void agregar (string unToken, unsigned unaPosicion, unsigned unDocID);

void agregar (Termino unTermino);

bool estaLleno();

unsigned memoriaOcupada();

/**
 * TEMPORAL
 * */
//void mostrar();
    
};

#endif
