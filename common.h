#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <set>

/**
* Hay comparaciones, no reemplazar por tipo personalizado sin pensarlo
*/
typedef std::string tipoDocID;
//typedef int tipoDocID;

using namespace std;

struct palabraPos {
    string palabra;
    unsigned int posicion;
};

#endif
