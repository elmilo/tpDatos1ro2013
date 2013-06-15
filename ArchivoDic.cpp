/*
 * ArchivoDic.cpp
 *
 *  Created on: 13/06/2013
 *      Author: Guido
 */

#include "ArchivoDic.h"
#include "Diccionario.h"
#include "Termino.h"

void ArchivoDic::Escritor::escribir(Diccionario* diccionario) {
	IteradorDiccionario it = diccionario->iterator();
	for (; it != diccionario->end(); it++) {
		archivo.escribirSize((*it)->getTermino().size());
		archivo.escribirString((*it)->getTermino());
	}
}

std::string ArchivoDic::Lector::leer() {
	std::string termino;
	if (!archivo.eof()) {
		size_t size = archivo.leerSize();
		termino = archivo.leerString(size);
	}
	return termino;
}
