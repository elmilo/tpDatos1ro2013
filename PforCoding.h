#ifndef PFORCODING_H_
#define PFORCODING_H_

#include "coding.cpp"

class PforCoding : public coding {

public:
	PforCoding();
	
	int Compresion (unsigned int* entrada, unsigned int* salida, int tamanio);
	
	int Descompresion(unsigned int* entrada, unsigned int* salida, int tamanio);
  
	void setTamanioBloque (int tamanio); //Por defecto es 128

private:
  int codificarPFOR(unsigned int** w, unsigned int* p, int num);
  unsigned* decodificarPFOR(unsigned int* _p, unsigned int* _w, int flag);

  int block_size; //En bits, solo 32, 64, 128 o 256

  float FRAC;  // Porcentaje de excepciones del PFOR
  int cnum[17];

  int b;
  int start;
  int t;
  int unpack_count;
};

#endif /* PFORCODING_H_ */
