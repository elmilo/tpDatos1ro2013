#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "common.h"
#include "Termino.h"

// Se elige 'map' porque permite identificar el termino por su token ahorrando
// tiempo de búsqueda.
// Además, se elige 'map' porque no inserta duplicados y aparte ordena alfabéticamente.
typedef std::map<tToken,Termino*> ConjuntoTerminos;
typedef ConjuntoTerminos::const_iterator IteradorTerminos;

class Diccionario {

	unsigned memoriaOcupada;
	ConjuntoTerminos diccionario;

public:

	Diccionario();
	~Diccionario();

	// realiza una copia del termino pasado y lo agrega o actualiza si ya existe
	void agregar(const Termino& unTermino);  // INCOMPLETO
	// lo crea si no existe. Sinó solo agrega la posicion y el docID
	void agregar(tToken unToken, tPos unaPosicion, tDocId unDocID);

	ConjuntoTerminos* getTerminos();

	// tamaño aproximado en memoria del diccionario
	unsigned getMemoriaOcupada();

private:

	bool existeTermino(tToken unToken);
	// retorna true si lo pudo agregar
	bool agregarTerminoSiNoExiste(tToken unToken);

};

#endif
