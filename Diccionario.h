#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "common.h"
#include "Termino.h"

class Diccionario {

	typedef set<Termino*> ConjuntoTerminos;
//typedef set<Terminos*>::const_iterator IteradorDiccionario;

	ConjuntoTerminos diccionario;

private:

	bool buscarTermino(std::string unToken);

public:

	Diccionario(std::string repo, std::string dir);

	Diccionario();

	/**
	 * Trata de insertar una palabra si corresponde, si no actualiza la lista
	 * */
	void agregar(string unToken, unsigned unaPosicion, unsigned unDocID);

	void agregar(Termino unTermino);

	unsigned memoriaOcupada();

};

#endif
