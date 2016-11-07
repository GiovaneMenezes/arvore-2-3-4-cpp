#include <iostream>
#include <stdlib.h>
#include "arvore234.h"

using namespace std;

Arvore234::Arvore234(){
	//A raiz da árvore é criada
	//o primeiro filho recebe nulo
	raiz = new NO;
	for(int i=0;i<4;i++){raiz->ponteiros[i] = 0;}
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

//funcao auxiliar da busca
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
NO* Arvore234::busca(int valor){ //**
	NO *atual = raiz;
	while(atual!=0){
		if(estanoNo(&atual, valor)){
			return atual;
		}
		else{
			atual = encontraNoFilho(&atual, valor);
		}
	}
	return 0;
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
		for(int i=0;i<4;i++){B->ponteiros[i]=0;}
		B->ponteiros[1] = *atual;
		B->pai = 0;
		B->quantDados = 1;
		B->dados[0] = (*atual)->dados[1];
		
		//cria novo NO C
		NO *C = new NO;
		for(int i=0;i<4;i++){C->ponteiros[i]=0;}
		C->ponteiros[1] = *atual;
		C->pai = B;
		C->quantDados = 1;
		C->dados[0] = (*atual)->dados[2];
		if(!eFolha(atual)){
			C->ponteiros[0] = (*atual)->ponteiros[2];
			((*atual)->ponteiros[2])->pai = C;
			C->ponteiros[1] = (*atual)->ponteiros[3];
			((*atual)->ponteiros[3])->pai = C;
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
			((*atual)->ponteiros[2])->pai = C;
			C->ponteiros[1] = (*atual)->ponteiros[3];
			((*atual)->ponteiros[3])->pai = C;
		}
		
		paiNo->ponteiros[paiNo->quantDados] = C; 
		(*atual)->quantDados = 1;
	}
	bubblesort(&(*atual)->pai);
}

void Arvore234::inserirValor(NO **atual, int valor){
	int quant = (*atual)->quantDados;
	(*atual)->dados[quant] = valor;
	(*atual)->quantDados++;
	bubblesort(atual);
}

void Arvore234::bubblesort(NO **atual){
	int quant = (*atual)->quantDados;
	int temp;
	for(int i=0;i<quant;i++){
		for(int j=i+1;j<quant;j++){
			if((*atual)->dados[i]>(*atual)->dados[j]){
				temp = (*atual)->dados[i];
				(*atual)->dados[i] = (*atual)->dados[j];
				(*atual)->dados[j] = temp;
			}
		}
	}
	//se o no nao for folha, realiza um bubblesort para ordenar os ponteiros do no.
	if(!eFolha(atual)){
		NO *temp_no;
		for(int i=0;i<=quant;i++){
			for(int j=i+1;j<=quant;j++){
				if(((*atual)->ponteiros[i])->dados[0]>((*atual)->ponteiros[j])->dados[0]){
					temp_no = (*atual)->ponteiros[i];
					(*atual)->ponteiros[i] = (*atual)->ponteiros[j];
					(*atual)->ponteiros[j] = temp_no;
				}
			}
		}
	}
}

NO* Arvore234::encontraSucessor(NO *atual, int valor){
	if(!eFolha(&atual)){
		for(int i=0;i<atual->quantDados;i++){
			if(atual->dados[i] == valor){
				atual = atual->ponteiros[i+1];
				break;
			}
		}
	}
	while(!eFolha(&atual)){
		atual = atual->ponteiros[0];
	}
	return atual;
}

void Arvore234::exclui(NO *atual, int valor){
	int pos;
	for(int i=0;i<atual->quantDados;i++){
		if(atual->dados[i]==valor){
			pos = i;
		}
	}
	for(int j=pos;j<atual->quantDados-1;j++){
		atual->dados[j] = atual->dados[j+1];
	}
	atual->quantDados--;
}

bool Arvore234::rotar(NO *atual){
	int posicao;
	NO *noPai = atual->pai;
	NO *noIrmao;
	if(!eRaiz(&atual)){
		for(int i=0;i<=noPai->quantDados;i++){
			if(noPai->ponteiros[i]==atual){
				posicao = i;
				break;
			}
		}
		int quantIrmao;
		if(posicao>0){
			noIrmao = noPai->ponteiros[posicao-1];
			quantIrmao = noIrmao->quantDados;
			if(noIrmao->quantDados>1){
				inserirValor(&atual, noPai->dados[posicao-1]);
				noPai->dados[posicao-1] = noIrmao->dados[quantIrmao-1];
				exclui(noIrmao, noIrmao->dados[quantIrmao-1]);
				return true;
			}				
		}
		if(posicao<noPai->quantDados){
			noIrmao = noPai->ponteiros[posicao+1];
			if(noIrmao->quantDados>1){
				inserirValor(&atual, noPai->dados[posicao]);
				noPai->dados[posicao] = noIrmao->dados[0];
				exclui(noIrmao, noIrmao->dados[0]);
				return true;
			}	
		}
	}
	return false;
}

void Arvore234::remover(int valor){
	NO *atual = busca(valor);
	NO *tempNo;
	int valorTroca;
	if(atual!=0){
		if(!eFolha(&atual)){
			for(int i=0;i<atual->quantDados;i++){
				if(atual->dados[i]==valor){
					tempNo = encontraSucessor(atual,valor);
					atual->dados[i]=tempNo->dados[0];
					valorTroca = atual->dados[i];
				}
			}
			atual = tempNo;
			exclui(atual, valorTroca);		
		}
		else{
			exclui(atual, valor);
		}
	}
	while(1){
		if(atual->quantDados!=0){
			return;
		}
		else if(rotar(atual)){
			return;
		}
		else{
			NO *noPai = atual->pai;
			if(noPai->quantDados==1){
				if(noPai->ponteiros[0]!=atual)
					inserirValor(&noPai, (noPai->ponteiros[0])->dados[0]);
				if(noPai->ponteiros[1]!=atual)
					inserirValor(&noPai, (noPai->ponteiros[1])->dados[0]);
				atual = noPai;
				//falta liberar o espa�o na memoria
				atual->ponteiros[0] = 0;
				return;
			}
			else{
				int posicao;
				NO *noIrmao;
				for(int i=0;i<=noPai->quantDados;i++){
					if(noPai->ponteiros[i]==atual){
						posicao = i;
						break;
					}
				}
				if(posicao<noPai->quantDados){
					noIrmao = noPai->ponteiros[posicao+1];
					inserirValor(&atual, noPai->dados[posicao]);
					inserirValor(&atual, noIrmao->dados[0]);
					exclui(noPai,noPai->dados[posicao]);
					//falta liberar memoria
					for(int i=posicao+1;i<noPai->quantDados+1;i++){
						noPai->ponteiros[i] = noPai->ponteiros[i+1];
					}
					return;
				}
				else{
					noIrmao = noPai->ponteiros[posicao-1];
					inserirValor(&atual, noPai->dados[posicao-1]);
					inserirValor(&atual, noIrmao->dados[0]);
					//falta liberar memoria
					noPai->ponteiros[posicao-1] = atual;
					exclui(noPai,noPai->dados[posicao-1]);
					return;
				}
			}
		}
		
		atual = atual->pai;
	}
}

void Arvore234::imprime(NO *atual){
	int quant=atual->quantDados;
	for(int i=0;i<quant;i++)
		cout << " [ "<< atual->dados[i] << " ] ";
	cout << endl;
	if(!eFolha(&atual)){
		for(int i=0;i<=quant;i++)
			imprime(atual->ponteiros[i]);
	}
}

void Arvore234::imprime(){
	imprime(raiz);
}
