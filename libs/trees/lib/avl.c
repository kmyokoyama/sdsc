#include <stdio.h>
#include <stdlib.h>
#include <avl.h>

void avl_initialize(AVL_NODE **ref_node) {
    *ref_node = NULL;
}

void avl_print_data(AVL_DATA data) {
    printf("%c\n", data);
}

AVL_NODE *avl_create_node(AVL_DATA data) {
    AVL_NODE *new_node = (AVL_NODE *) malloc(sizeof(AVL_NODE));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

AVL_NODE *avl_insert(AVL_NODE *node, AVL_DATA data) {
    if(node == NULL) {
        AVL_NODE *new_node = avl_create_node(data);

        return new_node;
    }
    else {
        if(node->data > data) {
            node->left = avl_insert(node->left, data);
        }
        else {
            node->right = avl_insert(node->right, data);
        }

        return node;
    }
}

AVL_NODE *avl_exists_data(AVL_NODE *node, AVL_DATA data) {
    if(node == NULL) {
        return NULL;
    }
    else {
        if(node->data == data) {
            return node;
        }

        if(node->data > data) {
            return avl_exists_data(node->left, data);
        }
        else {
            return avl_exists_data(node->right, data);
        }
    }
}

int avl_size(AVL_NODE *node) {
    if(node == NULL) {
        return 0;
    }
    else {
        int counter_left = avl_size(node->left);
        int counter_right = avl_size(node->right);

        return (counter_left + counter_right + 1);
    }
}

int avl_depth(AVL_NODE *node) {
    if(node == NULL) {
        return 0;
    }
    else {
        int depth_l = avl_depth(node->left);
        int depth_r = avl_depth(node->right);

        return(depth_l > depth_r ? (depth_l + 1) : (depth_r + 1));
    }
} 

int avl_height(AVL_NODE *node) {
    return avl_depth(node) - 1;
}

AVL_NODE *avl_minimum(AVL_NODE *node) {
    AVL_NODE *current = node;
    while(current->left != NULL) {
        current = current->left;
    }

    return current;
}

AVL_NODE *avl_maximum(AVL_NODE *node) {
    AVL_NODE *current = node;
    while(current->right != NULL) {
        current = current->right;
    }

    return current;
}

void avl_preorder_walk(AVL_NODE *node) {
    if (node != NULL) {
        avl_print_data(node->data);
        avl_preorder_walk(node->left);
        avl_preorder_walk(node->right);
    }
}

void avl_inorder_walk(AVL_NODE *node) {
    if (node != NULL) {
        avl_inorder_walk(node->left);
        avl_print_data(node->data);
        avl_inorder_walk(node->right);
    }
}

void avl_postorder_walk(AVL_NODE *node) {
    if (node != NULL) {
        avl_postorder_walk(node->left);
        avl_postorder_walk(node->right);
        avl_print_data(node->data);
    }
}

void avl_destroy(AVL_NODE *node) {
    if(node == NULL) {
        return;
    }
    else {
        if(node->left != NULL) {
            avl_destroy(node->left);
        }
        if(node->right != NULL) {
            avl_destroy(node->right);
        }

        free(node);
        return;
    }
}

static AVL_NODE *_rotate_left(AVL_NODE *node) {
    if (node != NULL) {
        AVL_NODE *right_child = node->right;
        node->right = right_child->left;
        right_child->left = node;

        return right_child;
    }

    return NULL;
}

static AVL_NODE *_rotate_right(AVL_NODE *node) {
    if (node != NULL) {
        AVL_NODE *left_child = node->left;
        node->left = left_child->right;
        left_child->right = node;

        return left_child;
    }

    return NULL;
}

static int _node_height(AVL_NODE *node) {
    return (node == NULL ? 0 : node->height);
}

static int is_balanced(AVL_NODE *node) {
    if (node == NULL) {
        return 1;
    }
    
    int h = node->height;
    int hl = _node_height(node->left);
    int hr = _node_height(node->right);

    if (!(h == (hl > hr ? hl + 1 : hr + 1))) {
        return 0;
    }

    if (hl > hr + 1 || hr > hl + 1) {
        return 0;
    }

    return (_is_balanced(node->left) && _is_balanced(node->right));
}

static int _is_avl(AVL_NODE *node) {
    return (_is_ordtree(node) && _is_balanced(node));
}
