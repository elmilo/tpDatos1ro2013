#ifndef INDEXADOR_INCLUDED
#define INDEXADOR_H_INCLUDED

#include "Parser.h"
#include "Diccionario.h"
#include "Merger.h"
#include <iostream>

namespace Indexador {
	class Creador {
	public:
		Creador(std::string repo, std::string dir);
		void indexar();

	private:
		void correrEtapa1();
		void correrEtapa2();

	private:
		std::string repo;
		std::string dir;  // dir del repo
		std::string outdir;  // dir de archivos tmp
	};

	class Buscador {
	public:
		Buscador(std::string repo, std::string dir);
		void buscar(std::string consulta);
	private:
		void armarTabla();
		void ordenarPorFreqs(lista);
		TablaIndice tabla;
	};
}

#endif 
