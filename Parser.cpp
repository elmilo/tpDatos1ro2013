#include "Parser.h"

Parser::Parser (string ficheroTxt){
    ficheroEntrada.open(ficheroTxt.c_str(),ios::in);
}

/*
*
*/
void Parser::filtrarPalabrasyPosicionEntrada(int maxNodos){

    char letra;
    int pos_text=0;
    int cantNodos=0;
    string linea;
    int char_dec;
    bool es_primera_palabra;
    palabraPos nodo;
    string palabra;
    int posicion=0;
    unsigned int longPalabra=0;

    es_primera_palabra = true;

 if (ficheroEntrada.is_open()){
     //while (ficheroEntrada.good()){} para hacer el ciclo de verdad
        while(!(maxNodos==cantNodos)){
    if (! ficheroEntrada.eof() ) {
    ficheroEntrada >> noskipws >> letra;

    pos_text++;


  char_dec = static_cast<int>(letra);

/*convierto mayusculas a minusculas*/

  if (char_dec >=65 and char_dec <=90){
        char_dec=char_dec+32;}


/*toma solo las letras minusculas y controla el paso al archivo*/

  if ((char_dec >=48 and char_dec <=57) or (  char_dec >=97 and char_dec <=122)){
        palabra.insert(palabra.end(),static_cast<char>(char_dec)) ;
         longPalabra++;
         }

  else {
                if (!(longPalabra==0)){

                if (es_primera_palabra){posicion=0;}
                else{posicion=(pos_text-longPalabra-1);
                }

                nodo.palabra=palabra;
                nodo.posicion=posicion;
                vecpalabraPos.push_back(nodo);
                cantNodos++;
                }

/*si la longitud es 0 significa que es un caracter no valido*/


                longPalabra=0;
                 palabra.clear();
                 es_primera_palabra = false;
         }

 }}
 ficheroEntrada.close();
 }
 
 //SACAR ESTO DESPUES:
 else cout << "Fichero inexistente" << endl;


}

/*
* no se usa
*/
void Parser::abrirArchivo(string archivotxt){
    ficheroEntrada.open(archivotxt.c_str());
}

/*
* para mas adelante
*/
void Parser::devolverGapsEntrepalabras (string entrada){
    
    
    
    
}
/*
* temporalmente para obtener el listado
*/
void Parser::listado(int cantidad){
    filtrarPalabrasyPosicionEntrada(cantidad);

for (int i=0; i<vecpalabraPos.size(); i++) {
    cout<<vecpalabraPos[i].palabra << " ";
    cout<<vecpalabraPos[i].posicion<< "\n";
    };
}

palabraPos Parser::unNodo(unsigned int posicion){
    return vecpalabraPos[posicion];
};
