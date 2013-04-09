#include "parser.cpp"


#include <iostream>

int main(int argc, char **argv)
{
    parser unParser("arch_entrada.txt");
    unParser.listado(60);
	return 0;
}

