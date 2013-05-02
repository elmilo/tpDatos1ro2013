/*
 * Normalizador.h
 *
 *  Created on: May 1, 2013
 *      Author: guidi
 */

#ifndef NORMALIZADOR_H_
#define NORMALIZADOR_H_

namespace Normalizador {
	std::string normalizarTermino(std::string termino);
	std::list<std::string>* normalizarConsulta(std::string consulta);
}


#endif /* NORMALIZADOR_H_ */
