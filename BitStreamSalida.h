#ifndef BitStreamSalida_H_
#define BitStreamSalida_H_

#include <iostream>
#include <fstream>

using namespace std;

class BitStreamSalida {

 private:

         fstream archSalida;
         char code;
         int posBit;
         char ultimoCaracter;
         char buffer[1];//tamaño buffer a grabar a disco
		 int posVector;
 public:

         BitStreamSalida();
         BitStreamSalida(const char* nomArchivo);
         void escribirBit(bool);
         void escribirCaracter();
         void escribirCaracterRelleno();
         void escribirCaracterFinal();
         void apuntarPosArch(int pos);
         int posEnArchivo();
         char getUltimoChar();
         virtual ~BitStreamSalida();
         void cerrarArchivo();
 };

#endif /* BitStreamSalida_H_ */
