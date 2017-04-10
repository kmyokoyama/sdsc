#include <stdio.h>
#include <stdlib.h>
#include <trees.h>

void bst_inicializa(BST_NODO **ref_nodo) {
    *ref_nodo = NULL;
}

void bst_imprime_dado(BST_DADO dado) {
    printf("%d\n", dado);
}

BST_NODO *bst_cria_nodo(BST_DADO dado) {
    BST_NODO *novo_nodo = (BST_NODO *) malloc(sizeof(BST_NODO));

    novo_nodo->dado = dado;
    novo_nodo->esquerda = NULL;
    novo_nodo->direita = NULL;

    return novo_nodo;
}

BST_NODO *bst_insere(BST_NODO *nodo, BST_DADO dado) {
    if(nodo == NULL) {
        BST_NODO *novo_nodo = bst_cria_nodo(dado);

        return novo_nodo;
    }
    else {
        if(nodo->dado > dado) {
            nodo->esquerda = bst_insere(nodo->esquerda, dado);
        }
        else {
            nodo->direita = bst_insere(nodo->direita, dado);
        }

        return nodo;
    }
}

int bst_existe_dado(BST_NODO *nodo, BST_DADO dado) {
    if(nodo == NULL) {
        return 0;
    }
    else {
        if(nodo->dado == dado) {
            return 1;
        }

        if(nodo->dado > dado) {
            return bst_existe_dado(nodo->esquerda, dado);
        }
        else {
            return bst_existe_dado(nodo->direita, dado);
        }
    }
}

int bst_contagem(BST_NODO *nodo) {
    if(nodo == NULL) {
        return 0;
    }
    else {
        int contador_esquerda = bst_contagem(nodo->esquerda);
        int contador_direita  = bst_contagem(nodo->direita);

        return (contador_esquerda + contador_direita + 1);
    }
}

int bst_profundidade(BST_NODO *nodo) {
    if(nodo == NULL) {
        return 0;
    }
    else {
        int profundidade_e = bst_profundidade(nodo->esquerda);
        int profundidade_d = bst_profundidade(nodo->direita);

        return(profundidade_e > profundidade_d ? (profundidade_e + 1) : (profundidade_d + 1));
    }
} 

int bst_altura(BST_NODO *nodo) {
    return bst_profundidade(nodo) - 1;
}

BST_DADO bst_minimo(BST_NODO *nodo) {
    BST_NODO *atual = nodo;
    while(atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual->dado;
}

BST_DADO bst_maximo(BST_NODO *nodo) {
    BST_NODO *atual = nodo;
    while(atual->direita != NULL) {
        atual = atual->direita;
    }

    return atual->dado;
}

void bst_imprime(BST_NODO *nodo) {
    if(nodo == NULL) {
        return;
    }
    else {
        if(nodo->esquerda != NULL) {
            bst_imprime(nodo->esquerda);
        }
        if(nodo->direita != NULL) {
            bst_imprime(nodo->direita);
        }
        
        bst_imprime_dado(nodo->dado);
    }
}

void bst_destroi(BST_NODO *nodo) {
    if(nodo == NULL) {
        return;
    }
    else {
        if(nodo->esquerda != NULL) {
            bst_destroi(nodo->esquerda);
        }
        if(nodo->direita != NULL) {
            bst_destroi(nodo->direita);
        }

        free(nodo);
        return;
    }
}
