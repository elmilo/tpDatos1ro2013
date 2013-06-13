#ifndef MERGER_H_
#define MERGER_H_

#include "Temporal.h"
#include "Termino.h"

class Merger {
public:
	Merger(std::string outdir);
	void mergearArchivos();
	Termino nextTermino();
	bool end();
private:
	std::string outdir;
	std::list<ArchivoTemporal::Lector*> archivos;
};

Termino Merger::nextTermino() {
	//Combinar termino usando la lista de temporales
}

#endif
