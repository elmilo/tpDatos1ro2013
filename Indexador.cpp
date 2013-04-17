#include "Indexador.h"

void Indexador::correrEtapa1() {
	Parser parser(dir);
	Diccionario* diccionario;
	while (parser.tieneTerminos()) {
		tTermino t = parser.nextTermino();
		tDocId d = parser.getDocIdActual();
		tPos p = parser.getPosActual();
		diccionario->agregar(t, d, p);
		if (diccionario->memoriaOcupada() < MAX_DIC_SIZE) {
			crearArchivoTemporal(diccionario);
		}
	}
}

void Indexador::correrEtapa2() {
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
