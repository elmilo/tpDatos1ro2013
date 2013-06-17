#include "Normalizador.h"

Normalizador::Normalizador (std::string unaFrase){

    const char* origen = unaFrase.c_str();
    char *frase, *palabra, *agregada;
    
    frase = strdup(origen);

    palabra = strtok(frase, delim);
    
    while(palabra != NULL) {
            
            agregada = strdup(palabra);
            
            agregarEnContenedor(agregada);
            palabra = strtok(NULL, delim);
    }

}

unsigned Normalizador::cantidad(){
    return posiciones.size();
};

string Normalizador::unTermino (unsigned posicion){
    return posiciones[posicion];
    }

/**********************************************************************************/
/****PRIVATE***********/
/**********************************************************************************/

const char* Normalizador::delim = ".,:;`/\"+-_(){}[]<>*&^%$#@!?~/|\\= \t\n'";

bool Normalizador::esAlfaNum (string entrada){
  locale loc;
  for (unsigned i=0; i< entrada.length() ; i++){
    if ( !isalnum(entrada[i]) )
        return false;
        }
    return true;
}


void Normalizador::agregarEnContenedor(char *palabra){

    int tamanio = 0;
    char *s = palabra;
    for (s = palabra; *s; s++)
        tamanio++;

    string tokenito(palabra, tamanio);
    
    if ( esAlfaNum(tokenito) ) {
        transform(tokenito.begin(),tokenito.end(),tokenito.begin(),(int (*)(int))tolower );
        posiciones.push_back(tokenito);
        }
}

