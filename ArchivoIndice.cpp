/*
 * ArchivoIndice.cpp
 *
 *  Created on: 17/06/2013
 *      Author: open0130
 */

ArchivoIndice::Escritor::Escritor(std::string rutaIndice, std::string rutaOffset) {
	escritorIndice.abrir(rutaIndice);
	escritorOffset.abrir(rutaOffset);
}

void ArchivoIndice::Escritor::escribir(Diccionario* diccionario) {
	ConjuntoTerminos::const_iterator it = diccionario->getTerminos()->const_iterator;
	while(it != diccionario->getTerminos()->end()) {
		Termino* termino = *it;
		escritorOffset.escribir(escritorIndice.getPos());
		BitStream* stream = crearBloque(Termino* termino);
		escritorIndice.escribirStream(stream);
		delete bloque;
	}
}

BitStream* ArchivoIndice::Escritor::crearBloque(Termino* termino) {

	IteradorDocumentos it = termino->getDocumentos()->const_iterator;
	BitStream* bloque = new BitStream();
	BitStream* fragmentos = new BitStream();
	for (int index = 0; it != termino->getDocumentos()->end(); it++, index++) {
		BitStream streamDGaps = pfor.agregar((*it)->getDocID());
		BitStream streamFrecuencias = stream->appendStream(comprimirFrecuencias(termino));
		BitStream streamListas = pfor.agregar((*it)->getOcurrencias());
		if (index == FRAG_SIZE) {
			fragmento->appendStream(streamDGaps); streamDGaps.vaciar();
			fragmento->appendStream(streamFrecuencias); streamFrecuencias.vaciar();
			fragmento->appendStream(streamListas); streamListas.vaciar();
		}
	}
}

BitStream* comprimirFragmento() {

}

ArchivoIndice::Lector::Lector(std::string rutaIndice, std::string rutaOffset);

Termino* ArchivoIndice::Lector::leerBloque(tOffset offset) {
	//AHORA SIGO
}

Termino* ArchivoIndice::Lector::leerFragmentos(tOffset offset, IteradorDocumentos documentos);
