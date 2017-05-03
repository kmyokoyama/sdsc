#include <stdio.h>
#include <stdlib.h>
#include <sdscload.h>

BST_NODE *load_bst(char *filename) {
    FILE *fp = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        exit(OPEN_FILE_ERROR);
    }

    BST_NODE *root;
    bst_initialize(root);

    char data;
    while ((data = fgetc(fp)) != EOF) {
        root = bst_insert(root, data);
    }

    return root;
}
