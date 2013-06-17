#include "Diccionario.h"

Diccionario::Diccionario() {
	memoriaOcupada = sizeof(Diccionario);
}

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
	if(!agregarTerminoSiNoExiste(unTermino.getToken())) {
		// falta hacer una mezcla con el termino existente
	}
}

void Diccionario::agregar(tTermino unToken, tPos unaPosicion, tDocId unDocID) {
	agregarTerminoSiNoExiste(unToken);
	if(((Termino*) diccionario[unToken])->agregarPosicion(unaPosicion, unDocID)) {
		memoriaOcupada += sizeof(Documento*) + sizeof(Documento);
	}
	memoriaOcupada += sizeof(tPos);
}

/*************************************************************************************/

ConjuntoTerminos* Diccionario::getTerminos() {
	return &diccionario;
}

unsigned Diccionario::getMemoriaOcupada() {
	return memoriaOcupada;
}

bool Diccionario::agregarTerminoSiNoExiste(tTermino unToken) {
	if(!existeTermino(unToken)) {
		diccionario[unToken] = new Termino(unToken);
		memoriaOcupada += sizeof(tTermino) + sizeof(Termino*) + sizeof(Termino);
		return true;
	}
	return false;
}
