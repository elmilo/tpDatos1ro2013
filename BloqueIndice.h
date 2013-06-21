/*
 * BloqueIndice.h
 *
 *  Created on: 16/06/2013
 *      Author: Guido
 */

#ifndef BLOQUEINDICE_H_
#define BLOQUEINDICE_H_

#include <stdlib.h>
#include "Fragmento.h"

namespace BloqueIndice {
	typedef std::list<Fragmento::Fragmento*> ConjuntoFragmentos;

	class Creador {
	public:
		Creador(Termino* termino);
		BitStream* getBloque();
	private:
		void generarFragmentos(Termino* bloque);
		void appendFragmentosA(BitStream* stream);
		void appendMetadatosA(BitStream* stream);
		void appendCantidadDocumentos(BitStream* stream);
		void appendCantidadFragmentos(BitStream* stream);
		void appendTamaniosFragmentos(BitStream* stream);
		ConjuntoFragmentos fragmentos;
		std::list<unsigned int> listaOffsets;
		tFreq cantidadDocumentos;
	};

	class Lector {
	public:
		Lector(BitStream* bloque);
		Termino* getTermino();
	private:
		Termino* termino;
	int i;

	void generarTermino(BitStream* stream);
	};

	class BloqueIndice {
	public:
		std::list<tOffset>* getOffsetsFragmentos();
	private:
	};
}


#endif /* BLOQUEINDICE_H_ */
