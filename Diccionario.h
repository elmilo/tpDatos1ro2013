/*
 * Diccionario.h
 *
 *  Created on: Apr 16, 2013
 *      Author: guido
 */

#ifndef DICCIONARIO_H_
#define DICCIONARIO_H_

class Diccionario {
public:
	Diccionario(std::string repo, std::string dir);
	Diccionario();
	void agregar(tTermino term, tDocId doc, tPos pos);
	void agregar(Termino term);
	unsigned int tamañoEnRam();

};


#endif /* DICCIONARIO_H_ */
