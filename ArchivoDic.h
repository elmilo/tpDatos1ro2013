
#ifndef ARCHIVODIC_H_
#define ARCHIVODIC_H_

#include "ArchivoGenerico.h"

namespace ArchivoDic {
	class Lector {
	public:
		Lector(std::string ruta);
		std::string leer();
		bool eof();
	private:
		ArchivoGenerico::Lector archivo;
	};
	class Escritor {
	public:
		Escritor(std::string ruta);
		void escribir(Diccionario* diccionario);
	private:
		ArchivoGenerico::Escritor archivo;
	};
}


#endif /* ARCHIVODIC_H_ */
