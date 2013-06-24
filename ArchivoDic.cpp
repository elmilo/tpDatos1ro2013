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
	IteradorTerminos it = diccionario->getTerminos()->const_iterator;
	for (; it != diccionario->getTerminos()->end(); it++) {
		archivo.escribirSize((*it).second->getToken().size());
		archivo.escribirString((*it).second->getToken());
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
