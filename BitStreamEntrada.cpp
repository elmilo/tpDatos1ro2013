#include "BitStreamEntrada.h"

BitStreamEntrada::BitStreamEntrada(const char* nomArch) {

    archEntrada.open(nomArch,ios_base::in|ios::binary);
	archEntrada.seekg(0);
	posBit = 7;
	posBuffer=0;
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

void BitStreamEntrada::cargarBloqueAmemoria(int tamanioBuffer){

sizeBuffer=tamanioBuffer;
buffer= new char [tamanioBuffer];

archEntrada.seekg (0, archEntrada.beg);

archEntrada.read(buffer,tamanioBuffer);

avanzarPosCaracterDeBuffer();
}

int BitStreamEntrada::tamanioArchivo(){
    archEntrada.seekg (0, archEntrada.end);
    int length = archEntrada.tellg();
    archEntrada.seekg (0, archEntrada.beg);
    return length;
}

bool BitStreamEntrada::leerBitDeBuffer() {

	bool retorno = bitBloque[posBit];
	posBit--;

	if (posBit < 0) {
		 avanzarPosCaracterDeBuffer();
		 posBit = 7;
	}

	return retorno;
}


void BitStreamEntrada::avanzarPosCaracterDeBuffer() {
    if (posBuffer<=sizeBuffer)
    	{
    	this->bitBloque = buffer[posBuffer];
        posBuffer++;
    	}
}
