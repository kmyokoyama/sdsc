#ifndef _DEQUE_H_
#define _DEQUE_H_

typedef char* DEQUE_DADO;

typedef struct deque_nodo {
    DEQUE_DADO dado;
    struct deque_nodo *proximo;
    struct deque_nodo *anterior;
} DEQUE_NODO;

typedef struct deque {
    DEQUE_NODO *comeco;
    DEQUE_NODO *fim;
    int tamanho;
} DEQUE;

typedef struct iterador_deque {
    DEQUE_NODO *nodo;
    int posicao;
    int tem_proximo;
} DEQUE_ITERADOR;

DEQUE *deque_cria(); 
void deque_adiciona_comeco(DEQUE *deque, DEQUE_DADO dado);
DEQUE_DADO deque_remove_comeco(DEQUE *deque);
void deque_adiciona_fim(DEQUE *deque, DEQUE_DADO dado);
DEQUE_DADO deque_remove_fim(DEQUE *deque);
void deque_adiciona_indice(DEQUE *deque, int indice, DEQUE_DADO dado);
DEQUE_DADO deque_remove_indice(DEQUE *deque, int indice);
DEQUE *deque_copia(DEQUE *deque_origem);
int deque_contagem(DEQUE *deque);
int deque_indice_primeiro(DEQUE *deque, DEQUE_DADO dado);
void deque_remove_duplicados(DEQUE *deque);
void deque_troca_dados(DEQUE *deque, int indice_origem, int indice_destino);
void deque_reverte(DEQUE *deque);
void deque_destroi(DEQUE **ref_deque);

#endif //_DEQUE_H_
