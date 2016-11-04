#include <iostream>
#include "arvore234.h"

using namespace std;

int main() {

	//Isso é uma Instancia da classe
	Arvore234 arvore234 = Arvore234();


	//Inserindo valores na Árvore
	arvore234.inserir(10);
	arvore234.inserir(30);
	arvore234.inserir(50);
	
	
	return 0;
}
