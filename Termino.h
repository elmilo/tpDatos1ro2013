#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED

#include "common.h"
#include "Documento.h"


typedef list< Documento* > ConjuntoDocumentos;
typedef list< Documento* >::const_iterator IteradorDocumentos;

class Termino{

    string token;
    ConjuntoDocumentos documentos;


IteradorDocumentos buscarDocumento(unsigned unDocID);


public:

Termino (string unTermino);

void agregarPosicion (unsigned unaPosicion, unsigned unDocID);

string getTermino();

bool operator== (Termino &rhs);

bool operator!= (Termino &rhs);

};

#endif
