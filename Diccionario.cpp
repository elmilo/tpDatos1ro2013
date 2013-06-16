#include "Diccionario.h"

Diccionario::~Diccionario() {
	IteradorTerminos it_map = diccionario.begin();
	while(it_map != diccionario.end()) {
		delete (*it_map).second;
		it_map++;
	}
}

/*************************************************************************************/
/*************************************************************************************/
bool Diccionario::existeTermino(tTermino unToken) {
	return diccionario.count(unToken) > 0;
}

/*************************************************************************************/
void Diccionario::agregar(const Termino& unTermino) {
	tTermino token = unTermino.getToken();
	if(!existeTermino(token)) {
		diccionario[token] = new Termino(unTermino);
	}
	else {
		// falta hacer una mezcla con el termino existente
	}
}

void Diccionario::agregar(tTermino unToken, tPos unaPosicion, tDocId unDocID) {
	if(!existeTermino(unToken)) {
		diccionario[unToken] = new Termino(unToken);
	}
	((Termino*) diccionario[unToken])->agregarPosicion(unaPosicion, unDocID);
}
/*************************************************************************************/

ConjuntoTerminos* Diccionario::getTerminos() {
	return &diccionario;
}

unsigned Diccionario::memoriaOcupada() {

}
