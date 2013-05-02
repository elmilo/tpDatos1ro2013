/*
 * TablaIndice.h
 *
 *  Created on: May 1, 2013
 *      Author: guidi
 */

#ifndef TABLAINDICE_H_
#define TABLAINDICE_H_

class TablaIndice {
public:
	TablaIndice();
	void pushearTermino(std::string termino);
	void pushearFreq(tFreq freq);
	void pushearOffset(tOffset offset);
	tPos buscar(std::string);

	tFreq getFreq(tPos pos);
	tOffset getOffset(tPos pos);

	unsigned int sizeTerminos();
	unsigned int sizeFreqs();
	unsigned int sizeOffsets();
};


#endif /* TABLAINDICE_H_ */
