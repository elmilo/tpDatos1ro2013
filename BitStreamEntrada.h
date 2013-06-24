
#ifndef BitStreamEntrada_H_
#define BitStreamEntrada_H_

#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

// BitStreamEntrada toma chars de a uno  y los descompone en booleanos que representan cada bit;

class BitStreamEntrada {

 private:
         ifstream archEntrada;
         bitset<8> bitBloque;
         int posBit;
         char* buffer;
         int sizeBuffer;
         int posBuffer;

 public:

         BitStreamEntrada();
         BitStreamEntrada(const char* nomArch);
         bool leerBit();
         void avanzarPosCaracter();
         void apuntarPosArch(int pos);
         int posEnArchivo();
         void cargarBloqueAmemoria(int tamanioBuffer);
         bool terminoArch();

         bool leerBitDeBuffer();
         void cargarBloqueAmemoria();
         int tamanioArchivo();
         void avanzarPosCaracterDeBuffer();
         virtual ~BitStreamEntrada();
 };


#endif /* BitStreamEntrada_H_ */

