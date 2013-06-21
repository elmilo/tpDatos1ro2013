/*
 * Fragmento.cpp
 *
 *  Created on: 20/06/2013
 *      Author: Guido
 */

#include "Fragmento.h"

void Fragmento::Fragmento::agregarDocumento(Documento* documento) {
	dgaps.agregar(documento->getDocID());
	frecuencias.codificar(documento->getFrecuencia());
	ConjuntoOcurrencias ocurrencias = documento->getOcurrencias();
	IteradorOcurrencias itOcurrencias = ocurrencias.const_iterator;
	for ( ; itOcurrencias != ocurrencias.end(); itOcurrencias++) {
		posiciones.agregar((*itOcurrencias));
	}
	cuantosDocumentos++;
}

BitStream* Fragmento::Fragmento::getStream() {
	BitStream* fragmentos = new BitStream();
	fragmentos->appendStream(dgaps.flushStream());
	fragmentos->appendStream(frecuencias.flushStream());
	fragmentos->appendStream(posiciones.flushStream());
}

size_t Fragmento::Fragmento::streamSize() {
	//Generar stream y ver tamaño
}

Fragmento::Defragmentador::Defragmentador(BitStream* bloque, unsigned int cantidadDocumentos) {
	descomprimir(bloque, cantidadDocumentos);
}

Termino* Fragmento::Defragmentador::getTermino() {
	return termino;
}

void Fragmento::Defragmentador::descomprimir(BitStream* bloque, unsigned int cantidadDocumentos) {
	Pfor::Descompresor dgapsDescompresor, posicionesDescompresor;
	Rice::Decodificador frecuenciasDescompresor;
	int documentosDescomprimidos = 0;
	while(documentosDescomprimidos < cantidadDocumentos) {
		unsigned int documentosEnFragmentoActual =
				(cantidadDocumentos < FRAG_SIZE) ? cantidadDocumentos : FRAG_SIZE;
		std::list<unsigned int>* documentos = dgapsDescompresor.descomprimir(bloque, documentosEnFragmentoActual);
		std::list<unsigned int>* frecuencias =
				frecuenciasDescompresor.decodificar(bloque, documentosEnFragmentoActual);
		while(!documentos->empty()) {
			tDocId docId = documentos->front(); documentos->pop_front();
			tFreq frecuencia =	frecuencias->front(); frecuencias->pop_front();
			std::list<unsigned int>* posiciones = posicionesDescompresor.descomprimir(bloque, frecuencia);
			for(int i = 0; i < posiciones->size(); i++) {
				tPos pos = posiciones->front(); posiciones->pop_front();
				termino->agregarPosicion(pos, docId);
			}
		}
	}
}
