#ifndef _AVL_H_
#define _AVL_H_

typedef char AVL_DATA;

typedef struct avl_node {
    AVL_DATA data;
    int height;
    struct avl_node *left;
    struct avl_node *right;
} AVL_NODE;

void avl_initialize(AVL_NODE **ref_node);
void avl_print_data(AVL_DATA data);
AVL_NODE *avl_create_node(AVL_DATA data);
AVL_NODE *avl_insert(AVL_NODE *node, AVL_DATA data);
AVL_NODE *avl_exists_data(AVL_NODE *node, AVL_DATA data);
int avl_size(AVL_NODE *node);
int avl_depth(AVL_NODE *node);
int avl_height(AVL_NODE *node);
AVL_NODE *avl_minimum(AVL_NODE *node);
AVL_NODE *avl_maximum(AVL_NODE *node);
void avl_preorder_walk(AVL_NODE *node);
void avl_inorder_walk(AVL_NODE *node);
void avl_postorder_walk(AVL_NODE *node);
void avl_destroy(AVL_NODE *node);
static AVL_NODE *_rotate_left(AVL_NODE *node);
static AVL_NODE *_rotate_right(AVL_NODE *node);
static int _node_height(AVL_NODE *node);

#endif //_AVL_H_
