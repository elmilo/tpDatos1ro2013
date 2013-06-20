#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED

#include "common.h"
#include "Documento.h"

struct ComparadorDeDocumentos {
	bool operator() (Documento* const lhs, Documento* const rhs) const {
		return *lhs < *rhs;
	}
};

// se elige 'set' porque no inserta duplicados y aparte se ordena automáticamente
// se utiliza ComparadorDeDocumentos para comparar en el set
typedef std::set<Documento*,ComparadorDeDocumentos> ConjuntoDocumentos;
typedef ConjuntoDocumentos::const_iterator IteradorDocumentos;

typedef std::vector<tDocId> ListaDeDocIds;

class Termino {

	tTermino token; // palabra/texto
	ConjuntoDocumentos documentos;

public:
	Termino();
	Termino(tTermino unTermino);
	Termino(const Termino& otroTermino);
	~Termino();

	// retorna true si creó un nuevo documento
	bool agregarPosicion(tPos unaPosicion, tDocId unDocID);

	//IteradorDocumentos iteradorDocs();  // ¿¿Para que se usa esto??

	//Solo conserva aquellos docs iguales y posiciones que se encuentren a la distancia especificada
	//otroTermino.pos() - pos() == distancia
	//Retorna una lista con los docIDs que cumplen la condicion
	//http://www.youtube.com/watch?v=oM1dVZWRwmA   minuto: 14:03
	ListaDeDocIds intersectar(Termino* otroTermino, tPos distancia);

	ConjuntoOcurrencias* listarPosiciones(tDocId unDocID);

	tTermino getToken() const;

	const ConjuntoDocumentos* getDocumentos() const;

	bool operator<(const Termino &rhs) const;

	bool operator==(const Termino &rhs) const;

	bool operator!=(const Termino &rhs) const;

private:

	IteradorDocumentos buscarDocumento(tDocId unDocID) ;

	// Desacoplo la segunda parte del algoritmo de interseccion.
	// unDoc y otroDoc tienen igual docId
	bool seIntersectan(Documento* unDoc, Documento* otroDoc, tPos distancia);

};

#endif
