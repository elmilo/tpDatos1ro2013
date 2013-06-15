#ifndef ARCHIVOGENERICO_H_
#define ARCHIVOGENERICO_H_

namespace ArchivoGenerico {
	class Escritor {
	public:
		Escritor();
		~Escritor();
		void escribir(BitStream* bitStream);
		void escribir(size_t integer);
		void escribir(std::string string);
		void escribir(std::list<unsigned int> intergers);
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
		size_t leerSize();
		std::string leerString(size_t size);
		unsigned int leerUnsigned();
		bool eof();
		int abrir(std::string ruta);
		int cerrar();
	private:
		std::ifstream archivo;

	};
}

#endif /* ARCHIVOGENERICO_H_ */
