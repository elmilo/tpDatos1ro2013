#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "common.h"
#include "Termino.h"

typedef set<Termino*>::const_iterator IteradorDiccionario;

class Diccionario {

	typedef set<Termino*> ConjuntoTerminos;
	ConjuntoTerminos diccionario;

private:

	bool buscarTermino(std::string unToken);

public:

	Diccionario();

	IteradorDiccionario iterator();

	Termino* end();
	/**
	 * Trata de insertar una palabra si corresponde, si no actualiza la lista
	 * */
	void agregar(string unToken, tPos unaPosicion, unsigned unDocID);
	void agregar(Termino unTermino);
	unsigned memoriaOcupada();



};

#endif
