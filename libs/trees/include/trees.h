#ifndef _TREES_H_
#define _TREES_H_

typedef int BST_DATA;

typedef struct bst_node {
    BST_DATA data;
    struct bst_node *left;
    struct bst_node *right;
} BST_NODE;

void bst_initialize(BST_NODE **ref_node);
void bst_print_data(BST_DATA data);
BST_NODE *bst_create_node(BST_DATA data);
BST_NODE *bst_insert(BST_NODE *node, BST_DATA data);
int bst_exists_data(BST_NODE *node, BST_DATA data);
int bst_count(BST_NODE *node);
int bst_depth(BST_NODE *node);
int bst_height(BST_NODE *node);
BST_DATA bst_minimum(BST_NODE *node);
BST_DATA bst_maximum(BST_NODE *node);
void bst_print(BST_NODE *node);
void bst_destroy(BST_NODE *node);

#endif //_TREES_H_
