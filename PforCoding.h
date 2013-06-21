
#ifndef PFORCODING_H_
#define PFORCODING_H_

namespace Pfor {
	class Compresor {
	public:
		void agregar(unsigned int numero);
		BitStream* flushStream();
	};
	class Descompresor {
		void descomprimir(BitStream* stream, unsigned int integers);
	};
}


#endif /* PFORCODING_H_ */
