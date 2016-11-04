#include <iostream>
#include <stdlib.h>
#include "arvore234.h"

using namespace std;

Arvore234::Arvore234(){
	//A raiz da árvore é criada
	//o primeiro filho recebe nulo
	raiz = new NO;
	raiz->ponteiros[0] = 0;
	raiz->quantDados = 0;
	raiz->pai = 0;
}


bool Arvore234::eRaiz(NO **atual){ //**
	if((*atual)->pai == 0)
		return true;
	else
		return false;
}

bool Arvore234::eFolha(NO **atual){ //**
	if((*atual)->ponteiros[0] == 0)
		return true;
	else
		return false;
}

//Função Auxiliar de Busca
bool Arvore234::estanoNo(NO **atual, int valor){ //**
	int quant = (*atual)->quantDados;
	for(int i=0;i<=quant-1;i++){
		if((*atual)->dados[i] == valor)
			return true;
	}
	return false;	
}

//Função utilizada tanto na função de Busca e Insersão
//Essa função retorna o filho do no atual, onde deve esta
//o valor

NO* Arvore234::encontraNoFilho(NO **atual, int valor){ //**
	int quant = (*atual)->quantDados;
	if(eFolha(atual))//se for folhar nao tem filhos posiveis retorna 0
		return 0;
	else{//senão buscar posição do possivel filho 
		for(int i=0;i<=quant-1;i++){
			if((*atual)->dados[i] > valor){
				return (*atual)->ponteiros[i];	
			}
		}
		return (*atual)->ponteiros[quant];
	}
}

//busca um determinado valor na arvore
bool Arvore234::busca(int valor){ //**
	NO *atual = raiz;
	while(atual!=0){
		if(estanoNo(&atual, valor)){
			return true;
		}
		else{
			atual = encontraNoFilho(&atual, valor);
		}
	}
	return false;
}

//inserir 

void Arvore234::inserir(int valor){
	NO *atual = raiz;
	while(1){
		if (atual->quantDados == 3){
			divide(&atual);//caso o No esteja cheio, iremos dividir
			atual = atual->pai;
			atual = encontraNoFilho(&atual, valor); //busca o filho onde será inserido
		}
		else if(eFolha(&atual)){
			break;//se for folha, interrompe a busca pela posicao
			
		}else{
			atual = encontraNoFilho(&atual, valor);//caso nao seja necessario dividir, buscar o filho onde sera inserido

		}

	}
	//após a busca por filho insere o valor na posicao encontrada/atual;
	insereValor(&atual, valor);

}
 

//função divide, auxilia na inserção
void Arvore234:divide(NO **atual){

	
}



