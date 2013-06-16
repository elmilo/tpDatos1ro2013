#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED

#include "common.h"
#include "Documento.h"

//class Documento;

typedef std::list<Documento*> ConjuntoDocumentos;
typedef ConjuntoDocumentos::const_iterator IteradorDocumentos;
typedef std::list<tDocId> ListaDeDocIds;

class Termino {

	tTermino token; // palabra/texto
	ConjuntoDocumentos documentos;

public:

	Termino(tTermino unTermino);
	Termino(const Termino& otroTermino);
	~Termino();

	//
	void mezclarCon(const Termino& otroTermino);

	void agregarPosicion(tPos unaPosicion, tDocId unDocID);

	IteradorDocumentos iteradorDocs();  // ¿¿Para que se usa esto??

	//Solo conserva aquellos docs iguales y posiciones que se encuentren a la distancia especificada
	//otroTermino.pos() - pos() == distancia
	//Retorna una lista con los docIDs que cumplen la condicion
	//http://www.youtube.com/watch?v=oM1dVZWRwmA   minuto: 14:03
	ListaDeDocIds intersectar(Termino* otroTermino, tPos distancia);

	void listarPosiciones();  // ¿¿Para que se usa esto??

	tTermino getToken() const;

	ConjuntoDocumentos* getDocumentos();

	bool operator==(const Termino &rhs) const;

	bool operator!=(const Termino &rhs) const;

private:

	IteradorDocumentos buscarDocumento(tDocId unDocID);

	// Desacoplo la segunda parte del algoritmo de interseccion.
	// unDoc y otroDoc tienen igual docId
	bool seIntersectan(Documento* unDoc, Documento* otroDoc, tPos distancia);

};

#endif
