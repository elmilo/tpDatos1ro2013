#include "Lzw.h"

BitStreamSalida streamSalida("diccionario.lzw");
BitStreamEntrada streamEntrada("diccionario.lzw");

Lzw::Lzw(){
sizeBuffer=4785;
}

void Lzw::crearDiccionarioCompresion(){
 dictSize = 256;
  for (int i = 0; i < 256; i++)
    dictionaryC[string(1, i)] = i;}

void Lzw::crearDiccionarioDescompresion(){
    dictSize = 256;
  for (int i = 0; i < 256; i++)
    dictionaryD[i] = string(1, i);}



string Lzw::leerBloque(){
char * buffer = new char [sizeBuffer];
string x;
 archEntrada.read (buffer,sizeBuffer);
 for(int i=0;i<sizeBuffer;i++){x+=buffer[i];}
 return x;
 }


void Lzw::borrarTablaCompresion(){
dictionaryC.clear();
}
void Lzw::borrarTablaDescompresion(){
dictionaryD.clear();
}



template <typename Iterator>
Iterator  Lzw::compress(const string &uncompressed, Iterator result) {

  string w;
  for (string::const_iterator it = uncompressed.begin();
       it != uncompressed.end(); ++it) {
           //si se llena la tabla hacer un clearing
           if (dictSize>512){
           borrarTablaCompresion();
           crearDiccionarioCompresion();
           }

    char c = *it;
    string wc = w + c;
    if (dictionaryC.count(wc))
      w = wc;
    else {
      *result++ = dictionaryC[w];
      // Add wc to the dictionary.
      dictionaryC[wc] = dictSize++;
      w = string(1, c);
    }
  }

  // Output the code for w.
  if (!w.empty())
    *result++ = dictionaryC[w];
  return result;
}


template <typename Iterator>
string Lzw::decompress(Iterator begin, Iterator end) {

  std::string w(1, *begin++);
  std::string result = w;
  std::string entry;
  for ( ; begin != end; begin++) {

        if (dictSize>512){
           borrarTablaDescompresion();
           crearDiccionarioDescompresion();
           }
    int k = *begin;
    if (dictionaryD.count(k))
      entry = dictionaryD[k];
    else if (k == dictSize)
      entry = w + w[0];
    else
      throw "Bad compressed k";

    result += entry;

    // Add w+entry[0] to the dictionary.
    dictionaryD[dictSize++] = w + entry[0];

    w = entry;
  }
  return result;
}







byte Lzw::bin2char(string sSecuencia) {

  if (sSecuencia.size() != 8) return '\0';

  int nLongitud = static_cast<int>(sSecuencia.size());
  byte nSum = 0;
  for (int i = 0; i < nLongitud; i++) {
    unsigned char c = sSecuencia[i];
    int n = 0;
    if (c == '0') {
      n = 0;
    } else if (c == '1'){
      n = 1;
    }
    nSum += static_cast<unsigned int>(n*pow(2.0, (nLongitud - 1) - i));
  }
  byte cOcteto;
  cOcteto = static_cast<byte>(nSum);
  return cOcteto;
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


 char Lzw::convertirEnBit(bool bitBool)
{
    if(bitBool==true){ return '1';}
        else {return '0';}}

bool Lzw::esUno(char bitChar){

if (bitChar=='1'){
    return true;}
        else {return false;}
}


void  Lzw::escribirUnCodigo(int codEnDecimal){

string codBinario;
codBinario=char2bin(codEnDecimal);

//si es un numero mayor a la tabla se graba primero el 1
if (codEnDecimal<256){
    streamSalida.escribirBit(esUno(0));}
   else {
       streamSalida.escribirBit(true);}

 for(int i=0;i<=7;i++){

   streamSalida.escribirBit(esUno(codBinario[i]));}
}



int Lzw::leerUnCodigo(){
char bitChar;
string codBin;
int codDecimal;
codBin.clear();

   bitChar=convertirEnBit(streamEntrada.leerBit());
   if(bitChar=='0'){
    for(int i=0;i<=7;i++){
        codBin+=convertirEnBit(streamEntrada.leerBit());}
        codDecimal=bin2char(codBin);
   }
   else{
    for(int i=0;i<=7;i++){
        codBin+=convertirEnBit(streamEntrada.leerBit());}
        //se convierten los 8 primeros bits y despues se suma 256 para formar el numero real
        codDecimal=bin2char(codBin);
        codDecimal=codDecimal+256;
   }

return codDecimal;
}




void Lzw::escribirBloque(vector<int> vecSalida){
int tamanioVec;
tamanioVec=vecSalida.size();
for(int i=0;i<=tamanioVec-1;i++){escribirUnCodigo(vecSalida[i]);}
//agregar caracter final archivo
streamSalida.escribirBit(false);
streamSalida.escribirBit(true);
streamSalida.escribirBit(true);
streamSalida.escribirBit(true);
streamSalida.escribirBit(true);
streamSalida.escribirBit(true);
streamSalida.escribirBit(true);
streamSalida.escribirBit(true);
streamSalida.escribirBit(true);
streamSalida.escribirCaracterFinal();

}

void Lzw::comprimirBloque(string bloque){
  vector<int> buffer;
  compress(bloque, back_inserter(buffer));
  escribirBloque(buffer);
  }

string Lzw::descomprimirBloque(){
vector<int> buffer;

int codigo=0;


while(codigo!=255){
codigo=leerUnCodigo();
buffer.push_back(codigo);
cout<<codigo<<"-";

}
borrarTablaDescompresion();
crearDiccionarioDescompresion();
return decompress(buffer.begin(),buffer.end());
}

void Lzw::comprimirArchivo(const char* nomArch){
    archEntrada.open(nomArch,ios_base::in|ios::binary);
    borrarTablaCompresion();
    crearDiccionarioCompresion();

    comprimirBloque(leerBloque());
    archEntrada.close();
}

Lzw::~Lzw()
{
}
