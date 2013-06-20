/*
 * BloqueIndice.cpp
 *
 *  Created on: 19/06/2013
 *      Author: Guido
 */

#include "BloqueIndice.h"

BloqueIndice::Escritor::Escritor(Termino* termino) {
	this->termino = termino;
	generarFragmentos(termino);
}

BitStream* BloqueIndice::Escritor::getBloque() {
	BitStream* stream = new BitStream();
	appendMetadatosA(stream);
	appendFragmentosA(stream);
	return stream;
}

void BloqueIndice::Escritor::generarFragmentos(Termino* termino) {
	ConjuntoDocumentos documentos = termino->getDocumentos();
	Fragmentacion::Frag fragmentador(termino->getDocumentos());
	fragmentador.
	/*while(it != documentos.end()) {
		for (int i = 0; i < FRAG_SIZE; i++) dgaps.agregar((*it)->getDocID());
		streamFragmentos->appendStream(dgaps.flushStream());
		for (int i = 0; i < FRAG_SIZE; i++) frecuencias.codificar((*it)->getFrecuencia());
		streamFragmentos->appendStream(frecuencias.getStream());
		for (int i = 0; i < FRAG_SIZE; i++) {
			ConjuntoOcurrencias ocurrencias = termino->listarPosiciones((*it)->getDocID());
			IteradorOcurrencias itOcurrencias = ocurrencias.const_iterator;
			for ( ; itOcurrencias != ocurrencias.end(); it++) {
				listas.agregar((*itOcurrencias));
			}
			streamFragmentos->appendStream(listas.flushStream());
		}
		streamFragmentos->rellenarBits();
		this->listaOffsets.push_back(streamFragmentos->byteSize() + ultimoTamanio);
		unsigned int ultimoTamanio = streamFragmentos->byteSize();
	}*/
}

void BloqueIndice::Escritor::appendMetadatosA(BitStream* stream) {
	stream->appendSize(this->listaOffsets.size());
	std::list<unsigned int>::const_iterator it = listaOffsets.const_iterator;
	for (; it != listaOffsets.end(); it++) {
		stream->appendUnsigned((*it));
	}
}

void BloqueIndice::Escritor::appendFragmentosA(BitStream* stream) {
	stream->appendStream(fragmentador.getStream());
}

BloqueIndice::Lector::Lector(BitStream* bloque) {
	generarTermino(bloque);
}

Termino* BloqueIndice::Lector::getTermino() {
	return this->termino;
}

void BloqueIndice::Lector::generarTermino(BitStream* bloque) {
	size_t cantidadFragmentos = bloque->popSize();
	size_t tamanioFragmentos = 0;
	for (int i = 0; i < cantidadFragmentos; i++) {
		tamanioFragmentos += bloque->popSize();
	}
	Fragmentacion::Defrag defragmentador(bloque);
	this->termino = defragmentador.getTermino();
}

std::list<tOffset>* BloqueIndice::getOffsetsFragmentos() {
	return this->listaOffsets;
}


