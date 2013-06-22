#include "NullCoding.h"
using namespace std;

int NullCoding::Compresion(unsigned int* entrada, unsigned int* salida, int cantidad) {
  for (int i = 0; i < cantidad; ++i) {
    salida[i] = entrada[i];
  }
  return cantidad;
}

int NullCoding::Descompresion(unsigned int* entrada, unsigned int* salida, int cantidad) {
  for (int i = 0; i < cantidad; ++i) {
    salida[i] = entrada[i];
  }
  return cantidad;
}

void NullCoding::setTamanioBloque(int tamanio) {
  block_size = tamanio;
}
