#include "Parser.h"
#include "Diccionario.h"
#include <iostream>

int main(int argc, char **argv) {

	//Si parametro es indexar, indexar
	//Si parametro es buscar, buscar
    
//Argv[i] es de tipo char* !

for (int i=1; i<argc ;i++){
    if (argv[i][0] == '-' )
        switch (argv[i][1]){
            case 'i':
                //Indexar (Directorio, nombreRepo)
                Indexar (argv[i+1], argv[i+2]);
                break;
            case 'q':
                //Buscar (nombreRepo, consulta)
                Buscar (argv[i+1], argv[i+2]);
                break;
            default:
                std::cout << "Opción no válida... ";
                std::cout << "Reintente con -q o -i" << std::endl;
                break;
        }
    }

    return 0;
}

