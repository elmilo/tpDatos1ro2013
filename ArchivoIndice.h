
#ifndef ARCHIVOINDICE_H_
#define ARCHIVOINDICE_H_

#include "ArchivoOffset.h"

namespace ArchivoIndice {
	class Escritor {
	public:
		Escritor(std::string rutaIndice, std::string rutaOffset);
		void escribir(Diccionario* diccionario);
	private:
		tPos getPos();
		ArchivoOffset::Escritor escritorOffset;
		ArchivoGenerico::Escritor escritorIndice;
	};
	class Lector {
	public:
		Lector(std::string rutaIndice, std::string rutaOffset);
		Termino* leerBloque(tOffset offset);
		Termino* leerFragmentos(tOffset offset, IteradorDocumentos documentos);
	private:
		ArchivoGenerico::Lector archivo;
	};
}

void ArchivoIndice::Escritor::escribir(Diccionario* diccionario) {
	//Escribir de acuerdo a la estructura

	escritorOffset.escribir(getPos());
}


#endif /* ARCHIVOINDICE_H_ */
