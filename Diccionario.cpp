#include "Diccionario.h"


void Diccionario::insertar(palabraPos termino, tipoDocID unDoc){

string unTermino = termino.palabra;
unsigned int unaPosicion = termino.posicion;


if (diccionario.count(unTermino) == 1){
    if (diccionario[unTermino].count(unDoc)==1){
        //El termino y el documento existen en el diccionario
        diccionario[unTermino][unDoc].insertarPosicion(unaPosicion);
        
        }else{
        //Significa que el termino existe, pero el mapa del documento no.
        PosicionesPorDocumento listado(unaPosicion);
        diccionario[unTermino].insert(make_pair(unDoc, listado));
        }
    }else{
    /**
     * No existe el termino en el mapa del diccionario, por ende se  
     * debe crear el mapa para ese termino y el del documento
     * */
    mapa1 mapita;
    PosicionesPorDocumento listado(unaPosicion);
    mapita[unDoc] = listado;
    
    diccionario.insert(make_pair(unTermino, mapita));
    }
};

/**
 * 
 * TEMPORAL
 * */
void Diccionario::mostrar(){
    mapa1::iterator interno;
    mapaDelDiccionario::iterator externo;

  for (externo=diccionario.begin(); externo!=diccionario.end(); externo++){
        cout << "--------------------" << endl;
        cout << "Termino: " << externo->first << endl;
    for (interno=externo->second.begin(); interno != externo->second.end(); interno++){
        cout << "docID: " << interno->first << endl;
        cout << "Posiciones: ";
        interno->second.mostrarPosiciones();
        cout << "--------------------" << endl;}
    }
    
};

