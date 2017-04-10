#ifndef _TREES_H_
#define _TREES_H_

typedef int BST_DADO;

typedef struct bst_nodo {
    BST_DADO dado;
    struct bst_nodo *esquerda;
    struct bst_nodo *direita;
} BST_NODO;

void bst_inicializa(BST_NODO **ref_nodo);
void bst_imprime_dado(BST_DADO dado);
BST_NODO *bst_cria_nodo(BST_DADO dado);
BST_NODO *bst_insere(BST_NODO *nodo, BST_DADO dado);
int bst_existe_dado(BST_NODO *nodo, BST_DADO dado);
int bst_contagem(BST_NODO *nodo);
int bst_profundidade(BST_NODO *nodo);
int bst_altura(BST_NODO *nodo);
BST_DADO bst_minimo(BST_NODO *nodo);
BST_DADO bst_maximo(BST_NODO *nodo);
void bst_imprime(BST_NODO *nodo);
void bst_destroi(BST_NODO *nodo);

#endif //_TREES_H_
