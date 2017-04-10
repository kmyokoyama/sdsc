#include <stdlib.h>
#include <deque.h>

DEQUE *deque_cria() {
    DEQUE *deque;

    deque = (DEQUE *) malloc(sizeof(DEQUE));

    deque->comeco = NULL;
    deque->fim = NULL;
    deque->tamanho = 0;

    return(deque);
}

void deque_adiciona_comeco(DEQUE *deque, DEQUE_DADO dado) {
    DEQUE_NODO *novo_nodo;

    novo_nodo = (DEQUE_NODO *) malloc(sizeof(DEQUE_NODO));

    novo_nodo->dado = dado;
    novo_nodo->anterior = NULL;
    novo_nodo->proximo = deque->comeco;

    if(deque->tamanho == 0) {
        deque->fim = novo_nodo;
    }
    else {
        deque->comeco->anterior = novo_nodo;
    }

    deque->comeco = novo_nodo;

    deque->tamanho++;
}

DEQUE_DADO deque_remove_comeco(DEQUE *deque) {
    if(deque->tamanho == 0) {
        return NULL;
    }

    DEQUE_NODO *primeiro = deque->comeco;
    DEQUE_DADO dado = primeiro->dado;

    deque->comeco = primeiro->proximo;

    if(deque->comeco == NULL) {
        deque->fim = NULL;
    }
    else {
        deque->comeco->anterior = NULL;
    }

    free(primeiro);
    deque->tamanho--;

    return(dado);
}

void deque_adiciona_fim(DEQUE *deque, DEQUE_DADO dado) {
    DEQUE_NODO *novo_nodo;

    novo_nodo = (DEQUE_NODO *) malloc(sizeof(DEQUE_NODO));

    novo_nodo->dado = dado;
    novo_nodo->anterior = deque->fim;
    novo_nodo->proximo = NULL;

    if(deque->tamanho == 0) {
        deque->comeco = novo_nodo;
    }
    else {
        deque->fim->proximo = novo_nodo;
    }

    deque->fim = novo_nodo;

    deque->tamanho++;
}

DEQUE_DADO deque_remove_fim(DEQUE *deque) {
    if(deque->tamanho == 0) {
        return NULL;
    }

    DEQUE_NODO *ultimo = deque->fim;
    DEQUE_DADO dado = ultimo->dado;

    deque->fim = ultimo->anterior;

    if(deque->fim == NULL) {
        deque->comeco = NULL;
    }
    else {
        deque->fim->proximo = NULL;
    }

    free(ultimo);
    deque->tamanho--;

    return(dado);
}

void deque_adiciona_indice(DEQUE *deque, int indice, DEQUE_DADO dado) {
    if((indice < 0) || (indice > deque->tamanho)) {
        return;
    }

    if(indice == 0) {
        deque_adiciona_comeco(deque, dado);
        return;
    }
    if(indice == deque->tamanho) {
        deque_adiciona_fim(deque, dado);
        return;
    }

    DEQUE_NODO *atual = deque->comeco;
    
    int i = 0;
    for(i = 0; i < indice-1; i++) {
        atual = atual->proximo;
    }

    DEQUE_NODO *novo_nodo;
    novo_nodo = (DEQUE_NODO *) malloc(sizeof(DEQUE_NODO));

    novo_nodo->dado = dado;
    novo_nodo->anterior = atual;
    novo_nodo->proximo = atual->proximo;
    atual->proximo->anterior = novo_nodo;
    atual->proximo = novo_nodo;

    deque->tamanho++;
}

DEQUE_DADO deque_remove_indice(DEQUE *deque, int indice) {
    if(deque->tamanho == 0) {
        return NULL;
    }

    if((indice < 0) || (indice > deque->tamanho)) {
        return NULL;
    }

    if(indice == 0) {
        deque_remove_comeco(deque);
        return NULL;
    }
    if(indice == deque->tamanho) {
        deque_remove_fim(deque);
        return NULL;
    }

    DEQUE_NODO *atual = deque->comeco;

    int i = 0;
    for(i = 0; i < indice; i++) {
        atual = atual->proximo;
    }

    DEQUE_DADO dado = atual->dado;

    atual->anterior->proximo = atual->proximo;
    atual->proximo->anterior = atual->anterior;

    free(atual);

    deque->tamanho--;

    return(dado);
}

DEQUE *deque_copia(DEQUE *deque_origem) {
    DEQUE *deque_destino;
    deque_destino = deque_cria();

    DEQUE_NODO *atual;

    for(atual = deque_origem->comeco;
        atual != NULL;
        atual = atual->proximo) {
        DEQUE_DADO dado_atual = atual->dado;
        deque_adiciona_fim(deque_destino, dado_atual);
    }

    return(deque_destino);
}

int deque_contagem(DEQUE *deque) {
    return deque->tamanho;
}

int deque_indice_primeiro(DEQUE *deque, DEQUE_DADO dado) {
    DEQUE_NODO *atual = deque->comeco;
    int i = 0;

    while(atual != NULL) {
        if(atual->dado == dado) {
            return i;
        }
        atual = atual->proximo;
        i++;
    }

    return -1;
}

void deque_remove_duplicados(DEQUE *deque) {
    DEQUE_NODO *atual = deque->fim;
    int i = deque->tamanho - 1;

    while(atual != NULL) {
        int primeiro;
        while((primeiro = deque_indice_primeiro(deque, atual->dado)) != i) {
            deque_remove_indice(deque, primeiro);
            i--;
        }

        atual = atual->anterior;
        i--;
    }
}

void deque_troca_dados(DEQUE *deque, int indice_origem, int indice_destino) {
    if(indice_origem >= deque->tamanho ||
       indice_destino >= deque->tamanho) {
        return;
    }

    DEQUE_NODO *origem = NULL;
    DEQUE_NODO *destino = NULL;
    
    DEQUE_NODO *atual = deque->comeco;
    int i = 0;
    for(i = 0; i < deque->tamanho; i++) {
        if(i == indice_origem) {
            origem = atual;
        }
        if(i == indice_destino) {
            destino = atual;
        }

        if(origem != NULL && destino != NULL)
            break;

        atual = atual->proximo;
    }

    DEQUE_DADO dado_temp = origem->dado;
    origem->dado = destino->dado;
    destino->dado = dado_temp;
}

void deque_reverte(DEQUE *deque) {
    DEQUE_NODO *atual = deque->fim;
    while(atual != NULL) {
        DEQUE_NODO *anterior_temp = atual->anterior;
        atual->anterior = atual->proximo;
        atual->proximo = anterior_temp;
        
        atual = atual->proximo;
    }

    DEQUE_NODO *comeco_temp = deque->comeco;
    deque->comeco = deque->fim;
    deque->fim = comeco_temp;
}

void deque_destroi(DEQUE **ref_deque) {
    if((*ref_deque)->tamanho == 0) {
        free(*ref_deque);
        *ref_deque = NULL;

        return;
    }

    DEQUE_NODO *atual;
    atual = (*ref_deque)->comeco;

    while(atual != NULL) {
        DEQUE_NODO *tmp = atual->proximo;
        free(atual);
        atual = tmp;
    }

    free(*ref_deque);
    *ref_deque = NULL;
}
