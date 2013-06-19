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

ArchivoIndice::Lector::Lector(std::string rutaIndice, std::string rutaOffset);

Termino* ArchivoIndice::Lector::leerBloque(tOffset offset) {
	//AHORA SIGO
}

Termino* ArchivoIndice::Lector::leerFragmentos(tOffset offset, IteradorDocumentos documentos);
