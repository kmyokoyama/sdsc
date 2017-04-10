#ifndef _DEQUE_ITERADOR_H_
#define _DEQUE_ITERADOR_H_

#include <deque.h>

DEQUE_ITERADOR cria_deque_iterador(DEQUE *deque);
void avanca_deque_iterador(DEQUE_ITERADOR *it);
DEQUE_DADO deque_le_dado(DEQUE_ITERADOR *it);

#endif //_DEQUE_ITERADOR_H_
