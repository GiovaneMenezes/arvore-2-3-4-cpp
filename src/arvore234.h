
typedef struct no {
	struct no* pai;
	int dados[3];
	int quantDados;
	struct no* ponteiros[4];
} NO;

class Arvore234{
	public:
		Arvore234();
		void inserir(int);//**
		void imprime();
		void remover(int);
		bool buscaValor(int);
		//void imprimir();
	private:
		NO *raiz;
		NO *busca(int); //**
		void insere(NO**, int); //**
		void divide(NO**); //**
		bool estanoNo(NO**, int); //**
		bool eRaiz(NO**); //**
		bool eFolha(NO**); //**
		NO *encontraNoFilho(NO**,int); //**
		void inserirValor(NO**, int);//**
		void imprime(NO*);
		void bubblesort(NO**);
		NO *encontraSucessor(NO*, int);
		bool rotar(NO*);
		void exclui(NO*, int);
};
