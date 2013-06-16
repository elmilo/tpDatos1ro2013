#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "common.h"
#include "Termino.h"

// Se elige 'map' porque permite identificar el termino por su token ahorrando
// tiempo de búsqueda.
// Además, se elige 'map' porque no inserta duplicados y aparte ordena alfabéticamente.
typedef std::map<tTermino,Termino*> ConjuntoTerminos;
typedef ConjuntoTerminos::const_iterator IteradorTerminos;

class Diccionario {

	ConjuntoTerminos diccionario;

public:

	Diccionario();
	~Diccionario();

	// realiza una copia del termino pasado y lo agrega o actualiza si ya existe
	void agregar(const Termino& unTermino);
	// lo crea si no existe. Sinó solo agrega la posicion y el docID
	void agregar(tTermino unToken, tPos unaPosicion, tDocId unDocID);

	// retorna el iterador apuntando al primer elemento del map
	ConjuntoTerminos* getTerminos();

	unsigned memoriaOcupada();

private:

	bool existeTermino(tTermino unToken);

};

#endif
