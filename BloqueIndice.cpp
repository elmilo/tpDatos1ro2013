/*
 * BloqueIndice.cpp
 *
 *  Created on: 19/06/2013
 *      Author: Guido
 */

#include "BloqueIndice.h"

BloqueIndice::Creador::Creador(Termino* termino) {
	this->cantidadDocumentos = termino->getDocumentos()->size();
	generarFragmentos(termino);
}

void BloqueIndice::Creador::generarFragmentos(Termino* termino) {
	ConjuntoDocumentos documentos = termino->getDocumentos();
	IteradorDocumentos it = documentos.const_iterator;
	Fragmento::Fragmento* fragmento = 0;
	while (it != documentos.end()) {
		fragmento = new Fragmento();
		for(int i = 0; i < FRAG_SIZE and it != documentos.end(); i++, it++) {
			fragmento->agregarDocumento((*it));
		}
		listaOffsets.push_back(fragmento->streamSize() + 1);
		fragmentos.push_back(fragmento);
	}
}

BitStream* BloqueIndice::Creador::getBloque() {
	BitStream* stream = new BitStream();
	appendMetadatosA(stream);
	appendFragmentosA(stream);
	return stream;
}

void BloqueIndice::Creador::appendMetadatosA(BitStream* stream) {
	appendCantidadDocumentos(stream);
	appendCantidadFragmentos(stream);
	appendTamaniosFragmentos(stream);
}

void BloqueIndice::Creador::appendCantidadDocumentos(BitStream* stream) {
	stream->appendUnsigned(this->cantidadDocumentos);
}

void BloqueIndice::Creador::appendCantidadFragmentos(BitStream* stream) {
	stream->appendSize(this->listaOffsets.size());
}

void BloqueIndice::Creador::appendTamaniosFragmentos(BitStream* stream) {
	std::list<unsigned int>::const_iterator it = listaOffsets.const_iterator;
	for (; it != listaOffsets.end(); it++) {
		stream->appendUnsigned((*it));
	}
}

void BloqueIndice::Creador::appendFragmentosA(BitStream* stream) {
	while(!fragmentos.empty()) {
		stream->appendStream(fragmentos.front()->getStream());
		delete fragmentos.front();
		fragmentos.pop_front();
	}
}

BloqueIndice::Lector::Lector(BitStream* bloque) {
	generarTermino(bloque);
}

Termino* BloqueIndice::Lector::getTermino() {
	return this->termino;
}

void BloqueIndice::Lector::generarTermino(BitStream* bloque) {
	unsigned int cantidadDocumentos = bloque->popUnsigned();
	size_t cantidadFragmentos = bloque->popSize();
	size_t tamanioFragmentos = 0;
	for (int i = 0; i < cantidadDocumentos; i++) {
		tamanioFragmentos += bloque->popSize();
	}
	Fragmento::Defragmentador defragmentador(bloque, cantidadDocumentos);
	this->termino = defragmentador.getTermino();
}

