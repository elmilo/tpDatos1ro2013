OBJ = main.o Diccionario.o ListadorDeArchivos.o Parser.o PosicionesPorDocumento.o
CXXFLAGS = -fmessage-length=0 -Wall
CXXDEBUG = -O0 -g3
CXXRELEASE = -O3

all: debug

debug: CXX += $(CXXDEBUG)
debug: Indexador

release: CXX += $(CXXRELEASE)
release: Indexador

Indexador: main.o Diccionario.o ListadorDeArchivos.o Parser.o PosicionesPorDocumento.o
	g++ -o Indexador $(OBJ)

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp

Diccionario.o: Diccionario.h Diccionario.cpp PosicionesPorDocumento.h
	g++ $(CXXFLAGS) -c Diccionario.cpp

ListadorDeArchivos.o: ListadorDeArchivos.cpp ListadorDeArchivos.h
	g++ $(CXXFLAGS) -c ListadorDeArchivos.cpp

Parser.o: Parser.cpp Parser.h common.h
	g++ $(CXXFLAGS) -c Parser.cpp

PosicionesPorDocumento.o: PosicionesPorDocumento.cpp PosicionesPorDocumento.h common.h
	g++ $(CXXFLAGS) -c PosicionesPorDocumento.cpp

clean:
	rm $(OBJ) Indexador

.PHONY = clean