/*
 * Indexador.h
 *
 *  Created on: Apr 16, 2013
 *      Author: guido
 */

#ifndef INDEXADOR_H_
#define INDEXADOR_H_

class Indexador {
public:
	Indexador(std::string repo, std::string dir);
	void indexar();

private:
	void correrEtapa1() {
		Parser parser;
		Diccionario* diccionario;
		while (parser.tieneTerminos()) {
			tTermino t = parser.nextTermino();
			tDocId d = parser.getDocIdActual();
			tPos p = parser.getPosActual();
			diccionario->agregar(t, d, p);
			if (diccionario->tamañoEnRam() < maxRam) {
				crearArchivoTemporal(diccionario);
			}
		}
	}

	void correrEtapa2() {
		Diccionario* diccionario;
		Merger merger(OUTDIR);
		while (!merger.end()) {
			Termino t = merger.nextTermino();
			diccionario->agregar(t);
			if (calculaTamanioEnCodigo(diccionario) > maxTamanioBloque) {
				escribirAArchivoFinal(diccionario);
			}
		}
	}
	void crearArchivoTemporal(Diccionario* dic);
	void escribirAArchivoFinal(Diccionario* dic);
	unsigned int calculaTamanioEnCodigo(Diccionario* dic);

private:
	std::string repo;
	std::string dir;  // dir del repo
	std::string outdir;  // dir de archivos tmp

};


#endif /* INDEXADOR_H_ */
