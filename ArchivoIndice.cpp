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
		BitStream* stream = crearBloque(termino);
		escritorIndice.escribirSize(stream->byteSize());
		escritorIndice.escribirStream(stream);
	}
}

BitStream* ArchivoIndice::Escritor::crearBloque(Termino* termino) {
	BloqueIndice::Creador creadorBloque(termino);
	BitStream* bloque = creadorBloque.getBloque();
	escritorIndice.escribirSize(bloque->byteSize());
	escritorIndice.escribirStream(bloque);
	return bloque;
}

ArchivoIndice::Lector::Lector(std::string rutaIndice) {
	archivo.abrir(rutaIndice);
}

Termino* ArchivoIndice::Lector::leerBloque(tOffset offset) {
	archivo.seek(offset);
	size_t sizeBloque = archivo.leerSize();
	BitStream* stream = archivo.leerStream(sizeBloque);
	BloqueIndice::Lector lectorBloque(stream);
	Termino* termino = lectorBloque.getTermino();
	return termino;
}

Termino* ArchivoIndice::Lector::leerFragmentos(tOffset offset, IteradorDocumentos documentos) {
	Termino* termino;
	return termino;
}
