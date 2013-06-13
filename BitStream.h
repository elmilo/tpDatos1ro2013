/*
 * BitStream.h
 *
 *  Created on: May 1, 2013
 *      Author: guidi
 */

#ifndef BITSTREAM_H_
#define BITSTREAM_H_

/* Bitstream es un stream de bits
 * Lleva cuenta de los bits que tiene.
 * */

class BitStream {
public:
	BitStream();
	void appendBit(tBit bit);
	tBit popBit();

	/* Devuelve un array de bytes de tamaño:
	 * la cantidad de bits dividido ocho.
	 * Debería devolver un ERROR si la cantidad de bits
	 * no es divisible por 8, para evitar errores.
	 * Las lógicas de rellenado de bits deben estar
	 * fuera de esta clase
	 */
	void flush(void*& array, unsigned int& size);

	/*Devuelve verdadero si no quedan más bits.
	 */
	bool eos();
};


#endif /* BITSTREAM_H_ */
