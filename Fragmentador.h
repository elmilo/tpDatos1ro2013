/*
 * Fragmento.h
 *
 *  Created on: 20/06/2013
 *      Author: Guido
 */

#ifndef FRAGMENTO_H_
#define FRAGMENTO_H_

namespace Fragmentacion {
	class Frag {
	public:
		Frag(ConjuntoDocumentos* documentos);
		BitStream* getStream();
	private:
		void agregarDocumentos(ConjuntoDocumentos* documentos);
		void agregarDocumento(Documento* documento);
		Pfor::Compresor dgaps, listas;
		Rice::Codificador frecuencias;
	};

	class Defrag {
	public:
		Defrag(BitStream* fragmentos);
		Termino* getTermino();
	private:
		void generarTermino();
		Pfor::Descompresor dgaps, listas;
		Rice::Decodificador frecuencias;
	};
}


#endif /* FRAGMENTO_H_ */
