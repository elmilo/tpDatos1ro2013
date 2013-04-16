/*
 * Parser.h
 *
 *  Created on: Apr 16, 2013
 *      Author: guido
 */

#ifndef PARSER_H_
#define PARSER_H_

class Parser {
public:
	Parser(std::string dir);
	tTermino nextTermino();
	tDocId getDocIdActual();
	tPos getPosActual();
	bool tieneTerminos();

private:
	tTermino term;
	tDocId docId;
	tPos pos;
};


#endif /* PARSER_H_ */
