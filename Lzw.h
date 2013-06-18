#ifndef LZW_H
#define LZW_H
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include "BitStreamSalida.h"
using namespace std;
typedef unsigned char byte;


class Lzw
{

private:

    fstream archEntrada;
    map<string,int> dictionary;
    int dictSize;
    int sizeBuffer;

    public:

        Lzw();
        void comprimirLzw(const char* nomArch);
        void crearDiccionario();
        string leerBloque(int sizeBuffer);
        void borrarTabla();
        string char2bin(byte cData);
        void escribirUnCodigo(int codEnDecimal);
        void escribirBloque(vector<int> vecSalida);
        void comprimirBloque(string bloque);
        bool esUno(char bitChar);
        template <typename Iterator>
        Iterator compress(const string &uncompressed, Iterator result);
        virtual ~Lzw();

};

#endif // LZW_H
