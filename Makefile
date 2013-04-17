OBJ = main.o Diccionario.o Documento.o Indexador.o Loader.o Termino.o
CXXFLAGS = -fmessage-length=0 -Wall
CXXDEBUG = -O0 -g3
#CXXRELEASE = -03
NAME = agat

all: debug

debug: CXXFLAGS += $(CXXDEBUG)
debug: $(NAME)

release: CXXFLAGS += $(CXXRELEASE)
release: $(NAME)

agat: $(OBJ)
	#g++ -o $(NAME) $(OBJ)

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp
	
Indexador.o: Indexador.h Indexador.cpp Parser.h Diccionario.h
	g++ $(CXXFLAGS) -c Indexador.cpp

Diccionario.o: Diccionario.h Diccionario.cpp Termino.h
	g++ $(CXXFLAGS) -c Diccionario.cpp
	
Loader.o: Loader.h Loader.cpp
	g++ $(CXXFLAGS) -c Loader.cpp

Documento.o: Documento.h Documento.cpp 
	g++ $(CXXFLAGS) -c Documento.cpp

Parser.o: Parser.cpp Parser.h common.h
	g++ $(CXXFLAGS) -c Parser.cpp

Termino.o: Termino.cpp Termino.h common.h
	g++ $(CXXFLAGS) -c Termino.cpp

clean:
	rm $(OBJ) $(NAME)

.PHONY = clean
