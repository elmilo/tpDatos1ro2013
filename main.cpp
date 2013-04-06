#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;

char* arch_entrada = "arch_entrada.txt";


ifstream ficheroEntrada(arch_entrada ,ios::in );

struct palabraPos {
    string palabra;
    unsigned int posicion;
 };

 vector<palabraPos> vecpalabraPos;







string devuelve_palabra (string linea){

string palabra;
int posFinPalabra;

posFinPalabra= linea.find(",");

palabra = linea.substr(0,posFinPalabra);

return palabra; }





string devuelve_posicion_palabra (string linea){

string palabra;
int posFinPalabra =0;
int posInicioCopiaArchivo =0;
int posInicioPalabra=0;

posInicioPalabra= linea.find(",");
posInicioPalabra= posInicioPalabra++;
posFinPalabra= linea.length();


palabra = linea.substr(posInicioPalabra,posFinPalabra);

return palabra; }






void filtrarPalabrasyPosicionEntrada(int maxNodos){

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

 if (ficheroEntrada) {
        while(!(maxNodos==cantNodos)){
    if (! ficheroEntrada.eof() ) {
    ficheroEntrada >> noskipws >> letra;

    pos_text++;


  char_dec = static_cast<int>(letra);

/*convierto mayusculas a minusculas*/

  if (char_dec >=65 and char_dec <=90){
        char_dec=char_dec+32;}


/*toma solo las letras minusculas y controla el paso al archivo*/

  if ((char_dec >=48 and char_dec <=57) or (  char_dec >=97 and char_dec <=122)) {
        palabra.insert(palabra.end(),static_cast<char>(char_dec)) ;
         longPalabra++;}

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

 else cout << "Fichero inexistente" << endl;


}






int main () {
    palabraPos nodo;
filtrarPalabrasyPosicionEntrada(10);

for (int i=0; i<vecpalabraPos.size(); i++) {
    nodo = vecpalabraPos[i] ;
    cout<<nodo.palabra;
    cout<<nodo.posicion<<"|";
}

 system ("pause");
 return 0;

}

