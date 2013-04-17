#ifndef DOCUMENTO_H_INCLUDED
#define DOCUMENTO_H_INCLUDED

#include "common.h"


using namespace std;

class Documento{
private:

typedef list<unsigned> ConjuntoOcurrencias;

    unsigned docID; //Correspondiente al documento actual
    ConjuntoOcurrencias ocurrencias; //lista de ocurrencias

public:

Documento(unsigned unDocID);

void agregarOcurrencia(unsigned unaPosicion);

unsigned getFrecuencia();

unsigned getDocID();

};

#endif
