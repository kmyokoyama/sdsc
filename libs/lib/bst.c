#include <stdio.h>
#include <stdlib.h>
#include <bst.h>

void bst_initialize(BST_NODE **ref_node) {
    *ref_node = NULL;
}

/*
void bst_print_data(BST_DATA data) {
    printf("%d\n", data);
}
*/

BST_NODE *bst_create_node(BST_DATA data, BST_NODE *parent) {
    BST_NODE *new_node = (BST_NODE *) malloc(sizeof(BST_NODE));

    new_node->data = data;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

static BST_NODE *_bst_insert(BST_NODE *node, BST_DATA data, BST_NODE *parent) {
    if(node == NULL) {
        BST_NODE *new_node = bst_create_node(data, parent);

        return new_node;
    }
    else {
        if(node->data > data) {
            node->left = _bst_insert(node->left, data, node);
        }
        else {
            node->right = _bst_insert(node->right, data, node);
        }

        return node;
    }
}

BST_NODE *bst_insert(BST_NODE *node, BST_DATA data) {
    return _bst_insert(node, data, (node ? node : NULL));
}

BST_NODE *bst_exists_data(BST_NODE *node, BST_DATA data) {
    if(node == NULL) {
        return NULL;
    }
    else {
        if(node->data == data) {
            return node;
        }

        if(node->data > data) {
            return bst_exists_data(node->left, data);
        }
        else {
            return bst_exists_data(node->right, data);
        }
    }
}

int bst_size(BST_NODE *node) {
    if(node == NULL) {
        return 0;
    }
    else {
        int counter_left = bst_size(node->left);
        int counter_right = bst_size(node->right);

        return (counter_left + counter_right + 1);
    }
}

int bst_depth(BST_NODE *node) {
    if(node == NULL) {
        return 0;
    }
    else {
        int depth_l = bst_depth(node->left);
        int depth_r = bst_depth(node->right);

        return(depth_l > depth_r ? (depth_l + 1) : (depth_r + 1));
    }
} 

int bst_height(BST_NODE *node) {
    return bst_depth(node) - 1;
}

BST_NODE *bst_minimum(BST_NODE *node) {
    BST_NODE *current = node;
    while(current->left != NULL) {
        current = current->left;
    }

    return current;
}

BST_NODE *bst_maximum(BST_NODE *node) {
    BST_NODE *current = node;
    while(current->right != NULL) {
        current = current->right;
    }

    return current;
}

BST_NODE *bst_predecessor(BST_NODE *node) {
    if (node->left != NULL) {
        return bst_maximum(node->left);
    }
    BST_NODE *predecessor = node->parent;
    while (predecessor != NULL && node == predecessor->left) {
        node = predecessor;
        predecessor = predecessor->parent;
    }

    return predecessor;
}

BST_NODE *bst_successor(BST_NODE *node) {
    if (node->right != NULL) {
        return bst_minimum(node->right);
    }
    BST_NODE *successor = node->parent;
    while (successor != NULL && node == successor->right) {
        node = successor;
        successor = successor->parent;
    }

    return successor;
}

/*
void bst_preorder_walk(BST_NODE *node) {
    if (node != NULL) {
        bst_print_data(node->data);
        bst_preorder_walk(node->left);
        bst_preorder_walk(node->right);
    }
}

void bst_inorder_walk(BST_NODE *node) {
    if (node != NULL) {
        bst_inorder_walk(node->left);
        bst_print_data(node->data);
        bst_inorder_walk(node->right);
    }
}

void bst_postorder_walk(BST_NODE *node) {
    if (node != NULL) {
        bst_postorder_walk(node->left);
        bst_postorder_walk(node->right);
        bst_print_data(node->data);
    }
}
*/

void bst_destroy(BST_NODE *node) {
    if(node == NULL) {
        return;
    }
    else {
        if(node->left != NULL) {
            bst_destroy(node->left);
        }
        if(node->right != NULL) {
            bst_destroy(node->right);
        }

        free(node);
        return;
    }
}
