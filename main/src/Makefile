TARGET=test_linked_list
SRCS=${TARGET}.c

BASE=../..
BINDIR=../bin

include libs.in

LIBSDIR=${LISTSDIR} ${TREESDIR}
FLAGS=-static -O2 -Wall -g -MMD
INCLUDE=-I. -I${LISTSINCLUDE} -I${TREESINCLUDE}
LIBDIR=-L${LISTSDIR} -L${TREESDIR}
LIBS=-llists -ltrees
LIBSAR=${LISTSAR} ${TREESAR}

CC=gcc
CFLAGS=${FLAGS} ${INCLUDE}
LDFLAGS=${LIBDIR} ${LIBS}

all: ${TARGET}

${TARGET}: ${SRCS:%.c=%.o} ${LIBSAR}
	${CC} ${CFLAGS} ${LDFLAGS} -o ${BINDIR}/$@ $^

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

${LISTSAR}:
	@echo "#################### Building lists... ####################"
	@cd ${LISTSDIR}; make; make clean

${TREESAR}:
	@echo "#################### Building trees... ####################"
	@cd ${TREESDIR}; make; make clean

.PHONY: valgrind
valgrind: ${TARGET}
	valgrind --leak-check=yes --tool=memcheck --track-origins=yes ${BINDIR}/${TARGET}

.PHONY: allclean
allclean: distclean libclean

.PHONY: clean
clean:
	@rm -f *.~ *.bak *.o *.d

.PHONY: distclean
distclean: clean
	@rm -f ${BINDIR}/${TARGET}

.PHONY: libclean
libclean:
		@for dir in ${LIBSDIR}; do ( cd $${dir}; make distclean; ) done;
