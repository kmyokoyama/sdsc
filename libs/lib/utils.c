#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

char *as_str(void *data) {
    return (char *)data;
}

char *as_char(void *data) {
    return *(char *)data;
}

char *as_int(void *data) {
    return *(int *)data;
}

char *as_float(void *data) {
    return *(float *)data;
}
