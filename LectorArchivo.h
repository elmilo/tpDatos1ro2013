/*
 * LectorArchivo.h
 *
 *  Created on: Apr 16, 2013
 *      Author: guido
 */

#ifndef LECTORARCHIVO_H_
#define LECTORARCHIVO_H_

#include "common.h"

class LectorArchivo {
public:
	LectorArchivo();
	~LectorArchivo();
	tBit leerBit();
	char leerByte();

	//Devuelve un array en memoria dinámica, debe ser borrado
	void* leerArray(unsigned int size);
	bool eof();
	int abrir(std::string ruta);
	int cerrar();
private:
	std::ifstream archivo;

};


#endif /* LECTORARCHIVO_H_ */
