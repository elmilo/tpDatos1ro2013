
#ifndef RICECODING_H_
#define RICECODING_H_

namespace Rice {
	class Codificador {
	public:
		void codificar(unsigned int integer);
		BitStream* flushStream();
	};
	class Decodificador {
		void appendBit();
		bool codigoDescifrado();
		unsigned int decodificar(BitStream* stream);
		unsigned int decodificar(BitStream* stream, unsigned int integers);
	};
}


#endif /* RICECODING_H_ */
