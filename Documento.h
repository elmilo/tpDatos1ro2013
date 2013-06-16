#ifndef DOCUMENTO_H_INCLUDED
#define DOCUMENTO_H_INCLUDED

#include "common.h"

// se elige 'set' porque no inserta duplicados y aparte se ordena automáticamente
typedef std::set<tPos> ConjuntoOcurrencias;

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

	tDocId getDocID() const;

};

#endif

