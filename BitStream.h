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
	void appendStream(BitStream* bitStream);
	void appendUnsigned(unsigned int integer);
	void appendSize(size_t integer);
	void appendString(std::string string);
	void appendBit(tBit bit);
	void appendChar(char caracter);

	tBit popBit();
	char popChar();

	/* Devuelve un array de bytes de tamaño:
	 * la cantidad de bits dividido ocho.
	 * Debería devolver un ERROR si la cantidad de bits
	 * no es divisible por 8, para evitar errores.
	 * Las lógicas de rellenado de bits deben estar
	 * fuera de esta clase
	 */
	void flush(char*& array, unsigned int& size);

	/*Devuelve verdadero si no quedan más bits.
	 */
	bool empty();

	/* Devuelve la cantidad entera de bytes.
	 * Si el �ltimo byte no esta completado, no lo cuenta*/
	size_t byteSize();

private:
	std::list<tBit> bits;
};


#endif /* BITSTREAM_H_ */
