#include <iostream>
#include "arvore234.h"
#include <stdlib.h>

using namespace std;

int main() {

	//Isso é uma Instancia da classe
	Arvore234 arvore234 = Arvore234();


	//Inserindo valores na Árvore
	for(int i=1;i<=10;i++){
		arvore234.inserir(i);
	}
	arvore234.remover(2);
	arvore234.imprime();
	
	/*if(arvore234.busca(77))
		cout << "Encontrou!!" << endl;
	else
		cout << "Tenta outro!" << endl;*/
	return 0;
}
