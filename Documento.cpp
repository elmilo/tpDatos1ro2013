#include "Documento.h"

Documento::Documento(tDocId unDocID) {
	docID = unDocID;
}

Documento::Documento(const Documento& otroDoc) {
	docID = otroDoc.docID;
	ConjuntoOcurrencias::const_iterator it = otroDoc.ocurrencias.begin();
	while (it != otroDoc.ocurrencias.end()) {
		ocurrencias.insert(*it);
	}
}

/*************************************************************************************/
void Documento::agregarOcurrencia(tPos unaPosicion) {
	ocurrencias.insert(unaPosicion);
}

/*************************************************************************************/
/*************************************************************************************/
tFreq Documento::getFrecuencia() {
	return ocurrencias.size();
}

/*************************************************************************************/
/*************************************************************************************/
ConjuntoOcurrencias* Documento::getOcurrencias() {
	return &ocurrencias;
}

tDocId Documento::getDocID() const {
	return docID;
}

bool Documento::operator< (const Documento& rhs) const {
	return this->getDocID() < rhs.getDocID();
}
