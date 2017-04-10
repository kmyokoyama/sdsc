#include <stdlib.h>
#include <deque_iterador.h>

DEQUE_ITERADOR cria_deque_iterador(DEQUE *deque) {
    DEQUE_ITERADOR it;

    it.nodo = deque->comeco;
    it.posicao = 0;

    if(it.nodo == NULL)
        it.tem_proximo = 0;
    else
        it.tem_proximo = 1;

    return it;
}

void avanca_deque_iterador(DEQUE_ITERADOR *it) {
    it->nodo = it->nodo->proximo;

    if(it->nodo == NULL)
        it->tem_proximo = 0;
    else
        it->tem_proximo = 1;
}

DEQUE_DADO deque_le_dado(DEQUE_ITERADOR *it) {
    DEQUE_DADO dado = it->nodo->dado;

    avanca_deque_iterador(it);

    return(dado);
}
