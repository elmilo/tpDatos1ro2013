/*
 * TablaIndice.h
 *
 *  Created on: May 1, 2013
 *      Author: guidi
 */

#ifndef TABLAINDICE_H_
#define TABLAINDICE_H_

class TablaIndice {
public:
	TablaIndice();
	void armar();
	//Devuelve el offset del termino menor
	tOffset menor(std::list<tTermino>* terminos);
	unsigned int size();
private:
	void pushearTermino(std::string termino);
	void pushearFreq(tFreq freq);
	void pushearOffset(tOffset offset);
	tPos buscar(std::string);


	tFreq getFreq(tPos pos);
	tOffset getOffset(tPos pos);

	//Metodos utilizados para verificar llenado, sus resultados deberían ser iguales
	unsigned int sizeTerminos();
	unsigned int sizeFreqs();
	unsigned int sizeOffsets();
};

void TablaIndice::armar() {
	ArchivoDic::Lector lectorDic;
	ArchivoFreqs::Lector lectorFreqs;
	ArchivoOffset::Lector lectorOffset;
	while (!lectorDic.eof()) {
		std::string termino = lectorDic.leer();
		pushearTermino(termino);
	}
	while (!lectorFreqs.eof()) {
		tFreq freq = lectorFreqs.leer();
		pushearFreq(freq);
	}
	while (!lectorOffset.eof()) {
		tOffset offset = lectorOffset.leer();
		pushearOffset(offset);
	}
	std:: cout << "En la tabla se insertaron: " << std::endl
			<< sizeTerminos() << " terminos." << std::endl
			<< sizeFreqs() << " frecuencias." << std::endl
			<< sizeOffsets() << " offsets." << std::endl;
}

#endif /* TABLAINDICE_H_ */
