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
	archivo.escribir(termino.getTermino().size());
	archivo.escribir(termino.getTermino());
	archivo.escribir(termino.getDocumentos()->front()->getDocID());
	archivo.escribir(termino.getDocumentos()->front()->getFrecuencia());
	archivo.escribir(termino.getDocumentos()->front()->getOcurrencias());
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
