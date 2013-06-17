/*
 * Temporal.h
 *
 *  Created on: Apr 30, 2013
 *      Author: guidi
 */

#ifndef TEMPORAL_H_
#define TEMPORAL_H_

#include "Diccionario.h"
#include "ArchivoGenerico.h"

namespace ArchivoTemporal {

	const std::string EXTENSION = "tmp";

	class Lector {
	public:
		Lector(std::string ruta);
		Termino leerTermino();
		bool eof();
	private:
		ArchivoGenerico::Lector archivo;
	};

	class Escritor {
	public:
		Escritor(std::string ruta);
		void crearTemporal(Diccionario* diccionario);
	private:
		void escribirTermino(const Termino& termino);
		ArchivoGenerico::Escritor archivo;
	};
}

#endif /* TEMPORAL_H_ */
