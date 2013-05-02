/*
 * ArchivoIndice.h
 *
 *  Created on: May 1, 2013
 *      Author: guidi
 */

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
	};
	class Lector {
		Lector(std::string rutaIndice, std::string rutaOffset);
		void leer(tOffset offset);
	};
}

void ArchivoIndice::Escritor::escribir(Diccionario* diccionario) {
	//Escribir de acuerdo a la estructura

	escritorOffset.escribir(getPos());
}

#endif /* ARCHIVOINDICE_H_ */
