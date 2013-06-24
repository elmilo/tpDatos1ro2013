#ifndef NULLCODING_H_
#define NULLCODING_H_

#include "coding.cpp"

class NullCoding : public coding {

public:
  int Compresion(unsigned int* entrada, unsigned int* salida, int cantidad);
  int Descompresion(unsigned int* entrada, unsigned int* salida, int cantidad);
  void setTamanioBloque(int tamanio);

private:
  int block_size;

};

#endif /* NULLCODING_H_ */
