/*
 * BitStream.h
 *
 *  Created on: May 1, 2013
 *      Author: guidi
 */

#ifndef BITSTREAM_H_
#define BITSTREAM_H_

class BitStream {
public:
	BitStream();
	void escribirBit(tBit bit);
	void escribirString(std::string cadena);
	tBit leerBit();

	//Saca a memoria
	void flush(void*& array, unsigned int& size);
	//End of stream
	bool eos();
};


#endif /* BITSTREAM_H_ */
