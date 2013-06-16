
#ifndef RICECODING_H_
#define RICECODING_H_

namespace Rice {
	BitStream codificar(unsigned int integer);
	class Decodificador {
		void appendBit();
		bool codigoDescifrado();
		unsigned int decodificar(BitStream stream);
	};
}


#endif /* RICECODING_H_ */
