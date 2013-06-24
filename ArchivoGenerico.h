#ifndef ARCHIVOGENERICO_H_
#define ARCHIVOGENERICO_H_

#include "ArchivoGenerico.h"

namespace ArchivoGenerico {
	void empaquetarUnsigned(char*& array, unsigned int integer);
	void empaquetarSize(char*& array, unsigned int integer);
	void empaquetarString(char*& array, std::string string);

	class Escritor {
	public:
		Escritor();
		~Escritor();
		void escribirStream(BitStream* bitStream);
		void escribirUnsigned(unsigned int integer);
		void escribirSize(size_t integer);
		void escribirString(std::string string);
		void escribirBit(tBit bit);
		size_t getPos();

		/*Rellena con varios 0's, y un 1 final*/
		void rellenarBits();
		int abrir(std::string ruta, std::string extension = "")
		int cerrar();

		/*IMPORTANTE
		 *Solo se bajan cosas a disco cuando se usa esto*/
		void flush();
	private:
		BitStream stream;
		std::ofstream archivo;
	};

	class Lector {
	public:
		Lector();
		~Lector();
		BitStream* leerStream(unsigned int byteSize);
		size_t leerSize();
		tBit leerBit();
		std::string leerString(size_t size);
		unsigned int leerUnsigned();
		bool eof();
		int abrir(std::string ruta, std::string extension = "");
		int cerrar();
		void seek(tOffset offset);
	private:
		std::ifstream archivo;
		BitStream stream;
	};
}

#endif /* ARCHIVOGENERICO_H_ */
