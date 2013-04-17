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
>>>>>>> cdd94d93c4590a4371a2986f84fe9cbdedbed8cc
};


#endif /* PARSER_H_ */
