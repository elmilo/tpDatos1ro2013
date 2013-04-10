#include "Parser.cpp"
#include "Diccionario.cpp"

#include <iostream>

int main(int argc, char **argv){
    
    Diccionario eldicc;
    
    //string dir1="arch_entrada.txt";
    string dir1="textos/arch1";
    string dir2="textos/arch2";
    int limite=4; //poner la cantidad de palabras del texto!!
    int limite2=4;
    
    Parser unParser(dir1);
    unParser.filtrarPalabrasyPosicionEntrada(limite2);
    for (int i=0; i<limite2; i++){
        eldicc.insertar(unParser.unNodo(i), dir1);
        };
    
    Parser otroParser(dir2);
    otroParser.filtrarPalabrasyPosicionEntrada(limite);
    for (int i=0; i<limite; i++){
        eldicc.insertar(otroParser.unNodo(i), dir2);
        };
    
    eldicc.mostrar();
        
	return 0;
}

