#ifndef MERGER_H_
#define MERGER_H_

#include "ArchivoTemporal.h"
#include "Termino.h"

struct ComparadorDeTerminos {
	bool operator() (Termino* const lhs, Termino* const rhs) const {
		return *lhs < *rhs;
	}
};

// se elige 'map' porque no inserta duplicados y los inserta ordenados
// tambien porque me permite asociar el archivo con el termino leido
// se utiliza ComparadorDeTerminos para ordenar los terminos alfabéticamente
typedef std::map<Termino*,ArchivoTemporal::Lector*,ComparadorDeTerminos> BufferDeTerminos;

class Merger { // merge de N entradas

	std::string tempdir;  // directorio donde se encuentran los temporales
	BufferDeTerminos buffer;

public:

	Merger(std::string tempdir);
	~Merger();

	// abre los archivos y carga el buffer con el primer término de
	// cada uno de los archivos.
	void mergearArchivos();

	// extrae el elemento más pequeño del buffer y lo reemplaza por
	// el elemento siguiente del mismo archivo desde el cual provino
	// el elemento extraído.
	Termino* nextTermino();

	// pregunta si el buffer está vacio
	bool end();

private:

	// inserta un nuevo término en el buffer solo si es nuevo.
	// Caso contrario, lee desde el archivo hasta lograr insertar uno distinto.
	// Si no pudo insertar y se terminó el archivo, entonces cierra el archivo y
	// lo borra del buffer (en este caso retorna false, sinó siempre true).
	void insertarDistinto(ArchivoTemporal::Lector* arch);

};

#endif
