typedef struct NO* Arv_AVL;

int alt_no(struct NO* no);
int balanceamento_NO(struct NO* no);
int maior(int x, int y);

void RotacaoLL(Arv_AVL* raiz);
void RotacaoRR(Arv_AVL* raiz);
void RotacaoLR(Arv_AVL* raiz);
void RotacaoRL(Arv_AVL* raiz);

int insereArvAVL(Arv_AVL* raiz, int valor);
int removeArvAVL(Arv_AVL* raiz, int valor);

struct NO* buscarMenor(struct NO* atual);

void imprimir(NO* raiz);