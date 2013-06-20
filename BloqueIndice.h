/*
 * BloqueIndice.h
 *
 *  Created on: 16/06/2013
 *      Author: Guido
 */

#ifndef BLOQUEINDICE_H_
#define BLOQUEINDICE_H_

#include <stdlib.h>

namespace BloqueIndice {
	class Escritor {
	public:
		Escritor(Termino* termino);
		BitStream* getBloque();
	private:
		void generarFragmentos(Termino* bloque);
		void appendFragmentosA(BitStream* stream);
		void appendMetadatosA(BitStream* stream);
		BitStream* bloque;
		std::list<unsigned int> listaOffsets;
	};

	class Lector {
	public:
		Lector(BitStream* bloque);
		Termino* getTermino();
	private:
		Termino* termino;
		void generarTermino(BitStream* stream);
	};

	class BloqueIndice {
	public:
		std::list<tOffset>* getOffsetsFragmentos();
	private:
	};
}


#endif /* BLOQUEINDICE_H_ */
