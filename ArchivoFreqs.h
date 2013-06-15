
#ifndef ARCHIVOFREQS_H_
#define ARCHIVOFREQS_H_

namespace ArchivoFreqs {
	class Escritor {
		Escritor(std::string ruta);
		void escribir(Diccionario* diccionario);
	};
	class Lector {
		Lector(std::string ruta);
		tFreq leer();
		bool eof();
	};
}


#endif /* ARCHIVOFREQS_H_ */
