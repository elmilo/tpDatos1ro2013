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
		escritorIndice.escribirSize(stream->byteSize());
		escritorIndice.escribirStream(stream);
		delete bloque;
	}
}

BitStream* ArchivoIndice::Escritor::crearBloque(Termino* termino) {
	BitStream* stream = new BitStream();
	BloqueIndice bloque(termino);
	std::list<tOffset>* offsetsFragmentos = bloque.getOffsetsFragmentos();
	stream->appendSize(offsetsFragmentos->size());
	std::list<tOffset>::const_iterator it = bloque.getOffsetsFragmentos()->const_iterator;
	for(; it != offsetsFragmentos->end(); it++) {
		stream->appendUnsigned(*it);
	}
	stream->appendStream(bloque.getFragmentos());
	return stream;
}

ArchivoIndice::Lector::Lector(std::string rutaIndice) {
	archivo.abrir(rutaIndice);
}

Termino* ArchivoIndice::Lector::leerBloque(tOffset offset) {
	archivo.seek(offset);
	size_t sizeBloque = archivo.leerSize();
	BitStream* stream = archivo.leerStream(sizeBloque);
	BloqueIndice bloque(stream);
	Termino* termino = bloque.getTermino();
	return termino;
}

Termino* ArchivoIndice::Lector::leerFragmentos(tOffset offset, IteradorDocumentos documentos) {
	Termino* termino;
	return termino;
}
