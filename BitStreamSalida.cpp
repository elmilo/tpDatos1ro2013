#include "BitStreamSalida.h"

BitStreamSalida::BitStreamSalida(const char* nomArchivo) {
	code = 0;
	archSalida.open(nomArchivo,ios::in|ios::out|ios::binary);
	if(!archSalida.good())
	{
		archSalida.open(nomArchivo,ios::out|ios::binary);
	}
	posBit = 7;
	posVector = 0;
 }


 BitStreamSalida::~BitStreamSalida() {
     archSalida.close();
 }

 //se apunta a una posicion de archivo y se vacia buffer

 void BitStreamSalida::apuntarPosArch(int pos) {
	 archSalida.seekp(pos,ios::beg);
	 posVector = 0;

 }

 //se escribe bit (V=1 F=0)
 //el BYTE(8bits) se  graba solo en archivo al llenarse el buffer

 void BitStreamSalida::escribirBit(bool valor) {
	 code += valor << posBit;
	 posBit--;
	 if (posBit < 0) {
		 escribirCaracter();
		 posBit = 7;
		 code = 0;
	 }

 }

 void BitStreamSalida::escribirCaracter() {
	 ultimoCaracter = code;
         buffer[posVector] = ultimoCaracter;
         posVector++;

         if (posVector >= (int)sizeof(buffer)) {
        	 archSalida.write(buffer,posVector);
        	 posVector = 0;
         }

 }


 void BitStreamSalida::escribirCaracterRelleno() {
	 	ultimoCaracter = code;
		 archSalida.write(buffer,posVector);
		 posVector = 0;

 }

//devuelve el ultimo caracter escrito en buffer;
 char BitStreamSalida::getUltimoChar() {
         return ultimoCaracter;
 }

//rellena el BYTE actual con ceros y borra el buffer
//es como una finalizacion de archivo
 void BitStreamSalida::escribirCaracterFinal() {
         while (posBit != 7)
                 escribirBit(false);
        escribirCaracterRelleno();
 }

 int BitStreamSalida::posEnArchivo()
{
	 return archSalida.tellp();
}

void BitStreamSalida::cerrarArchivo()
 {
     archSalida.close();
 }
