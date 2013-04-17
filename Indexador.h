#ifndef INDEXADOR_INCLUDED
#define INDEXADOR_H_INCLUDED

#include "Parser.h"
#include "Diccionario.h"
#include "Merger.h"
#include <iostream>

class Indexador {
public:
	Indexador(std::string repo, std::string dir);
	void indexar();

private:
	void correrEtapa1();
	void correrEtapa2();
	void crearArchivoTemporal(Diccionario* dic);
	void escribirAArchivoFinal(Diccionario* dic);
	unsigned int calculaTamanioEnCodigo(Diccionario* dic);

private:
	std::string repo;
	std::string dir;  // dir del repo
	std::string outdir;  // dir de archivos tmp

};

#endif 
