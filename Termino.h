#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED

#include "common.h"
#include "Documento.h"
#include <list>

class Documento;

typedef std::list<Documento*> ConjuntoDocumentos;
typedef std::list<Documento*>::const_iterator IteradorDocumentos;

class Termino {

	std::string token;
	ConjuntoDocumentos* documentos;

	IteradorDocumentos buscarDocumento(unsigned unDocID);

public:

	Termino(std::string unTermino);

	void agregarPosicion(unsigned unaPosicion, unsigned unDocID);

	IteradorDocumentos iteradorDocs();

	//Solo conserva aquellos docs iguales y posiciones que se encuentren en distancia especificada
	//pos() - otroTermino.pos() == distancia
	void intersectar(Termino* otroTermino, tPos distancia);

	void listarPosiciones();

	std::string getTermino();

	ConjuntoDocumentos* getDocumentos();

	bool operator==(Termino &rhs);

	bool operator!=(Termino &rhs);

};

#endif
