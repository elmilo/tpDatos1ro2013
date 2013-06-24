#include <iostream>
#include <iomanip>
#include "PforCoding.h"
#include "RiceCoding.h"
//#include "NullCoding.h"

//Determina el tamaño del buffer de salida para comprimir
//Solamente se dobla el tamaño, se podria usar uno más compacto
#define LimiteSuperiorBufferSalidaComprimido(buffer_size) ((buffer_size) << 1)

// Imprimir unsigned en formato binario, con espacio separando cada byte
void ImprimirBinario(unsigned int num) {
  int arr[32];
  int i = 0;
  while (i++ < 32 || num / 2 != 0) {
    arr[i - 1] = num % 2;
    num /= 2;
  }

  for (int i = 31; i >= 0; i--) {
    std::cout << arr[i];
    if (i % 8 == 0)
      std::cout <<" ";
  }
}


int main(int argc, char **argv){

    const int tamanio = 32; //<- debe ser multiplo de 32
    /*unsigned entrada[tamanio] = {33, 5, 2, 1,
                            36, 5, 63, 25,
                            99, 3, 41, 68,
                            85, 50, 88, 156,
                            12, 120, 65, 74,
                            33, 132, 9, 512,
                            12, 68, 8, 668,
                            88, 68, 5, 1024};*/
    
    unsigned entrada[tamanio] = {2, 3,7,14,
                            26, 32, 41, 43,
                            45, 49, 56, 71,
                            85, 86, 88, 96,
                            102, 111, 118, 128,
                            156, 158, 199, 201,
                            203, 205, 224, 236,
                            237, 246, 248, 255};
                            

    /*unsigned entrada[tamanio] = {17, 1023, 17, 17,
                            17, 17, 17, 17,
                            17, 17, 17, 17,
                            17, 17, 1023, 17,
                            17, 17, 17, 17,
                            17, 17, 17, 17,
                            17, 17, 17, 17,
                            17, 17, 17, 17};*/

    RiceCoding coder;
    coder.setTamanioBloque(32);
    
    //coder.Compresion(&entrada[0], pSalida, cantidad);
    
 
    /*for (unsigned i=0; i < cantidad; i++)
        std::cout << salida[i] << std::endl;*/

/****************************************************************************/
/****************************************************************************/
    std::cout << "Comprimiendo el siguiente array (izquierda a derecha):" << std::endl;
    for (int i = 0; i < tamanio; i += 4) {
        std::cout << entrada[i] << "   " << entrada[i + 1];
        std::cout << "   " << entrada[i + 2] << "   " << entrada[i + 3];
        if (i < tamanio - 4)
            std::cout << ",";
        std::cout << std::endl;
    }
    
    
    unsigned tamanioSalida = LimiteSuperiorBufferSalidaComprimido(tamanio);
    
    unsigned int salidaComprimida[tamanioSalida];
    int cantidadPalabrasComprimidas = coder.Compresion(entrada, salidaComprimida, tamanio);
    
    std::cout << "Comprimido en " <<  cantidadPalabrasComprimidas << " palabras, con el siguiente contenido: " << std::endl;
    for (int i = 0; i < cantidadPalabrasComprimidas; ++i) {
        std::cout << std::setw(12)  << std::left << salidaComprimida[i];
        ImprimirBinario(salidaComprimida[i]);
        std::cout << std::endl;
    }
/****************************************************************************/
/****************************************************************************/
    unsigned int salidaDescomprimida[tamanio];
    int cantidadPalabrasDescomprimidas = coder.Descompresion(salidaComprimida, salidaDescomprimida, tamanio);

    std::cout << "Descomprimidas " <<  cantidadPalabrasDescomprimidas << " palabras, con el siguiente contenido: " << std::endl;
    for (int i = 0; i < tamanio; ++i) {
        std::cout << std::setw(8) << salidaDescomprimida[i] << std::left;
        ImprimirBinario(salidaDescomprimida[i]);
        std::cout << std::endl;
    }


	return 0;
}

