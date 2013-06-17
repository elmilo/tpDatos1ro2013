#include "Merger.h"
#include "Loader.h"

Merger::Merger(std::string tempdir) {
	this->tempdir = tempdir;
}

Merger::~Merger() {
	BufferDeTerminos::const_iterator it_map = buffer.begin();
	while(it_map != buffer.end()) {
		delete it_map->first;
		delete it_map->second;
		it_map++;
	}
}

void Merger::mergearArchivos() {
	Loader loader(tempdir, ArchivoTemporal::EXTENSION);
	while(!loader.estaVacio()) {
		std::string nameTemp = loader.popDocumento();
		ArchivoTemporal::Lector* arch = new ArchivoTemporal::Lector(nameTemp);
		insertarDistinto(arch);
	}
}

Termino* Merger::nextTermino() {
	Termino* next = buffer.begin()->first;
	ArchivoTemporal::Lector* arch = buffer.begin()->second;
	insertarDistinto(arch);
	return next;
}

bool Merger::end() {
	return buffer.empty();
}

/*************************************************************************************/

void Merger::insertarDistinto(ArchivoTemporal::Lector* arch) {
	if(!arch->eof()) {
		std::pair<BufferDeTerminos::iterator,bool> result;
		do {
			Termino* term = new Termino(arch->leerTermino());
			result = buffer.insert(make_pair(term, arch));
			if(!result.second)  // no pudo insertar el nuevo termino así que lo borra
				delete term;
		} while(!arch->eof() && !result.second);

		if(arch->eof() && !result.second) {
			delete (result.first)->first;
			delete (result.first)->second;
			buffer.erase(result.first);
		}
	}
}
