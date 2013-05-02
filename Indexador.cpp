#include "Indexador.h"

#include "ArchivoFreqs.h"
#include "ArchivoDic.h"
#include "ArchivoIndice.h"
#include "Normalizador.h"

void Indexador::Creador::correrEtapa1() {
	Parser parser(dir);
	Diccionario* diccionario;
	ArchivoTemporal::Escritor escritor(TEMPDIR);
	while (parser.tieneTerminos()) {
		tTermino t = parser.nextTermino();
		tDocId d = parser.getDocIdActual();
		tPos p = parser.getPosActual();
		diccionario->agregar(t, d, p);
		if (diccionario->memoriaOcupada() < MAX_DIC_SIZE) {
			escritor.crearTemporal(diccionario);
		}
	}
}

void Indexador::Creador::correrEtapa2() {
	Diccionario* diccionario;
	Merger merger(OUTDIR);
	ArchivoDic::Escritor escritorDic;
	ArchivoFreqs::Escritor escritorFreqs;
	ArchivoIndice::Escritor escritorIndice(rutaIndice, rutaOffsets);
	while (!merger.end()) {
		Termino t = merger.nextTermino();
		diccionario->agregar(t);
		if (diccionario->memoriaOcupada() < MAX_DIC_SIZE) {
			escritorDic.escribir(diccionario);
			escritorFreqs.escribir(diccionario);
			escritorIndice.escribir(diccionario);
		}
	}
}

void Indexador::Buscador::buscar(std::string consulta) {
	armarTabla();
	std::list<std::string>* terminos = Normalizador::normalizarConsulta(consulta);
	//Ordenar lista de acuerdo a frecuencias globales
	std::list<tOffset>offsets = tabla.buscar(lista);
	ordenarPorFreq(lista);
	//TODO: Escribir logica de mergeo de consultas
}

void Indexador::Buscador::armarTabla() {
	ArchivoDic::Lector lectorDic;
	ArchivoFreqs::Lector lectorFreqs;
	ArchivoOffset::Lector lectorOffset;
	while (!lectorDic.eof()) {
		std::string termino = lectorDic.leer();
		tabla.pushearTermino(termino);
	}
	while (!lectorFreqs.eof()) {
		tFreq freq = lectorFreqs.leer();
		tabla.pushearFreq(freq);
	}
	while (!lectorOffset.eof()) {
		tOffset offset = lectorOffset.leer();
		tabla.pushearOffset(offset);
	}
	std:: cout << "En la tabla se insertaron: " << std::endl
			<< tabla.sizeTerminos() << " terminos." << std::endl
			<< tabla.sizeFreqs() << " frecuencias." << std::endl
			<< tabla.sizeOffsets() << " offsets." << std::endl;
}

