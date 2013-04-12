#include "Parser.h"
#include "Diccionario.h"
#include "ListadorDeArchivos.h"
#include <iostream>

int main(int argc, char **argv){
    
    Diccionario eldicc;
    string directorio="textos";

    int limite=150; //poner la cantidad de palabras del texto si son pocas!!
    int limite2=100;
    
    
    ListadorDeArchivos lister("textos");
    
    string dir1 = lister.documento(2); //<-- Lo nuevo, accede al texto 3 y al 4 abajo
    string dir2 = lister.documento(3);
    
    Parser unParser(dir1);
    unParser.filtrarPalabrasyPosicionEntrada(limite2);
    for (int i=0; i<limite2; i++){
        eldicc.insertar(unParser.unNodo(i), 2); //<-- Lo nuevo, le pasa unsigned como docID
        };
    
    Parser otroParser(dir2);
    otroParser.filtrarPalabrasyPosicionEntrada(limite);
    for (int i=0; i<limite; i++){
        eldicc.insertar(otroParser.unNodo(i), 3);
        };
    
    eldicc.mostrar();
        
	return 0;
}

