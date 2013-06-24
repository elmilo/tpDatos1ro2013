#include "PforCoding.h"
using namespace std;

PforCoding::PforCoding():
  FRAC(0.1) {
  cnum[0] = 0;
  cnum[1] = 1;
  cnum[2] = 2;
  cnum[3] = 3;
  cnum[4] = 4;
  cnum[5] = 5;
  cnum[6] = 6;
  cnum[7] = 7;
  cnum[8] = 8;
  cnum[9] = 9;
  cnum[10] = 10;
  cnum[11] = 11;
  cnum[12] = 12;
  cnum[13] = 13;
  cnum[14] = 16;
  cnum[15] = 20;
  cnum[16] = 32;

  block_size = 128;
}

void PforCoding::setTamanioBloque(int tamanio) {
  // PForDelta puede usar los siguientes tamaños de bloque:
  if (tamanio < 64)
    block_size = 32;
  else if (tamanio < 128)
    block_size = 64;
  else if (tamanio < 256)
    block_size = 128;
  else
    block_size = 256;
}

int PforCoding::Compresion(unsigned int* entrada, unsigned int* salida, int cantidad) {
  int flag = -1;
  unsigned int* w;
  for (int k = 0; flag < 0; k++) {
    w = salida + 1;
    flag = codificarPFOR(&w, entrada, k);
  }

  *salida = flag;
  return w - salida;
}

int PforCoding::codificarPFOR(unsigned int** w, unsigned int* p, int num) {
  int i, l, n, bb, t, s;
  unsigned int m;
  int b = cnum[num + 2];
  int start;

  unsigned int out[block_size];
  unsigned int ex[block_size];

  if (b == 32) {
    for (i = 0; i < block_size; i++) {
      (*w)[i] = p[i];
    }
    *w += block_size;
    return ((num << 12) + (2 << 10) + block_size);
  }

  // Encontrar el mayor número de los que se comprimen
  for (m = 0, i = 0; i < block_size; i++) {
    if (p[i] > m)
      m = p[i];
  }

  if (m < 256) {
    bb = 8;
    t = 0;
  } else if (m < 65536) {
    bb = 16;
    t = 1;
  } else {
    bb = 32;
    t = 2;
  }

  for (start = 0, n = 0, l = -1, i = 0; i < block_size; i++) {
    if ((p[i] >= static_cast<unsigned> (1 << b)) || ((l >= 0) && (i - l == (1 << b)))) {
      if (l < 0)
        start = i;
      else
        out[l] = i - l - 1;

      ex[n++] = p[i];
      l = i;
    } else {
      out[i] = p[i];
    }
  }

  if (l >= 0)
    out[l] = (1 << b) - 1;
  else
    start = block_size;

  if (static_cast<double> (n) <= FRAC * static_cast<double> (block_size)) {
    s = ((b * block_size) >> 5);
    for (i = 0; i < s; i++) {
      (*w)[i] = 0;
    }
    pack(out, b, block_size, *w);
    *w += s;

    s = ((bb * n) >> 5) + ((((bb * n) & 31) > 0) ? 1 : 0);
    for (i = 0; i < s; i++) {
      (*w)[i] = 0;
    }
    pack(ex, bb, n, *w);
    *w += s;
    return ((num << 12) + (t << 10) + start);
  }

  return -1;
}

int PforCoding::Descompresion(unsigned int* entrada, unsigned int* salida, int cantidad) {
  unsigned int* tmp = entrada;
  int flag = *tmp;
  b = cnum[((flag >> 12) & 15) + 2];
  unpack_count = ((flag >> 12) & 15) + 2;
  t = (flag >> 10) & 3;
  start = flag & 1023;

  tmp++;
  tmp = decodificarPFOR(salida, tmp, flag);
  return tmp - entrada;
}

unsigned* PforCoding::decodificarPFOR(unsigned int* _p, unsigned int* _w, int flag) {
  int i, s;
  unsigned int x;
  (unpack[unpack_count])(_p, _w, block_size);
  _w += ((b * block_size) >> 5);

  switch (t) {
    case 0:
      for (s = start, i = 0; s < block_size; i++) {
        x = _p[s] + 1;
        _p[s] = (_w[i >> 2] >> (24 - ((i & 3) << 3))) & 255;
        s += x;
      }
      _w += (i >> 2);

      if ((i & 3) > 0)
        _w++;
      break;

    case 1:
      for (s = start, i = 0; s < block_size; i++) {
        x = _p[s] + 1;
        _p[s] = (_w[i >> 1] >> (16 - ((i & 1) << 4))) & 65535;
        s += x;
      }
      _w += (i >> 1);
      if ((i & 1) > 0)
        _w++;
      break;

    case 2:
      for (s = start, i = 0; s < block_size; i++) {
        x = _p[s] + 1;
        _p[s] = _w[i];
        s += x;
      }
      _w += i;
      break;
  }
  return _w;
}
