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
	class Lector {
	public:
		Lector(std::string archivo);
		Termino leerTermino();
		bool eof();
	private:
		ArchivoGenerico::Lector archivo;
	};

	class Escritor {
	public:
		Escritor(std::string directorio);
		void crearTemporal(Diccionario* diccionario);
	private:
		void escribirTermino(const Termino& termino);
		ArchivoGenerico::Escritor archivo;
	};
}

#endif /* TEMPORAL_H_ */
