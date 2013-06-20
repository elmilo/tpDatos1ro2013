/*
 * Fragmento.cpp
 *
 *  Created on: 20/06/2013
 *      Author: Guido
 */

#include "Fragmentador.h"

Fragmentacion::Frag::Frag(ConjuntoDocumentos* documentos) {
	agregarDocumentos(documentos);
}

BitStream* Fragmentacion::Frag::getStream() {
}

void Fragmentacion::Frag::agregarDocumentos(ConjuntoDocumentos* documentos) {
	IteradorDocumentos it = documentos->const_iterator;
	for (;it != documentos->end(); it++) {
		agregarDocumento(*it);
	}
}

void Fragmentacion::Frag::agregarDocumento(Documento* documento) {
	dgaps.agregar(documento->getDocID());
	frecuencias.codificar(documento->getFrecuencia());
	ConjuntoOcurrencias ocurrencias = documento->getOcurrencias();
	IteradorOcurrencias itOcurrencias = ocurrencias.const_iterator;
	for ( ; itOcurrencias != ocurrencias.end(); itOcurrencias++) {
		listas.agregar((*itOcurrencias));
	}
}

Termino* Fragmentacion::Defrag::getTermino() {

}

void Fragmentacion::Defrag::DeFrag(BitStream* stream) {
	generarTermino(stream);
}

void Fragmentacion::Defrag::generarTermino(BitStream* stream) {

}
