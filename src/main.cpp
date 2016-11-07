/********************************************************************
    * Implementação Arvore 2-3-4 em C++ Insercao, Busca e Remocao   *
    * Estrutura de dados e Algoritmos III                           *
    * Professor: Antonio Ramos de Carvalho Junior                   *
    * FUCAPI - 07/11/2016 - Manaus-AM                               *
    *                                                               *
    * Team: Giovane Menezes - Engenharia de Computacao              *
    *       David Camurça  - Engenharia de Software                 *
*********************************************************************/

#include <iostream>
#include "arvore234.h"
#include <stdlib.h>

using namespace std;

int main() {

	//Isso é uma Instancia da classe
	Arvore234 arvore234 = Arvore234();


	//Inserindo valores na Árvore
	for(int i=1;i<5;i++){
		arvore234.inserir(i);
	}
	arvore234.remover(2);
	arvore234.imprime();

	cout << "Arvore construida" << endl;

	if(arvore234.buscaValor(54678))
		cout << "Encontrou!!" << endl;
	else
		cout << "Tenta outro!" << endl;
	return 0;
}
