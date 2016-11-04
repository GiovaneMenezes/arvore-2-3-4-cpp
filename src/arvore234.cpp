#include <iostream>
#include <stdlib.h>
#include "arvore234.h"

using namespace std;

Arvore234::Arvore234(){
	//A raiz da árvore é criada
	//o primeiro filho recebe nulo
	raiz = new NO;
	for(int i=0;i<3;i++){raiz->ponteiros[i] = 0;}
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
	inserirValor(&atual, valor);

}
 

//função divide, auxilia na inserção
void Arvore234::divide(NO **atual){
	//se for raiz
	if((*atual)->pai == 0){
		//cria novo NO B
		NO *B = new NO;
		for(int i=0;i<3;i++){B->ponteiros[i]=0;}
		B->ponteiros[1] = *atual;
		B->pai = 0;
		B->quantDados = 1;
		B->dados[0] = (*atual)->dados[1];
		
		//cria novo NO C
		NO *C = new NO;
		for(int i=0;i<3;i++){C->ponteiros[i]=0;}
		C->ponteiros[1] = *atual;
		C->pai = B;
		C->quantDados = 1;
		C->dados[0] = (*atual)->dados[2];
		if(!eFolha(atual)){
			C->ponteiros[0] = (*atual)->ponteiros[2];
			C->ponteiros[1] = (*atual)->ponteiros[3];
		}
		
		B->ponteiros[0] = *atual;
		B->ponteiros[1] = C;
		(*atual)->pai = B;
		(*atual)->quantDados = 1;
		raiz = B; //raiz atributo da classe		
	}
	//se n�o � raiz
	else{
		NO *paiNo = (*atual)->pai;
		//envia B para o pai do atual
		paiNo->dados[paiNo->quantDados++] = (*atual)->dados[1];
		
		//cria novo NO C
		NO *C = new NO;
		for(int i=0;i<3;i++){C->ponteiros[i]=0;}
		C->ponteiros[1] = *atual;
		C->pai = paiNo;
		C->quantDados = 1;
		C->dados[0] = (*atual)->dados[2];
		if(!eFolha(atual)){
			C->ponteiros[0] = (*atual)->ponteiros[2];
			C->ponteiros[1] = (*atual)->ponteiros[3];
		}
		
		paiNo->ponteiros[paiNo->quantDados] = C; 
		(*atual)->quantDados = 1;
	}
}

void Arvore234::inserirValor(NO **atual, int valor){
	int quant = (*atual)->quantDados;
	int pos = quant;
	for(int i=0;i<quant;i++){
		if(valor<(*atual)->dados[i]){
			pos = i;
			break;	
		}
	}
	for(int j=quant;j>pos;j--){
		(*atual)->dados[j+1] = (*atual)->dados[j];
	}
	(*atual)->dados[pos] = valor;
	(*atual)->quantDados++;
}

