/*
 * Fragmento.cpp
 *
 *  Created on: 20/06/2013
 *      Author: Guido
 */

void Fragmento::agregarDocumento(Documento* documento) {
	dgaps.agregar(documento->getDocID());
	frecuencias.codificar(documento->getFrecuencia());
	ConjuntoOcurrencias ocurrencias = documento->getOcurrencias();
	IteradorOcurrencias itOcurrencias = ocurrencias.const_iterator;
	for ( ; itOcurrencias != ocurrencias.end(); itOcurrencias++) {
		listas.agregar((*itOcurrencias));
	}
	cuantosDocumentos++;
}

BitStream* Fragmento::flushStream() {
	dgaps.flushStream();
	frecuencias.flushStream();
}
