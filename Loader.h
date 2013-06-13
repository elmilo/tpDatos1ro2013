#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED

#define SEPARADOR_DIR "/"

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <fstream>
#include <dirent.h>
#include <list>
#include <algorithm> 

using namespace std;

class Loader {

private:

	list<string> direcciones; //guarda las direcciones de archivos que van a ser leidos
	const char * raizPpal; //raiz principal: la que se pasa para leer los archivos
	string raizPpalStr;
	unsigned largoRaizStr; //tamanio del string de la raiz principal
	unsigned laPosicion; //Guarda la posicion (usado para docID)
	/**
	 * Filtra los directorios y los archivos
	 * */
	int filtroArchivos(const struct dirent * dire, const char* raiz);

	bool filtroExtensiones(string nombreArchivo, string extension);

	/**
	 * Insertar ruta del archivo en la estructura
	 * */
	void insertar(string archivoPorAgregar, string extension);

	/**
	 * Borra la raiz antes de ser guardada en el vector,
	 * para que se devuelva el directorio en consideracion
	 * */
	string sacarRaizPpal(string unArchivo);

	/**
	 * Obtiene todos los archivos de la carpeta a listar.
	 * Se llama recursivamente para obtener los archivos de los subdirectorios
	 * */
	void listarArchivos(const char* unDirectorio, string extension);

public:

	/**
	 * Constructor: recibe el directorio y extension (por defecto puede no recibirla).
	 * Inspecciona el directorio y deja ordenada la estructura con los mismos
	 * */
	Loader(string directorio, string extension);

	/**
	 * Pregunta si la estructura esta vacia
	 * */
	bool estaVacio();

	/**
	 * Obtener un documento
	 * */
	string popDocumento();

	unsigned getPosicion();
};

#endif
