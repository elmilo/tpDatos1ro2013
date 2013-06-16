
#ifndef ARCHIVOFREQS_H_
#define ARCHIVOFREQS_H_

namespace ArchivoFreqs {
	class Escritor {
	public:
		Escritor(std::string ruta);
		void escribir(Diccionario* diccionario);
	private:
		ArchivoGenerico::Escritor archivo;
	};
	class Lector {
	public:
		Lector(std::string ruta);
		tFreq leer();
		bool eof();
	private:
		ArchivoGenerico::Lector archivo;
	};
}


#endif /* ARCHIVOFREQS_H_ */
