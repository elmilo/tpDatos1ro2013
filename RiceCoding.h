#ifndef RICECODING_H_
#define RICECODING_H_

#include "coding.cpp"

class RiceCoding : public coding {
public:
  int Compresion(unsigned int* entrada, unsigned int* salida, int cantidad);
  int Descompresion(unsigned int* entrada, unsigned int* salida, int cantidad);
  void setTamanioBloque(int tamanio);

private:
  void codificarRice(unsigned int* buf, unsigned int* bp, unsigned int val, unsigned int bits);
  unsigned int decodificarRice(unsigned int* buf, unsigned int* bp, unsigned int bits);

  int b;
  int block_size;
};

#endif /* RICE_CODING_H_ */
