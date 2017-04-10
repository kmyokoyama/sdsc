#include <stdio.h>
#include <lists.h>

int main(int argc, char **argv) {
    DEQUE *deque;

    deque = deque_cria();

    deque_adiciona_comeco(deque, "Voce");
    deque_adiciona_fim(deque, "eh");
    deque_adiciona_fim(deque, "bem");
    deque_adiciona_indice(deque, 3, "legal");
    deque_adiciona_indice(deque, 1, "nao");

    DEQUE *novo_deque = deque_copia(deque);

    while(deque->tamanho != 0) {
        printf("%s\n", deque_remove_comeco(deque));
    }

    deque_destroi(&deque);

    if(deque == NULL) {
        printf("Deque foi destruido.\n");
    }

    deque_adiciona_indice(novo_deque, 2, "legal");
    deque_adiciona_fim(novo_deque, "Voce");

    deque_remove_duplicados(novo_deque);

    deque_troca_dados(novo_deque, 0, 4);

    deque_reverte(novo_deque);

    DEQUE_ITERADOR it = cria_deque_iterador(novo_deque);
    while(it.tem_proximo) {
        printf("%s\n", deque_le_dado(&it));
    }

    deque_destroi(&novo_deque);

    return 0;
}
