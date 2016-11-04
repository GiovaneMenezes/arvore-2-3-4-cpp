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
	arvore234.inserir(40);
	arvore234.inserir(25);
	arvore234.inserir(60);
	arvore234.inserir(100);
	arvore234.inserir(95);
	arvore234.inserir(77);
	
	arvore234.imprime();
	
	if(arvore234.busca(100))
		cout << "Encontrou!!" << endl;
	else
		cout << "Tenta outro!" << endl;
	return 0;
}
