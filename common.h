#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
//class Termino;

typedef bool tBit;
typedef std::string tToken;
typedef unsigned int tDocId;
typedef unsigned int tPos;
//typedef std::set<Termino*> tTermSet;
typedef unsigned int tFreq;
typedef unsigned int tOffset;
typedef std::list<tFreq> ConjuntoFrecuencias;
typedef ConjuntoFrecuencias::const_iterator IteradorFrecuencias;

const unsigned int MAX_DIC_SIZE = 1024;
const unsigned int BITS_PER_BYTE = 8;
const unsigned int FRAG_SIZE = 128;
const std::string TEMPDIR;
const std::string OUTDIR;
const unsigned int maxTamanioBloque = 182379793; //elegir uno o definir en momento de ejecucion

#endif /* COMMON_H_ */
