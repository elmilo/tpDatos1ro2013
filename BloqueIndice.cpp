/*
 * BloqueIndice.cpp
 *
 *  Created on: 19/06/2013
 *      Author: Guido
 */

BloqueIndice::BloqueIndice(Termino* termino) {
	this->termino = termino;
	generarStream(termino);
}

BloqueIndice::BloqueIndice(BitStream* bloque) {
	generarTermino(bloque);
}

std::list<tOffset>* BloqueIndice::getOffsetsFragmentos() {
	return this->listaOffsets;
}

BitStream* BloqueIndice::getFragmentos() {
	return this->streamFragmentos;
}

Termino* BloqueIndice::getTermino() {
	return this->termino;
}

void BloqueIndice::generarStream(Termino* termino) {
	Pfor::Compresor dgaps, listas;
	Rice::Codificador frecuencias;
	ConjuntoDocumentos documentos = termino->getDocumentos();
	IteradorDocumentos it = documentos.const_iterator;
	unsigned int ultimoTamanio = 0;
	while(it != documentos.end()) {
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
	}
}

void BloqueIndice::generarTermino(BitStream* bloque) {
	Pfor::Descompresor dgaps, listas;
	Rice::Decodificador frecuencias;
	this->termino = new Termino();
	size_t
}


