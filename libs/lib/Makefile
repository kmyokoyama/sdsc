TARGET=libsdsc.a
SRCS=linked_list.c linked_list_iterator.c stack.c queue.c deque.c bst.c load.c

FLAGS=-O2 -Wall -g -MMD
INCLUDE=-I. -I../include
LIBDIR=-L../lib
LIBS=

CC=gcc
CFLAGS=${FLAGS} ${INCLUDE}
LDFLAGS=${LIBDIR} ${LIBS}

CCAR=ar
CCARFLAGS=-crvs

all: ${TARGET}

${TARGET}: ${SRCS:%.c=%.o}
	${CCAR} ${CCARFLAGS} $@ $^

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

.PHONY: clean
clean:
	@rm -f *.~ *.bak *.o *.d

.PHONY: distclean
distclean: clean
	@rm -f ${TARGET}
