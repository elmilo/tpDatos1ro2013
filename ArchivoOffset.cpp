/*
 * ArchivoOffset.cpp
 *
 *  Created on: 16/06/2013
 *      Author: Guido
 */

ArchivoOffset::Escritor::Escritor(std::string ruta) {
	archivo.abrir(ruta);
}

void ArchivoOffset::Escritor::escribir(tPos pos) {
	archivo.escribirUnsigned(pos);
}

ArchivoOffset::Lector::Lector(std::string ruta) {
	archivo.abrir(ruta);
}

tPos ArchivoOffset::Lector::leer() {
	return (archivo.leerUnsigned());
}

bool ArchivoOffset::Lector::eof() {
	return (archivo.eof());
}
