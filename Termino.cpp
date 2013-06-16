#include "Termino.h"

/*************************************************************************************/
/*************************************************************************************/
Termino::Termino (tTermino unTermino) {
	token = unTermino;
}

Termino::Termino(const Termino& otroTermino) {
	token = otroTermino.token;
	IteradorDocumentos it = otroTermino.documentos.begin();
	while (it != otroTermino.documentos.end()) {
		documentos.insert(new Documento(**it));
	}
}

Termino::~Termino() {
	IteradorDocumentos it_set = documentos.begin();
	while(it_set != documentos.end()) {
		delete *it_set;
		it_set++;
	}
}

/*************************************************************************************/
/*************************************************************************************/
IteradorDocumentos Termino::buscarDocumento(tDocId unDocID) {

	IteradorDocumentos elemento;
	Documento* desref;

	for (elemento = documentos.begin(); elemento != documentos.end(); ++elemento) {
		desref = *elemento;
		if (desref->getDocID() == unDocID) {
			return elemento;
		}
	}

	return documentos.end();  // El documento buscado no existe en la lista
}

/*************************************************************************************/
/*************************************************************************************/
void Termino::agregarPosicion (tPos unaPosicion, tDocId unDocID) {

	IteradorDocumentos elemento = buscarDocumento(unDocID);
	Documento* desref = *elemento;

	if (elemento == documentos.end()) {  // el docId no esta en la lista
		desref = new Documento(unDocID);
		documentos.insert(desref);
	}

	desref->agregarOcurrencia(unaPosicion);
}

ListaDeDocIds Termino::intersectar(Termino* otroTermino, tPos distancia) {

	ListaDeDocIds docIds;  // guarda los docIDs que cumplen las condiciones
	IteradorDocumentos it = this->getDocumentos()->begin();
	IteradorDocumentos itOtro = otroTermino->getDocumentos()->begin();

	while (it != this->getDocumentos()->end() &&
			itOtro != otroTermino->getDocumentos()->end()) {
		tDocId d1 = ((Documento*) *it)->getDocID();
		tDocId d2 = ((Documento*) *itOtro)->getDocID();
		if (d1 == d2) {
			if(seIntersectan(*it, *itOtro, distancia))
				docIds.push_back(d1);
		}
		else if (d1 < d2)
			it++;
		else
			itOtro++;
	}

	return docIds;
}

bool Termino::seIntersectan(Documento* doc, Documento* otroDoc, tPos distancia) {

	ConjuntoOcurrencias::const_iterator it = doc->getOcurrencias()->begin();
	ConjuntoOcurrencias::const_iterator itOtro = otroDoc->getOcurrencias()->begin();

	while (it != doc->getOcurrencias()->end() &&
			itOtro != otroDoc->getOcurrencias()->end()) {
		tPos p1 = *it;
		tPos p2 = *itOtro;
		if (p2 - p1 == distancia)  // debe ser p1 < p2 porque el termino 'this' aparece antes en el doc
			return true;
		else if (p2 - p1 > distancia)
			it++;
		else
			itOtro++;
	}

	return false;
}

ConjuntoOcurrencias* Termino::listarPosiciones(tDocId unDocID) {
	return ((Documento*) *buscarDocumento(unDocID))->getOcurrencias();
}

tTermino Termino::getToken() const {
	return token;
}

ConjuntoDocumentos* Termino::getDocumentos() {
	return &documentos;
}

/*************************************************************************************/
/*************************************************************************************/
bool Termino::operator== (const Termino& rhs) const {
	return this->getToken() == rhs.getToken();
}

/*************************************************************************************/
/*************************************************************************************/
bool Termino::operator!= (const Termino& rhs) const {
	return !(*this == rhs);
}
