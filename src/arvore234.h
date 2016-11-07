/********************************************************************
    * Implementação Arvore 2-3-4 em C++ Insercao, Busca e Remocao   *
    * Estrutura de dados e Algoritmos III                           *
    * Professor: Antônio Ramos de Carvalho Junior                   *
    * FUCAPI - 07/11/2016 - Manaus-AM                               *
    *                                                               *
    * Team: Giovane Menezes - Engenharia de Computacao              *
    *       David Camurça  - Engenharia de Software                 *
*********************************************************************/

//Estrutura da Arvore 2-3-4
typedef struct no {
	struct no* pai;
	int dados[3];
	int quantDados;
	struct no* ponteiros[4];
} NO;


//Classe da Arvore 2-3-4
class Arvore234{
	public:
		Arvore234();
		void inserir(int);
		void imprime();
		void remover(int);
		bool buscaValor(int);

	private:
		NO *raiz;
		NO *busca(int);
		void insere(NO**, int);
		void divide(NO**);
		bool estanoNo(NO**, int);
		bool eRaiz(NO**);
		bool eFolha(NO**);
		NO *encontraNoFilho(NO**,int);
		void inserirValor(NO**, int);
		void imprime(NO*);
		void bubblesort(NO**);
		NO *encontraSucessor(NO*, int);
		bool rotar(NO*);
		void exclui(NO*, int);
};
