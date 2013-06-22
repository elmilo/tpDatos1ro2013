#ifndef NULL_CODING_H_
#define NULL_CODING_H_

#include "coding.cpp"

class NullCoding : public coding {

public:
  int Compresion(unsigned int* entrada, unsigned int* salida, int cantidad);
  int Descompresion(unsigned int* entrada, unsigned int* salida, int cantidad);
  void setTamanioBloque(int tamanio);

private:
  int block_size;

};

#endif /* NULL_CODING_H_ */
