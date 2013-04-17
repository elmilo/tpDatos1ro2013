#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include "common.h"

class Parser {
public:
	Parser(std::string dir);
	tTermino nextTermino();
	tDocId getDocIdActual();
	tPos getPosActual();
	bool tieneTerminos();

private:
	void listado(int cantidad);
	void filtrarPalabrasyPosicionEntrada(int maxNodos);
	void abrirArchivo(string archivotxt);
	void devolverGapsEntrepalabras(string entrada);
	bool terminoArchivo();
	/*palabraPos Parser::siguienteNodo();
	palabraPos Parser::unNodo(unsigned int posicion);*/
	tTermino term;
	tDocId docId;
	tPos pos;
};


#endif /* PARSER_H_ */
