/*
  * Fragmento.h
 *
 *  Created on: 20/06/2013
 *      Author: Guido
 */

#ifndef FRAGMENTO_H_
#define FRAGMENTO_H_

#include "PforCoding.h"
#include "RiceCoding.h"

namespace Fragmento {
	class Fragmento {
	public:
		void agregarDocumento(Documento* documento);
		BitStream* getStream();
		size_t streamSize();
	private:
		Pfor::Compresor dgaps, posiciones;
		Rice::Codificador frecuencias;
		unsigned int cuantosDocumentos = 0;
	};

	class Defragmentador {
	public:
		Defragmentador(BitStream* bloque, unsigned int cantidadDocumentos);
		Termino* getTermino();
	private:
		void descomprimir(BitStream* bloque, unsigned int cantidadDocumentos);
		Termino* termino;
	};
}

#endif /* FRAGMENTO_H_ */
