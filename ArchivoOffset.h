/*
 * ArchivoOffset.h
 *
 *  Created on: May 1, 2013
 *      Author: guidi
 */

#ifndef ARCHIVOOFFSET_H_
#define ARCHIVOOFFSET_H_

namespace ArchivoOffset {
	class Escritor {
	public:
		Escritor(std::string ruta);
		void abrir(std::string ruta);
		void escribir(tPos pos);
	private:
		ArchivoGenerico::Escritor archivo;
	};
	class Lector {
	public:
		Lector(std::string ruta);
		tOffset leer();
		bool eof();
	private:
		ArchivoGenerico::Lector archivo;
	};
}


#endif /* ARCHIVOOFFSET_H_ */
