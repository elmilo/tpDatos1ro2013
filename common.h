#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>
//#include <set>
#include <map>
//class Termino;

typedef bool tBit;
typedef std::string tTermino;
typedef unsigned int tDocId;
typedef unsigned int tPos;
//typedef std::set<Termino*> tTermSet;
typedef unsigned int tFreq;
typedef unsigned int tOffset;

const unsigned int MAX_DIC_SIZE = 1024;
const std::string TEMPDIR;
const std::string OUTDIR;
const unsigned int maxTamanioBloque = 182379793; //elegir uno o definir en momento de ejecucion

#endif /* COMMON_H_ */
