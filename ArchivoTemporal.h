/*
 * Temporal.h
 *
 *  Created on: Apr 30, 2013
 *      Author: guidi
 */

#ifndef TEMPORAL_H_
#define TEMPORAL_H_

#include "Termino.h"

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
		void escribirTermino(Termino termino);
		ArchivoGenerico::Escritor archivo;
	};
}

void ArchivoTemporal::Escritor::crearTemporal(Diccionario* diccionario) {
	Termino t;
	//Itera en el diccionario y para cada termino obtenido
	escribirTermino(t);
}

#endif /* TEMPORAL_H_ */
