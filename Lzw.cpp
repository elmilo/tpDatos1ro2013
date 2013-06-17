#include "Lzw.h"

BitStreamSalida streamSalida("diccionario.lzw");

Lzw::Lzw(){
 sizeBuffer=6;
}

void Lzw::crearDiccionario(){
  // Build the dictionary.
 dictSize = 256;
  for (int i = 0; i < 256; i++)
    dictionary[string(1, i)] = i;}



string Lzw::leerBloque(int sizeBuffer){
char * buffer = new char [sizeBuffer];
string x;
 archEntrada.read (buffer,sizeBuffer);
 for(int i=0;i<sizeBuffer;i++){x+=buffer[i];}
 return x;
 }

void Lzw::borrarTabla(){
dictionary.clear();
crearDiccionario();
}

// Compress a string to a list of output symbols.
// The result will be written to the output iterator
// starting at "result"; the final iterator is returned.
template <typename Iterator>
Iterator  Lzw::compress(const string &uncompressed, Iterator result) {

  string w;
  for (string::const_iterator it = uncompressed.begin();
       it != uncompressed.end(); ++it) {
           //si se llena la tabla hacer un clearing
           if (dictSize>512){
           borrarTabla();
           }

    char c = *it;
    string wc = w + c;
    if (dictionary.count(wc))
      w = wc;
    else {
      *result++ = dictionary[w];
      // Add wc to the dictionary.
      dictionary[wc] = dictSize++;
      w = string(1, c);
    }
  }

  // Output the code for w.
  if (!w.empty())
    *result++ = dictionary[w];
  return result;
}


string Lzw::char2bin(byte cData) {
  string sBuffer;
  string sBufferFinal;
  if(cData==0){
    for (int i = 0; i < 8; i++ )
      sBufferFinal.push_back('0');
    return sBufferFinal;
  }
  else{
    for (byte i = cData; i > 1; i/=2) {
      byte nResto = i%2;
      if (nResto == 0) {
	sBuffer.push_back('0');
      } else {
			  sBuffer.push_back('1');
      }
    }
    sBuffer.push_back('1');
    int nLongitud = static_cast<int>(sBuffer.size());
    for (int i = 0; i < (8 - nLongitud); i++ ) sBufferFinal.push_back('0');
    for(int i = nLongitud - 1; i >= 0; i-- ) sBufferFinal.push_back(sBuffer[i]);
    return sBufferFinal;
  }
}


bool Lzw::esUno(char bitChar){

if (bitChar=='1'){
    return true;}
        else {return false;}
}


void  Lzw::escribirUnCodigo(int codEnDecimal){

string codBinario;
codBinario=char2bin(codEnDecimal);

//si es un numero mayor a la tabla se graba primero el 1
//if (codEnDecimal<256){
  //  streamSalida.escribirBit(esUno(0));}
//    else {
 //      streamSalida.escribirBit(esUno(1));}

 for(int i=0;i<=7;i++){

   streamSalida.escribirBit(esUno(codBinario[i]));}
}

void Lzw::escribirBloque(vector<int> vecSalida){
int tamanioVec;
tamanioVec=vecSalida.size();
for(int i=0;i<=tamanioVec-1;i++){escribirUnCodigo(vecSalida[i]);}
}

void Lzw::comprimirBloque(string bloque){
  vector<int> buffer;
  compress(bloque, back_inserter(buffer));
  escribirBloque(buffer);}

void Lzw::comprimirLzw(const char* nomArch){
    archEntrada.open(nomArch,ios_base::in|ios::binary);
    crearDiccionario();
    comprimirBloque(leerBloque(sizeBuffer));
    archEntrada.close();
}

Lzw::~Lzw()
{
}
