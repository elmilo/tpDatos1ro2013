#ifndef ESCRITORARCHIVO_H_
#define ESCRITORARCHIVO_H_

#include "common.h"

class EscritorArchivo {
public:
	EscritorArchivo();
	~EscritorArchivo();
	void escribirBit(tBit bit);
	void escribirByte(char byte);
	void escribirArray(void* array, unsigned int size);
	int abrir(std::string ruta);
	int cerrar();
private:
	std::ofstream archivo;

};


#endif
