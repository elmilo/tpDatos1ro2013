#include "Documento.h"

Documento::Documento(tDocId unDocID) {
	docID = unDocID;
}

Documento::Documento(const Documento& otroDoc) {
	docID = otroDoc.docID;
	ConjuntoOcurrencias::const_iterator it = otroDoc.ocurrencias.begin();
	while (it != otroDoc.ocurrencias.end()) {
		ocurrencias.push_back(*it);
	}
}

/*************************************************************************************/
/*************************************************************************************/
void Documento::agregarOcurrencia(tPos unaPosicion) {
	ocurrencias.push_back(unaPosicion);
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

tDocId Documento::getDocID() {
	return docID;
}
