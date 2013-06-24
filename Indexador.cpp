#include "Indexador.h"

#include "ArchivoFreqs.h"
#include "ArchivoDic.h"
#include "ArchivoIndice.h"
#include "Normalizador.h"
#include "TablaIndice.h"

void Indexador::Creador::correrEtapa1() {
	Parser parser(dir);
	Diccionario* diccionario;
	ArchivoTemporal::Escritor escritor(TEMPDIR);
	while (parser.tieneTerminos()) {
		tToken t = parser.nextTermino();
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
	merger.mergearArchivos();
	ArchivoDic::Escritor escritorDic;
	ArchivoFreqs::Escritor escritorFreqs;
	ArchivoIndice::Escritor escritorIndice(rutaIndice, rutaOffsets);
	while (!merger.end()) {
		Termino termino = merger.nextTermino();
		escritorDic.escribir(termino);
		escritorFreqs.escribir(termino);
		escritorIndice.escribir(termino);
	}
}

void Indexador::Buscador::buscar(std::string consulta) {
	std::list<tToken>* terminos = Normalizador::normalizarConsulta(consulta);
	tOffset offset = tabla.menor(terminos);

	/*TODO: crear una estructura que guarde las posiciones iniciales de cada string
	 * para despues poder intersectar las listas de docs de cada término
	*/
	ArchivoIndice::Lector lector;
	Termino* termino = lector.leerBloque(offset);
	while (offset = lista.siguiente()) {
		Termino* otroTermino = lector.leerFragmentos(offset, termino->iteradorDocs());
		tPos distancia = termino->posInicial() - otroTermino->posInicial();
		termino->intersectar(otroTermino, distancia);
	}
	termino->listarPosiciones();
}



