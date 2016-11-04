
typedef struct no {
	struct no* pai;
	int dados[3];
	int quantDados;
	struct no* ponteiros[4];
} NO;

class Arvore234{
	public:
		Arvore234();
		bool busca(int); //**
		void inserir(int);//**
		//void remover();
		//void imprimir();
	private:
		NO *raiz;
		void insere(NO**, int); //**
		void divide(NO**); //**
		bool estanoNo(NO**, int); //**
		bool eRaiz(NO**); //**
		bool eFolha(NO**); //**
		NO *encontraNoFilho(NO**,int); //**
		void inserirValor(NO**, int);//**
};

