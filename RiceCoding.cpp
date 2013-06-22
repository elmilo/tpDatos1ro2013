#include "RiceCoding.h"
using namespace std;

void RiceCoding::setTamanioBloque(int tamanio) {
  block_size = tamanio;
}

int RiceCoding::Compresion(unsigned int* entrada, unsigned int* salida, int cantidad) {
  uint64_t avg = 0;
  // Encontrar el promedio de los números a comprimir:
  for (int i = 0; i < cantidad; ++i) {
    avg += entrada[i];
  }
  avg /= cantidad;
  // Encontrar el número potencia de 2 más cercano al promedio (observar aritmetica de bits)
  b = 0;
  while ((avg >>= 1) > 0) {
    ++b;
  }

  unsigned int* aux1 = salida;
  *aux1 = (unsigned int) b;
  aux1++;

  unsigned int bp = 0;
  for (int i = 0; i < cantidad; ++i) {
    codificarRice(aux1, &bp, entrada[i], b);
  }

  int s;
  if ((bp & 0x1f) != 0)
    s = (1 + (bp >> 5));
  else
    s = (bp >> 5);
  s += 1;
  return s;
}

void RiceCoding::codificarRice(unsigned int* buf, unsigned int* bp, unsigned int val, unsigned int bits) {
  unsigned int w;
  writeBits(buf, bp, val & MASK[bits], bits);
  for (w = (val >> bits); w > 0; --w) {
    writeBits(buf, bp, 1, 1);
  }
  writeBits(buf, bp, 0, 1);
}

int RiceCoding::Descompresion(unsigned int* entrada, unsigned int* salida, int cantidad) {
  int i;
  unsigned int bp;
  unsigned int* tmp = entrada;
  b = *tmp;
  tmp++;
  for (i = 0, bp = 0; i < cantidad; ++i) {
    salida[i] = decodificarRice(tmp, &bp, b);
  }

  int s;
  if (bp & 0x1f)
    s = (1 + (bp >> 5));
  else
    s = (bp >> 5);
  s += 1;
  return s;
}

unsigned int RiceCoding::decodificarRice(unsigned int* buf, unsigned int* bp, unsigned int bits) {
  unsigned int v;
  v = readBits(buf, bp, bits);
  while (TESTBIT(buf, *bp)) {
    v += (1 << bits);
    (*bp)++;
  }

  (*bp)++;
  return v;
}
