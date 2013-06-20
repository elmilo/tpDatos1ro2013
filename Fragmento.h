/*
 * Fragmento.h
 *
 *  Created on: 20/06/2013
 *      Author: Guido
 */

#ifndef FRAGMENTO_H_
#define FRAGMENTO_H_

class Fragmento {
public:
	void agregarDocumento(Documento* documento);
	BitStream* getStream();
	size_t cuantosDocumentos();
	BitStream* flushStream();
private:
	Pfor::Compresor dgaps, listas;
	Rice::Codificador frecuencias;
	unsigned int cuantosDocumentos = 0;
};


#endif /* FRAGMENTO_H_ */
