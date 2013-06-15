#include "BitStreamEntrada.h"

BitStreamEntrada::BitStreamEntrada(const char* nomArch) {

    archEntrada.open(nomArch,ios_base::in|ios::binary);
	archEntrada.seekg(0);
	posBit = 7;
	avanzarPosCaracter();

}

BitStreamEntrada::~BitStreamEntrada() {
	archEntrada.close();
}

//apunta a un determinado char del archivo para luego entregarlo en forma binaria con leerBit()
void BitStreamEntrada::apuntarPosArch(int pos) {
	archEntrada.seekg(pos,ios::beg);
	avanzarPosCaracter();
	posBit = 7;

}

//devuelve bit a bit en forma de bools
bool BitStreamEntrada::leerBit() {

	bool retorno = bitBloque[posBit];
	posBit--;

	if (posBit < 0) {
		 avanzarPosCaracter();
		 posBit = 7;
	}

	return retorno;
}

//avanza siguiente caracter
void BitStreamEntrada::avanzarPosCaracter() {
    if (!archEntrada.eof())
    	{
    	this->bitBloque = archEntrada.get();

    	}
}

bool BitStreamEntrada::terminoArch() {
	return !archEntrada.good();
}

int BitStreamEntrada::posEnArchivo()
{
	return archEntrada.tellg();
}

