
typedef struct no {
	struct no* pai;
	int dados[3];
	int quantDados;
	struct no* ponteiros[4];
} NO;

class Arvore234{
	public:
		Arvore234();//metodo construtor
		bool busca(int); //Funcao destinada a busca de valores
		void inserir(int);//Funcao publica de inserir elementos
		void imprime();//imprimir elementos da arvore
		//void remover();

	private:
		NO *raiz;
		//void insere(NO**, int);
		void divide(NO**); //funcao auxilar na insersao divide NO e RAIZ.
		bool estanoNo(NO**, int); //
		bool eRaiz(NO**); //Verifica se um determinado NO e Raiz
		bool eFolha(NO**); //Verifica se um NO e folha
		NO *encontraNoFilho(NO**,int); //Encontra o filho para inserir um novo valor
		void inserirValor(NO**, int);//Funcao privada chamada pela funcao publica
		void imprime(NO*);//funcao privada imprimir arvore
		//void remover(NO**,int);
};

