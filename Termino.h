/*
 * Termino.h
 *
 *  Created on: Apr 16, 2013
 *      Author: guido
 */

#ifndef TERMINO_H_
#define TERMINO_H_

class Termino {
public:
	Termino(std::string term);
	void addPosEnDoc(tPos pos, tDocId docId);
	bool operator==(Termino term);
};


#endif /* TERMINO_H_ */
