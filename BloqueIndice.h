/*
 * BloqueIndice.h
 *
 *  Created on: 16/06/2013
 *      Author: Guido
 */

#ifndef BLOQUEINDICE_H_
#define BLOQUEINDICE_H_

class BloqueIndice {
public:
	BloqueIndice(Termino* termino);
	BloqueIndice(BitStream* bloque);
	std::list<tOffset>* getOffsetsFragmentos();
	BitStream* getFragmentos();
	Termino* getTermino();
private:
	void generarStream(Termino* bloque);
	void generarTermino(BitStream* stream);
	Termino* termino;
	std::list<unsigned int> listaOffsets;
	BitStream* streamFragmentos;
};


#endif /* BLOQUEINDICE_H_ */
