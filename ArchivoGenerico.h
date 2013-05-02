/*
 * ArchivoGenerico.h
 *
 *  Created on: May 1, 2013
 *      Author: guidi
 */

#ifndef ARCHIVOGENERICO_H_
#define ARCHIVOGENERICO_H_

namespace ArchivoGenerico {
	class Escritor {
	public:
		Escritor();
		~Escritor();
		void escribir(BitStream* bitStream);
		int abrir(std::string ruta);
		int cerrar();
	private:
		std::ofstream archivo;

	};

	class Lector {
	public:
		Lector();
		~Lector();
		BitStream* leer(unsigned int size);

		bool eof();
		int abrir(std::string ruta);
		int cerrar();
	private:
		std::ifstream archivo;

	};
}

#endif /* ARCHIVOGENERICO_H_ */
