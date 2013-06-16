/*
 * ArchivoTemporal.cpp
 *
 *  Created on: Jun 12, 2013
 *      Author: guidi
 */

#include "ArchivoTemporal.h"

void ArchivoTemporal::Escritor::crearTemporal (Diccionario* diccionario) {
	IteradorTerminos it_dic = diccionario->getTerminos()->begin();
	while(it_dic != diccionario->getTerminos()->end()) {
		escribirTermino(*(*it_dic).second); // itera en el diccionario y escribe cada termino
		it_dic++;
	}
}

void ArchivoTemporal::Escritor::escribirTermino (const Termino& termino) {
	archivo.escribirSize(termino.getToken().size());
	archivo.escribirString(termino.getToken());

	IteradorDocumentos it = termino.getDocumentos()->begin();
	while(it != termino.getDocumentos()->end()) {
		archivo.escribirUnsigned((*it)->getDocID());
		archivo.escribirUnsigned((*it)->getFrecuencia());

		std::list<tPos>::const_iterator it_ocu = (*it)->getOcurrencias()->begin();
		while(it_ocu != (*it)->getOcurrencias()->end()) {
			archivo.escribirUnsigned(*it_ocu);
			it_ocu++;
		}
		it++;
	}
}

Termino ArchivoTemporal::Lector::leerTermino() {
	Termino termino;
	size_t stringSize = archivo.leerSize();
	std::string string = archivo.leerString(stringSize);
	tDocId docId = archivo.leerUnsigned();
	tFreq frecuencia = archivo.leerUnsigned();
	for (int i = 0; i < frecuencia; i++) {
		tPos pos = archivo.leerUnsigned();
		termino.agregarPosicion(pos, docId);
	}
	return termino;
}
