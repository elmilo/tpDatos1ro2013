/*
 * ArchivoDic.h
 *
 *  Created on: Apr 30, 2013
 *      Author: guidi
 */

#ifndef ARCHIVODIC_H_
#define ARCHIVODIC_H_

namespace ArchivoDic {
	class Lector {
		Lector(std::string ruta);
		std::string leer();
		bool eof();
	};
	class Escritor {
		Escritor(std::string ruta);
		void escribir(Diccionario* diccionario);
	};
}


#endif /* ARCHIVODIC_H_ */
