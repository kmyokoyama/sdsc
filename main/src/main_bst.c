#include <stdio.h>
#include <trees.h>

int main(int argc, char **argv) {
    BST_NODO *raiz;

    bst_inicializa(&raiz);

    raiz = bst_insere(raiz, 2);
    raiz = bst_insere(raiz, 1);
    raiz = bst_insere(raiz, 3);
    raiz = bst_insere(raiz, 4);
    raiz = bst_insere(raiz, 5);

    printf("Numero de nodos: %d\n", bst_contagem(raiz));
    printf("Profundidade: %d\n", bst_profundidade(raiz));
    printf("Altura: %d\n", bst_altura(raiz));
    printf("Minimo: %d\n", bst_minimo(raiz));
    printf("Maximo: %d\n", bst_maximo(raiz));

    bst_imprime(raiz);

    bst_destroi(raiz);

    return 0;
}
