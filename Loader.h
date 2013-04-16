/*
 * Loader.h
 *
 *  Created on: Apr 16, 2013
 *      Author: guido
 */

#ifndef LOADER_H_
#define LOADER_H_

class Loader {
public:
	Loader(std::string ruta, std::string extension = "");
	std::string getRutas();
};


#endif /* LOADER_H_ */
