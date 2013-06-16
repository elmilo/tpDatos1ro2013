/*
 * ArchivoTemporal.cpp
 *
 *  Created on: Jun 12, 2013
 *      Author: guidi
 */

#include "Documento.h"

#include "ArchivoGenerico.h"

void ArchivoTemporal::Escritor::crearTemporal(Diccionario* diccionario) {

}

void ArchivoTemporal::Escritor::escribirTermino(Termino termino) {
	archivo.escribirSize(termino.getTermino().size());
	archivo.escribirString(termino.getTermino());
	archivo.escribirUnsigned(termino.getDocumentos()->front()->getDocID());
	archivo.escribirUnsigned(termino.getDocumentos()->front()->getFrecuencia());
	list<unsigned>::iterator it = termino.getDocumentos()->front()->getOcurrencias().begin();
	for ( ; it != termino.getDocumentos()->front()->getOcurrencias().end(); it++)
		archivo.escribirUnsigned((*it));
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
}
