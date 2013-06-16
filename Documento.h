#ifndef DOCUMENTO_H_INCLUDED
#define DOCUMENTO_H_INCLUDED

#include "common.h"

typedef std::list<tPos> ConjuntoOcurrencias;

class Documento {
private:

	tDocId docID; // Correspondiente al documento actual
	ConjuntoOcurrencias ocurrencias; // lista de ocurrencias

public:

	Documento(tDocId unDocID);
	Documento(const Documento& otroDoc);

	void agregarOcurrencia(tPos unaPosicion);

	tFreq getFrecuencia();

	ConjuntoOcurrencias* getOcurrencias();

	tDocId getDocID();

};

#endif

