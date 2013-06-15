/*
 * ArchivoFreqs.cpp
 *
 *  Created on: 13/06/2013
 *      Author: Guido
 */

#include "ArchivoFreqs.h"
#include "RiceCoding.h"

void ArchivoFreqs::Escritor::escribir(Diccionario* diccionario) {
	IteradorDiccionario it = diccionario->iterator();
	for (; it != diccionario->end(); it++) {
		BitStream stream = Rice::comprimir((*it)->getFrecuenciaAbsoluta());
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

