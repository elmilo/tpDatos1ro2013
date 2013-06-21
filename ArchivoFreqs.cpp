/*
 * ArchivoFreqs.cpp
 *
 *  Created on: 13/06/2013
 *      Author: Guido
 */

#include "ArchivoFreqs.h"
#include "RiceCoding.h"

void ArchivoFreqs::Escritor::escribir(Diccionario* diccionario) {
	IteradorTerminos it = diccionario->getTerminos()->const_iterator;
	for (; it != diccionario->getTerminos()->end(); it++) {
		Rice::Codificador rice;
		BitStream* stream = rice.codificar((*it).second->getFrecuenciaAbsoluta());
		archivo.escribirStream(stream);
	}
	archivo.flush();
}

tFreq ArchivoFreqs::Lector::leer() {
	tFreq freq;
	if (!archivo.eof()) {


		freq = archivo.leerUnsigned();
	}
	return freq;
}

