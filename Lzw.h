#ifndef LZW_H
#define LZW_H
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <cmath>
#include <bitset>
#include "BitStreamSalida.h"
#include "BitStreamEntrada.h"
using namespace std;
typedef unsigned char byte;


class Lzw
{

private:

    fstream archEntrada;
    map<string,int> dictionaryC;
    map<int,string> dictionaryD;
    int dictSize;
    int sizeBuffer;

    public:

        Lzw();
        void comprimirArchivo(const char* nomArch);
        void crearDiccionarioCompresion();
        void crearDiccionarioDescompresion();
        string leerBloque();
        void borrarTablaDescompresion();
        void borrarTablaCompresion();
        string char2bin(byte cData);
        void escribirUnCodigo(int codEnDecimal);
        void escribirBloque(vector<int> vecSalida);
        void comprimirBloque(string bloque);
        bool esUno(char bitChar);

        template <typename Iterator>
        Iterator compress(const string &uncompressed, Iterator result);

        char convertirEnBit(bool bitBool);

        int leerUnCodigo();
        string descomprimirBloque();



        virtual ~Lzw();

};

#endif // LZW_H
